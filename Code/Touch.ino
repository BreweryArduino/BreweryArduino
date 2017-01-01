void waitForItButton(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRect (x1, y1, x2, y2);
  delay(200);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.drawRect (x1, y1, x2, y2);
}
//_________________________________________________________________________________________________
void waitForItButton1(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRect (x1, y1, x2, y2);
  /*while (myTouch.dataAvailable())
    myTouch.read();
    myGLCD.setColor(VGA_BLACK);
    myGLCD.drawRect (x1, y1, x2, y2);*/
}
//_________________________________________________________________________________________________
void SetTime(byte g) {// Обработка кнопок + - ок установки часов

  while (true)
  {
    timeselect ();
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (g == 1) {
        if (y > 156 && y < 196) {
          if (x > 30 && x < 70) {// "-"
            waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
            hoset --;
            if (hoset >= 25) hoset = 23;
            SetTimeClock (hoset, miset, seset);//Установка даты и времени часов
            ScreenTime (96, 100, 2, 9, 1);//Обновляем время
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(91, 95, 133, 121);
          }
          if (x > 250 && x < 290) {// "+"
            waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
            hoset ++;
            if (hoset >= 25) hoset = 0;
            SetTimeClock (hoset, miset, seset);//Установка даты и времени часов
            ScreenTime (96, 100, 2, 9, 1);//Обновляем время
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(91, 95, 133, 121);
          }
          if (x > 145 && x < 185) {// "ок"
            waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
            myGLCD.print(" ", 108, 117);
            ScreenSetTime ();
          }
        }
      }

      if (g == 2) {
        if (y > 156 && y < 196) {
          if (x > 30 && x < 70) {// "-"
            waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
            miset--;
            if (miset > 59) miset = 59;
            SetTimeClock (hoset, miset, seset);//Установка даты и времени часов
            ScreenTime (96, 100, 2, 9, 1);//Обновляем время
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(137, 95, 180, 121);
          }
          if (x > 250 && x < 290) {// "+"
            waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
            miset++;
            if (miset > 59) miset = 0;
            SetTimeClock (hoset, miset, seset);//Установка даты и времени часов
            ScreenTime (96, 100, 2, 9, 1);//Обновляем время
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(137, 95, 180, 121);
          }
          if (x > 145 && x < 185) {// "ок"
            waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
            myGLCD.print(" ", 160, 117);
            ScreenSetTime ();
          }
        }
      }

      if (g == 3) {
        if (y > 156 && y < 196) {
          if (x > 30 && x < 70) {// "-"
            waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
            seset--;
            if (seset > 59) seset = 59;
            SetTimeClock (hoset, miset, seset);//Установка даты и времени часов
            ScreenTime (96, 100, 2, 9, 1);//Обновляем время
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(185, 95, 229, 121);
          }
          if (x > 250 && x < 290) {// "+"
            waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
            seset++;
            if (seset > 59) seset = 0;
            SetTimeClock (hoset, miset, seset);//Установка даты и времени часов
            ScreenTime (96, 100, 2, 9, 1);//Обновляем время
            myGLCD.setColor(VGA_WHITE);
            myGLCD.drawRoundRect(185, 95, 229, 121);
          }
          if (x > 145 && x < 185) {// "ок"
            waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
            myGLCD.print(" ", 208, 117);
            SetTimeClock (hoset, miset, seset);//Установка даты и времени часов
            ScreenSetTime ();
          }
        }
      }
    }
  }
}
//_________________________________________________________________________________________________
void Touch0 () { // обработка тачскрина главного меню
  while (true)
  {
    /*myGLCD.setColor(VGA_RED);
      printTemperatureNoScr();
      myGLCD.setFont(SevenSegNumFont);
      if (TempC > 99 ) TempC = 99;
      myGLCD.printNumI(TempC, 128, 95);
    */
    ScreenTime (96, 39, 2, 9, 1);
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (y > 95 && y < 145) {
        if (x > 15 && x < 65) Screen1 ();
        if (x > 75 && x < 125) Screen2 ();
        //if (x > 135 && x < 185) Screen3 ();
        if (x > 195 && x < 245) Screen4 ();
        if (x > 255 && x < 305) Screen5 ();
      }
    }
  }
}
//_________________________________________________________________________________________________
void Touch1 () { // обработка тачскрина меню настроек
  while (true)
  {

    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (y > 95 && y < 145) {
        if (x > 15 && x < 65) ScreenSys ();
        if (x > 75 && x < 125) setHot ();
        if (x > 135 && x < 185) setNasos ();
        if (x > 195 && x < 245) setBeer ();
        if (x > 255 && x < 305) setSD ();
      }
      if (x > 32 && x < 96 && y > 20 && y < 50) {
        Save_sys ();
        Screen0 ();// возврат в главное меню
      }
    }
  }
}
//_________________________________________________________________________________________________
void Touch2 () { // обработка тачскрина меню тэна

  while (true)
  {
    myGLCD.setColor(VGA_LIME);
    myGLCD.setFont(BigRusFont);
    myGLCD.printNumI(TempC, 200, 80);
    byte p;
    if (TempC < 10) p = 16;
    if (TempC < 100) p = 32;
    if (TempC >= 100) p = 48;
    myGLCD.print("\x7F""C", 200 + p, 80);
    if (ON_OFF == 1) {
      printTemperatureNoScr();
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен
    }
    if (ON_OFF == 0) {
      ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
    }
    if (innverN == true) {
      TimeWorkNasos (nasosWH, nasosPH, 0);
      myGLCD.setFont(SmallRusFont);
      if (digitalRead(NasosPin) == ReleOn) {
        myGLCD.setColor(VGA_LIME);
        myGLCD.print("auto", 209, 45);
      }
      if (digitalRead(NasosPin) == ReleOff) {
        myGLCD.setColor(VGA_RED);

        myGLCD.print("auto", 209, 45);
      }
    }
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 32 && x < 96 && y > 20 && y < 50) {
        innverN = false;
        OffNasos (0);
        fT = 1;
        ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
        Screen0 ();// возврат в главное меню
      }

      if (x > 260 && x < 310 && y > 10 && y < 60) {
        fT = 1;
        fR = 1;
        innverN = false;
        OffNasos (0);
        setBeerN_1 (1);
      }
      if (x > 200 && x < 250 && y > 10 && y < 60) {
        innverN = !innverN;
        delay (100);


        if (innverN == true) {
          myGLCD.drawBitmap(200, 10, 50, 50, nasos, 1);
          myGLCD.setFont(SmallRusFont);
          myGLCD.setColor(VGA_RED);
          myGLCD.print("B""\x91""K""\x88", 209, 30);

        }
        if (innverN == false) {
          myGLCD.drawBitmap(200, 10, 50, 50, nasos, 1);
          myGLCD.setFont(SmallRusFont);

          myGLCD.setColor(VGA_LIME);
          myGLCD.print("BK""\x88", 213, 30);
          //}
          fT = 1;
          fR = 1;
          OffNasos (0);
        }
      }

      myGLCD.setFont(BigRusFont);
      if (x > 15 && x < 94 && y > 180 && y < 230) {
        ON_OFF = 0;
        myGLCD.setColor(VGA_BLACK);
        myGLCD.fillRoundRect(15, 180, 94, 230);
        myGLCD.setColor(VGA_WHITE);
        myGLCD.fillRoundRect(226, 180, 305, 230);
        myGLCD.setColor(VGA_LIME);
        myGLCD.print("BK""\x88", 242, 197);//ВКЛ
      }
      if (x > 226 && x < 305 && y > 180 && y < 230) {
        ON_OFF = 1;
        myGLCD.setColor(VGA_BLACK);
        myGLCD.fillRoundRect(226, 180, 305, 230);
        myGLCD.setColor(VGA_WHITE);
        myGLCD.fillRoundRect(15, 180, 94, 230);
        myGLCD.setColor(VGA_LIME);
        myGLCD.print("B""\x91""K""\x88", 23, 197);//ВЫКЛ

      }

      if (x > 15 && x < 79 && y > 105 && y < 135) {
        out--;
        if (out > 100) out = 0;

      }
      if (x > 241 && x < 305 && y > 105 && y < 135) {
        out++;
        if (out > 100) out = 100;

      }
      myGLCD.setColor(VGA_BLACK);
      if (out < 10)myGLCD.fillRoundRect(132, 95, 196, 145);
      if (out < 100)myGLCD.fillRoundRect(164, 95, 196, 145);
      myGLCD.setColor(VGA_RED);
      myGLCD.setFont(SevenSegNumFont);
      myGLCD.printNumI(out, 100, 95);
    }
  }
}

//_________________________________________________________________________________________________
/*void Touch3 () { // обработка тачскрина меню насоса
  while (true)
  {

    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 32 && x < 96 && y > 20 && y < 50) Screen0 ();// возврат в главное меню
    }
  }
  }
*/
//_________________________________________________________________________________________________
void Touch4 () { // обработка тачскрина меню варки пива
  while (true)
  {

    if (myTouch.dataAvailable())
    {

      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 68 && x < 132 && y > 20 && y < 50) Screen0 ();// возврат в главное меню
      if (x > 188 && x < 252 && y > 20 && y < 50) Screen4_1 ();// переход на 2 этап настроек
      if (x > 279 && x < 309) {
        if (y > 57 &&  y < 121) {// Вверх
          waitForItButton(279, 57, 309, 121);//Делаем окантовку кнопки
          flagTabel--;
          if (flagTabel == 0) flagTabel = 13;
          UpDown ();
        }
        if (y > 171 && y < 235) {// Вниз
          waitForItButton(279, 171, 309, 235);//Делаем окантовку кнопки
          flagTabel++;
          if (flagTabel > 13) flagTabel = 1;
          UpDown ();
        }
      }
      if (x > 274 && x < 314 && y > 126 && y < 166)
      {
        waitForItButton(274, 126, 314, 166);//Делаем окантовку кнопки
        OkTabel ();
      }
    }
  }
}
//_________________________________________________________________________________________________
void Touch4_1 () {
  while (true)
  {

    if (myTouch.dataAvailable())
    {

      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 68 && x < 132 && y > 20 && y < 50) Screen4 ();// возврат в главное меню
      if (x > 188 && x < 252 && y > 20 && y < 50) Screen4_2 ();// возврат в главное меню
      if (x > 279 && x < 309) {
        if (y > 57 &&  y < 121) {// Вверх
          waitForItButton(279, 57, 309, 121);//Делаем окантовку кнопки
          flagTabel1--;
          if (flagTabel1 == 0) flagTabel1 = 7;
          UpDown1 ();
        }
        if (y > 171 && y < 235) {// Вниз
          waitForItButton(279, 171, 309, 235);//Делаем окантовку кнопки
          flagTabel1++;
          if (flagTabel1 > 7) flagTabel1 = 1;
          UpDown1 ();
        }
      }
      if (x > 274 && x < 314 && y > 126 && y < 166)
      {
        waitForItButton(274, 126, 314, 166);//Делаем окантовку кнопки
        OkTabel1 ();
      }
    }

  }
}
//_________________________________________________________________________________________________
void Touch4_2 () {
  while (true)
  {

    if (myTouch.dataAvailable())
    {

      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 68 && x < 132 && y > 20 && y < 50) Screen4_1 ();// возврат в главное меню
      if (x > 188 && x < 252 && y > 20 && y < 50)  Beer ();// возврат в главное меню
      if (x > 135 && x < 185 && y > 10 && y < 60) Screen5_2 ();
    }
  }
}
//_________________________________________________________________________________________________
void Touch5 () { // обработка тачскрина меню sd карты

  while (true)
  {

    if (myTouch.dataAvailable())
    {
      NameBeer = "/BEER/";
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
LabelListDir:
      if ( x > 5 && x < 200) {
        if (y > 70 && y < 96) {// первая строка
          waitForItButton1(5, 70, 245, 96);
          delay(100);
          Touch ();
          if (y > 70 && y < 96) {
            switch (ScreenDir) {
              case 1:
                if (SumDir >= 1) {
                  NameBeer += NameDir[0];
                  SDReadBeer ();
                }
                break;
              case 2:
                if (SumDir >= 5) {
                  NameBeer += NameDir[5];
                  SDReadBeer ();
                }
                break;
              case 3:
                if (SumDir >= 10) {
                  NameBeer += NameDir[10];
                  SDReadBeer ();
                }
                break;
              case 4:
                if (SumDir >= 15) {
                  NameBeer += NameDir[15];
                  SDReadBeer ();
                }
                break;
              case 5:
                if (SumDir >= 20) {
                  NameBeer += NameDir[20];
                  SDReadBeer ();
                }
                break;
            }
          }
          else {
            waitForItButton(5, 70, 245, 96);
            goto LabelListDir;
          }
        }
        if (y > 102 && y < 128) {//вторая строка
          waitForItButton1(5, 102, 245, 128);
          delay(100);
          Touch ();
          if (y > 102 && y < 128) {//вторая строка
            switch (ScreenDir) {
              case 1:
                if (SumDir >= 2) {
                  NameBeer += NameDir[1];
                  SDReadBeer ();
                }
                break;
              case 2:
                if (SumDir >= 6) {
                  NameBeer += NameDir[6];
                  SDReadBeer ();
                }
              case 3:
                if (SumDir >= 11) {
                  NameBeer += NameDir[11];
                  SDReadBeer ();
                }
                break;
              case 4:
                if (SumDir >= 16) {
                  NameBeer += NameDir[16];
                  SDReadBeer ();
                }
                break;
              case 5:
                if (SumDir >= 21) {
                  NameBeer += NameDir[21];
                  SDReadBeer ();
                }
                break;
            }
          }
          else {
            waitForItButton(5, 102, 245, 128);
            goto LabelListDir;
          }
        }
        if (y > 134 && y < 160) {//третья строка
          waitForItButton1(5, 134, 245, 160);
          delay(100);
          Touch ();
          if (y > 134 && y < 160) {//третья строка
            switch (ScreenDir) {
              case 1:
                if (SumDir >= 3) {
                  NameBeer += NameDir[2];
                  SDReadBeer ();
                }
                break;
              case 2:
                if (SumDir >= 7) {
                  NameBeer += NameDir[7];
                  SDReadBeer ();
                }
              case 3:
                if (SumDir >= 12) {
                  NameBeer += NameDir[12];
                  SDReadBeer ();
                }
                break;
              case 4:
                if (SumDir >= 17) {
                  NameBeer += NameDir[17];
                  SDReadBeer ();
                }
                break;
              case 5:
                if (SumDir >= 22) {
                  NameBeer += NameDir[22];
                  SDReadBeer ();
                }
                break;
            }
          }
          else {
            waitForItButton(5, 134, 245, 160);
            goto LabelListDir;
          }
        }
        if (y > 166 && y < 192) {//четвёртая строка
          waitForItButton1(5, 166, 245, 192);
          delay(100);
          Touch ();
          if (y > 166 && y < 192) {//четвёртая строка
            switch (ScreenDir) {
              case 1:
                if (SumDir >= 4) {
                  NameBeer += NameDir[3];
                  SDReadBeer ();
                }
                break;
              case 2:
                if (SumDir >= 8) {
                  NameBeer += NameDir[8];
                  SDReadBeer ();
                }
              case 3:
                if (SumDir >= 13) {
                  NameBeer += NameDir[13];
                  SDReadBeer ();
                }
                break;
              case 4:
                if (SumDir >= 18) {
                  NameBeer += NameDir[18];
                  SDReadBeer ();
                }
                break;
              case 5:
                if (SumDir >= 24) {
                  NameBeer += NameDir[24];
                  SDReadBeer ();
                }
                break;
            }
          }
          else {
            waitForItButton(5, 166, 245, 192);
            goto LabelListDir;
          }
        }
        if (y > 198 && y < 224) {//пятая строка
          waitForItButton1(5, 198, 245, 224);
          delay(100);
          Touch ();
          if (y > 198 && y < 224) {//пятая строка
            switch (ScreenDir) {
              case 1:
                if (SumDir >= 5) {
                  NameBeer += NameDir[4];
                  SDReadBeer ();
                }
                break;
              case 2:
                if (SumDir >= 9) {
                  NameBeer += NameDir[9];
                  SDReadBeer ();
                }
              case 3:
                if (SumDir >= 14) {
                  NameBeer += NameDir[14];
                  SDReadBeer ();
                }
                break;
              case 4:
                if (SumDir >= 19) {
                  NameBeer += NameDir[19];
                  SDReadBeer ();
                }
                break;
              case 5:
                if (SumDir >= 25) {
                  NameBeer += NameDir[25];
                  SDReadBeer ();
                }
                break;
            }
          }
          else {
            waitForItButton(5, 198, 245, 224);
            goto LabelListDir;
          }
        }

      }
      if (x > 279 && x < 309 && y > 57 && y < 121) {

        if (SumDir > 5 && ScreenDir == 2) {
          waitForItButton(279, 165, 309, 229);
          ScreenDir --;
          Screen5 ();

        }
        if (SumDir > 5 && ScreenDir == 3) {
          waitForItButton(279, 165, 309, 229);
          ScreenDir --;
          ScreenListDir (5);
        }
        if (SumDir > 10 && ScreenDir == 4) {
          waitForItButton(279, 165, 309, 229);
          ScreenDir--;
          ScreenListDir (10);
        }
        if (SumDir > 20 && ScreenDir == 5) {
          waitForItButton(279, 165, 309, 229);
          ScreenDir --;
          ScreenListDir (15);
        }
      }
      if (x > 279 && x < 309 && y > 165 && y < 229) {
        if (SumDir > 5 && ScreenDir == 1) {
          waitForItButton(279, 165, 309, 229);
          ScreenDir ++;
          ScreenListDir (5);
        }
        if (SumDir > 10 && ScreenDir == 2) {
          waitForItButton(279, 165, 309, 229);
          ScreenDir ++;
          ScreenListDir (10);
        }
        if (SumDir > 15 && ScreenDir == 3) {
          waitForItButton(279, 165, 309, 229);
          ScreenDir ++;
          ScreenListDir (15);
        }
        if (SumDir > 20 && ScreenDir == 4) {
          waitForItButton(279, 165, 309, 229);
          ScreenDir ++;
          ScreenListDir (20);
        }
      }
      if (x > 32 && x < 96 && y > 20 && y < 50) Screen0 ();// возврат в главное меню
    }
  }
}

//_________________________________________________________________________________________________
void Touch5_2 () {
  while (true)
  {
    myGLCD.setFont(BigRusFont);
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 32 && x < 96 && y > 20 && y < 50) Screen4_2 ();//
      if ( x > 50 && x < 270 && y > 154 && y < 230) {
        NameBeer = "/BEER/";
        for (int  i = 0; i < 8; i++) {
          NameBeer += BufName[i];
        }
        NameBeer += ".TXT";

        if (SD.exists(NameBeer) == false) {
          SDSaveBeer ();
        }
        else {

          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRoundRect(50, 154, 270, 230);
          myGLCD.setColor(VGA_LIME);
          myGLCD.setFont(BigRusFont);
          myGLCD.print ("Pe""\xA6""e""\xA3""\xA4"" ""c"" ""\xA4""a""\x9F""\x9D""\xA1", CENTER, 172);
          myGLCD.print ("\x9D""\xA1""e""\xA2""e""\xA1"" ""cy""\xA9""ec""\xA4""\x97""ye""\xA4""!", CENTER, 195);
          delay(3000);
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRect(0, 154, 319, 238);
          waitForItButton1(10, 160, 60, 210);
          waitForItButton1(260, 160, 310, 210);
          myGLCD.print ("\x82""A", 19, 176);
          myGLCD.print ("HET", 261, 176);
          myGLCD.print("COXPAH""\x86""T""\x92""?", CENTER, 176);
          boolean a;
          while (true) {
            if (myTouch.dataAvailable())
            {
              myTouch.read();
              x = myTouch.getX();
              y = myTouch.getY();
              if (x > 10 && x < 60 && y > 160 && y < 210) {
                SDSaveBeer ();
                if (SD.exists(NameBeer) == false) {
                  myGLCD.setColor(VGA_BLACK);
                  myGLCD.fillRect(0, 154, 319, 238);
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.print ("\x8B""a""\x9E""\xA0"" ""\xA2""e"" ""co""\x9C""\x99""a""\xA2""!", CENTER, 188);//файл не создан!
                  delay (3000);
                  setSD ();
                }
                if (SD.exists(NameBeer) == true) {
                  myGLCD.setColor(VGA_BLACK);
                  myGLCD.fillRect(0, 154, 319, 238);
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.print (NameBeer, 0, 188);
                  delay (3000);
                  Screen4_2 ();
                }

              }
              if (x > 260 && x < 310 && y > 160 && y < 210) Screen5_2 ();
            }
          }
        }
        if (SD.exists(NameBeer) == false) {
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRect(0, 154, 319, 238);
          myGLCD.setColor(VGA_LIME);
          myGLCD.print ("\x8B""a""\x9E""\xA0"" ""\xA2""e"" ""co""\x9C""\x99""a""\xA2""!", CENTER, 188);//файл не создан!
          delay (3000);
          setSD ();
        }
        if (SD.exists(NameBeer) == true) {
          myGLCD.setColor(VGA_BLACK);
          myGLCD.fillRect(0, 154, 319, 238);
          myGLCD.setColor(VGA_LIME);
          myGLCD.print (NameBeer, 0, 188);
          delay (3000);
          Screen4_2 ();
        }
      }
      if ( y > 85 && y < 131) {
        if ( x > 26 && x < 60) {
          waitForItButton1(26, 85, 60, 131);
          TouchSDBeerReName (0);
        }
        if ( x > 61 && x < 95) {
          waitForItButton1(61, 85, 95, 131);
          TouchSDBeerReName (1);
        }
        if ( x > 96 && x < 130) {
          waitForItButton1(96, 85, 130, 131);
          TouchSDBeerReName (2);
        }
        if ( x > 131 && x < 165) {
          waitForItButton1(131, 85, 165, 131);
          TouchSDBeerReName (3);
        }
        if ( x > 166 && x < 200) {
          waitForItButton1(166, 85, 200, 131);
          TouchSDBeerReName (4);
        }
        if ( x > 201 && x < 235) {
          waitForItButton1(201, 85, 235, 131);
          TouchSDBeerReName (5);
        }
        if ( x > 236 && x < 270) {
          waitForItButton1(236, 85, 270, 131);
          TouchSDBeerReName (6);
        }
        if ( x > 271 && x < 305) {
          waitForItButton1(271, 85, 305, 131);
          TouchSDBeerReName (7);
        }
      }
    }
  }
}
void TouchSDBeerReName (byte g) {
  myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// " - "
  myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// " + "
  myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
  byte w = 0;
  byte h = 0;
  w = g +  1;
  if (w == 0) w = 1;
  while (true)
  {

    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (y > 156 && y < 196) {
        if (x > 250 && x < 290) {
          h++;
          if (h > 35) h = 0;
          myGLCD.print(ACS[h], 35 * w, 100);
          delay(100);

        }
        if (x > 30 && x < 70) {
          h--;
          if (h > 35) h = 35;
          myGLCD.print(ACS[h], 35 * w, 100);
          delay(100);

        }
        if (x > 145 && x < 185) {
          BufName[g] =  ACS[h];
          Screen5_2 ();
        }
      }
    }
  }
}
//_________________________________________________________________________________________________
void TouchSys () {

  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 75 && x < 125 && y > 95  && y < 145) ScreenREC ();
      if (x > 15 && x < 65 && y > 95 && y < 145) ScreenSetTime ();
      if (x > 15 && x < 65 && y > 10 && y < 60) Screen1 ();// возврат в главное меню
      if (x > 135 && x < 185 && y > 95 && y < 145 )SetRele ();
    }
  }
}
void TouchREC () {
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 15 && x < 125 && y > 95 && y < 145) {
        myGLCD.setBackColor(VGA_BLACK);
        myGLCD.setFont(SmallRusFont);
        Save_sys ();
        SDSaveSys ();
        myGLCD.setColor(VGA_WHITE);
        myGLCD.print("O""\x96""pa""\x9C"" ""co""\x9C""\x99""a""\xA2""!", CENTER, 200);//образ
      }

      if (x > 150 && x < 280 && y > 95 && y < 145) {
        SDReadSys ();
        resetFunc();

      }
      if (x > 15 && x < 65 && y > 10 && y < 65) ScreenSys ();// возврат в  меню SYS
    }
  }
}

void TouchSetTime () { //обработка меню часов
  while (true)
  {
    ScreenTime (96, 100, 2, 9, 1);
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (y > 100 && y < 116) {
        if (x > 96 && x < 128) {
          // myGLCD.setFont(SmallRusFont);
          myGLCD.setColor(VGA_WHITE);
          myGLCD.drawRoundRect(91, 95, 133, 121);
          SetTime (1);
        }
        if (x > 144 && x < 176) {
          // myGLCD.setFont(SmallRusFont);
          myGLCD.setColor(VGA_WHITE);
          myGLCD.drawRoundRect(137, 95, 181, 121);
          SetTime (2);
        }
        if (x > 192 && x < 224) {
          //myGLCD.setFont(SmallRusFont);
          myGLCD.setColor(VGA_WHITE);
          myGLCD.drawRoundRect(185, 95, 229, 121);
          SetTime (3);
        }
      }
      if (x > 15 && x < 65 && y > 10 && y < 60) {
        ScreenSys ();// возврат в  меню sis
      }
    }
  }
}
//_________________________________________________________________________________________________
void TouchRele () {
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 15 && x < 65 && y > 10 && y < 65) ScreenSys ();// возврат в  меню SYS
      if (x > 16 && x < 84 && y > 80 && y < 140) {
        waitForItButton(16, 80, 84, 140);
        ReleOn = !ReleOn;
        if (ReleOn == 1) ReleOff = 0;
        if (ReleOn == 0) ReleOff = 1;



        digitalWrite(NasosPin, ReleOff);
        SetRele ();
      }
    }
  }
}
//_________________________________________________________________________________________________
void TouchHot () { //обработка меню настройки тэна
  while (true)
  {
    myGLCD.setColor(VGA_LIME);
    printTemperatureNoScr();
    myGLCD.setFont(SevenSegNumFont);
    myGLCD.setColor(VGA_BLACK);
    if (TempC < 10)myGLCD.fillRoundRect(242, 10, 306, 60);
    if (TempC < 100)myGLCD.fillRoundRect(274, 10, 306, 60);
    if (TempC < 0) TempC = 0;
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(TempC, 210, 10);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("   ", CENTER, 170);
    myGLCD.printNumI(out, CENTER, 170);
    myGLCD.print("Mo""\xA9""\xA2""oc""\xA4""\xAC"" %", CENTER, 184);
    if (ON_OFF == 1) {

      PIctl(TempC, TempCSET);
      ten.lpwm(t_pwm, out);//медленный ШИМ на тен

    }
    if (ON_OFF == 0) {
      ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
    }
    if (myTouch.dataAvailable())
    {

      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 15 && x < 65 && y > 10 && y < 60) {
        ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
        Screen1 ();// возврат в  меню настроек
      }
      myGLCD.setFont(BigRusFont);

      if (x > 32 && x < 96 && y > 20 && y < 50) {
        ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
        Screen0 ();// возврат в главное меню
      }
      if (x > 15 && x < 94 && y > 180 && y < 230) {
        ON_OFF = 0;
        myGLCD.setColor(VGA_BLACK);
        myGLCD.fillRoundRect(15, 180, 94, 230);
        myGLCD.setColor(VGA_WHITE);
        myGLCD.fillRoundRect(226, 180, 305, 230);
        myGLCD.setColor(VGA_LIME);
        myGLCD.print("BK""\x88", 242, 197);//ВКЛ
      }
      if (x > 226 && x < 305 && y > 180 && y < 230) {
        ON_OFF = 1;
        myGLCD.setColor(VGA_BLACK);
        myGLCD.fillRoundRect(226, 180, 305, 230);
        myGLCD.setColor(VGA_WHITE);
        myGLCD.fillRoundRect(15, 180, 94, 230);
        myGLCD.setColor(VGA_LIME);
        myGLCD.print("B""\x91""K""\x88", 23, 197);//ВЫКЛ

      }
      if (y > 95 && y < 150) {
        if (x > 10 && x < 106) {

          myGLCD.setColor(VGA_LIME);

          myGLCD.setFont(SevenSegNumFont);
          myGLCD.printNumI(kP, 10, 95);
          myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
          myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
          myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
          while (true)
          {
            if (myTouch.dataAvailable())
            {

              myTouch.read();
              x = myTouch.getX();
              y = myTouch.getY();
              if (y > 156 && y < 196) {
                if (x > 145 && x < 185) {// "ок"
                  waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
                  setHot ();
                }
                if (x > 250 && x < 290) {// "+"
                  waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
                  kP++;
                  if (kP > 100 ) kP = 0;
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.setFont(SevenSegNumFont);
                  int kPScr (kP);
                  myGLCD.setColor(VGA_BLACK);
                  if (kPScr < 10)myGLCD.fillRoundRect(42, 95, 106, 145);
                  if (kPScr < 100)myGLCD.fillRoundRect(74, 95, 106, 145);
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.printNumI(kPScr, 10, 95);

                }
                if (x > 30 && x < 70) {// "-"
                  waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
                  if (kP != 0 ) {
                    kP--;
                  }
                  else {
                    kP = 100;
                  }
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.setFont(SevenSegNumFont);
                  int kPScr (kP);
                  myGLCD.setColor(VGA_BLACK);
                  if (kPScr < 10)myGLCD.fillRoundRect(42, 95, 106, 145);
                  if (kPScr < 100)myGLCD.fillRoundRect(74, 95, 106, 145);
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.printNumI(kPScr, 10, 95);

                }
              }
            }
          }
        }
        if (x > 122 && x < 218) {

          myGLCD.setColor(VGA_LIME);

          myGLCD.setFont(SevenSegNumFont);
          myGLCD.printNumI(kI, 122, 95);
          myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
          myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
          myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
          while (true)
          {
            if (myTouch.dataAvailable())
            {

              myTouch.read();
              x = myTouch.getX();
              y = myTouch.getY();
              if (y > 156 && y < 196) {
                if (x > 145 && x < 185) {// "ок"
                  waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
                  setHot ();
                }
                if (x > 250 && x < 290) {// "+"
                  waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
                  kI++;
                  if (kI > 100 ) kI = 0;

                  myGLCD.setFont(SevenSegNumFont);
                  int kIScr (kI);
                  myGLCD.setColor(VGA_BLACK);
                  if (kIScr < 10)myGLCD.fillRoundRect(154, 95, 218, 145);
                  if (kIScr < 100)myGLCD.fillRoundRect(186, 95, 218, 145);
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.printNumI(kIScr, 122, 95);
                }
                if (x > 30 && x < 70) {// "-"
                  waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
                  if (kI != 0 ) {
                    kI--;
                  }
                  else {
                    kI = 100;
                  }

                  myGLCD.setFont(SevenSegNumFont);
                  int kIScr (kI);
                  myGLCD.setColor(VGA_BLACK);
                  if (kIScr < 10)myGLCD.fillRoundRect(154, 95, 218, 145);
                  if (kIScr < 100)myGLCD.fillRoundRect(186, 95, 218, 145);
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.printNumI(kIScr, 122, 95);
                }
              }
            }
          }
        }
        if (x > 234 && x < 298) {

          myGLCD.setColor(VGA_LIME);

          myGLCD.setFont(SevenSegNumFont);
          myGLCD.printNumI(TempCSET, 234, 95);
          myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
          myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
          myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
          while (true)
          {
            if (myTouch.dataAvailable())
            {

              myTouch.read();
              x = myTouch.getX();
              y = myTouch.getY();
              if (y > 156 && y < 196) {
                if (x > 145 && x < 185) {// "ок"
                  waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
                  setHot ();
                }
                if (x > 250 && x < 290) {// "+"
                  waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
                  TempCSET++;
                  if (TempCSET > 99 ) TempCSET = 0;
                  myGLCD.setFont(SevenSegNumFont);
                  myGLCD.setColor(VGA_BLACK);
                  if (TempCSET < 10)myGLCD.fillRoundRect(266, 95, 298, 145);
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.printNumI(TempCSET, 234, 95);
                }
                if (x > 30 && x < 70) {// "-"
                  waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
                  if (TempCSET != 0 ) {
                    TempCSET--;
                  }
                  else {
                    TempCSET = 99;
                  }
                  myGLCD.setColor(VGA_BLACK);
                  if (TempCSET < 10)myGLCD.fillRoundRect(266, 95, 298, 145);
                  myGLCD.setColor(VGA_LIME);
                  myGLCD.printNumI(TempCSET, 234, 95);
                }
              }
            }
          }
        }
      }
    }
  }
}
//_________________________________________________________________________________________________
void TouchNasos () { //обработка меню насоса первая страница
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      myGLCD.drawBitmap(188, 20, 64, 30, RightButton1, 1);
      if (x > 188 && x < 252 && y > 20 && y < 50) setNasos_1();
      if (x > 15 && x < 65 && y > 10 && y < 60) Screen1 ();// возврат в  меню настроек
      if (x > 279 && x < 309) {
        if (y > 57 &&  y < 121) {// Вверх
          waitForItButton(279, 57, 309, 121);//Делаем окантовку кнопки
          flagTabelWN--;
          if (flagTabelWN == 0) flagTabelWN = 14;
          UpDown2 ();
        }
        if (y > 171 && y < 235) {// Вниз
          waitForItButton(279, 171, 309, 235);//Делаем окантовку кнопки
          flagTabelWN++;
          if (flagTabelWN > 14) flagTabelWN = 1;
          UpDown2 ();
        }
      }
      if (x > 274 && x < 314 && y > 126 && y < 166)
      {
        waitForItButton(274, 126, 314, 166);//Делаем окантовку кнопки
        OkTabel2 ();
      }
    }
  }
}
//_________________________________________________________________________________________________
void TochNasos_1 () {//обработка меню насоса второя страница
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 244 && x < 304 && y > 80 && y < 140) {
        waitForItButton(244, 80, 304, 140);
        OnOffTerpNW = !OnOffTerpNW;
        myGLCD.setColor(VGA_WHITE);
        myGLCD.fillRoundRect(244 , 80, 304 , 140);
        myGLCD.setColor(VGA_BLACK);
        myGLCD.setFont(SmallRusFont);
        if (OnOffTerpNW == false)myGLCD.print ("B""\x91""K""\x88"".", 258, 106);
        if (OnOffTerpNW == true)myGLCD.print ("B""K""\x88"".", 262, 106);
      }
      if (x > 68 && x < 132 && y > 20 && y < 50) setNasos ();
      if (x > 16 && x <  76 && y > 90 && y < 150) {
        myGLCD.setColor (VGA_RED);
        myGLCD.drawRoundRect(16 , 80, 76 , 140);
        myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
        myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
        myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
        myGLCD.setColor (VGA_RED);
        myGLCD.setBackColor (VGA_BLACK);
        myGLCD.setFont(SevenSegNumFont);
        myGLCD.printNumI(maxTerpNW, CENTER, 99);

        while (true) {
          if (myTouch.dataAvailable())
          {

            myTouch.read();
            x = myTouch.getX();
            y = myTouch.getY();
            if (y > 156 && y < 196) {
              if (x > 30 && x < 70) {
                maxTerpNW --;
                if (maxTerpNW < 10) maxTerpNW = 120;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(maxTerpNW, CENTER, 99);
                delay(100);
              }
              if (x > 250 && x < 290) {
                maxTerpNW ++;
                if (maxTerpNW > 120) maxTerpNW = 10;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(maxTerpNW, CENTER, 99);
                delay(100);
              }
              if (x > 145 && x < 185) setNasos_1 ();
            }
          }
        }
      }
      if (x > 16 && x <  76 && y > 170 && y < 230) {
        myGLCD.setColor (VGA_RED);
        myGLCD.drawRoundRect(16 , 170, 76 , 230);
        myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
        myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
        myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
        myGLCD.setColor (VGA_RED);
        myGLCD.setBackColor (VGA_BLACK);
        myGLCD.setFont(SevenSegNumFont);
        myGLCD.printNumI(airW, 160, 99);

        while (true) {
          if (myTouch.dataAvailable())
          {

            myTouch.read();
            x = myTouch.getX();
            y = myTouch.getY();
            if (y > 156 && y < 196) {
              if (x > 30 && x < 70) {
                airW --;
                if (airW > 120) airW = 120;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(airW, 160, 99);
                delay(100);
              }
              if (x > 250 && x < 290) {
                airW ++;
                if (airW > 120) airW = 1;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(airW, 160, 99);
                delay(100);
              }
              if (x > 145 && x < 185) setNasos_1 ();
            }
          }
        }
      }

      if (x > 130 && x <  190 && y > 170 && y < 230) {
        myGLCD.setColor (VGA_RED);
        myGLCD.drawRoundRect(130 , 170, 190 , 230);
        myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
        myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
        myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
        myGLCD.setColor (VGA_RED);
        myGLCD.setBackColor (VGA_BLACK);
        myGLCD.setFont(SevenSegNumFont);
        myGLCD.printNumI(airP, 160, 99);

        while (true) {
          if (myTouch.dataAvailable())
          {

            myTouch.read();
            x = myTouch.getX();
            y = myTouch.getY();
            if (y > 156 && y < 196) {
              if (x > 30 && x < 70) {
                airP --;
                if (airP > 120) airP = 120;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(airP, 160, 99);
                delay(100);
              }
              if (x > 250 && x < 290) {
                airP ++;
                if (airP > 120) airP = 1;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(airP, 160, 99);
                delay(100);
              }
              if (x > 145 && x < 185) setNasos_1 ();
            }
          }
        }
      }

      if (x > 244 && x <  304 && y > 170 && y < 230) {
        myGLCD.setColor (VGA_RED);
        myGLCD.drawRoundRect(244 , 170, 304 , 230);
        myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
        myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
        myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
        myGLCD.setColor (VGA_RED);
        myGLCD.setBackColor (VGA_BLACK);
        myGLCD.setFont(SevenSegNumFont);
        myGLCD.printNumI(rep, 160, 99);

        while (true) {
          if (myTouch.dataAvailable())
          {

            myTouch.read();
            x = myTouch.getX();
            y = myTouch.getY();
            if (y > 156 && y < 196) {
              if (x > 30 && x < 70) {
                rep --;
                if (rep > 10) rep = 10;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(rep, 160, 99);
                delay(100);
              }
              if (x > 250 && x < 290) {
                rep ++;
                if (rep > 120) rep = 1;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(rep, 160, 99);
                delay(100);
              }
              if (x > 145 && x < 185) setNasos_1 ();
            }
          }
        }
      }
    }
  }
}
//_________________________________________________________________________________________________
void TouchBeer () { //первая страница меню настройки пивоварни
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 15 && x < 65 && y > 10 && y < 60) Screen1 ();// возврат в  меню настроек
      if (x > 188 && 252 && y > 20 && y < 50) setBeer_1 ();
      if (x > 279 && x < 309) {
        if (y > 57 &&  y < 121) {// Вверх
          waitForItButton(279, 57, 309, 121);//Делаем окантовку кнопки
          flagTabelB--;
          if (flagTabelB == 0) flagTabelB = 14;
          UpDown3 ();
        }
        if (y > 171 && y < 235) {// Вниз
          waitForItButton(279, 171, 309, 235);//Делаем окантовку кнопки
          flagTabelB++;
          if (flagTabelB > 14) flagTabelB = 1;
          UpDown3 ();
        }
      }
      if (x > 274 && x < 314 && y > 126 && y < 166)
      {
        waitForItButton(274, 126, 314, 166);//Делаем окантовку кнопки
        for ( byte i = 1; i <= 7; i++) {
          if (flagTabelB == i ) {
            setBeerN_1 (0);
          }
        }
        for ( byte i = 8; i <= 14; i++) {
          if (flagTabelB == i ) {
            setBeerM_1 ();
          }
        }
      }
    }
  }
}
//_________________________________________________________________________________________________
void TouchBeer_1 () { //Вторая страница меню настройки пивоварни
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (x > 68 && x < 132 && y > 20 && y < 50) setBeer ();// возврат в  меню настроек
      if (x > 16 && x <  76 && y > 90 && y < 150) {
        myGLCD.setColor (VGA_RED);
        myGLCD.drawRoundRect(16 , 80, 76 , 140);
        myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
        myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
        myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
        myGLCD.setColor (VGA_RED);
        myGLCD.setBackColor (VGA_BLACK);
        myGLCD.setFont(SevenSegNumFont);
        myGLCD.printNumI(termKIP, CENTER, 99);

        while (true) {
          if (myTouch.dataAvailable())
          {

            myTouch.read();
            x = myTouch.getX();
            y = myTouch.getY();
            if (y > 156 && y < 196) {
              if (x > 30 && x < 70) {
                termKIP --;
                if (termKIP < 10) termKIP = 120;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(termKIP, CENTER, 99);
                delay(100);
              }
              if (x > 250 && x < 290) {
                termKIP ++;
                if (termKIP > 120) termKIP = 10;
                myGLCD.setColor (VGA_BLACK);
                myGLCD.fillRoundRect(112, 99, 208, 149);
                myGLCD.setColor (VGA_RED);
                myGLCD.printNumI(termKIP, CENTER, 99);
                delay(100);
              }
              if (x > 145 && x < 185) setBeer_1 ();
            }
          }
        }
      }
    }
  }
}
//_________________________________________________________________________________________________
void TouchsetBeerN_1 (byte hh) {
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (y > 50 && y < 110) {
        if (x > 16 && x < 76) {
          if (hh == 0) {
            for ( byte i = 1; i <= 7; i++) {
              if (flagTabelB == i) {
                BeerN[i - 1] = 0;
                setBeer ();
              }
            }
          }
          if (hh == 1) {
            nasosWH = WorkN[0];
            nasosPH = PauseN[0];
            Screen2_1 ();
          }
        }
        if (x > 92 && x < 152) {
          if (hh == 0) {
            for ( byte i = 1; i <= 7; i++) {
              if (flagTabelB == i) {
                BeerN[i - 1] = 1;
                setBeer ();
              }
            }
          }
          if (hh == 1) {
            nasosWH = WorkN[1];
            nasosPH = PauseN[1];
            Screen2_1 ();
          }
        }
        if (x > 168 && x < 228) {
          if (hh == 0) {
            for ( byte i = 1; i <= 7; i++) {
              if (flagTabelB == i) {
                BeerN[i - 1] = 2;
                setBeer ();
              }
            }
          }
          if (hh == 1) {
            nasosWH = WorkN[2];
            nasosPH = PauseN[2];
            Screen2_1 ();
          }
        }
        if (x > 244 && x < 304) {
          if (hh == 0) {
            for ( byte i = 1; i <= 7; i++) {
              if (flagTabelB == i) {
                BeerN[i - 1] = 3;
                setBeer ();
              }
            }
          }
          if (hh == 1) {
            nasosWH = WorkN[3];
            nasosPH = PauseN[3];
            Screen2_1 ();
          }
        }
      }
      if (y > 130 && y < 190) {
        if (x > 16 && x < 76) {
          if (hh == 0) {
            for ( byte i = 1; i <= 7; i++) {
              if (flagTabelB == i) {
                BeerN[i - 1] = 4;
                setBeer ();
              }
            }
          }
          if (hh == 1) {
            nasosWH = WorkN[4];
            nasosPH = PauseN[4];
            Screen2_1 ();
          }
        }
        if (x > 92 && x < 152) {
          if (hh == 0) {
            for ( byte i = 1; i <= 7; i++) {
              if (flagTabelB == i) {
                BeerN[i - 1] = 5;
                setBeer ();
              }
            }
          }
          if (hh == 1) {
            nasosWH = WorkN[5];
            nasosPH = PauseN[5];
            Screen2_1 ();
          }
        }
        if (x > 168 && x < 228) {
          if (hh == 0) {
            for ( byte i = 1; i <= 7; i++) {
              if (flagTabelB == i) {
                BeerN[i - 1] = 6;
                setBeer ();
              }
            }
          }
          if (hh == 1) {
            nasosWH = WorkN[6];
            nasosPH = PauseN[6];
            Screen2_1 ();
          }
        }
        if (x > 244 && x < 304) {
          if (hh == 0) {
            for ( byte i = 1; i <= 7; i++) {
              if (flagTabelB == i) {
                BeerN[i - 1] = 7;
                setBeer ();
              }
            }
          }
          if (hh == 1) {
            nasosWH = WorkN[7];
            nasosPH = PauseN[7];
            Screen2_1 ();
          }
        }
      }
    }
  }
}

//_________________________________________________________________________________________________
void TouchsetBeerM_1 () {
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (y > 50 && y < 110) {
        if (x > 16 && x < 76) {
          for ( byte i = 8; i <= 14; i++) {
            if (flagTabelB == i) {
              MelodiN[i - 8] = 0;
              setBeer ();
            }
          }
        }
        if (x > 92 && x < 152) {
          for ( byte i = 8; i <= 14; i++) {
            if (flagTabelB == i) {
              MelodiN[i - 8] = 1;
              setBeer ();
            }
          }
        }
        if (x > 168 && x < 228) {
          for ( byte i = 8; i <= 14; i++) {
            if (flagTabelB == i) {
              MelodiN[i - 8] = 2;
              setBeer ();
            }
          }
        }
      }
      if (y > 130 && y < 190) {
        if (x > 16 && x < 76) melodi ();
        if (x > 92 && x < 152) melodiErr ();
        if (x > 168 && x < 228) {

        }
        if (x > 244 && x < 304) {
          for ( byte i = 8; i <= 14; i++) {
            if (flagTabelB == i) {
              MelodiN[i - 8] = 7;
              setBeer ();
            }
          }
        }
      }
    }
  }
}
//_________________________________________________________________________________________________
void TouchSD () { //обработка меню рецептов
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (SdTouch == true && x > 100 && x < 220 && y > 160 && y < 210) setSD ();
      if (x > 15 && x < 65 && y > 10 && y < 60) Screen1 ();// возврат в  меню настроек
    }
  }
}
//_________________________________________________________________________________________________
void SetScreen4 (byte g, byte i) {// Обработка кнопок + - ок установки температуры и времени пауз

  while (true)
  {
    myGLCD.setColor (VGA_RED);
    myGLCD.setBackColor (VGA_BLACK);
    myGLCD.setFont(SevenSegNumFont);

    if (g == 1) {

      while (true)
      {
        myTouch.read();
        x = myTouch.getX();
        y = myTouch.getY();
        if (y > 156 && y < 196) {
          if (x > 30 && x < 70) {// "-"
            waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
            if (i == 1) {
              termB1--;
              if (termB1 >= 120) termB1 = 120;
            }
            if (i == 2) {
              termB2--;
              if (termB2 >= 120) termB2 = 120;
            }
            if (i == 3) {
              termB3--;
              if (termB3 >= 120) termB3 = 120;
            }
            if (i == 4) {
              termB4--;
              if (termB4 >= 120) termB4 = 120;
            }
            if (i == 5) {
              termB5--;
              if (termB5 >= 120) termB5 = 120;
            }
            if (i == 6) {
              termB6--;
              if (termB6 >= 120) termB6 = 120;
            }
            if (i == 7) {
              termB7--;
              if (termB7 >= 120) termB7 = 120;
            }
            myGLCD.setColor (VGA_BLACK);
            myGLCD.fillRoundRect(112, 99, 208, 149);
            myGLCD.setColor (VGA_RED);
            if (i == 1)myGLCD.printNumI(termB1, CENTER, 99);
            if (i == 2)myGLCD.printNumI(termB2, CENTER, 99);
            if (i == 3)myGLCD.printNumI(termB3, CENTER, 99);
            if (i == 4)myGLCD.printNumI(termB4, CENTER, 99);
            if (i == 5)myGLCD.printNumI(termB5, CENTER, 99);
            if (i == 6)myGLCD.printNumI(termB6, CENTER, 99);
            if (i == 7)myGLCD.printNumI(termB7, CENTER, 99);
          }
          if (x > 250 && x < 290) {// "+"
            waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
            if (i == 1) {
              termB1++;
              if (termB1 >= 120) termB1 = 0;
            }
            if (i == 2) {
              termB2++;
              if (termB2 >= 120) termB2 = 0;
            }
            if (i == 3) {
              termB3++;
              if (termB3 >= 120) termB3 = 0;
            }
            if (i == 4) {
              termB4++;
              if (termB4 >= 120) termB4 = 0;
            }
            if (i == 5) {
              termB5++;
              if (termB5 >= 120) termB5 = 0;
            }
            if (i == 6) {
              termB6++;
              if (termB6 >= 120) termB6 = 0;
            }
            if (i == 7) {
              termB7++;
              if (termB7 >= 120) termB7 = 0;
            }
            myGLCD.setColor (VGA_BLACK);
            myGLCD.fillRoundRect(112, 99, 208, 149);
            myGLCD.setColor (VGA_RED);
            if (i == 1)myGLCD.printNumI(termB1, CENTER, 99);
            if (i == 2)myGLCD.printNumI(termB2, CENTER, 99);
            if (i == 3)myGLCD.printNumI(termB3, CENTER, 99);
            if (i == 4)myGLCD.printNumI(termB4, CENTER, 99);
            if (i == 5)myGLCD.printNumI(termB5, CENTER, 99);
            if (i == 6)myGLCD.printNumI(termB6, CENTER, 99);
            if (i == 7)myGLCD.printNumI(termB7, CENTER, 99);
          }
          if (x > 145 && x < 185) {// "ок"
            waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
            Screen4 ();
          }
        }
      }
    }
    if (g == 2) {
      while (true)
      {
        myTouch.read();
        x = myTouch.getX();
        y = myTouch.getY();
        if (y > 156 && y < 196) {
          if (x > 30 && x < 70) {// "-"
            waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
            if (i == 1) {
              pauseB1--;
              if (pauseB1 >= 240) pauseB1 = 240;
            }
            if (i == 2) {
              pauseB2--;
              if (pauseB2 >= 240) pauseB2 = 240;
            }
            if (i == 3) {
              pauseB3--;
              if (pauseB3 >= 240) pauseB3 = 240;
            }
            if (i == 4) {
              pauseB4--;
              if (pauseB4 >= 240) pauseB4 = 240;
            }
            if (i == 5) {
              pauseB5--;
              if (pauseB5 >= 240) pauseB5 = 240;
            }
            if (i == 6) {
              pauseB6--;
              if (pauseB6 >= 240) pauseB6 = 240;
            }

            myGLCD.setColor (VGA_BLACK);
            myGLCD.fillRoundRect(112, 99, 208, 149);
            myGLCD.setColor (VGA_RED);
            if (i == 1)myGLCD.printNumI(pauseB1, CENTER, 99);
            if (i == 2)myGLCD.printNumI(pauseB2, CENTER, 99);
            if (i == 3)myGLCD.printNumI(pauseB3, CENTER, 99);
            if (i == 4)myGLCD.printNumI(pauseB4, CENTER, 99);
            if (i == 5)myGLCD.printNumI(pauseB5, CENTER, 99);
            if (i == 6)myGLCD.printNumI(pauseB6, CENTER, 99);

          }
          if (x > 250 && x < 290) {// "+"
            waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
            if (i == 1) {
              pauseB1++;
              if (pauseB1 >= 240) pauseB1 = 0;
            }
            if (i == 2) {
              pauseB2++;
              if (pauseB2 >= 240) pauseB2 = 0;
            }
            if (i == 3) {
              pauseB3++;
              if (pauseB3 >= 240) pauseB3 = 0;
            }
            if (i == 4) {
              pauseB4++;
              if (pauseB4 >= 240) pauseB4 = 0;
            }
            if (i == 5) {
              pauseB5++;
              if (pauseB5 >= 240) pauseB5 = 0;
            }
            if (i == 6) {
              pauseB6++;
              if (pauseB6 >= 240) pauseB6 = 0;
            }
            myGLCD.setColor (VGA_BLACK);
            myGLCD.fillRoundRect(112, 99, 208, 149);
            myGLCD.setColor (VGA_RED);
            if (i == 1)myGLCD.printNumI(pauseB1, CENTER, 99);
            if (i == 2)myGLCD.printNumI(pauseB2, CENTER, 99);
            if (i == 3)myGLCD.printNumI(pauseB3, CENTER, 99);
            if (i == 4)myGLCD.printNumI(pauseB4, CENTER, 99);
            if (i == 5)myGLCD.printNumI(pauseB5, CENTER, 99);
            if (i == 6)myGLCD.printNumI(pauseB6, CENTER, 99);

          }
          if (x > 145 && x < 185) {// "ок"
            waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
            Screen4 ();
          }
        }
      }
    }
    if (g == 3) {

      while (true)
      {
        if (myTouch.dataAvailable())
        {
          myTouch.read();
          x = myTouch.getX();
          y = myTouch.getY();
          if (y > 156 && y < 196) {
            if (x > 30 && x < 70) {// "-"
              waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
              if (i == 1) {
                chil--;
                if (chil >= 120) chil = 120;
              }
              if (i == 2) {
                timeB1--;
                if (timeB1 >= 240) timeB1 = 240;
              }
              if (i == 3) {
                timeB2--;
                if (timeB2 >= 240) timeB2 = 240;
              }
              if (i == 4) {
                timeB3--;
                if (timeB3 >= 240) timeB3 = 240;
              }
              if (i == 5) {
                timeB4--;
                if (timeB4 >= 240) timeB4 = 240;
              }
              if (i == 6) {
                timeB5--;
                if (timeB5 >= 240) timeB5 = 240;
              }
              if (i == 7) {
                timeB6--;
                if (timeB6 >= 240) timeB6 = 240;
              }
              myGLCD.setColor (VGA_BLACK);
              myGLCD.fillRoundRect(112, 99, 208, 149);
              myGLCD.setColor (VGA_RED);
              if (i == 1)myGLCD.printNumI(chil, CENTER, 99);
              if (i == 2)myGLCD.printNumI(timeB1, CENTER, 99);
              if (i == 3)myGLCD.printNumI(timeB2, CENTER, 99);
              if (i == 4)myGLCD.printNumI(timeB3, CENTER, 99);
              if (i == 5)myGLCD.printNumI(timeB4, CENTER, 99);
              if (i == 6)myGLCD.printNumI(timeB5, CENTER, 99);
              if (i == 7)myGLCD.printNumI(timeB6, CENTER, 99);
            }
            if (x > 250 && x < 290) {// "+"
              waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
              if (i == 1) {
                chil++;
                if (chil >= 120) chil = 0;
              }
              if (i == 2) {
                timeB1++;
                if (timeB1 >= 240) timeB1 = 0;
              }
              if (i == 3) {
                timeB2++;
                if (timeB2 >= 240) timeB2 = 0;
              }
              if (i == 4) {
                timeB3++;
                if (timeB3 >= 240) timeB3 = 0;
              }
              if (i == 5) {
                timeB4++;
                if (timeB4 >= 240) timeB4 = 0;
              }
              if (i == 6) {
                timeB5++;
                if (timeB5 >= 240) timeB5 = 0;
              }
              if (i == 7) {
                timeB6++;
                if (timeB6 >= 240) timeB6 = 0;
              }
              myGLCD.setColor (VGA_BLACK);
              myGLCD.fillRoundRect(112, 99, 208, 149);
              myGLCD.setColor (VGA_RED);
              if (i == 1)myGLCD.printNumI(chil, CENTER, 99);
              if (i == 2)myGLCD.printNumI(timeB1, CENTER, 99);
              if (i == 3)myGLCD.printNumI(timeB2, CENTER, 99);
              if (i == 4)myGLCD.printNumI(timeB3, CENTER, 99);
              if (i == 5)myGLCD.printNumI(timeB4, CENTER, 99);
              if (i == 6)myGLCD.printNumI(timeB5, CENTER, 99);
              if (i == 7)myGLCD.printNumI(timeB6, CENTER, 99);
            }
            if (x > 145 && x < 185) {// "ок"
              waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
              Screen4_1 ();
            }
          }
        }
      }
    }
  }
}

//_________________________________________________________________________________________________
void FWorkN (byte workN1) {
  myGLCD.setColor (VGA_RED);
  myGLCD.setBackColor (VGA_BLACK);
  myGLCD.setFont(SevenSegNumFont);
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (y > 156 && y < 196) {
        if (x > 30 && x < 70) {// "-"
          waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
          WorkN[workN1] = WorkN[workN1] - 1;
          if (WorkN[workN1] > 120)WorkN[workN1] = 120;
          myGLCD.setColor (VGA_BLACK);
          myGLCD.fillRoundRect(112, 99, 208, 149);
          myGLCD.setColor (VGA_RED);
          myGLCD.printNumI(WorkN[workN1], CENTER, 99);

        }
        if (x > 250 && x < 290) {// "+"
          waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
          WorkN[workN1] = WorkN[workN1] + 1;
          if (WorkN[workN1] > 120)WorkN[workN1] = 0;
          myGLCD.setColor (VGA_BLACK);
          myGLCD.fillRoundRect(112, 99, 208, 149);
          myGLCD.setColor (VGA_RED);
          myGLCD.printNumI(WorkN[workN1], CENTER, 99);
        }
        if (x > 145 && x < 185) {// "ок"
          waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
          setNasos ();
        }
      }
    }
  }
}
//_________________________________________________________________________________________________
void FPauseN (byte pauseN1) {
  myGLCD.setColor (VGA_RED);
  myGLCD.setBackColor (VGA_BLACK);
  myGLCD.setFont(SevenSegNumFont);
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      if (y > 156 && y < 196) {
        if (x > 30 && x < 70) {// "-"
          waitForItButton(30, 156, 70, 196);//Делаем окантовку кнопки
          PauseN[pauseN1] = PauseN[pauseN1] - RelePause;
          if (PauseN[pauseN1] > 120)PauseN[pauseN1] = 120;
          myGLCD.setColor (VGA_BLACK);
          myGLCD.fillRoundRect(112, 99, 208, 149);
          myGLCD.setColor (VGA_RED);
          myGLCD.printNumI(PauseN[pauseN1], CENTER, 99);
        }
        if (x > 250 && x < 290) {// "+"
          waitForItButton(250, 156, 290, 196);//Делаем окантовку кнопки
          PauseN[pauseN1] = PauseN[pauseN1] + RelePause;
          if (PauseN[pauseN1] > 120)PauseN[pauseN1] = 0;
          myGLCD.setColor (VGA_BLACK);
          myGLCD.fillRoundRect(112, 99, 208, 149);
          myGLCD.setColor (VGA_RED);
          myGLCD.printNumI(PauseN[pauseN1], CENTER, 99);
        }
        if (x > 145 && x < 185) {// "ок"
          waitForItButton(145, 156, 185, 196);//Делаем окантовку кнопки
          setNasos ();
        }
      }
    }
  }
}
//_________________________________________________________________________________________________


