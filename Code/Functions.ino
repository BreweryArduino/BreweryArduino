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
      myGLCD.setColor(VGA_GRAY);
    }

    myGLCD.print("No clock", x, y);
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(2009, 7, 3, 0, 0, 0));
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
    da =  now.day();
    mon =  now.month();
    yea = now.year();

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
    temperature = sensors.getTempCByIndex(0) + TermCk;
    idle = 0;
    resolution++;
    if (resolution > 12) resolution = 9;
    sensors.setResolution(tempDeviceAddress, resolution);
    sensors.requestTemperatures();
    delayInMillis = 750 / (1 << (12 - resolution));
    lastTempRequest = millis();
  }
  idle++;

  TempC = temperature + 0.51 + TermCk;

  myGLCD.setColor(VGA_LIME);
  if (TempC < 100) {
    myGLCD.setColor(VGA_BLACK);
    myGLCD.fillRoundRect(273, 81, 305, 131);
  }
  myGLCD.setColor(VGA_LIME);
  myGLCD.printNumI(TempC, 209, 81);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void printTemperatureNoScr() {
  if (millis() - lastTempRequest >= delayInMillis) // waited long enough??
  {
    temperature = sensors.getTempCByIndex(0) + TermCk;
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
  daset = now.day();
  monset =  now.month();
  yeaset = now.year();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void timeReal () {
  DateTime now = rtc.now();
  ho = now.hour();
  mi = now.minute();
  se = now.second();
  da = now.day();
  mon =  now.month();
  yea = now.year();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void SetTimeClock (int yea2, byte mon2, byte da2, byte ho2, byte mi2, byte se2) {

  rtc.adjust(DateTime(yea2, mon2, da2, ho2, mi2, se2));

}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//Функция считает сколько осталось времени до завершения шага с выводом на экран
int OutTime (byte z, byte x) { // z = pauseB[], x = termB[]
  int iz = 0;
  ScreenTime (96, 188, 2, 9, 1);
  myGLCD.setColor(VGA_LIME);
  DateTime now = rtc.now();
  ho = now.hour();    //узнаем какой текущий час
  mi = now.minute();  //узнаем какая текущая минута
  se = now.second();  //узнаем какая текущая секунда
  da = now.day();   //узнаем какой текущий день
  if (ho ==  ho1 && mi == mi1 && se == se1 && da == da1) {
    iz = z + 1;
  }
  long int q;
  long int h1;
  int m1;
  int s1;
  if (da1 == da) {
    h1 = (ho1 - ho) * 3600;   //остаток паузы часов в сеундах
    m1 = (mi1 - mi) * 60;   //остаток паузы минут в сеундах
    s1 = (se1 - se);      //остаток паузы сеунд
    timeWorkPause = (h1 + m1 + s1);
    q = (h1 + m1 + s1) / 60;
  }
  else {
    ho = ho * 3600;
    mi = mi * 60;
    h1 = ho1 * 3600;
    m1 = mi1 * 60;
    timeWorkPause = ((86400 + h1 + m1 + se1) - (ho + mi + se));
    q = ((86400 + h1 + m1 + se1) - (ho + mi + se)) / 60;//минуты
  }
  if (q > 0) {

    if (q > 99) myGLCD.printNumI(q, 208, 25);
    if  (q >= 10 && q <= 99) {
      myGLCD.print(" ", 208, 25);
      myGLCD.printNumI(q, 224, 25);
    }
    if (q >= 0 && q <= 9) {
      myGLCD.print(" ", 224, 25);
      myGLCD.printNumI(q, 240, 25);
    }


    //----------отображает секунды
    int q1;
    q1 = (-q * 60) + timeWorkPause;
    myGLCD.print(":", 256, 25);
    //q1 = secundprint[se];
    if (q1 >= 10) {
      myGLCD.printNumI(q1, 272, 25);
    }
    else {
      myGLCD.printNumI(0, 272, 25);
      myGLCD.printNumI(q1, 288, 25);
    }
    //-------------
  }
  if (q == 0) {
    myGLCD.printNumI(0, 240, 25);
    myGLCD.print(":", 256, 25);
    if (da1 == da) {
      q = (h1 + m1 + s1) / 1;
    }
    else q = ((86400 + h1 + m1 + se1) - (ho + mi + se)) / 1;
    timeWorkPause = q;
    if (q >= 10) {
      myGLCD.printNumI(q, 272, 25);
    }
    else {
      myGLCD.printNumI(q, 288, 25);
      myGLCD.printNumI(0, 272, 25);
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

  ScreenTime (96, 188, 2, 9, 1);
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
    timeWorkPause = (h1 + m1 + s1);
    q = (h1 + m1 + s1) / 60;
  }
  else {
    ho = ho * 3600;
    mi = mi * 60;
    h1 = ho1 * 3600;
    m1 = mi1 * 60;
    timeWorkPause = ((86400 + h1 + m1 + se1) - (ho + mi + se));
    q = ((86400 + h1 + m1 + se1) - (ho + mi + se)) / 60;
  }
  if (q > 0) {

    if (q > 99) myGLCD.printNumI(q, 208, 25);
    if  (q >= 10 && q <= 99) {
      myGLCD.print(" ", 208, 25);
      myGLCD.printNumI(q, 224, 25);
    }
    if (q >= 0 && q <= 9) {
      myGLCD.print(" ", 224, 25);
      myGLCD.printNumI(q, 240, 25);
    }


    //----------отображает секунды
    int q1;
    q1 = (-q * 60) + timeWorkPause;
    myGLCD.print(":", 256, 25);
    //q1 = secundprint[se];
    if (q1 >= 10) {
      myGLCD.printNumI(q1, 272, 25);
    }
    else {
      myGLCD.printNumI(0, 272, 25);
      myGLCD.printNumI(q1, 288, 25);
    }
    //-------------
  }
  if (q == 0) {
    myGLCD.printNumI(0, 240, 25);
    myGLCD.print(":", 256, 25);
    if (da1 == da) {
      q = (h1 + m1 + s1) / 1;
    }
    else q = ((86400 + h1 + m1 + se1) - (ho + mi + se)) / 1;
    timeWorkPause = q;
    if (q >= 10) {
      myGLCD.printNumI(q, 272, 25);
    }
    else {
      myGLCD.printNumI(q, 288, 25);
      myGLCD.printNumI(0, 272, 25);
    }
  }
  return iz;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void NoCommerc() {
  if (EEPROM.read(100) != 1) {
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setFont(SmallRusFont);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.print("Commercial use without ", CENTER, 10);
    myGLCD.print("permission is prohibited", CENTER, 26);
    delay(500);
    myGLCD.print("is prohibited !", CENTER, 42);
    delay(500);
    myGLCD.print("Dementev Nikolay", CENTER, 58);
    delay(500);
    myGLCD.print("breweryarduino@mail.ru", CENTER, 74);
    delay(500);
    myGLCD.print("Ko""\xA1""\xA1""ep""\xA7""ec""\x9F""oe ""\x9D""c""\xA3""o""\xA0""\xAC""\x9C""o""\x97""a""\xA2""\x9D", CENTER, 100);
    delay(500);
    myGLCD.print("\x96""e""\x9C"" ""pa""\x9C""pe""\xA8""e""\xA2""\x9D""\xAF"" ""a""\x97""\xA4""opa", CENTER, 116);
    delay(500);
    myGLCD.print("\x9C""a""\xA3""pe""\xA9""e""\xA2""o !", CENTER, 132);
    delay(500);
    myGLCD.print("\x82""e""\xA1""e""\xA2""\xA4""\xAC""e""\x97"" ""H""\x9D""\x9F""o""\xA0""a""\x9E", CENTER, 148);
    delay(500);
    myGLCD.print("breweryarduino@mail.ru", CENTER, 164);
    myGLCD.setFont(BigRusFont);
    myGLCD.setColor(VGA_BLUE);
    myGLCD.fillRoundRect(50, 180, 270, 236);
    myGLCD.setBackColor(VGA_BLUE);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("\x89""P""\x86""H""\x95""T""\x92", CENTER, 200);
    while (true)
    {
      if (myTouch.dataAvailable())
      {
        myTouch.read();
        x = myTouch.getX();
        y = myTouch.getY();
        if (x > 50 && x < 270 && y > 180 && y < 236) {
          waitForItButton(50, 180, 270, 236);
          EEPROM.write(100, 1);
          Screen0 ();
        }

      }
    }
  }
  ReturnBackup ();
  Screen0 ();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void Date (int x, int y, byte z, byte r, byte b) {// x,y начальные координаты вывода на экран даты, z = 1 Маленький шрифт; 2 Большой шрифт, r - цвет шрифта, b - цвет фона шрифта

  byte m, s, h;

  int c;
  if (! rtc.isrunning()) {
    myGLCD.setFont(SmallRusFont);
    if (scrclr == 0) {
      scrclr ++;
      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillRect(x, y, x + (8 * c) * 8, y + ((4 * c) + 8));
      myGLCD.setColor(VGA_GRAY);
    }

    myGLCD.print("No clock", x, y);
    // following line sets the RTC to the date & time this sketch was compiled
    // rtc.adjust(DateTime(2009, 7, 3, 0, 0, 0));
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
    da =  now.day();
    mon =  now.month();
    yea = now.year();

    if (now.day() < 10) {
      myGLCD.printNumI(0, x, y);
      h = 8 * c;
    }
    else h = 0;
    myGLCD.printNumI(now.day(), x + h, y);
    myGLCD.print(".", x + ((8 * c) * 2), y);
    if (now.month() < 10) {
      myGLCD.printNumI(0, x + ((8 * c) * 3), y);
      m = 8 * c;
    }
    else m = 0;
    myGLCD.printNumI(now.month(), x + ((8 * c) * 3) + m, y);
    myGLCD.print(".", x + ((8 * c) * 5), y);
    s = 0;
    myGLCD.printNumI(now.year(), x + ((8 * c) * 6) + s, y);
  }
}

//----------------------------------------------------------------------------------------------------------------------------------

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
        byte q;
        if (maxTerpNW >= 10 && maxTerpNW < 100) {
          q = 8;
        }
        else q = 0;
        if (maxTerpNW < 10) q = 26;
        myGLCD.printNumI(maxTerpNW, 136 + q, 40);
        myGLCD.setBackColor(VGA_BLACK);
        OnOffTerpScr = false;
        termgist = 2;
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
      OffNasos (l);
      //digitalWrite( NasosPin, ReleOff);
      // if (l == 1) {
      //myGLCD.setColor(VGA_BLACK);
      //myGLCD.fillRoundRect(134, 18, 187, 72);
      //}
    }
    else {
      //digitalWrite( NasosPin, ReleOn);
      //if ( l == 1) {
      OnNasos (l);
      //myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
      //}
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
        byte q;
        if (maxTerpNW >= 10 && maxTerpNW < 100) {
          q = 8;
        }
        else q = 0;
        if (maxTerpNW < 10) q = 26;
        myGLCD.printNumI(maxTerpNW, 136 + q, 40);
        myGLCD.setBackColor(VGA_BLACK);
        OnOffTerpScr = false;
        termgist = 2;
      }
    }
    goto labelOn;
  }
  OnOffTerpScr = true;
  if (l == 1) {
    if (OnOffTerpNW == true) {
      if (maxTerpNW > TempC + termgist) {
        myGLCD.setFont(SmallRusFont);
        myGLCD.setBackColor(VGA_WHITE);
        myGLCD.setColor(VGA_GREEN);
        myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
        byte q;

        if (maxTerpNW > 10 && maxTerpNW < 100) {
          q = 8;
        }
        else q = 0;
        if (maxTerpNW < 10) q = 16;
        myGLCD.printNumI(maxTerpNW, 161 + q, 58);
        myGLCD.setBackColor(VGA_BLACK);

        digitalWrite( NasosPin, ReleOn);//
        termgist = 0;
      }
    }
    else {
      myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
      digitalWrite( NasosPin, ReleOn);
    }
  }
  else digitalWrite( NasosPin, ReleOn);
labelOn:
  byte i;//просто так но без ниго не как.
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void OffHot () {
  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRoundRect(134, 74, 187, 126);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void OnHot () {
  myGLCD.drawBitmap(135, 75, 50, 50, Hot2, 1);
  myGLCD.setFont(SmallRusFont);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setColor(VGA_GREEN);
  byte q;

  if (out > 10 && out < 100) {
    q = 8;
  }
  else q = 0;
  if (out < 10) q = 16;
  myGLCD.printNumI(out, 161 + q, 112);
  myGLCD.setBackColor(VGA_BLACK);
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
//----------------------------------------------------------------------------------------------------------------------------------------------------
void melodiNokia () {
  int melody[] = { NOTE_E5, NOTE_D5, NOTE_F4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_D4, NOTE_E4, NOTE_B4, NOTE_A4, NOTE_C4, NOTE_E4, NOTE_A4 };
  int noteDurations[] = { 8, 8, 4, 4, 8, 8, 4, 4, 8, 8, 4, 4, 1 };
  int amountNotes = 13;


  for (int thisNote = 0; thisNote < amountNotes; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(Bib, melody[thisNote], noteDuration);
    delay(noteDuration);
    noTone(Bib);
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void FMelodi (byte Melodi1) {
  if (Melodi1 == 0) melodi ();
  if (Melodi1 == 1) melodiErr ();
  if (Melodi1 == 2) melodiNokia ();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------------------------------------
void Touch () {
  byte i = 0;
  while (i == 0) {
    if (myTouch.dataAvailable())
    {
      if (x > 300 && x < 320 && y > 0 && y < 10) {
        myGLCD.print("\x82""e""\xA1""e""\xA2""\xA4""\xAC""e""\x97"" ""H""\x9D""\x9F""o""\xA0""a""\x9E", CENTER, 204);
      }
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      i++;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void ProgressBerr (byte i) {
  myGLCD.setColor(VGA_YELLOW);
  scale = scale + (kof * i);
  //myGLCD.printNumI(scale, 250, 200);
  myGLCD.fillRect (10, 225, scale, 230);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void BlackScr () {
  myGLCD.setColor(VGA_BLACK);
  myGLCD.fillRect (3, 3, 317, 201);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
// call back for file timestamps
void dateTime(uint16_t* date, uint16_t* time) {
  DateTime now = rtc.now();

  // return date using FAT_DATE macro to format fields
  *date = FAT_DATE(now.year(), now.month(), now.day());

  // return time using FAT_TIME macro to format fields
  *time = FAT_TIME(now.hour(), now.minute(), now.second());
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void TochStop (byte pause, boolean pauseNo) {
  boolean iz = 0;
  int ii = 0;
  if (myTouch.dataAvailable())
  {
    myTouch.read();
    x = myTouch.getX();
    y = myTouch.getY();
    if (x > 10 && x < 310 && y > 170 && y < 230) {
      playTone(3400);
      myGLCD.setColor(VGA_RED);
      myGLCD.setFont(BigRusFont);
      myGLCD.print("          ", 96, 188); // Затираем часы
      myGLCD.print("\x89""ay""\x9C""a", CENTER, 188); // Пауза
      ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
      OffHot ();
      OffNasos (1);
      delay (300);
      while (iz == 0)
      {
        if (myTouch.dataAvailable())
        {
          myTouch.read();
          x = myTouch.getX();
          y = myTouch.getY();
          if (x > 10 && x < 310 && y > 170 && y < 220) {
            playTone(3400);
            iz++  ;
            myGLCD.print("          ", CENTER, 188); // Затираем
            if (BeerStep != 24) {
              ii = (pause * 60) - ((pause * 60) - timeWorkPause);
              myGLCD.setColor(VGA_WHITE);
              DateTime now = rtc.now();
              DateTime future (now.unixtime() + ii);
              ho1 = future.hour();
              mi1 = future.minute();
              se1 = future.second();
              da1 = future.day();
            }
            /*else {
              ii = (pause * 60) - ((pause * 60) - timeWorkPause);
              myGLCD.setColor(VGA_WHITE);
              DateTime now = rtc.now();
              DateTime future (now.unixtime() + ii);
              ho1 = future.hour();
              mi1 = future.minute();
              se1 = future.second();
              da1 = future.day();
              if (timeB2 != 0) {
                if (timeB2 > (pause * 60) - timeWorkPause) {
                  int B2 = (timeB2 * 60) - ((pause * 60) - timeWorkPause);
                  DateTime now = rtc.now();
                  DateTime future (now.unixtime() + B2);
                  hoB2 = future.hour();
                  miB2 = future.minute();
                  seB2 = future.second();
                  daB2 = future.day();
                }
              }
              if (timeB3 != 0) {
                if (timeB3 > (pause * 60) - timeWorkPause) {
                  int B3 = (timeB3 * 60) - ((pause * 60) - timeWorkPause);
                  DateTime now = rtc.now();
                  DateTime future (now.unixtime() + B3);
                  hoB3 = future.hour();
                  miB3 = future.minute();
                  seB3 = future.second();
                  daB3 = future.day();
                }
              }
              if (timeB4 != 0) {
                if (timeB4 > (pause * 60) - timeWorkPause) {
                  int B4 = (timeB4 * 60) - ((pause * 60) - timeWorkPause);
                  DateTime now = rtc.now();
                  DateTime future (now.unixtime() + B4);
                  hoB4 = future.hour();
                  miB4 = future.minute();
                  seB4 = future.second();
                  daB4 = future.day();
                }
              }
              if (timeB5 != 0) {
                if (timeB5 > (pause * 60) - timeWorkPause) {
                  int B5 = (timeB5 * 60) - ((pause * 60) - timeWorkPause);
                  DateTime now = rtc.now();
                  DateTime future (now.unixtime() + B5);
                  hoB5 = future.hour();
                  miB5 = future.minute();
                  seB5 = future.second();
                  daB5 = future.day();
                }
              }
              if (timeB6 != 0) {
                if (timeB6 > (pause * 60) - timeWorkPause) {
                  int B6 = (timeB6 * 60) - ((pause * 60) - timeWorkPause);
                  DateTime now = rtc.now();
                  DateTime future (now.unixtime() + B6);
                  hoB6 = future.hour();
                  miB6 = future.minute();
                  seB6 = future.second();
                  daB6 = future.day();
                }
              }
              }*/
          }
        }
      }
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
void Return () {
  playTone(2800);
  if (statusDoubleTap == 1 && BeerStep > 9) DoubleTap = 1;
  if (  BeerStep < 5) {
    ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
    OffNasos (0);
    BeerStep = 0;
    scale = 0;
    DoubleTap = 0;
    statusMainMenu = 1;
  }
  else {
    statusMainMenu = 2;
    ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
    OffNasos (0);
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void MainMenu (byte pause) {

  if ( statusMainMenu == 1) {//Выход в главное меню
    Save_sys ();
    statusMainMenu = 0;
    Screen0 ();
  }
  if (statusMainMenu == 2) {//Выход из варки в меню настроек
    pause = pauseBeerScreen1;
    statusMainMenu = 3;
    if (DoubleTap == 1) {
      BeerStep = 0;
      SubBeerStep = 0;
      DoubleTap = 0;
      Save_sys ();
      statusMainMenu = 0;
      statusDoubleTap = 0;
      // Очищаем Backup
      for (byte i = 199; i < 245; i++) {
        EEPROM.write(i,  0); //Записываем новые значения в память
      }
      Screen0 ();
    }
    else {
      Screen1 ();
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void PauseBeerScreen1 () {
  int Pauseii;
  if (BeerStep != 24 && BeerStep > 14 ) {
    Pauseii = (pauseBeerScreen1 * 60) - ((pauseBeerScreen1 * 60) - timeWorkPause);
    myGLCD.setColor(VGA_WHITE);
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + Pauseii);
    ho1 = future.hour();
    mi1 = future.minute();
    se1 = future.second();
    da1 = future.day();
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void ReturnBackup () {
  statusBeer = EEPROM.read(220);
  if (statusBeer == 1) {
    myGLCD.fillScr(VGA_BLACK);
    //myGLCD.fillRoundRect(40, 20, 280, 56);
    myGLCD.setColor(139, 69, 19);
    myGLCD.fillRoundRect(40, 70, 280, 130);
    myGLCD.fillRoundRect(40, 140, 280, 200);
    myGLCD.setFont(BigRusFont);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.print("Bap""\x9F""a ""\xA2""e ""\x9C""a""\x97""ep""\xA8""e""\xA2""a!", CENTER, 10);//Варка не завершена!
    myGLCD.print("\x89""po""\x99""o""\xA0""\x9B""\x9D""\xA4""\xAC""?", CENTER, 40);//Продолжить
    myGLCD.setBackColor(139, 69, 19);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.print("\x82""A", CENTER, 162);//Продолжить
    myGLCD.print("HET", CENTER, 92);//Добавить паузу
    myGLCD.setBackColor(VGA_BLACK);
    while (true)
    {

      if (myTouch.dataAvailable())
      {
        myTouch.read();
        x = myTouch.getX();
        y = myTouch.getY();
        if (x > 40 && x < 280) {
          if (y > 70 && y < 130) {
            waitForItButton(40, 70, 280, 130);
            statusBeer = 0;
            BeerStep = 0;
            SubBeerStep = 0;
            DoubleTap = 0;
            statusMainMenu = 0;
            statusDoubleTap = 0;
            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            // Очищаем Backup
            for (byte i = 199; i < 245; i++) {
              EEPROM.write(i,  0); //Записываем новые значения в память
            }
            Screen0 ();
          }
          if (y > 140 && y < 200) {
            waitForItButton(40, 140, 280, 200);
            ReadBackup ();
            if ( BeerStep == 1) Screen4 ();
            if ( BeerStep == 2)Screen4_1 ();
            if ( BeerStep == 3)Screen4_2 ();
            Beer ();
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void playTone(int note) {
  long elapsed_time = 0;
  while (elapsed_time < note_len) {
    digitalWrite(Bib, HIGH);
    delayMicroseconds(note / 2);
    digitalWrite(Bib, LOW);
    delayMicroseconds(note / 2);
    elapsed_time += (note);
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void ToneToch () {
  const int threshold = 10;    // minimum reading of the sensors that generates a note

  // notes to play, corresponding to the 3 sensors:
  int notes[] = {
    NOTE_A4, NOTE_B4, NOTE_C3
  };
  for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
    // get a sensor reading:
    int sensorReading = analogRead(thisSensor);

    // if the sensor is pressed hard enough:
    if (sensorReading > threshold) {
      // play the note corresponding to this sensor:
      tone(Bib, notes[thisSensor], 20);
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
