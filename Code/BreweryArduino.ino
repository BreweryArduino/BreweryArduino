

// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>
#include "RTClib.h"
#include <UTFT.h>
#include <URTouch.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <EEPROM.h>
#include <SPI.h>
#include <SD.h>
#include "pitches.h"
#include <DigOut.h>//класс дискретного выхода
// Data wire is plugged into port 8 on the Arduino
#define ONE_WIRE_BUS 8

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
Sd2Card card;
SdVolume volume;
SdFile root;
const int chipSelect = 53;
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// arrays to hold device address
DeviceAddress tempDeviceAddress;

UTFT    myGLCD(ILI9341_16, 38, 39, 40, 41);
URTouch  myTouch( 6, 5, 4, 3, 2);
DigOut ten(12);//нагреватель на 9 пине
#define NasosPin  10// насос
#define Bib 11// pin 11 - выход писчалки
#define t_pwm 1000//период медленного ШИМ`а
uint8_t out = 0;
float kP = 15; //коэффициент пропорциональности
#define p_min 0.0//минимум П составляющей - не < 0
#define p_max 100.0//максимум П составляющей - не > 100
float kI = 0;//коэффициент интегрирования
#define i_min -30.0//минимум И составляющей
#define i_max 30.0//максимум И составляющей
#define d_ctl 0.5//зона пропорциональности ust-d_ctl
#define out_min 0//минимальный выходной %
#define out_max 100//максимальный выходной %
static float iPid = 0;
float ePid, pPid;

void(* resetFunc) (void) = 0; // Reset MC function

void ScreenTime (int x, int y, byte z, byte r, byte b);//Вывод на времени на экран
void SetTimeClock (int yea2, byte mon2, byte da2, byte ho2, byte mi2, byte se2); //Установка даты и времени часов
void waitForItButton(int x1, int y1, int x2, int y2); void waitForItButton1(int x1, int y1, int x2, int y2);
int OutTime (byte z, byte x); void SetTime (byte g); void timeselect (); void printTemperature();
byte PIctl(float temp, int8_t ust); void printTemperatureNoScr(); void NoCommerc();
int Se (); void melodi (); void melodiErr (); int OutTimeNoScr (byte z); void UpDown2 (); void setBeerN_1 (byte gg); void FMelodi (byte Melodi1);
void setBeerM_1 (); void setBeerN1 (); void TimeWorkNasos (byte r, byte f, byte l); void TimeWorkNasosAir (); void OffNasos (byte l);
void OnNasos (byte l); void OffHot (); void OnHot (); void Save_sys (); void Read_sys (); void CardInfo (); void SDSaveSys (); void SDRead (String nameF);
void SDReadSys (); void SDBeerName (); void SDSaveBeer (); void SDReadDir (); void ErroSD (); void SDReadBeer (); void ScreenListDir (byte i);
void ProgressBerr (byte i); void BlackScr (); void melodiNokia (); void Date (int x, int y, byte z, byte r, byte b); void SetDate (byte g); void timeReal ();
void Return ();void MainMenu ();
//******************************************************************************************************************
void Screen0(); void Screen1(); void Screen2(); void Screen2_1 (); void Screen3(); void Screen4(); void Screen5(); void ScreenSetTime ();
void setHot (); void setNasos (); void setBeer (); void setSD (); void Screen4_1 (); void Screen4_2 (); void Screen5_2 (); void Beer ();
void setBeer_1 (); void ScreenSys (); void ScreenREC (); void SetRele (); void setNasos_1 ();
//******************************************************************************************************************
void Touch0 (); void Touch1 (); void Touch2 (); void Touch3 (); void Touch4_1 (); void  UpDown (); void UpDown1 (); void OkTabel (); void SetScreen4 (byte g, byte i);
void Touch4 (); void Touch5 (); void TouchHot (); void TouchNasos (); void TouchBeer (); void TouchSD (); void TouchSetTime (); void OkTabel1 (); void Touch4_2 ();
void Touch5_2 (); void OkTabel2 (); void FWorkN (byte workN1); void FPauseN (byte pauseN1); void UpDown3 (); void TouchsetBeerN_1 (byte hh); void TouchsetBeerM_1 ();
void TouchBeer_1 (); void TouchSys (); void TouchREC (); void TouchSDBeerReName (byte g); void TouchRele (); void Touch (); void TochNasos_1 (); void TochStop (byte pause, boolean pauseNo);
//******************************************************************************************************************

extern unsigned Set2[0x9C4];
extern unsigned sd[0x9C4];
extern unsigned nasos[0x9C4];
extern unsigned Hot2[0x9C4];
extern unsigned beer[0x9C4];
extern unsigned LeftButton1[0x780];
extern unsigned ok1[0x640];
extern unsigned clock1[0x9C4];
extern unsigned RightButton1[0x780];
extern unsigned minus1[0x640];
extern unsigned Plus1[0x640];
extern unsigned downButton1[0x780];
extern unsigned UpButton1[0x780];

extern uint8_t SmallRusFont[];
extern uint8_t BigRusFont[];
extern uint8_t SevenSegNumFont[];
word colorlist[] = {
  VGA_WHITE, VGA_BLACK, VGA_RED, VGA_BLUE, VGA_GREEN, VGA_FUCHSIA, VGA_YELLOW, VGA_AQUA, VGA_GRAY, VGA_LIME
};
//RTC_Millis rtc;
RTC_DS1307 rtc;

int x = 100;
int y = 100;
byte numberPauseB = 0;// кол-во температурных пауз
byte scrclr = 1;//флаг запрета обновления надписи "no clok"
byte pauseB1; byte pauseB2; byte pauseB3; byte pauseB4; byte pauseB5; byte pauseB6; //массив хранения температурных пауз в приготовлении пива 1 по 6 время паузы
byte termB1; byte termB2; byte termB3; byte termB4; byte termB5; byte termB6; byte termB7;
byte timeB1, timeB2, timeB3, timeB4, timeB5, timeB6; //время кипячения и закладки хмеля
byte chil;//охладить
byte termKIP = 100;// температура закипания
long int ho, mi, se, da, yea, mon;
long int ho1, mi1, se1, da1;
int yeaset;
byte hoset, miset, seset, daset, monset;
int hoB2, miB2, seB2, daB2, hoB3, miB3, seB3, daB3, hoB4, miB4, seB4, daB4, hoB5, miB5, seB5, daB5, hoB6, miB6, seB6, daB6;
int hoN, miN, seN, daN;
byte fT = 1;
byte fR = 1;
byte ReleTime = 60;//кратность в секундах работы насоса
byte RelePause = 1;//кратность в секундах простоя насоса
byte ReleOn = LOW;
byte ReleOff = HIGH;
byte iteration = 0;
byte flagTabel = 1; byte flagTabel1 = 1; byte flagTabelWN = 1; byte flagTabelB = 1; byte flagTabelName = 1;
int TempC;
int TempCSET = 10;
byte ON_OFF = 0;

byte PauseN[7];//массив пауз насоса
byte WorkN[7] {}; // массив времени работы наноса
byte BeerN[7] {7, 7, 7, 7, 7, 7, 7}; //массив привязки насоса к этапам пивоварения
byte MelodiN[7] {1, 1, 1, 1, 1, 1, 0}; //массив привязки мелодий к этапам пивоварения
int  resolution = 12;
unsigned long lastTempRequest = 0;
int  delayInMillis = 0;
float temperature = 0.0;
int  idle = 0;
byte airW = 5; byte airP = 5; byte rep = 3;// продувка насосa
byte nasosWH = 1; byte nasosPH = 1; // переменные для хранения времени работы и простоя насоса в режиме тэна
boolean innverN = false;//переменная для инвертирования в Touch2
boolean SdTouch = false;//переменная для запрета нажатия кнопки "ПОВТОРИТЬ" в TouchSD и CardInfo
int outArray[150];
String NameBeer = "/BEER/";
String NameDir[25] = "";//буфер хренеия имен рецептов считанных с SD карты
char* BufName[] = {"M", "Y", "_", "_", "B", "E", "E", "R",}; // временный буфер для хранения имени сохраняемого рецепта
byte SumDir = 0;//для хранения кол-во рецептов
byte ScreenDir = 1;
int kof;//шкала прогресса
int scale = 0;//шкала прогресса
byte maxTerpNW = 85;
boolean OnOffTerpNW = false;
boolean OnOffTerpScr = true;
byte termgist;
byte BeerStep = 0;//Переменная для хранения этапа варки
long int timeWorkPause;// переменная для сохранения "сколько работает пауза"
byte statusMainMenu = 0;
byte SubBeerStep = 0;
byte SubSubBeerStep = 0;//подпод шаги для йодной пробы
byte DoubleTap = 0;//флаг двойного нажатия для выход из меню настроек(варка) в главное меню
boolean statusDoubleTap = 0;
void setup () {
attachInterrupt(5, Return, RISING); //Раскомментировать если используете кнопку перехода в главное меню
  Read_sys ();
  Wire.begin();
  SD.begin(chipSelect);
  //rtc.begin();
  DateTime now = rtc.now();

  Serial.begin(9600);
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.fillScr(VGA_BLACK);
  myTouch.InitTouch(1);
  myTouch.setPrecision(PREC_MEDIUM);
  sensors.begin();
  sensors.getAddress(tempDeviceAddress, 0);
  sensors.setResolution(tempDeviceAddress, resolution);

  sensors.setWaitForConversion(false);
  sensors.requestTemperatures();
  delayInMillis = 750 / (1 << (12 - resolution));
  lastTempRequest = millis();

  pinMode (NasosPin, OUTPUT);
  digitalWrite(NasosPin, ReleOff);
  NoCommerc();

}

void loop () {




}




