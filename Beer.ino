void Beer () {
  byte Dpause = 0;
  byte DtempC = 0;
  myGLCD.fillScr(VGA_BLACK);
  //-------------------------------расчет и отрисовка прогресс бара-----------------------------
  int alltime = 0;
  if  (termB2 != 0 && pauseB1 != 0) alltime = alltime + pauseB1;
  if  (termB3 != 0 && pauseB2 != 0) alltime = alltime + pauseB2;
  if  (termB4 > 0 && pauseB3 > 0) alltime = alltime + pauseB3;
  if  (termB5 > 0 && pauseB4 > 0) alltime = alltime + pauseB4;
  if  (termB6 > 0 && pauseB5 > 0) alltime = alltime + pauseB5;
  if  (termB7 > 0 && pauseB6 > 0) alltime = alltime + pauseB6;
  if  (timeB1 > 0 )alltime = alltime + timeB1;
  kof = 300 / alltime;
  myGLCD.setColor(VGA_GRAY);
  int summTime = 0;
  myGLCD.drawRect (10, 222, 310, 233);
  if  (termB2 != 0 && pauseB1 != 0) {
    summTime = summTime + (kof * pauseB1);
    myGLCD.drawRect (summTime, 222, summTime, 233);
  }
  if  (termB3 != 0 && pauseB2 != 0) {
    summTime = summTime + (kof * pauseB2);
    myGLCD.drawRect (summTime, 222, summTime, 233);
  }
  if  (termB4 > 0 && pauseB3 > 0) {
    summTime = summTime + (kof * pauseB3);
    myGLCD.drawRect (summTime, 222, summTime, 233);
  }
  if  (termB5 > 0 && pauseB4 > 0) {
    summTime = summTime + (kof * pauseB4);
    myGLCD.drawRect (summTime, 222, summTime, 233);
  }
  if  (termB6 > 0 && pauseB5 > 0) {
    summTime = summTime + (kof * pauseB5);
    myGLCD.drawRect (summTime, 222, summTime, 233);
  }
  if  (termB7 > 0 && pauseB6 > 0) {
    summTime = summTime + (kof * pauseB6);
    myGLCD.drawRect (summTime, 222, summTime, 233);
  }
  //-------------------------------навигация по этапам варки-----------------------------
  myGLCD.setColor(VGA_GREEN);
  myGLCD.fillRoundRect(10, 5, 310, 55);//Пропустить
  myGLCD.setFont(BigRusFont);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.drawRoundRect(10, 5, 310, 55);//Окантовка
  myGLCD.setBackColor(VGA_GREEN);
  myGLCD.print("\x89""PO""\x89""\x8A""CT""\x86""T""\x92", CENTER, 22);
  myGLCD.setFont(SmallRusFont);
  if  (termB3 != 0 && pauseB2 != 0) {//если пауза есть то зеленая кнопка иначе серая
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillRoundRect(10, 80, 60, 130);//Пауза№2
    myGLCD.setBackColor(VGA_GREEN);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 80, 60, 130);//Окантовка
    myGLCD.print("\x89""ay""\x9C""a2", 12, 101);
  }
  else {
    myGLCD.setColor(VGA_GRAY);
    myGLCD.fillRoundRect(10, 80, 60, 130);//Пауза№2
    myGLCD.setBackColor(VGA_GRAY);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.print("\x89""ay""\x9C""a2", 12, 101);
  }

  if  (termB4 != 0 && pauseB3 != 0) {//если пауза есть то зеленая кнопка иначе серая
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillRoundRect(70, 80, 120, 130);//Пауза№3
    myGLCD.setBackColor(VGA_GREEN);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(70, 80, 120, 130);//Окантовка
    myGLCD.print("\x89""ay""\x9C""a3", 72, 101);
  }
  else {
    myGLCD.setColor(VGA_GRAY);
    myGLCD.fillRoundRect(70, 80, 120, 130);//Пауза№3
    myGLCD.setBackColor(VGA_GRAY);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.print("\x89""ay""\x9C""a3", 72, 101);
  }
  if  (termB5 != 0 && pauseB4 != 0) {//если пауза есть то зеленая кнопка иначе серая
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillRoundRect(130, 80, 180, 130);//Пауза№4
    myGLCD.setBackColor(VGA_GREEN);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(130, 80, 180, 130);//Окантовка
    myGLCD.print("\x89""ay""\x9C""a4", 132, 101);
  }
  else {
    myGLCD.setColor(VGA_GRAY);
    myGLCD.fillRoundRect(130, 80, 180, 130);//Пауза№4
    myGLCD.setBackColor(VGA_GRAY);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.print("\x89""ay""\x9C""a4", 132, 101);
  }
  if  (termB6 != 0 && pauseB5 != 0) {//если пауза есть то зеленая кнопка иначе серая
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillRoundRect(190, 80, 240, 130);//Пауза№5
    myGLCD.setBackColor(VGA_GREEN);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(190, 80, 240, 130);//Окантовка
    myGLCD.print("\x89""ay""\x9C""a5", 192, 101);
  }
  else {
    myGLCD.setColor(VGA_GRAY);
    myGLCD.fillRoundRect(190, 80, 240, 130);//Пауза№5
    myGLCD.setBackColor(VGA_GRAY);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.print("\x89""ay""\x9C""a5", 192, 101);
  }
  if  (termB7 != 0 && pauseB6 != 0) {//если пауза есть то зеленая кнопка иначе серая
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillRoundRect(250, 80, 310, 130);//Мешаут
    myGLCD.setBackColor(VGA_GREEN);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(250, 80, 310, 130);//Окантовка
    myGLCD.print("Me""\xA8""ay""\xA4", 258, 101);
  }
  else {
    myGLCD.setColor(VGA_GRAY);
    myGLCD.fillRoundRect(250, 80, 310, 130);//Мешаут
    myGLCD.setBackColor(VGA_GRAY);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.print("Me""\xA8""ay""\xA4", 258, 101);
  }
  myGLCD.setColor(VGA_GREEN);
  myGLCD.fillRoundRect(10, 150, 150, 200);//Йодная пауза
  myGLCD.setBackColor(VGA_GREEN);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.drawRoundRect(10, 150, 150, 200);//Окантовка
  myGLCD.print("\x87""o""\x99""\xA2""a""\xAF"" ""\xA3""po""\x96""a", 32, 171);

  if  (timeB1 != 0) {//если пауза есть то зеленая кнопка иначе серая
    myGLCD.setColor(VGA_GREEN);
    myGLCD.fillRoundRect(170, 150, 310, 200);//Кипячение
    myGLCD.setBackColor(VGA_GREEN);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(170, 150, 310, 200);//Окантовка
    myGLCD.print("K""\x9D""\xA3""\xAF""\xA7""e""\xA2""\x9D""e", 208, 171);
  }
  else {
    myGLCD.setColor(VGA_GRAY);
    myGLCD.fillRoundRect(170, 150, 310, 200);//Кипячение
    myGLCD.setBackColor(VGA_GRAY);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.print("K""\x9D""\xA3""\xAF""\xA7""e""\xA2""\x9D""e", 208, 171);
  }
  byte iz = 0;
  int ik = 0;
  while ( iz == 0)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 10 && x < 310 && y > 5 && y < 50) {
        waitForItButton1(10, 5, 310, 55);
        delay(200);
        Touch ();
        if (x > 10 && x < 310 && y > 5 && y < 50) {
          iz++  ;
        }
        else {
          myGLCD.setColor(VGA_WHITE);
          myGLCD.drawRoundRect(10, 5, 310, 55);//Окантовка
        }
      }
      if (y > 80 && y < 130) {
        if (x > 10 && x < 60 && termB3 != 0 && pauseB2 != 0) {
          waitForItButton1(10, 80, 60, 130);
          delay(200);
          Touch ();
          if (x > 10 && x < 60 && y > 80 && y < 130) {
            ProgressBerr (pauseB1);
            goto lablePause2;
          }
          else {
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(10, 80, 60, 130);//Окантовка
          }
        }
        if (x > 70 && x < 120 && termB4 != 0 && pauseB3 != 0) {
          waitForItButton1(70, 80, 120, 130);
          delay(200);
          Touch ();
          if (x > 70 && x < 120 && y > 80 && y < 130) {
            ProgressBerr (pauseB1 + pauseB2);
            goto lablePause3;
          }
          else {
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(70, 80, 120, 130);//Окантовка
          }
        }
        if (x > 130 && x < 180 && termB5 != 0 && pauseB4 != 0) {
          waitForItButton1(130, 80, 180, 130);
          delay(200);
          Touch ();
          if (x > 130 && x < 180 && y > 80 && y < 130) {
            ProgressBerr (pauseB1 + pauseB2 + pauseB3);
            goto lablePause4;
          }
          else {
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(130, 80, 180, 130);//Окантовка
          }
        }
        if (x > 190 && x < 240 && termB6 != 0 && pauseB5 != 0) {
          waitForItButton1(190, 80, 240, 130);
          delay(200);
          Touch ();
          if (x > 190 && x < 240 && y > 80 && y < 130) {
            ProgressBerr (pauseB1 + pauseB2 + pauseB3 + pauseB4);
            goto lablePause5;
          }
          else {
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(190, 80, 240, 130);//Окантовка
          }
        }
        if (x > 250 && x < 310 && termB7 != 0 && pauseB6 != 0) {
          waitForItButton1(250, 80, 310, 130);
          delay(200);
          Touch ();
          if (x > 250 && x < 310 && y > 80 && y < 130) {
            ProgressBerr (pauseB1 + pauseB2 + pauseB3 + pauseB4 + pauseB5);
            goto lableMashOut;
          }
          else {
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(250, 80, 310, 130);//Окантовка
          }
        }
      }
      if (y > 150 && y < 200) {
        if (x > 10 && x < 150) {
          waitForItButton1(10, 150, 150, 200);
          delay(200);
          Touch ();
          if (x > 10 && x < 150 && y > 150 && y < 200) {
            ProgressBerr (pauseB1 + pauseB2 + pauseB3 + pauseB4 + pauseB5 + pauseB6);
            goto lableIodnayProba;
          }
          else {
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(10, 150, 150, 200);//Окантовка
          }
        }
        if (x > 170 && x < 310 && timeB1 != 0) {
          waitForItButton1(170, 150, 310, 200);
          delay(200);
          Touch ();
          if (x > 170 && x < 310 && y > 150 && y < 200) {
            ProgressBerr (pauseB1 + pauseB2 + pauseB3 + pauseB4 + pauseB5 + pauseB6);
            goto lableKipychenie;
          }
          else {
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(170, 150, 310, 200);//Окантовка
          }
        }
      }
    }
  }
  // 1 шаг __________________________________________________________________
  BeerStep = 1;
  iz = 0;
  BlackScr ();
  myGLCD.setFont(BigRusFont);
  myGLCD.setColor(VGA_BLUE);
  myGLCD.fillRoundRect(50, 80, 270, 156);
  myGLCD.setBackColor(VGA_BLUE);
  myGLCD.setColor(VGA_LIME);
  myGLCD.print("\x85""a""\xA0""e""\x9E""\xA4""e"" ""\x97""o""\x99""y", 64, 110);//Залейте воду

  while ( iz == 0)
  {
    ScreenTime (96, 196, 2, 9, 1);
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 50 && x < 270 && y > 90 && y < 166) iz++  ;
    }
  }

  //************************************ Продуть насос *******************************
  BeerStep = 2;
  if (rep > 0 && airW > 0 && airP > 0) {
    BlackScr ();
    myGLCD.setFont(BigRusFont);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(50, 80, 270, 156);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.setColor(VGA_BLACK);
    myGLCD.print("\x89""po""\x99""y""\x97""\x9F""a", CENTER, 90);//Продувка
    myGLCD.print("\xA2""acoca", CENTER, 122);//насоса
    iz = 0;
    while ( iteration == 0)    {
      ScreenTime (96, 196, 2, 9, 1);
      TimeWorkNasosAir ();
      if (fR == 1 && fT == 1)iz++;

      if (iz == rep) {//кол-во повторов
        OffNasos (0);
        fT = 1;
        iteration ++;
      }
    }
  }
  iteration = 0;
  //************************************ Нагерть воду*******************************
  BeerStep = 3;
  if (termB1 != 0) {//
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("Ha""\x98""pe""\x9E""\xA4""e"" ""\x97""o""\x99""y"" ""\x99""o", 7, 160); //Нагрейте воду до
    myGLCD.printNumI(termB1, 136, 160);
    int i;
    if (termB1 < 10) i = 0;
    if (termB1 > 9 && termB1 < 100) i = 8;
    if (termB1 > 99)  i = 16;
    myGLCD.print("\x7F""C", 144 + i, 160);
    myGLCD.print(", ", 160 + i, 160);
    myGLCD.print("\x9C""ac""\xAB""\xA3""\xA4""e"" ""co""\xA0""o""\x99"".", 176 + i, 160); //засыпьте солод
    myGLCD.setFont(BigRusFont);
    for (byte i = 0; i < 3; i++) {
      myGLCD.drawRoundRect(0 + i, 0 + i, 320 - i, 240 - i);
    }
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();

    while ( termB1 >= TempC) {
      OnNasos (1);
      PIctl(TempC, termB1);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myGLCD.setFont(SevenSegNumFont);
      myGLCD.setColor(VGA_RED);
      myGLCD.printNumI(termB1, 15, 81);
      printTemperature();
    }
  }
  OffNasos (1);
  OffHot ();
  FMelodi (MelodiN[0]);

  // **************************************Засыпка солода************************************
  BeerStep = 4;
  BlackScr ();
  if (termB1 == 0 ) termB1 = TempC;
  myGLCD.setFont(BigRusFont);
  myGLCD.setColor(VGA_YELLOW);
  myGLCD.fillRoundRect(40, 80, 280, 156);
  myGLCD.setBackColor(VGA_YELLOW);
  myGLCD.setColor(VGA_RED);
  myGLCD.print("\x85""ac""\xAB""\xA3""\xAC""\xA4""e"" ""co""\xA0""o""\x99", CENTER, 110);//Засыпьте солод
  iz = 0;
  while ( iz == 0)
  {
    printTemperatureNoScr();
    PIctl(TempC, termB1);
    ten.lpwm(t_pwm, out);//медленный ШИМ на тен
    ScreenTime (96, 196, 2, 9, 1);
    TochStop (0, 0);
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 50 && x < 270 && y > 90 && y < 166) iz++  ;
    }
  }
  //**************************************Пауза №1************************************
  BeerStep = 5;
  if  (termB2 != 0 && pauseB1 != 0) {
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, 160); //выдержать при
    myGLCD.printNumI(termB2, 119, 160);
    int i;
    if (termB2 < 10) i = 0;
    if (termB2 > 9 && termB2 < 100) i = 8;
    if (termB2 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, 160);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, 160); //в течении
    int q;
    if (pauseB1 < 10) q = 0;
    if (pauseB1 > 9 && pauseB1 < 100) q = 8;
    if (pauseB1 > 99)  q = 16;
    myGLCD.printNumI(pauseB1, 231 + i, 160);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, 160); //минут
    myGLCD.setFont(BigRusFont);
    for (byte i = 0; i < 3; i++) {
      myGLCD.drawRoundRect(0 + 1, 0 + 1, 320 - i, 240 - i);
    }
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(termB2, 15, 81);
    while (termB2 >= TempC)//
    {
      OnNasos (1);
      PIctl(TempC, termB2);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myGLCD.setFont(SevenSegNumFont);
      printTemperature();
    }
    OffNasos (1);
    int ii = pauseB1 * 60;
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    ho1 = future.hour();
    mi1 = future.minute();
    se1 = future.second();
    da1 = future.day();
    myGLCD.setColor(VGA_RED);
    myGLCD.setFont(BigRusFont);
    myGLCD.printNumI(pauseB1, 231, 25);
    myGLCD.printNumI(pauseB1, 37, 25);
    ik = 0;
    fT = 1;
    fR = 1;
    while (ik < pauseB1) //
    {
      TimeWorkNasos (WorkN[BeerN[1]] , PauseN[BeerN[1]], 1 ) ; //Функция считает время работы и простоя насоса (работа,простой)
      PIctl(TempC, termB2);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      TochStop (pauseB1, 1);
      ik = OutTime (pauseB1, termB2);


    }
    fT = 1;
    OffNasos (1);
    ProgressBerr (pauseB1);
    FMelodi (MelodiN[1]);
  }
  //**************************************Пауза №2************************************
  BeerStep = 6;
lablePause2:
  if  (termB3 != 0 && pauseB2 != 0) {
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, 160); //выдержать при
    myGLCD.printNumI(termB3, 119, 160);
    int i;
    if (termB3 < 10) i = 0;
    if (termB3 > 9 && termB3 < 100) i = 8;
    if (termB3 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, 160);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, 160); //в течении
    int q;
    if (pauseB2 < 10) q = 0;
    if (pauseB2 > 9 && pauseB2 < 100) q = 8;
    if (pauseB2 > 99)  q = 16;
    myGLCD.printNumI(pauseB2, 231 + i, 160);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, 160); //минут
    myGLCD.setFont(BigRusFont);
    for (byte i = 0; i < 3; i++) {
      myGLCD.drawRoundRect(0 + 1, 0 + 1, 320 - i, 240 - i);
    }
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(termB3, 15, 81);
    while (termB3 >= TempC)//
    {
      OnNasos (1);
      PIctl(TempC, termB3);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myGLCD.setFont(SevenSegNumFont);
      printTemperature();
    }
    OffNasos (1);
    int ii = pauseB2 * 60;
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    ho1 = future.hour();
    mi1 = future.minute();
    se1 = future.second();
    da1 = future.day();
    myGLCD.setColor(VGA_RED);
    myGLCD.setFont(BigRusFont);
    myGLCD.printNumI(pauseB2, 231, 25);
    myGLCD.printNumI(pauseB2, 37, 25);
    ik = 0;
    while (ik < pauseB2) //
    {
      TochStop (pauseB2, 1);
      TimeWorkNasos (WorkN[BeerN[2]] , PauseN[BeerN[2]], 1 ) ; //Функция считает время работы и простоя насоса (работа,простой)
      PIctl(TempC, termB3);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ik = OutTime (pauseB2, termB3);


    }
    fT = 1;
    OffNasos (1);
    ProgressBerr (pauseB2);
    FMelodi (MelodiN[2]);
  }
  //**************************************Пауза №3************************************
lablePause3:
  BeerStep = 7;
  if  (termB4 != 0 && pauseB3 != 0) {
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, 160); //выдержать при
    myGLCD.printNumI(termB4, 119, 160);
    int i;
    if (termB4 < 10) i = 0;
    if (termB4 > 9 && termB4 < 100) i = 8;
    if (termB4 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, 160);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, 160); //в течении
    int q;
    if (pauseB3 < 10) q = 0;
    if (pauseB3 > 9 && pauseB3 < 100) q = 8;
    if (pauseB3 > 99)  q = 16;
    myGLCD.printNumI(pauseB3, 231 + i, 160);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, 160); //минут
    myGLCD.setFont(BigRusFont);
    for (byte i = 0; i < 3; i++) {
      myGLCD.drawRoundRect(0 + i, 0 + i, 320 - i, 240 - i);
    }
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(termB4, 15, 81);
    while (termB4 >= TempC)//
    {
      OnNasos (1);
      PIctl(TempC, termB4);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myGLCD.setFont(SevenSegNumFont);
      printTemperature();
    }
    OffNasos (1);
    int ii = pauseB3 * 60;
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    ho1 = future.hour();
    mi1 = future.minute();
    se1 = future.second();
    da1 = future.day();
    myGLCD.setColor(VGA_RED);
    myGLCD.setFont(BigRusFont);
    myGLCD.printNumI(pauseB3, 231, 25);
    myGLCD.printNumI(pauseB3, 37, 25);
    ik = 0;
    while (ik < pauseB3) //
    {
      TochStop (pauseB3, 1);
      TimeWorkNasos (WorkN[BeerN[3]] , PauseN[BeerN[3]], 1 ) ; //Функция считает время работы и простоя насоса (работа,простой)
      PIctl(TempC, termB4);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ik = OutTime (pauseB3, termB4);


    }
    fT = 1;
    OffNasos (1);
    ProgressBerr (pauseB3);
    FMelodi (MelodiN[3]);
  }
  //**************************************Пауза №4************************************
lablePause4:
  BeerStep = 8;
  if  (termB5 != 0 && pauseB4 != 0) {
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, 160); //выдержать при
    myGLCD.printNumI(termB5, 119, 160);
    int i;
    if (termB5 < 10) i = 0;
    if (termB5 > 9 && termB5 < 100) i = 8;
    if (termB5 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, 160);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, 160); //в течении
    int q;
    if (pauseB4 < 10) q = 0;
    if (pauseB4 > 9 && pauseB4 < 100) q = 8;
    if (pauseB4 > 99)  q = 16;
    myGLCD.printNumI(pauseB4, 231 + i, 160);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, 160); //минут
    myGLCD.setFont(BigRusFont);
    for (byte i = 0; i < 3; i++) {
      myGLCD.drawRoundRect(0 + 1, 0 + 1, 320 - i, 240 - i);
    }
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(termB5, 15, 81);
    while (termB5 >= TempC)//
    {
      OnNasos (1);
      PIctl(TempC, termB5);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myGLCD.setFont(SevenSegNumFont);
      printTemperature();
    }
    OffNasos (1);
    int ii = pauseB4 * 60;
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    ho1 = future.hour();
    mi1 = future.minute();
    se1 = future.second();
    da1 = future.day();
    myGLCD.setColor(VGA_RED);
    myGLCD.setFont(BigRusFont);
    myGLCD.printNumI(pauseB4, 231, 25);
    myGLCD.printNumI(pauseB4, 37, 25);
    ik = 0;
    while (ik < pauseB4) //
    {
      TochStop (pauseB4, 1);
      TimeWorkNasos (WorkN[BeerN[4]] , PauseN[BeerN[4]], 1 ) ; //Функция считает время работы и простоя насоса (работа,простой)
      PIctl(TempC, termB5);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ik = OutTime (pauseB4, termB5);


    }
    fT = 1;
    OffNasos (1);
    ProgressBerr (pauseB4);
    FMelodi (MelodiN[4]);
  }
  //**************************************Пауза №5************************************
lablePause5:
  BeerStep = 9;
  if  (termB6 != 0 && pauseB5 != 0) {
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, 160); //выдержать при
    myGLCD.printNumI(termB6, 119, 160);
    int i;
    if (termB6 < 10) i = 0;
    if (termB6 > 9 && termB6 < 100) i = 8;
    if (termB6 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, 160);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, 160); //в течении
    int q;
    if (pauseB5 < 10) q = 0;
    if (pauseB5 > 9 && pauseB5 < 100) q = 8;
    if (pauseB5 > 99)  q = 16;
    myGLCD.printNumI(pauseB5, 231 + i, 160);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, 160); //минут
    myGLCD.setFont(BigRusFont);
    for (byte i = 0; i < 3; i++) {
      myGLCD.drawRoundRect(0 + 1, 0 + 1, 320 - i, 240 - i);
    }
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(termB6, 15, 81);
    while (termB6 >= TempC)//
    {
      OnNasos (1);
      PIctl(TempC, termB6);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myGLCD.setFont(SevenSegNumFont);
      printTemperature();
    }
    OffNasos (1);
    int ii = pauseB5 * 60;
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    ho1 = future.hour();
    mi1 = future.minute();
    se1 = future.second();
    da1 = future.day();
    myGLCD.setColor(VGA_RED);
    myGLCD.setFont(BigRusFont);
    myGLCD.printNumI(pauseB5, 231, 25);
    myGLCD.printNumI(pauseB5, 37, 25);
    ik = 0;
    while (ik < pauseB5) //
    {
      TochStop (pauseB5, 1);
      TimeWorkNasos (WorkN[BeerN[5]] , PauseN[BeerN[5]], 1 ) ; //Функция считает время работы и простоя насоса (работа,простой)
      PIctl(TempC, termB6);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ik = OutTime (pauseB5, termB6);


    }
    fT = 1;
    OffNasos (1);
    ProgressBerr (pauseB5);
    FMelodi (MelodiN[5]);
  }
  //  **************************************Йодная проба************************************
lableIodnayProba:
  BeerStep = 11;

  //labelIod:
  BlackScr ();
  myGLCD.setFont(BigRusFont);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRoundRect(40, 20, 280, 56);
  myGLCD.setColor(139, 69, 19);
  myGLCD.fillRoundRect(40, 70, 280, 130);
  myGLCD.fillRoundRect(40, 140, 280, 200);
  myGLCD.print("\x87""o""\x99""\xA2""a""\xAF"" ""\xA3""po""\x96""a", CENTER, 30);//Йодная проба
  myGLCD.setBackColor(139, 69, 19);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.print("\x89""po""\x99""o""\xA0""\x9B""\x9D""\xA4""\xAC", CENTER, 162);//Продолжить
  myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""\xA3""ay""\x9C""y", CENTER, 92);//Добавить паузу
  myGLCD.setBackColor(VGA_BLACK);
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 40 && x < 280 && y > 140 && y < 200) goto labelFiltr;
      if (x > 300 && x < 320 && y > 0 && y < 10) {
        myGLCD.print("\x82""e""\xA1""e""\xA2""\xA4""\xAC""e""\x97"" ""H""\x9D""\x9F""o""\xA0""a""\x9E", CENTER, 204);
      }
      if (x > 40 && x < 280 && y > 70 && y < 130) {
        BlackScr ();
        myGLCD.drawBitmap(48, 35, 64, 30, LeftButton1, 1);
        myGLCD.drawBitmap(208, 35, 64, 30, RightButton1, 1);
        myGLCD.drawBitmap(48, 115, 64, 30, LeftButton1, 1);
        myGLCD.drawBitmap(208, 115, 64, 30, RightButton1, 1);
        myGLCD.setColor(VGA_RED);
        myGLCD.printNumI(Dpause, CENTER, 42);//Пауза
        myGLCD.printNumI(DtempC, CENTER, 122);//Температура
        myGLCD.setColor(VGA_LIME);
        myGLCD.print("\x89""ay""\x9C""a", CENTER, 10);//Пауза
        myGLCD.print("Te""\xA1""\xA3""epa""\xA4""ypa", CENTER, 90);//Температура
        myGLCD.setColor(VGA_YELLOW);
        myGLCD.setBackColor(VGA_YELLOW);
        myGLCD.fillRoundRect(40, 160, 280, 196);
        myGLCD.setColor(VGA_RED);
        myGLCD.print("CTAPT", CENTER, 170);//
        myGLCD.setBackColor(VGA_BLACK);
        while (true)
        {
          myGLCD.setBackColor(VGA_BLACK);
          myGLCD.setColor(VGA_LIME);
          byte i;
          printTemperatureNoScr();
          myGLCD.setFont(SmallRusFont);
          if (TempC > 99 ) i = 0;
          if (TempC < 99 && TempC > 9) i = 8;
          if (TempC < 9) i = 16;
          myGLCD.printNumI(TempC, 265 + i, 10);
          myGLCD.print("\x7F""C", 289, 10);
          myGLCD.setColor(VGA_RED);
          myGLCD.setFont(BigRusFont);
          if (myTouch.dataAvailable())
          {
            myTouch.read();
            x = myTouch.getX();
            y = myTouch.getY();
            if ( x > 40 && x < 280 && y > 160 && y < 196) goto labelD;
            if (y > 35 && y < 65) {
              if (x > 48 && x < 112) {
                Dpause--;
                if (Dpause > 240) Dpause = 240;
                myGLCD.print("   ", CENTER, 42);//Пауза
                myGLCD.printNumI(Dpause, CENTER, 42);//Пауза
                delay (100);

              }

              if (x > 208 && x < 272) {
                Dpause++;
                if (Dpause > 240) Dpause = 0;
                myGLCD.print("   ", CENTER, 42);//Пауза
                myGLCD.printNumI(Dpause, CENTER, 42);//Пауза
                delay (100);
              }
            }
            if (y > 115 && y < 145) {
              if (x > 48 && x < 112) {
                DtempC--;
                if (DtempC > 120) DtempC = 240;
                myGLCD.print("   ", CENTER, 122);//Пауза
                myGLCD.printNumI(DtempC, CENTER, 122);//Температура
                delay (100);

              }

              if (x > 208 && x < 272) {
                DtempC++;
                if (DtempC > 120) DtempC = 0;
                myGLCD.print("   ", CENTER, 122);//Пауза
                myGLCD.printNumI(DtempC, CENTER, 122);//Температура
                delay (100);
              }
            }
          }
        }
      }
    }
  }
labelD:
  if  (DtempC != 0 && Dpause != 0) {
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, 160); //выдержать при
    myGLCD.printNumI(DtempC, 119, 160);
    int i;
    if (DtempC < 10) i = 0;
    if (DtempC > 9 && DtempC < 100) i = 8;
    if (DtempC > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, 160);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, 160); //в течении
    int q;
    if (Dpause < 10) q = 0;
    if (Dpause > 9 && pauseB5 < 100) q = 8;
    if (Dpause > 99)  q = 16;
    myGLCD.printNumI(Dpause, 231 + i, 160);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, 160); //минут
    myGLCD.setFont(BigRusFont);
    for (byte i = 0; i < 3; i++) {
      myGLCD.drawRoundRect(0 + 1, 0 + 1, 320 - i, 240 - i);
    }
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(DtempC, 15, 81);
    while (DtempC >= TempC)//
    {
      OnNasos (1);
      PIctl(TempC, DtempC);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myGLCD.setFont(SevenSegNumFont);
      printTemperature();
    }
    OffNasos (1);
    int ii = Dpause * 60;
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    ho1 = future.hour();
    mi1 = future.minute();
    se1 = future.second();
    da1 = future.day();
    myGLCD.setColor(VGA_RED);
    myGLCD.setFont(BigRusFont);
    myGLCD.printNumI(Dpause, 231, 25);
    myGLCD.printNumI(Dpause, 37, 25);
    ik = 0;
    while (ik < Dpause) //
    {
      TochStop (Dpause, 1);
      TimeWorkNasos (WorkN[BeerN[1]] , PauseN[BeerN[1]], 1 ) ; //Функция считает время работы и простоя насоса (работа,простой)
      PIctl(TempC, DtempC);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ik = OutTime (Dpause, DtempC);
    }
    fT = 1;
    OffNasos (1);
    FMelodi (MelodiN[5]);
    OffHot ();
  }
  goto lableIodnayProba;
  //**************************************Мешаут************************************
lableMashOut:
  BeerStep = 10;
  if  (termB7 != 0 && pauseB6 != 0) {
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("Me""\xA8""ay""\xA4"" ""\xA3""p""\x9D", 7, 160); //мешаут при
    myGLCD.printNumI(termB7, 95, 160);
    int i;
    if (termB7 < 10) i = 0;
    if (termB7 > 9 && termB7 < 100) i = 8;
    if (termB7 > 99)  i = 16;
    myGLCD.print("\x7F""C", 103 + i, 160);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 127 + i, 160); //в течении
    int q;
    if (pauseB6 < 10) q = 0;
    if (pauseB6 > 9 && pauseB5 < 100) q = 8;
    if (pauseB6 > 99)  q = 16;
    myGLCD.printNumI(pauseB6, 207 + i, 160);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 223 + i + q, 160); //минут
    for (byte i = 0; i < 3; i++) {
      myGLCD.drawRoundRect(0 + 1, 0 + 1, 320 - i, 240 - i);
    }
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(termB7, 15, 81);
    while (termB7 >= TempC)//
    {
      OnNasos (1);
      PIctl(TempC, termB7);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myGLCD.setFont(SevenSegNumFont);
      printTemperature();
    }
    OffNasos (1);
    int ii = pauseB6 * 60;
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    ho1 = future.hour();
    mi1 = future.minute();
    se1 = future.second();
    da1 = future.day();
    myGLCD.setColor(VGA_RED);
    myGLCD.setFont(BigRusFont);
    myGLCD.printNumI(pauseB6, 231, 25);
    myGLCD.printNumI(pauseB6, 37, 25);
    ik = 0;
    while (ik < pauseB6) //
    {
      TochStop (pauseB6, 1);
      TimeWorkNasos (WorkN[BeerN[6]] , PauseN[BeerN[6]], 1 ) ; //Функция считает время работы и простоя насоса (работа,простой)
      PIctl(TempC, termB7);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ik = OutTime (pauseB6, termB7);


    }
    fT = 1;
    OffNasos (1);
    ProgressBerr (pauseB6);
    FMelodi (MelodiN[6]);
  }
  //  **************************************Фильтрация************************************
labelFiltr:
  BeerStep = 12;
  BlackScr ();
  ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
  if (out != 0 ) {
    OnHot ();
  }
  else OffHot ();
  delay(1000);
  myGLCD.setFont(BigRusFont);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRoundRect(40, 80, 280, 156);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setColor(VGA_RED);
  myGLCD.print("\x89""po""\xA1""o""\x9E""\xA4""e"" ""\x9C""a""\xA4""op", CENTER, 110);//Промойте затор
  iz = 0;
  while ( iz == 0)
  {
    if (myTouch.dataAvailable())
    {
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 50 && x < 270 && y > 80 && y < 156) iz++;
    }
  }
  //************************************ Продуть насос *******************************
  BeerStep = 13;
  if (rep > 0 && airW > 0 && airP > 0) {
    BlackScr ();
    myGLCD.setFont(BigRusFont);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(50, 80, 270, 156);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.setColor(VGA_BLACK);
    myGLCD.print("\x89""po""\x99""y""\x97""\x9F""a", CENTER, 90);//Продувка
    myGLCD.print("\xA2""acoca", CENTER, 122);//насоса
    iz = 0;
    while ( iteration == 0)    {
      ScreenTime (96, 196, 2, 9, 1);
      //TochStop ();
      TimeWorkNasosAir ();
      if (fR == 1 && fT == 1)iz++;

      if (iz == rep) {//кол-во повторов
        OffNasos (0);
        fT = 1;
        iteration ++;
      }
    }
  }
  iteration = 0;
  //**************************************Кипятить************************************
lableKipychenie:
  BeerStep = 14;
  if  (timeB1 != 0) {
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("K""\x9D""\xA3""\xAF""\xA4""\x9D""\xA4""\xAC"" ""\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" ", 7, 160); //кипятить в течении
    int q;
    if (timeB1 < 10) q = 0;
    if (timeB1 > 9 && timeB1 < 100) q = 8;
    if (timeB1 > 99)  q = 16;
    myGLCD.printNumI(timeB1, 160, 160);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 176 + q, 160); //минут
    for (byte i = 0; i < 3; i++) {
      myGLCD.drawRoundRect(0 + 1, 0 + 1, 320 - i, 240 - i);
    }
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(termKIP, 15, 81);
    while (termKIP > TempC)//
    {
      OnNasos (1);
      PIctl(TempC, termKIP);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
      if (out != 0 ) {
        OnHot ();
      }
      else OffHot ();
      ScreenTime (96, 196, 2, 9, 1);
      TochStop (0, 0);
      myGLCD.setFont(SevenSegNumFont);
      printTemperature();
    }
    OffNasos (1);
    OffHot ();
    melodiErr ();
    out = 70;
    ten.lpwm(t_pwm, out);//медленный ШИМ на тен

    myGLCD.setColor(VGA_BLACK);
    myGLCD.fillRoundRect(10, 76, 116, 136);
    myGLCD.fillRoundRect(204, 76, 310, 136);
    myGLCD.setColor (VGA_WHITE);
    myGLCD.drawBitmap(15, 85, 64, 30, LeftButton1, 1);
    myGLCD.drawBitmap(241, 85, 64, 30, RightButton1, 1);
    myGLCD.setFont(SevenSegNumFont);
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(out, 100, 75);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("Mo""\xA9""\xA2""oc""\xA4""\xAC"" % ", 100, 130);
    myGLCD.setColor(VGA_LIME);

    int ii = timeB1 * 60;
    DateTime now = rtc.now();
    DateTime future (now.unixtime() + ii);
    ho1 = future.hour();
    mi1 = future.minute();
    se1 = future.second();
    da1 = future.day();
    if (timeB2 != 0) {
      int B2 = timeB2 * 60;
      DateTime now = rtc.now();
      DateTime future (now.unixtime() + B2);
      hoB2 = future.hour();
      miB2 = future.minute();
      seB2 = future.second();
      daB2 = future.day();
    }
    if (timeB3 != 0) {
      int B3 = timeB3 * 60;
      DateTime now = rtc.now();
      DateTime future (now.unixtime() + B3);
      hoB3 = future.hour();
      miB3 = future.minute();
      seB3 = future.second();
      daB3 = future.day();
    }
    if (timeB4 != 0) {
      int B4 = timeB4 * 60;
      DateTime now = rtc.now();
      DateTime future (now.unixtime() + B4);
      hoB4 = future.hour();
      miB4 = future.minute();
      seB4 = future.second();
      daB4 = future.day();
    }
    if (timeB5 != 0) {
      int B5 = timeB5 * 60;
      DateTime now = rtc.now();
      DateTime future (now.unixtime() + B5);
      hoB5 = future.hour();
      miB5 = future.minute();
      seB5 = future.second();
      daB5 = future.day();
    }
    if (timeB6 != 0) {
      int B6 = timeB6 * 60;
      DateTime now = rtc.now();
      DateTime future (now.unixtime() + B6);
      hoB6 = future.hour();
      miB6 = future.minute();
      seB6 = future.second();
      daB6 = future.day();
    }
    myGLCD.setColor(VGA_RED);
    myGLCD.setFont(BigRusFont);
    myGLCD.printNumI(timeB1, 231, 25);
    myGLCD.printNumI(timeB1, 37, 25);
    ik = 0;
    BeerStep = 15;
    while (ik < timeB1) //
    {
      printTemperatureNoScr();
      myGLCD.setColor(VGA_LIME);
      myGLCD.setFont(SmallRusFont);
      myGLCD.printNumI(TempC, 140, 25);
      int i;
      if (TempC < 10) i = 0;
      if (TempC > 9 && TempC < 100) i = 8;
      if (TempC > 99)  i = 16;
      myGLCD.print("\x7F""C", 148 + i, 25);

      if (myTouch.dataAvailable())
      {
        myGLCD.setFont(BigRusFont);
        myTouch.read();
        x = myTouch.getX();
        y = myTouch.getY();
        if (x > 15 && x < 79 && y > 85 && y < 115) {
          out--;
          if (out > 100) out = 0;

        }
        if (x > 241 && x < 305 && y > 85 && y < 115) {
          out++;
          if (out > 100) out = 100;

        }
      }
      myGLCD.setColor(VGA_BLACK);
      if (out < 10)myGLCD.fillRoundRect(132, 75, 196, 125);
      if (out < 100)myGLCD.fillRoundRect(164, 75, 196, 125);
      myGLCD.setColor(VGA_RED);
      myGLCD.setFont(SevenSegNumFont);
      myGLCD.printNumI(out, 100, 75);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен

      if (timeB2 != 0) {
        DateTime now = rtc.now();
        ho = now.hour();
        mi = now.minute();
        se = now.second();
        da = now.day();
        if (ho ==  hoB2 && mi == miB2 && se == seB2 && da == daB2) {
          melodiErr ();
          //ProgressBerr (timeB2);
          myGLCD.setFont(SmallRusFont);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(7, 157, 310, 175);
          myGLCD.setColor (VGA_WHITE);
          myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC"" #1", CENTER, 160); //Добавить хмель (14)
          //myGLCD.printNumI(1, 227, 160); //
        }
      }
      if (timeB3 != 0) {
        DateTime now = rtc.now();
        ho = now.hour();
        mi = now.minute();
        se = now.second();
        da = now.day();
        if (ho ==  hoB3 && mi == miB3 && se == seB3 && da == daB3) {
          melodiErr ();
          //ProgressBerr (timeB3 - timeB2);
          myGLCD.setFont(SmallRusFont);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(7, 157, 310, 175);
          myGLCD.setColor (VGA_WHITE);
          myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC"" #2", CENTER, 160); //Добавить хмель (14)
          //myGLCD.printNumI(2, 227, 160); //
        }
      }
      if (timeB4 != 0) {
        DateTime now = rtc.now();
        ho = now.hour();
        mi = now.minute();
        se = now.second();
        da = now.day();
        if (ho ==  hoB4 && mi == miB4 && se == seB4 && da == daB4) {
          melodiErr ();
          //ProgressBerr (timeB4 - timeB3);
          myGLCD.setFont(SmallRusFont);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(7, 157, 310, 175);
          myGLCD.setColor (VGA_WHITE);
          myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC"" #3", CENTER, 160); //Добавить хмель (14)
          //myGLCD.printNumI(3, 227, 160); //
        }
      }
      if (timeB5 != 0) {
        DateTime now = rtc.now();
        ho = now.hour();
        mi = now.minute();
        se = now.second();
        da = now.day();
        if (ho ==  hoB5 && mi == miB5 && se == seB5 && da == daB5) {
          melodiErr ();
          //ProgressBerr (timeB5 - timeB4);
          myGLCD.setFont(SmallRusFont);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(7, 157, 310, 175);
          myGLCD.setColor (VGA_WHITE);
          myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC"" #4", CENTER, 160); //Добавить хмель (14)
          //myGLCD.printNumI(4, 227, 160); //
        }
      }
      if (timeB6 != 0) {
        DateTime now = rtc.now();
        ho = now.hour();
        mi = now.minute();
        se = now.second();
        da = now.day();
        if (ho ==  hoB6 && mi == miB6 && se == seB6 && da == daB6) {
          melodiErr ();
          //ProgressBerr (timeB6 - timeB5);
          myGLCD.setFont(SmallRusFont);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(7, 157, 310, 175);
          myGLCD.setColor (VGA_WHITE);
          myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC"" #5", CENTER, 160); //Добавить хмель (14)
          //myGLCD.printNumI(5, 227, 160); //
        }
      }
      //TochStop (timeB1, 1);
      ik = OutTimeNoScr (timeB1);


    }
    ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
    ProgressBerr (timeB1);
    //ProgressBerr (timeB1 - (timeB2 + (timeB3 - timeB2) + (timeB4 - timeB3) + (timeB5 - timeB4) + (timeB6 - timeB5)));
    melodiErr ();
  }
  //**************************************Вирпул************************************
  BeerStep = 16;
  if (chil != 0) {
    BlackScr ();
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawRoundRect(10, 20, 116, 46);
    myGLCD.drawRoundRect(204, 20, 310, 46);
    myGLCD.drawRoundRect(10, 76, 116, 136);
    myGLCD.drawRoundRect(204, 76, 310, 136);
    myGLCD.drawRect(7, 156, 310, 156);
    myGLCD.drawRect(7, 176, 310, 176);
    myGLCD.setFont(SmallRusFont);
    myGLCD.setColor(VGA_BLACK);
    myGLCD.fillRoundRect(7, 157, 310, 175);
    myGLCD.setColor (VGA_WHITE);
    myGLCD.print("Ox""\xA0""a""\x99""\x9D""\xA4""\xAC"" ""\x99""o", 97, 160);//Охладить
    myGLCD.printNumI(chil, 193, 160);
    int i;
    if (chil < 10) i = 0;
    if (chil > 9 && chil < 100) i = 8;
    if (chil > 99)  i = 16;
    myGLCD.print("\x7F""C", 201 + i, 160);
    myGLCD.setFont(SevenSegNumFont);
    printTemperature();
    myGLCD.setColor(VGA_RED);
    myGLCD.printNumI(chil, 15, 81);
    byte dd = 0;
    while (chil < TempC) {

      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();

      if (x > 135 && x < 185 && y > 20 && y < 70) {
        dd = !dd;
        delay (100);
      }

      if (dd == 1) {

        myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
        myGLCD.setFont(SmallRusFont);
        myGLCD.setColor(VGA_LIME);
        myGLCD.print("BK""\x88", 148, 41);

        OnNasos (0);
      }
      if (dd == 0) {

        myGLCD.drawBitmap(135, 20, 50, 50, nasos, 1);
        myGLCD.setFont(SmallRusFont);
        myGLCD.setColor(VGA_RED);
        myGLCD.print("B""\x91""K""\x88", 148, 41);

        fT = 1;
        OffNasos (0);
      }
      ScreenTime (96, 196, 2, 9, 1);
      myGLCD.setFont(SevenSegNumFont);
      printTemperature();
    }

  }
  //**************************************Конец************************************
  BlackScr ();
  BeerStep = 0;
  melodi ();
  scale = 0;
  summTime = 0;
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("HA""\x84""M""\x86""TE"", ""\x8D""TO""\x80""\x91"" ""\x89""PO""\x82""O""\x88""\x84""\x86""T""\x92", CENTER, 225);
  for ( byte i = 0; i < 55; i++) {
    myGLCD.drawBitmap(0 + i, 0 + i, 50, 50, beer, 1);
    myGLCD.drawBitmap(0 + i, 190 - i, 50, 50, beer, 1);
    myGLCD.drawBitmap(270 - i, 190 - i, 50, 50, beer, 1);
    myGLCD.drawBitmap(270 - i, 0 + i, 50, 50, beer, 1);
    if (myTouch.dataAvailable()) {
      Screen0 ();
    }
  }
  myGLCD.setFont(BigRusFont);
  myGLCD.setColor(VGA_LIME);
  myGLCD.print("BAPKA"" ""\x85""ABEP""\x8E""E""HA!!!", CENTER, 110);
  while (true) {

    if (myTouch.dataAvailable()) {
      Screen0 ();
    }
  }

}
