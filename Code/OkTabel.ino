void OkTabel () {
  myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
  myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
  myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
  myGLCD.setColor (VGA_RED);
  myGLCD.setBackColor (VGA_BLACK);
  myGLCD.setFont(SevenSegNumFont);
  if (flagTabel == 1) {
    myGLCD.printNumI(termB1, CENTER, 99);
    SetScreen4 (1, 1); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 2) {
      if (termB2 == 0)termB2 = termB1;
      myGLCD.printNumI(termB2, CENTER, 99);
      SetScreen4 (1, 2); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 4) {
      if (termB3 == 0)termB3 = termB2;
      myGLCD.printNumI(termB3, CENTER, 99);
      SetScreen4 (1, 3); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 6) {
    if (termB4 == 0)termB4 = termB3;
    myGLCD.printNumI(termB4, CENTER, 99);
    SetScreen4 (1, 4); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 8) {
    if (termB5 == 0)termB5 = termB4;
    myGLCD.printNumI(termB5, CENTER, 99);
    SetScreen4 (1, 5); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 10) {
    if (termB6 == 0)termB6 = termB5;
    myGLCD.printNumI(termB6, CENTER, 99);
    SetScreen4 (1, 6); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 12) {
    if (termB7 == 0)termB7 = termB6;
    myGLCD.printNumI(termB7, CENTER, 99);
    SetScreen4 (1, 7); // 1 = termB: 2 = pauseB
  }
  //______________________________________________________________________
  if (flagTabel == 3) {
    myGLCD.printNumI(pauseB1, CENTER, 99);
    SetScreen4 (2, 1); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 5) {
    if (pauseB2 == 0)pauseB2 = pauseB1;
    myGLCD.printNumI(pauseB2, CENTER, 99);
    SetScreen4 (2, 2); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 7) {
    if (pauseB3 == 0)pauseB3 = pauseB2;
    myGLCD.printNumI(pauseB3, CENTER, 99);
    SetScreen4 (2, 3); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 9) {
    if (pauseB4 == 0)pauseB4 = pauseB3;
    myGLCD.printNumI(pauseB4, CENTER, 99);
    SetScreen4 (2, 4); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 11) {
    if (pauseB5 == 0)pauseB5 = pauseB4;
    myGLCD.printNumI(pauseB5, CENTER, 99);
    SetScreen4 (2, 5); // 1 = termB: 2 = pauseB
  }
  if (flagTabel == 13) {
    if (pauseB6 == 0)pauseB6 = pauseB5;
    myGLCD.printNumI(pauseB6, CENTER, 99);
    SetScreen4 (2, 6); // 1 = termB: 2 = pauseB
  }
}

void OkTabel1 () {
  myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
  myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
  myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
  myGLCD.setColor (VGA_RED);
  myGLCD.setBackColor (VGA_BLACK);
  myGLCD.setFont(SevenSegNumFont);
  if (flagTabel1 == 1) {
    myGLCD.printNumI(chil, CENTER, 99);
    SetScreen4 (3, 1); // 1 = termB: 2 = pauseB
  }
  if (flagTabel1 == 2) {
    myGLCD.printNumI(timeB1, CENTER, 99);
    SetScreen4 (3, 2); // 1 = termB: 2 = pauseB
  }
  if (flagTabel1 == 3) {
    myGLCD.printNumI(timeB2, CENTER, 99);
    SetScreen4 (3, 3); // 1 = termB: 2 = pauseB
  }
  if (flagTabel1 == 4) {

    myGLCD.printNumI(timeB3, CENTER, 99);
    SetScreen4 (3, 4); // 1 = termB: 2 = pauseB
  }
  if (flagTabel1 == 5) {

    myGLCD.printNumI(timeB4, CENTER, 99);
    SetScreen4 (3, 5); // 1 = termB: 2 = pauseB
  }
  if (flagTabel1 == 6) {

    myGLCD.printNumI(timeB5, CENTER, 99);
    SetScreen4 (3, 6); // 1 = termB: 2 = pauseB
  }
  if (flagTabel1 == 7) {

    myGLCD.printNumI(timeB6, CENTER, 99);
    SetScreen4 (3, 7); // 1 = termB: 2 = pauseB
  }

}

void OkTabel2 () {
  myGLCD.drawBitmap(30, 156, 40, 40, minus1, 1);// "-"
  myGLCD.drawBitmap(250, 156, 40, 40, Plus1, 1);// "+"
  myGLCD.drawBitmap(145, 156, 40, 40, ok1, 1);// "ok"
  myGLCD.setColor (VGA_RED);
  myGLCD.setBackColor (VGA_BLACK);
  myGLCD.setFont(SevenSegNumFont);
  if (flagTabelWN == 1) {
    myGLCD.printNumI(WorkN[0], CENTER, 99);
    FWorkN (0);
  }
  if (flagTabelWN == 2) {
    myGLCD.printNumI(WorkN[1], CENTER, 99);
    FWorkN (1);
  }
  if (flagTabelWN == 3) {
    myGLCD.printNumI(WorkN[2], CENTER, 99);
    FWorkN (2);
  }
  if (flagTabelWN == 4) {
    myGLCD.printNumI(WorkN[3], CENTER, 99);
    FWorkN (3);
  }
  if (flagTabelWN == 5) {
    myGLCD.printNumI(WorkN[4], CENTER, 99);
    FWorkN (4);
  }
  if (flagTabelWN == 6) {
    myGLCD.printNumI(WorkN[5], CENTER, 99);
    FWorkN (5);
  }
  if (flagTabelWN == 7) {
    myGLCD.printNumI(WorkN[6], CENTER, 99);
    FWorkN (6);
  }
  //______________________________________________________________________
  if (flagTabelWN == 8) {
    myGLCD.printNumI(PauseN[0], CENTER, 99);
    FPauseN (0);
  }
  if (flagTabelWN == 9) {
    myGLCD.printNumI(PauseN[1], CENTER, 99);
    FPauseN (1);
  }
  if (flagTabelWN == 10) {
    myGLCD.printNumI(PauseN[2], CENTER, 99);
    FPauseN (2);
  }
  if (flagTabelWN == 11) {
    myGLCD.printNumI(PauseN[3], CENTER, 99);
    FPauseN (3);
  }
  if (flagTabelWN == 12) {
    myGLCD.printNumI(PauseN[4], CENTER, 99);
    FPauseN (4);
  }
  if (flagTabelWN == 13) {
    myGLCD.printNumI(PauseN[5], CENTER, 99);
    FPauseN (5);
  }
  if (flagTabelWN == 14) {
    myGLCD.printNumI(PauseN[6], CENTER, 99);
    FPauseN (6);
  }
}



