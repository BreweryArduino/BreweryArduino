
void Screen0 () {// Главное меню

  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(15, 95, 50, 50, Set2, 1);
  myGLCD.drawBitmap(75, 95, 50, 50, Hot2, 1);

  myGLCD.drawBitmap(195, 95, 50, 50, beer, 1);
  myGLCD.drawBitmap(255, 95, 50, 50, sd, 1);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(BigRusFont);
  myGLCD.setColor(VGA_LIME);
  myGLCD.print("BreweryArduino", 28, 200);
  myGLCD.setFont(SmallRusFont);
  myGLCD.setColor(VGA_AQUA);
  myGLCD.print("Touch", 252, 200);
  myGLCD.setColor(VGA_LIME);
  myGLCD.print("\x82""e""\xA1""e""\xA2""\xA4""\xAC""e""\x97"" ""H""\x9D""\x9F""o""\xA0""a""\x9E"" 2016-2017""\x98"".", CENTER, 220);
  // myGLCD.printNumI(-1, CENTER, 180);
  Touch0 ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void Screen1 () {//Меню установки
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, Set2, 1);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRect(15, 95, 65, 145);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("SYS", 18, 114);
  myGLCD.drawBitmap(75, 95, 50, 50, Hot2, 1);
  myGLCD.drawBitmap(135, 95, 50, 50, nasos, 1);
  myGLCD.drawBitmap(195, 95, 50, 50, beer, 1);
  myGLCD.drawBitmap(255, 95, 50, 50, sd, 1);
  myGLCD.drawBitmap(32, 20, 64, 30, LeftButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("Hac""\xA4""po""\x9E""\x9F""a ""\x9F""o""\xA1""\xA3""o""\xA2""e""\xA2""\xA4""o""\x97"" ""c""\x9D""c""\xA4""e""\xA1""\xAB", CENTER, 70);
  Touch1 ();

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void Screen2() { //Меню управления тэном
  ON_OFF = 0;
  out = 70;
  fT = 1;
  fR = 1;
  OffNasos (0);
  innverN = false;
  ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, Hot2, 1);
  myGLCD.drawBitmap(32, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(200, 10, 50, 50, nasos, 1);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(SmallRusFont);
  myGLCD.setColor(VGA_LIME);
  myGLCD.print("BK""\x88", 213, 31);
  myGLCD.drawBitmap(15, 105, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(241, 105, 64, 30, RightButton1, 1);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRoundRect(260, 10, 310, 60);
  myGLCD.setColor(VGA_BLACK);
  //myGLCD.setFont(SmallRusFont);
  myGLCD.print("Pe""\x9B""\x9D""\xA1", 265, 18);
  byte p;
  if (nasosWH < 10) {
    p = 16;
  }
  else {
    if (nasosWH < 100) p = 8;
  }
  if (nasosWH >= 100) p = 0;
  myGLCD.printNumI(nasosWH, p + 257, 35);
  myGLCD.print("/", 281, 35);
  myGLCD.printNumI(nasosPH, 286, 35);

  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setColor(VGA_WHITE);
  //myGLCD.fillRoundRect(15, 180, 94, 230);
  myGLCD.fillRoundRect(226, 180, 305, 230);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("T""\x93""H", 128, 197);//ТЭН
  myGLCD.print("BK""\x88", 242, 197);//ВКЛ

  myGLCD.setFont(SmallRusFont);
  myGLCD.setColor(VGA_RED);
  myGLCD.print("Mo""\xA9""\xA2""oc""\xA4""\xAC"" %", 120, 150);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.printNumI(out, 128, 95);
  Touch2 ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void Screen2_1 () {//Меню управления тэном возврат с выбора режима работы насоса

  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, Hot2, 1);
  myGLCD.drawBitmap(32, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(200, 10, 50, 50, nasos, 1);

  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(SmallRusFont);
  if (digitalRead(NasosPin) == ReleOn) {

    myGLCD.setColor(VGA_RED);
    myGLCD.print("B""\x91""K""\x88", 209, 31);
  }
  if (digitalRead(NasosPin) == ReleOff) {
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("BK""\x88", 213, 31);
  }
  myGLCD.drawBitmap(15, 105, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(241, 105, 64, 30, RightButton1, 1);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRoundRect(260, 10, 310, 60);
  myGLCD.setColor(VGA_BLACK);
  //myGLCD.setFont(SmallRusFont);
  myGLCD.print("Pe""\x9B""\x9D""\xA1", 265, 18);
  byte p;
  if (nasosWH < 10) {
    p = 16;
  }
  else {
    if (nasosWH < 100) p = 8;
  }
  if (nasosWH >= 100) p = 0;
  myGLCD.printNumI(nasosWH, p + 257, 35);
  myGLCD.print("/", 281, 35);
  myGLCD.printNumI(nasosPH, 286, 35);

  myGLCD.setBackColor(VGA_BLACK);

  //

  myGLCD.setColor(VGA_LIME);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("T""\x93""H", 128, 197);//ТЭН
  if (ON_OFF == 0) {
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(226, 180, 305, 230);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("BK""\x88", 242, 197);//ВКЛ
    myGLCD.setColor(VGA_BLACK);
    myGLCD.fillRoundRect(15, 180, 94, 230);

  }
  if (ON_OFF == 1) {
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(15, 180, 94, 230);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("B""\x91""K""\x88", 23, 197);//ВЫКЛ
    myGLCD.setColor(VGA_BLACK);
    myGLCD.fillRoundRect(226, 180, 305, 230);
  }

  myGLCD.setFont(SmallRusFont);
  myGLCD.setColor(VGA_RED);
  myGLCD.print("Mo""\xA9""\xA2""oc""\xA4""\xAC"" %", 120, 150);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.printNumI(out, 128, 95);
  Touch2 ();
}
/*void Screen3 () {//
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, beer, 1);
  myGLCD.drawBitmap(32, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(188, 20, 64, 30, RightButton1, 1);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("H", 152, 27);
  Touch3 ();
  }
*/
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void Screen4 () {//Меню варки пива 1этап
  BeerStep = 1;//Переменная для хранения этапа варки
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, beer, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(188, 20, 64, 30, RightButton1, 1);
  myGLCD.drawBitmap(279, 171, 30, 64, downButton1, 1);
  myGLCD.drawBitmap(274, 126, 40, 40, ok1, 1);
  myGLCD.drawBitmap(279, 57, 30, 64, UpButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  //myGLCD.print("\x93""\xA4""a""\xA3", 236, 20);// этап
  myGLCD.setFont(BigRusFont);
  myGLCD.print("\x85""a""\xA4""\x9D""pa""\xA2""\x9D""e", CENTER, 60);// затирание
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("Ha""\x98""pe""\xA4""\xAC", 18, 97);//Нагреть
  for (byte i = 1; i <= 5; i++) {
    myGLCD.print("\x89""ay""\x9C""a", 18, 97 + (i * 20)); //Пауза
    myGLCD.printNumI(i, 80, 97 + (i * 20));
    myGLCD.setColor(VGA_LIME);
  }
  myGLCD.print("Me""\xA8""ay""\xA4", 18, 217);//Мешаут

  myGLCD.print("Te""\xA1""\xA3""epa""\xA4""ypa", 120, 81);
  myGLCD.print("Bpe""\xA1""\xAF", 220, 81);
  myGLCD.setColor(VGA_AQUA);
  myGLCD.drawLine (114, 81, 114, 234);
  myGLCD.drawLine (214, 81, 214, 234);
  myGLCD.drawLine (266, 81, 266, 234);
  for (byte i = 0; i <= 7; i++) {
    myGLCD.setColor(VGA_AQUA);
    myGLCD.drawLine (15, 94 + (i * 20), 266, 94 + (i * 20));
  }
  myGLCD.print("-", 240, 99);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.printNumI(pauseB1, 240, 119);
  myGLCD.printNumI(pauseB2, 240, 139);
  myGLCD.printNumI(pauseB3, 240, 159);
  myGLCD.printNumI(pauseB4, 240, 179);
  myGLCD.printNumI(pauseB5, 240, 199);
  myGLCD.printNumI(pauseB6, 240, 219);

  myGLCD.printNumI (termB1, 164, 99);
  myGLCD.printNumI (termB2, 164, 119);
  myGLCD.printNumI (termB3, 164, 139);
  myGLCD.printNumI (termB4, 164, 159);
  myGLCD.printNumI (termB5, 164, 179);
  myGLCD.printNumI (termB6, 164, 199);
  myGLCD.printNumI (termB7, 164, 219);
  UpDown ();
  Touch4 ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void Screen4_1 () {
  BeerStep = 2;//Переменная для хранения этапа варки
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, beer, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(188, 20, 64, 30, RightButton1, 1);
  myGLCD.drawBitmap(279, 171, 30, 64, downButton1, 1);
  myGLCD.drawBitmap(274, 126, 40, 40, ok1, 1);
  myGLCD.drawBitmap(279, 57, 30, 64, UpButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);

  myGLCD.setFont(BigRusFont);

  myGLCD.print("K""\x9D""\xA3""\xAF""\xA7""e""\xA2""\x9D""e", CENTER, 60);// Кипячение

  myGLCD.setFont(SmallRusFont);
  myGLCD.print("K""\x9D""\xA3""\xAF""\xA4""\x9D""\xA4""\xAC", 18, 97);//Кипятить
  for (byte i = 1; i <= 5; i++) {
    myGLCD.print("X""\xA1""e""\xA0""\xAC", 18, 97 + (i * 20)); //Хмель
    myGLCD.printNumI(i, 80, 97 + (i * 20));
  }
  myGLCD.print("Ox""\xA0""a""\x99""\x9D""\xA4""\xAC", 18, 217);//Охладить
  myGLCD.print("Te""\xA1""\xA3""epa""\xA4""ypa", 120, 81);
  myGLCD.print("Bpe""\xA1""\xAF", 220, 81);
  for (byte i = 0; i <= 7; i++) {
    myGLCD.setColor(VGA_AQUA);
    myGLCD.drawLine (15, 94 + (i * 20), 266, 94 + (i * 20));
  }
  myGLCD.drawLine (114, 81, 114, 234);
  myGLCD.drawLine (214, 81, 214, 234);
  myGLCD.drawLine (266, 81, 266, 234);

  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.printNumI(chil, 164, 219);
  myGLCD.printNumI(timeB1, 240, 99);
  myGLCD.printNumI(timeB2, 240, 119);
  myGLCD.printNumI(timeB3, 240, 139);
  myGLCD.printNumI(timeB4, 240, 159);
  myGLCD.printNumI(timeB5, 240, 179);
  myGLCD.printNumI(timeB6, 240, 199);
  myGLCD.print("-", 240, 217);
  for (byte i = 0; i <= 5; i++) {
    myGLCD.print("-", 164, 99 + (i * 20));

  }
  UpDown1 ();
  Touch4_1 ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void Screen4_2 () {
  BeerStep = 3;//Переменная для хранения этапа варки
  int w;
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, sd, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(188, 20, 64, 30, RightButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("Pe""\xA6""e""\xA3""\xA4"":", 27, 60);// Рецепт
  myGLCD.setFont(SmallRusFont);
  myGLCD.print (NameBeer, 138, 64);

  w = 80;
  if (termB1 > 0) {
    myGLCD.print("Ha""\x98""pe""\xA4""\xAC"" ""\x97""o""\x99""y"" ""\x99""o", 7, w); //нагреть воду до
    myGLCD.printNumI(termB1, 136, w);
    int i;
    if (termB1 < 10) i = 0;
    if (termB1 > 9 && termB1 < 100) i = 8;
    if (termB1 > 99)  i = 16;
    myGLCD.print("\x7F""C", 144 + i, w);
    myGLCD.print(", ", 160 + i, w);
    myGLCD.print("\x9C""ac""\xAB""\xA3""a""\xA4""\xAC"" ""co""\xA0""o""\x99"".", 176 + i, w); //засыпать солод
    w = w + 12;
  }
  if (termB2 > 0 && pauseB1 > 0) {
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, w); //выдержать при
    myGLCD.printNumI(termB2, 119, w);
    int i;
    if (termB2 < 10) i = 0;
    if (termB2 > 9 && termB2 < 100) i = 8;
    if (termB2 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, w);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, w); //в течении
    int q;
    if (pauseB1 < 10) q = 0;
    if (pauseB1 > 9 && pauseB1 < 100) q = 8;
    if (pauseB1 > 99)  q = 16;
    myGLCD.printNumI(pauseB1, 231 + i, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, w); //минут
    w = w + 12;
  }
  if (termB3 > 0 && pauseB2 > 0) {
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, w); //выдержать при
    myGLCD.printNumI(termB3, 119, w);
    int i;
    if (termB3 < 10) i = 0;
    if (termB3 > 9 && termB3 < 100) i = 8;
    if (termB3 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, w);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, w); //в течении
    int q;
    if (pauseB2 < 10) q = 0;
    if (pauseB2 > 9 && pauseB2 < 100) q = 8;
    if (pauseB2 > 99)  q = 16;
    myGLCD.printNumI(pauseB2, 231 + i, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, w); //минут
    w = w + 12;
  }
  if (termB4 > 0 && pauseB3 > 0) {
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, w); //выдержать при
    myGLCD.printNumI(termB4, 119, w);
    int i;
    if (termB4 < 10) i = 0;
    if (termB4 > 9 && termB4 < 100) i = 8;
    if (termB4 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, w);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, w); //в течении
    int q;
    if (pauseB3 < 10) q = 0;
    if (pauseB3 > 9 && pauseB3 < 100) q = 8;
    if (pauseB3 > 99)  q = 16;
    myGLCD.printNumI(pauseB3, 231 + i, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, w); //минут
    w = w + 12;
  }
  if (termB5 > 0 && pauseB4 > 0) {
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, w); //выдержать при
    myGLCD.printNumI(termB5, 119, w);
    int i;
    if (termB5 < 10) i = 0;
    if (termB5 > 9 && termB5 < 100) i = 8;
    if (termB5 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, w);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, w); //в течении
    int q;
    if (pauseB4 < 10) q = 0;
    if (pauseB4 > 9 && pauseB4 < 100) q = 8;
    if (pauseB4 > 99)  q = 16;
    myGLCD.printNumI(pauseB4, 231 + i, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, w); //минут
    w = w + 12;
  }
  if (termB6 > 0 && pauseB5 > 0) {
    myGLCD.print("B""\xAB""\x99""ep""\x9B""a""\xA4""\xAC"" ""\xA3""p""\x9D", 7, w); //выдержать при
    myGLCD.printNumI(termB6, 119, w);
    int i;
    if (termB6 < 10) i = 0;
    if (termB6 > 9 && termB6 < 100) i = 8;
    if (termB6 > 99)  i = 16;
    myGLCD.print("\x7F""C", 127 + i, w);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 151 + i, w); //в течении
    int q;
    if (pauseB5 < 10) q = 0;
    if (pauseB5 > 9 && pauseB5 < 100) q = 8;
    if (pauseB5 > 99)  q = 16;
    myGLCD.printNumI(pauseB5, 231 + i, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 247 + i + q, w); //минут
    w = w + 12;
  }
  if (termB7 > 0 && pauseB6 > 0) {
    myGLCD.print("Me""\xA8""ay""\xA4"" ""\xA3""p""\x9D", 7, w); //мешаут при
    myGLCD.printNumI(termB7, 95, w);
    int i;
    if (termB7 < 10) i = 0;
    if (termB7 > 9 && termB7 < 100) i = 8;
    if (termB7 > 99)  i = 16;
    myGLCD.print("\x7F""C", 103 + i, w);
    myGLCD.print("\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" " , 127 + i, w); //в течении
    int q;
    if (pauseB6 < 10) q = 0;
    if (pauseB6 > 9 && pauseB5 < 100) q = 8;
    if (pauseB6 > 99)  q = 16;
    myGLCD.printNumI(pauseB6, 207 + i, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 223 + i + q, w); //минут
    w = w + 12;
  }

  if (timeB1 > 0) {
    myGLCD.print("K""\x9D""\xA3""\xAF""\xA4""\x9D""\xA4""\xAC"" ""\x97"" ""\xA4""e""\xA7""e""\xA2""\x9D""e"" ", 7, w); //кипятить в течении
    int q;
    if (timeB1 < 10) q = 0;
    if (timeB1 > 9 && timeB1 < 100) q = 8;
    if (timeB1 > 99)  q = 16;
    myGLCD.printNumI(timeB1, 160, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 176 + q, w); //минут
    w = w + 12;
  }
  if (timeB2 > 0) {
    myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC", 7, w); //Добавить хмель (14)
    myGLCD.printNumI(1, 127, w); //
    myGLCD.print("\xA7""epe""\x9C", 143, w); //через (5)
    int q;
    if (timeB2 < 10) q = 0;
    if (timeB2 > 9 && timeB2 < 100) q = 8;
    if (timeB2 > 99)  q = 16;
    myGLCD.printNumI(timeB2, 191, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 207 + q, w); //минут
    w = w + 12;
  }
  if (timeB3 > 0) {
    myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC", 7, w); //Добавить хмель (14)
    myGLCD.printNumI(2, 127, w); //
    myGLCD.print("\xA7""epe""\x9C", 143, w); //через (5)
    int q;
    if (timeB3 < 10) q = 0;
    if (timeB3 > 9 && timeB3 < 100) q = 8;
    if (timeB3 > 99)  q = 16;
    myGLCD.printNumI(timeB3, 191, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 207 + q, w); //минут
    w = w + 12;
  }
  if (timeB4 > 0) {
    myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC", 7, w); //Добавить хмель (14)
    myGLCD.printNumI(3, 127, w); //
    myGLCD.print("\xA7""epe""\x9C", 143, w); //через (5)
    int q;
    if (timeB4 < 10) q = 0;
    if (timeB4 > 9 && timeB4 < 100) q = 8;
    if (timeB4 > 99)  q = 16;
    myGLCD.printNumI(timeB4, 191, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 207 + q, w); //минут
    w = w + 12;
  }
  if (timeB5 > 0) {
    myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC", 7, w); //Добавить хмель (14)
    myGLCD.printNumI(4, 127, w); //
    myGLCD.print("\xA7""epe""\x9C", 143, w); //через (5)
    int q;
    if (timeB5 < 10) q = 0;
    if (timeB5 > 9 && timeB5 < 100) q = 8;
    if (timeB5 > 99)  q = 16;
    myGLCD.printNumI(timeB5, 191, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 207 + q, w); //минут
    w = w + 12;
  }
  if (timeB6 > 0) {
    myGLCD.print("\x82""o""\x96""a""\x97""\x9D""\xA4""\xAC"" ""x""\xA1""e""\xA0""\xAC", 7, w); //Добавить хмель (14)
    myGLCD.printNumI(5, 127, w); //
    myGLCD.print("\xA7""epe""\x9C", 143, w); //через (5)
    int q;
    if (timeB6 < 10) q = 0;
    if (timeB6 > 9 && timeB6 < 100) q = 8;
    if (timeB6 > 99)  q = 16;
    myGLCD.printNumI(timeB6, 191, w);
    myGLCD.print("\xA1""\x9D""\xA2""y""\xA4", 207 + q, w); //минут
    w = w + 12;
  }
  Touch4_2 ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void Screen5 () {//Меню чтения рецептов
  ScreenDir = 1;

  int BufSumDir = 1;
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, sd, 1);
  myGLCD.drawBitmap(32, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(279, 165, 30, 64, downButton1, 1);
  // myGLCD.drawBitmap(274, 126, 40, 40, ok1, 1);
  myGLCD.drawBitmap(279, 57, 30, 64, UpButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("PE""\x8C""E""\x89""TOB: ", 210, 25);
  SDReadDir ();
  myGLCD.printNumI(SumDir, 280, 25);
  myGLCD.setFont(BigRusFont);


  for (byte i = 0 ; i < 5; i++) {
    myGLCD.printNumI(BufSumDir + i, 5, 75 + (i * 32));
    myGLCD.print(NameDir[i], 53, 75 + (i * 32));
  }
  Touch5 ();
}
void Screen5_2 () { //Сохранение рецептов
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, sd, 1);
  myGLCD.drawBitmap(32, 20, 64, 30, LeftButton1, 1);
  SDBeerName ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void ScreenSys () {
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);// назад
  myGLCD.drawBitmap(15, 10, 50, 50, Set2, 1);
  myGLCD.drawBitmap(15, 95, 50, 50, clock1, 1);
  myGLCD.drawBitmap(135, 95, 50, 50, nasos, 1);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRect(75, 95, 125, 145);
  myGLCD.fillRect(143, 10, 193, 60);
  myGLCD.fillRect(195, 95, 245, 145);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("REC", 77, 114);
  myGLCD.print("REL", 137, 114);
  myGLCD.print("T""\x7F""C", 197, 114);
  myGLCD.print("SYS", 145, 28);
  TouchSys ();

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void ScreenREC () {
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);// назад
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRect(143, 10, 193, 60);
  myGLCD.fillRect(15, 10, 65, 60);
  myGLCD.fillRect(15, 95, 130, 145);
  myGLCD.fillRect(150, 95, 280, 145);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("REC", 145, 28);
  myGLCD.print("SYS", 17, 28);
  myGLCD.print("Co""\x9C""\x99""a""\xA4""\xAC", 16, 105);//Создать
  myGLCD.print("o""\x96""pa""\x9C", 32, 125);//образ
  myGLCD.print("O""\x96""\xA2""o""\x97""\x9D""\xA4""\xAC", 151, 105);//Обновить
  myGLCD.print("c""\x9D""c""\xA4""e""\xA1""y", 155, 125);//систему
  TouchREC ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void ScreenSetTime () {
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.fillRect(15, 10, 65, 60);
  myGLCD.drawBitmap(15, 10, 50, 50, Set2, 1);
  myGLCD.drawBitmap(135, 10, 50, 50, clock1, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);// назад
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("Bpe""\xA1""\xAF", CENTER, 75);
  myGLCD.print("\x82""a""\xA4""a", CENTER, 125);
  TouchSetTime ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void SetRele () {
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, nasos, 1);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRect(15, 10, 65, 60);
  myGLCD.fillRoundRect(16 , 80, 84 , 140);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("SYS", 17, 28);
  myGLCD.print("REL", 135, 28);
  if (ReleOn == LOW) myGLCD.print ("LOW", 25, 102);
  if (ReleOn == HIGH) myGLCD.print ("HIGH", 18, 102);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.print ("-""\x86""\xA2""\x97""ep""\xA4""\x9D""po""\x97""a""\xA4""\xAC"" ""pe""\xA0""e", 86, 86);//Инвертировать реле
  myGLCD.print (" ""pe""\xA0""e", 86, 108);//Инвертировать реле
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);// назад
  TouchRele ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void setTerM () {
  myGLCD.fillScr(VGA_BLACK);

  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);// назад
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRect(135, 10, 185, 60);
  myGLCD.fillRect(15, 10, 65, 60);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setFont(BigRusFont);
  myGLCD.print("SYS", 17, 28);
  myGLCD.print("T""\x7F""C", 135, 28);
  myGLCD.drawBitmap(15, 85, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(241, 85, 64, 30, RightButton1, 1);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setColor(VGA_BLUE);
  myGLCD.print("T1", CENTER, 69);
  TochTerM ();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void setHot () {
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(15, 10, 50, 50, Set2, 1);
  myGLCD.drawBitmap(135, 10, 50, 50, Hot2, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("Hac""\xA4""po""\x9E""\x9F""a"" ""\x89""\x86"" ""pe""\x9B""\x9D""\xA1""a", 10, 65);// Настройка ПИ режима

  //ten.lpwm(t_pwm, 0);//медленный ШИМ на тен
  ON_OFF = 0;
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.drawLine(114, 95, 114, 158);
  myGLCD.drawLine(226, 95, 226, 158);
  myGLCD.fillRoundRect(226, 180, 305, 230);
  myGLCD.setFont(BigRusFont);
  myGLCD.setColor(VGA_LIME);
  myGLCD.print("BK""\x88", 242, 197);//ВКЛ
  myGLCD.setFont(SmallRusFont);
  //myGLCD.setColor(VGA_RED);
  //myGLCD.fillRoundRect(116, 200, 203, 230);
  //myGLCD.setColor(VGA_LIME);
  //myGLCD.print("Coxpa""\xA2""\x9D""\xA4""\xAC", CENTER, 208);//Сохранить(9)
  myGLCD.print("Te""\xA1""\xA3""epa""\xA4""ypa""\x7F""C", 210, 65);
  myGLCD.setColor(VGA_RED);
  byte a;
  if (kP <= 9 || kP == 0)a = 16;
  if (kP <= 99)a = 32;
  if (kP >= 100)a = 48;
  myGLCD.print("kP", 10 + a, 150);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.printNumI(kP, 10, 95);

  if (kI <= 9 || kI == 0)a = 0;
  if (kI <= 99)a = 32;
  if (kI >= 100)a = 48;
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("kI", 122 + a, 150);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.printNumI(kI, 122, 95);

  if (TempCSET <= 9 || TempCSET == 0)a = 8;
  if (TempCSET <= 99)a = 32;
  if (TempCSET >= 100)a = 48;
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("\x7F""C", 234 + a, 150);
  myGLCD.setFont(SevenSegNumFont);
  myGLCD.printNumI(TempCSET, 234, 95);
  TouchHot ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void setNasos () {//________________________________________________________Первая страница установки режима работы насоса
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(15, 10, 50, 50, Set2, 1);
  myGLCD.drawBitmap(135, 10, 50, 50, nasos, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(188, 20, 64, 30, RightButton1, 1);
  myGLCD.drawBitmap(279, 171, 30, 64, downButton1, 1);
  myGLCD.drawBitmap(274, 126, 40, 40, ok1, 1);
  myGLCD.drawBitmap(279, 57, 30, 64, UpButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);

  myGLCD.setFont(SmallRusFont);

  myGLCD.print("Pe""\x9B""\x9D""\xA1"" ""pa""\x96""o""\xA4""\xAB"" ""\xA2""acoca", CENTER, 60);// Режим работы насоса


  for (byte i = 0; i <= 6; i++) {
    myGLCD.print("Pe""\x9B""\x9D""\xA1", 18, 97 + (i * 20)); //Режим
    myGLCD.printNumI(i, 80, 97 + (i * 20));
  }

  myGLCD.print("Pa""\x96""o""\xA4""a""/""\xA1", 120, 81);
  myGLCD.print("\x89""ay""\x9C""a/c", 200, 81);
  for (byte i = 0; i <= 7; i++) {
    myGLCD.setColor(VGA_AQUA);
    myGLCD.drawLine (15, 94 + (i * 20), 266, 94 + (i * 20));
  }
  myGLCD.drawLine (114, 81, 114, 234);
  myGLCD.drawLine (190, 81, 190, 234);
  myGLCD.drawLine (266, 81, 266, 234);
  myGLCD.setColor(VGA_LIME);
  for (byte i = 0; i <= 6; i++) {

    myGLCD.printNumI(WorkN[i], 144, 97 + (i * 20));
  }
  for (byte i = 0; i <= 6; i++) {

    myGLCD.printNumI(PauseN[i], 220, 97 + (i * 20));
  }
  UpDown2 ();
}

void setNasos_1 () {//________________________________________________________Вторая страница установки режима работы насоса
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, nasos, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("Hac""\xA4""po""\x9E""\x9F""a"" ""\xA2""acoca", CENTER, 60);// Настройки насоса
  myGLCD.print("Ma""\x9F""c""\x9D""\xA1""a""\xA0""\xAC""\xA2""a""\xAF"" ""pa""\x96""o""\xA7""a""\xAF", 82, 94);//Максимальная рабочая
  myGLCD.print("\xA4""e""\xA1""\xA3""epa""\xA4""ypa"" ""\xA2""acoca", 90, 106);//температура насоса
  myGLCD.print("Pe""\x9B""\x9D""\xA1"" ""\xA3""po""\x99""y""\x97""\x9F""\x9D"" ""\xA2""acoca""(""\x97"" ""ce""\x9F""y""\xA2""\x99""ax)", CENTER, 150);// Режим продувки насоса

  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRoundRect(16 , 80, 76 , 140);
  myGLCD.fillRoundRect(16 , 170, 76 , 230);
  myGLCD.fillRoundRect(130 , 170, 190 , 230);
  myGLCD.fillRoundRect(244 , 170, 304 , 230);
  myGLCD.fillRoundRect(244 , 80, 304 , 140);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setColor(VGA_RED);
  myGLCD.print("Pa""\x96""o""\xA4""a", 22, 173);//
  myGLCD.print("\x89""ay""\x9C""a", 140, 173);//
  myGLCD.print("Ko""\xA0""-""\x97""o", 250, 173);//
  myGLCD.print("\xA3""o""\x97""\xA4"".", 258, 219);//
  myGLCD.setFont(BigRusFont);
  byte p;
  if (maxTerpNW < 10) p = 0;
  if (maxTerpNW < 100 && maxTerpNW >= 10) p = 8;
  if (maxTerpNW >= 100) p = 16;
  myGLCD.printNumI (maxTerpNW, 38 - p, 102);
  if (airW < 10) p = 0;
  else {
    if (airW < 100) p = 8;
  }
  if (airW >= 100) p = 16;
  myGLCD.printNumI (airW, 38 - p, 196);
  if (airP < 10) p = 0;
  else {
    if (airP < 100) p = 8;
  }
  if (airP >= 100) p = 16;
  myGLCD.printNumI (airP, 152 - p, 196);
  if (rep < 10) p = 0;
  else {
    if (rep < 100) p = 8;
  }
  if (rep >= 100) p = 16;
  myGLCD.printNumI (rep, 266 - p, 196);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setFont(SmallRusFont);
  if (OnOffTerpNW == false)myGLCD.print ("B""\x91""K""\x88"".", 258, 106);
  if (OnOffTerpNW == true)myGLCD.print ("B""K""\x88"".", 262, 106);
  TochNasos_1 ();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void setBeer () {//________________________________________________________Первая страница настройки пивоварни
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(15, 10, 50, 50, Set2, 1);
  myGLCD.drawBitmap(135, 10, 50, 50, beer, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);
  myGLCD.drawBitmap(188, 20, 64, 30, RightButton1, 1);
  myGLCD.drawBitmap(279, 171, 30, 64, downButton1, 1);
  myGLCD.drawBitmap(274, 126, 40, 40, ok1, 1);
  myGLCD.drawBitmap(279, 57, 30, 64, UpButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  //myGLCD.print("\x93""\xA4""a""\xA3", 236, 20);// этап
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("Hac""\xA4""po""\x9E""\x9F""a"" ""\xA3""\x9D""\x97""o""\x97""ap""\xA2""\x9D", CENTER, 60);// Настройки пивоварни

  myGLCD.print("Ha""\x98""pe""\xA4""\xAC", 18, 97);//Нагреть
  for (byte i = 1; i <= 5; i++) {
    myGLCD.print("\x89""ay""\x9C""a", 18, 97 + (i * 20)); //Пауза
    myGLCD.printNumI(i, 80, 97 + (i * 20));
    myGLCD.setColor(VGA_LIME);
  }
  myGLCD.print("Me""\xA8""ay""\xA4", 18, 217);//Мешаут

  myGLCD.print("Pe""\x9B""\x9D""\xA1"" ""\xA2""acoca", 118, 81);
  myGLCD.print("C""\x9D""\x98""\xA2""a""\xA0", 218, 81);
  myGLCD.setColor(VGA_AQUA);
  myGLCD.drawLine (114, 81, 114, 234);
  myGLCD.drawLine (214, 81, 214, 234);
  myGLCD.drawLine (266, 81, 266, 234);
  for (byte i = 0; i <= 7; i++) {
    myGLCD.setColor(VGA_AQUA);
    myGLCD.drawLine (15, 94 + (i * 20), 266, 94 + (i * 20));
  }

  myGLCD.setColor(VGA_LIME);
  setBeerN1 ();
  UpDown3 ();
  TouchBeer ();
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void setBeer_1 () {//________________________________________________________Вторая страница настройки пивоварни
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(135, 10, 50, 50, beer, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("Hac""\xA4""po""\x9E""\x9F""a"" ""\xA3""\x9D""\x97""o""\x97""ap""\xA2""\x9D", CENTER, 60);// Настройки пивоварни
  myGLCD.print("Te""\xA1""\xA3""epa""\xA4""ypa"" ""\x9C""a""\x9F""\x9D""\xA3""a""\xA2""\x9D""\xAF"" ""cyc""\xA0""a", 90, 106);//Температура закипания сусла

  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRoundRect(16 , 80, 76 , 140);
  myGLCD.setBackColor(VGA_WHITE);
  myGLCD.setColor(VGA_RED);
  myGLCD.setFont(BigRusFont);
  byte p;
  if (termKIP < 100) p = 0;
  if (termKIP >= 100) p = 8;
  myGLCD.printNumI (termKIP, 30 - p, 102);
  TouchBeer_1 ();

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void setBeerN_1 (byte gg) {//________________________________________________________Страница выбора режима работы насоса

  myGLCD.fillScr(VGA_BLACK);
  for (byte i = 0 ; i < 4; i++) {
    myGLCD.setBackColor(VGA_WHITE);
    byte z = 0;
    byte p = 0;
    if (i > 0) z = 16 * i;
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(16 + (i * 60 + z), 50, 76 + (i * 60 + z), 110);
    myGLCD.setColor(VGA_BLACK);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("Pe""\x9B""\x9D""\xA1"" ", 20 + (i * 60 + z), 60);
    myGLCD.printNumI(i, 66 + (i * 60 + z), 60);
    if (WorkN[i] < 10) {
      p = 36;
    }
    else {
      if (WorkN[i] < 100) p = 28;
    }
    if (WorkN[i] >= 100) p = 20;
    myGLCD.printNumI(WorkN[i], p + (i * 60 + z), 88);
    myGLCD.print("/", 44 + (i * 60 + z), 88);
    myGLCD.printNumI(PauseN[i], 52 + (i * 60 + z), 88);

  }
  for (byte i = 0 ; i < 3; i++) {
    byte z = 0;
    byte p = 0;
    byte c = 4;
    if (i > 0) z = 16 * i;
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(16 + (i * 60 + z), 130, 76 + (i * 60 + z), 190);

    myGLCD.setColor(VGA_BLACK);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("Pe""\x9B""\x9D""\xA1"" ", 20 + (i * 60 + z), 140);
    myGLCD.printNumI(i + c, 66 + (i * 60 + z), 140);
    if (WorkN[i + c] < 10) {
      p = 36;
    }
    else {
      if (WorkN[i + c] < 100) p = 28;
    }
    if (WorkN[i + c] >= 100) p = 20;
    myGLCD.printNumI(WorkN[i + c], p + (i * 60 + z), 168);
    myGLCD.print("/", 44 + (i * 60 + z), 168);
    myGLCD.printNumI(PauseN[i + c], 52 + (i * 60 + z), 168);
  }
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRoundRect(244, 130, 304, 190);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setFont(BigRusFont);
  myGLCD.print(" - ", 250, 150); //266
  TouchsetBeerN_1 (gg);

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void setBeerM_1 () {//________________________________________________________Страница выбора мелодий
  myGLCD.fillScr(VGA_BLACK);
  for (byte i = 0 ; i < 3; i++) {
    myGLCD.setBackColor(VGA_WHITE);
    byte z = 0;
    byte p = 0;
    if (i > 0) z = 16 * i;
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(16 + (i * 60 + z), 50, 76 + (i * 60 + z), 110);
    myGLCD.setColor(VGA_BLACK);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("Me""\xA0""o""\x99""\x9D""\xAF", 20 + (i * 60 + z), 60);//Мелодия
    myGLCD.printNumI(i, 44 + (i * 60 + z), 88);
  }
  for (byte i = 0 ; i < 3; i++) {
    byte z = 0;
    byte p = 0;
    byte c = 4;
    if (i > 0) z = 16 * i;
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(16 + (i * 60 + z), 130, 76 + (i * 60 + z), 190);

    myGLCD.setColor(VGA_BLACK);
    myGLCD.setFont(SmallRusFont);
    myGLCD.print("C""\xA0""y""\xA8""a""\xA4""\xAC", 20 + (i * 60 + z), 150);
  }
  myGLCD.setColor(VGA_WHITE);
  myGLCD.fillRoundRect(244, 130, 304, 190);
  myGLCD.fillRoundRect(244, 50, 304, 110);
  myGLCD.setColor(VGA_BLACK);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("O""\xA4""\xA1""e""\xA2""a", 250, 76);
  myGLCD.setFont(BigRusFont);
  myGLCD.print(" - ", 250, 150);
  for ( byte i = 8; i <= 14; i++) {
    if (flagTabelB == i) {
      if (MelodiN[i - 8] == 0)waitForItButton1(16, 50, 76, 110);
      if (MelodiN[i - 8] == 1)waitForItButton1(92, 50, 152, 110);
      if (MelodiN[i - 8] == 2)waitForItButton1(168, 50, 228, 110);
      if (MelodiN[i - 8] == 7)waitForItButton1(244, 130, 304, 190);
    }
  }
  TouchsetBeerM_1 ();

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
void setSD () {
  myGLCD.fillScr(VGA_BLACK);
  myGLCD.drawBitmap(15, 10, 50, 50, Set2, 1);
  myGLCD.drawBitmap(135, 10, 50, 50, sd, 1);
  myGLCD.drawBitmap(68, 20, 64, 30, LeftButton1, 1);
  SdTouch = false;
  CardInfo ();
  TouchSD ();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
