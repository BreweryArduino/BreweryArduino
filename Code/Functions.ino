/*Функция вывода часов на экран
   Для работы этой функции нужны следующие элементы в основном коде:
  #include "RTClib.h"
  #include <Wire.h>
  extern uint8_t SmallRusFont[];
  extern uint8_t BigRusFont[];
  word colorlist[] = {
  VGA_WHITE, VGA_BLACK, VGA_RED, VGA_BLUE, VGA_GREEN, VGA_FUCHSIA, VGA_YELLOW, VGA_AQUA
  RTC_DS1307 rtc;
 *********************************************************************************************
  void setup ()
  Wire.begin();
  rtc.begin();
*/
void ScreenTime (int x, int y, byte z, byte r, byte b) { // x,y начальные координаты вывода на экран часов, z = 1 Маленький шрифт; 2 Большой шрифт, r - цвет шрифта, b - цвет фона шрифта

  byte m, s, h;

  int c;
  if (! rtc.isrunning()) {
    myGLCD.setFont(SmallRusFont);
    if (scrclr == 0) {
      scrclr ++;
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(x, y, x + (8 * c) * 8, y + ((4 * c) + 8));
      myGLCD.setColor(VGA_WHITE);
    }

    myGLCD.print("No clock", x, y);
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(2014, 1, 1, 0, 0, 0));
  }
  else {
    myGLCD.setColor (colorlist[r]);
    myGLCD.setBackColor(colorlist[b]);
    scrclr = 0;
    if (z == 1 ) {
      c = 1;
      myGLCD.setFont(SmallRusFont);
    }
    if (z == 2 ) {
      c = 2;
      myGLCD.setFont(BigRusFont);
    }
    if ( x + ((8 * c) * 8) > 320) x = 320 - ((8 * c) * 8);
    if ( y + ((4 * c) + 8) > 240) y = 240 - ((4 * c) + 8);
    DateTime now = rtc.now();
    if (now.hour() < 10) {
      myGLCD.printNumI(0, x, y);
      h = 8 * c;
    }
    else h = 0;
    myGLCD.printNumI(now.hour(), x + h, y);
    myGLCD.print(":", x + ((8 * c) * 2), y);
    if (now.minute() < 10) {
      myGLCD.printNumI(0, x + ((8 * c) * 3), y);
      m = 8 * c;
    }
    else m = 0;
    myGLCD.printNumI(now.minute(), x + ((8 * c) * 3) + m, y);
    myGLCD.print(":", x + ((8 * c) * 5), y);
    if (now.second() < 10) {
      myGLCD.printNumI(0, x + ((8 * c) * 6), y);
      s = 8 * c;
    }
    else s = 0;
    myGLCD.printNumI(now.second(), x + ((8 * c) * 6) + s, y);
    //Serial.print(now.year(), DEC);
    //Serial.print('/');
    // Serial.print(now.month(), DEC);
    //Serial.print('/');
    // Serial.print(now.day(), DEC);

  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//расчет мощности по ПИ закону регулирования
byte PIctl(float temp, int8_t ust)//возвращает необходимую мощность
{

  /*#define kP 15//коэффициент пропорциональности
    #define p_min 0.0//минимум П составляющей - не < 0
    #define p_max 100.0//максимум П составляющей - не > 100
    #define kI 0.015//коэффициент интегрирования
    #define i_min -30.0//минимум И составляющей
    #define i_max 30.0//максимум И составляющей
    #define d_ctl 2.0//зона пропорциональности ust-d_ctl
    #define out_min 0//минимальный выходной %
    #define out_max 100//максимальный выходной %
  */

  ePid = (ust - temp); //ошибка регулирования
  //расчет p
  pPid = (temp < ust - d_ctl) ? p_max : (temp > ust) ? p_min : (kP * ePid);
  //расчет i
  iPid = (iPid < i_min) ? i_min : (iPid > i_max) ? i_max : iPid + (kI * ePid);
  out = (pPid + iPid < out_min) ? out_min : (pPid + iPid > out_max) ? out_max : pPid + iPid;
  return out;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void printTemperature() {


  if (millis() - lastTempRequest >= delayInMillis) // waited long enough??
  {
    temperature = sensors.getTempCByIndex(0);
    idle = 0;
    resolution++;
    if (resolution > 12) resolution = 9;
    sensors.setResolution(tempDeviceAddress, resolution);
    sensors.requestTemperatures();
    delayInMillis = 750 / (1 << (12 - resolution));
    lastTempRequest = millis();
  }
  idle++;

  TempC = temperature + 0.51;

  myGLCD.setColor(VGA_LIME);
  myGLCD.printNumI(TempC, 209, 81);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void printTemperatureNoScr() {
  if (millis() - lastTempRequest >= delayInMillis) // waited long enough??
  {
    temperature = sensors.getTempCByIndex(0);
    idle = 0;
    resolution++;
    if (resolution > 12) resolution = 9;
    sensors.setResolution(tempDeviceAddress, resolution);
    sensors.requestTemperatures();
    delayInMillis = 750 / (1 << (12 - resolution));
    lastTempRequest = millis();
  }
  idle++;

  TempC = temperature + 0.51;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void timeselect () {
  DateTime now = rtc.now();
  hoset = now.hour();
  miset = now.minute();
  seset = now.second();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void SetTimeClock (byte ho2, byte mi2, byte se2) {

  rtc.adjust(DateTime(2014, 1, 1, ho2, mi2, se2));

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//Функция считает сколько осталось времени до завершения шага с выводом на экран
int OutTime (byte z, byte x) { // z = pauseB[], x = termB[]
  int iz = 0;

  ScreenTime (96, 196, 2, 9, 1);
  myGLCD.setColor(VGA_LIME);
  DateTime now = rtc.now();
  ho = now.hour();
  mi = now.minute();
  se = now.second();
  da = now.day();
  if (ho ==  ho1 && mi == mi1 && se == se1 && da == da1) {
    iz = z + 1;
  }
  long int q;
  long int h1;
  int m1;
  int s1;
  if (da1 == da) {
    h1 = (ho1 - ho) * 3600;
    m1 = (mi1 - mi) * 60;
    s1 = (se1 - se);
    q = (h1 + m1 + s1) / 60;
  }
  else {
    ho = ho * 3600;
    mi = mi * 60;
    h1 = ho1 * 3600;
    m1 = mi1 * 60;
    q = ((86400 + h1 + m1 + se1) - (ho + mi + se)) / 60;
  }
  if (q > 0) {
    if (q <= 9) myGLCD.print(" ", 247, 25);
    if (q <= 99) myGLCD.print(" ", 263, 25);
    myGLCD.printNumI(q, 231, 25);
  }
  if (q == 0) {
    myGLCD.printNumI(0, 231, 25);
    myGLCD.print(".", 247, 25);
    if (da1 == da) {
      q = (h1 + m1 + s1) / 1;
    }
    else q = ((86400 + h1 + m1 + se1) - (ho + mi + se)) / 1;
    if (q >= 10) {
      myGLCD.printNumI(q, 263, 25);
    }
    else {
      myGLCD.printNumI(q, 263, 25);
      myGLCD.print(" ", 279, 25);
    }
  }
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setColor(VGA_RED);
  myGLCD.printNumI(x, 15, 81);
  printTemperature();
  return iz;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//Функция считает сколько осталось времени до завершения шага без вывода на экран
int OutTimeNoScr (byte z) { // z = pauseB[]
  int iz = 0;

  ScreenTime (96, 196, 2, 9, 1);
  myGLCD.setColor(VGA_LIME);
  DateTime now = rtc.now();
  ho = now.hour();
  mi = now.minute();
  se = now.second();
  da = now.day();
  if (ho ==  ho1 && mi == mi1 && se == se1 && da == da1) {
    iz = z + 1;
  }
  long int q;
  long int h1;
  int m1;
  int s1;
  if (da1 == da) {
    h1 = (ho1 - ho) * 3600;
    m1 = (mi1 - mi) * 60;
    s1 = (se1 - se);
    q = (h1 + m1 + s1) / 60;
  }
  else {
    ho = ho * 3600;
    mi = mi * 60;
    h1 = ho1 * 3600;
    m1 = mi1 * 60;
    q = ((86400 + h1 + m1 + se1) - (ho + mi + se)) / 60;
  }

  if (q <= 9) myGLCD.print(" ", 247, 25);
  if (q <= 99) myGLCD.print(" ", 263, 25);
  myGLCD.printNumI(q, 231, 25);
  return iz;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
/*int Se () {
  boolean h = false;
  if (chek == true) {
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + 60);
    miFSh = future.second();
  }
  DateTime now = rtc.now();
  miSh = now.second();
  byte seC =  miFSh - miSh;
  if (seC == 0) {
    h = true;
    chek  = true;
  }
  else h = false;
  return h;
  }
*/
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void TimeWorkNasos (byte r, byte f, byte l) { //Функция считает время работы и простоя насоса (работа,простой) и отображение
  printTemperatureNoScr();
  if (OnOffTerpNW == true && maxTerpNW <= TempC ) {
    if  (OnOffTerpScr == true) {
      fR = 1;
      fT = 1;
      digitalWrite( NasosPin, ReleOff);
      if (l == 1) {
        myGLCD.setBackColor(VGA_YELLOW);
        myGLCD.setColor(VGA_RED);
        myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
        myGLCD.drawLine(135, 20, 185, 70);
        myGLCD.drawLine(185, 20, 135, 70);
        myGLCD.setFont(BigRusFont);
        myGLCD.printNumI(maxTerpNW, 140, 40);
        myGLCD.setBackColor(VGA_BLACK);
        OnOffTerpScr = false;
      }
    }
    goto label;
  }
  OnOffTerpScr = true;
  if (fT == 1) {
    int ii;
    if (fR == 0) ii = f ;// простой
    if (fR == 1) ii = r * ReleTime;// работа
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    hoN = future.hour();
    miN = future.minute();
    seN = future.second();
    daN = future.day();
    fT = 0;
  }
  if (fR == 1 && fT == 0) {
    DateTime now = rtc.now();
    ho = now.hour();
    mi = now.minute();
    se = now.second();
    da = now.day();
    if (ho ==  hoN && mi == miN && se == seN && da == daN) {
      fR = 0;
      fT = 1;
      digitalWrite( NasosPin, ReleOff);
      if (l == 1) {
        myGLCD.setColor(VGA_BLACK);
        myGLCD.fillRoundRect(134, 18, 187, 72);
      }
    }
    else {
      digitalWrite( NasosPin, ReleOn);
      if ( l == 1) {
        myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
      }
    }

  }
label:
  if (fR == 0 && fT == 0) {
    DateTime now = rtc.now();
    ho = now.hour();
    mi = now.minute();
    se = now.second();
    da = now.day();
    if (ho ==  hoN && mi == miN && se == seN && da == daN) {
      fR = 1;
      fT = 1;
    }
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void TimeWorkNasosAir () { //Функция продувки насоса

  if (fT == 1) {
    int ii;
    if (fR == 0) ii = airP;// простой
    if (fR == 1) ii = airW;// работа
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    hoN = future.hour();
    miN = future.minute();
    seN = future.second();
    daN = future.day();
    fT = 0;
  }
  if (fR == 1 && fT == 0) {
    DateTime now = rtc.now();
    ho = now.hour();
    mi = now.minute();
    se = now.second();
    da = now.day();
    if (ho ==  hoN && mi == miN && se == seN && da == daN) {
      fR = 0;
      fT = 1;
      digitalWrite( NasosPin, ReleOff);
    }
    else digitalWrite( NasosPin, ReleOn);
  }
  if (fR == 0 && fT == 0) {
    DateTime now = rtc.now();
    ho = now.hour();
    mi = now.minute();
    se = now.second();
    da = now.day();
    if (ho ==  hoN && mi == miN && se == seN && da == daN) {
      fR = 1;
      fT = 1;
    }
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void OffNasos (byte l) {
  if (l == 1) {
    myGLCD.setColor(VGA_BLACK);
    myGLCD.fillRoundRect(134, 18, 187, 72);
  }
  digitalWrite( NasosPin, ReleOff);
   OnOffTerpScr = true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void OnNasos (byte l) {
   if (OnOffTerpNW == true && maxTerpNW <= TempC ) {
    if  (OnOffTerpScr == true) {
      digitalWrite( NasosPin, ReleOff);
      if (l == 1) {
        myGLCD.setBackColor(VGA_YELLOW);
        myGLCD.setColor(VGA_RED);
        myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
        myGLCD.drawLine(135, 20, 185, 70);
        myGLCD.drawLine(185, 20, 135, 70);
        myGLCD.setFont(BigRusFont);
        myGLCD.printNumI(maxTerpNW, 140, 40);
        myGLCD.setBackColor(VGA_BLACK);
        OnOffTerpScr = false;
      }
    }
    goto labelOn;
  }
  OnOffTerpScr = true;
  if (l == 1) {
    if (OnOffTerpNW == true){
      myGLCD.setFont(SmallRusFont);
      myGLCD.setColor(VGA_LIME);      
       myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
       myGLCD.printNumI(maxTerpNW, 158, 60);
    }
    else myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
  }
  digitalWrite( NasosPin, ReleOn);
  labelOn:
  byte i;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void OffHot () {
  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRoundRect(134, 74, 187, 126);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void OnHot () {
  myGLCD.drawBitmap(135, 75, 50, 50, Hot2, 1);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void melodi ()
{
  // notes in the melody:
  int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(Bib, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(Bib);
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void melodiErr ()
{
  int melodyErr[] = {
    NOTE_A6, NOTE_C7, NOTE_D7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_C8, NOTE_DS8,
    NOTE_A6, NOTE_C7, NOTE_D7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_C8, NOTE_DS8
  };
  int noteDurationsErr[] = {
    2, 3, 4, 5, 6, 7, 8, 2, 9, 8, 7, 6, 5, 4, 3, 6
  };

  for (int thisNote = 0; thisNote < 16; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDurationErr = 1000 / noteDurationsErr[thisNote];
    tone(Bib, melodyErr[thisNote], noteDurationErr);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDurationErr / 10;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(Bib);
  }
}
void FMelodi (byte Melodi1) {
  if (Melodi1 == 0) melodi ();
  if (Melodi1 == 1) melodiErr ();
}
void ErroSD () {
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    myGLCD.setColor(VGA_RED);
    myGLCD.setBackColor(VGA_YELLOW);
    myGLCD.setFont(BigRusFont);
    myGLCD.print("O""\xA8""\x9D""\x96""\x9F""a"" ""S""D"" ""\x9F""ap""\xA4""\xAB""!", CENTER, 110);//Ошибка!
    delay(3000);
    setSD ();
  }
}

void ScreenListDir (byte i) {
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, sd, 1);
  myGLCD.drawBitmap(32, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(279, 165, 30, 64, downButton1, 1);
  // myGLCD.drawBitmap(274, 126, 40, 40, ok1, 1);
  myGLCD.drawBitmap(279, 57, 30, 64, UpButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("PE""\x8C""E""\x89""TOB: ", 210, 25);
  // SDReadDir ();
  myGLCD.printNumI(SumDir, 280, 25);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("PE""\x8C""E""\x89""TOB: ", 210, 25);
  myGLCD.printNumI(SumDir, 280, 25);
  myGLCD.setFont(BigRusFont);
  myGLCD.printNumI(1 + i, 5, 75);
  myGLCD.printNumI(2 + i, 5, 107);
  myGLCD.printNumI(3 + i, 5, 139);
  myGLCD.printNumI(4 + i, 5, 171);
  myGLCD.printNumI(5 + i, 5, 203);

  myGLCD.print(NameDir[0 + i], 53, 75);
  myGLCD.print(NameDir[1 + i], 53, 107);
  myGLCD.print(NameDir[2 + i], 53, 139);
  myGLCD.print(NameDir[3 + i], 53, 171);
  myGLCD.print(NameDir[4 + i], 53, 203);
  Touch5 ();
}
void Touch () {
  byte i = 0;
  while (i == 0) {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      i++;
    }
  }
}
void ProgressBerr (byte i) {
  myGLCD.setColor(VGA_WHITE);
  scale = scale + (kof * i);
  myGLCD.fillRect (10, 225, scale, 230);
}
void BlackScr () {
  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRect (3, 3, 317, 220);
}

