
void UpDown () {

  if (flagTabel == 1) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(termB1, 164, 99);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(termB2, 164, 119);
    myGLCD.printNumI(pauseB6, 240, 219);
    Touch4 ();
  }
  if (flagTabel == 2) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(termB2, 164, 119);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(termB3, 164, 139);
    myGLCD.printNumI(termB1, 164, 99);
    Touch4 ();
  }
  if (flagTabel == 3) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(termB3, 164, 139);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(termB2, 164, 119);
    myGLCD.printNumI(termB4, 164, 159);
    Touch4 ();
  }
  if (flagTabel == 4) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(termB4, 164, 159);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(termB3, 164, 139);
    myGLCD.printNumI(termB5, 164, 179);
    Touch4 ();
  }
  if (flagTabel == 5) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(termB5, 164, 179);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(termB4, 164, 159);
    myGLCD.printNumI(termB6, 164, 199);
    Touch4 ();
  }
  if (flagTabel == 6) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(termB6, 164, 199);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(termB5, 164, 179);
    myGLCD.printNumI(termB7, 164, 219);
    Touch4 ();
  }
  if (flagTabel == 7) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(termB7, 164, 219);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(termB6, 164, 199);
    myGLCD.printNumI(pauseB1, 240, 119);
    Touch4 ();
  }
  if (flagTabel == 8) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(pauseB1, 240, 119);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(termB7, 164, 219);
    myGLCD.printNumI(pauseB2, 240, 139);
    Touch4 ();
  }
  if (flagTabel == 9) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(pauseB2, 240, 139);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(pauseB1, 240, 119);
    myGLCD.printNumI(pauseB3, 240, 159);
    Touch4 ();
  }
  if (flagTabel == 10) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(pauseB3, 240, 159);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(pauseB2, 240, 139);
    myGLCD.printNumI(pauseB4, 240, 179);
    Touch4 ();
  }
  if (flagTabel == 11) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(pauseB4, 240, 179);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(pauseB3, 240, 159);
    myGLCD.printNumI(pauseB5, 240, 199);
    Touch4 ();
  }
  if (flagTabel == 12) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(pauseB5, 240, 199);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(pauseB4, 240, 179);
    myGLCD.printNumI(pauseB6, 240, 219);
    Touch4 ();
  }
  if (flagTabel == 13) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(pauseB6, 240, 219);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(pauseB5, 240, 199);
    myGLCD.printNumI(termB1, 164, 99);
    Touch4 ();
  }
}


void UpDown1 () {

  if (flagTabel1 == 1) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(chil, 164, 219);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(timeB6, 240, 199);
    myGLCD.printNumI(timeB1, 240, 99);
    Touch4_1 ();
  }
  if (flagTabel1 == 2) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(timeB1, 240, 99);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(chil, 164, 219);
    myGLCD.printNumI(timeB2, 240, 119);
    Touch4_1 ();
  }
  if (flagTabel1 == 3) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(timeB2, 240, 119);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(timeB1, 240, 99);
    myGLCD.printNumI(timeB3, 240, 139);
    Touch4_1 ();
  }
  if (flagTabel1 == 4) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(timeB3, 240, 139);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(timeB2, 240, 119);
    myGLCD.printNumI(timeB4, 240, 159);
    Touch4_1 ();
  }
  if (flagTabel1 == 5) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(timeB4, 240, 159);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(timeB3, 240, 139);
    myGLCD.printNumI(timeB5, 240, 179);
    Touch4_1 ();
  }
  if (flagTabel1 == 6) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(timeB5, 240, 179);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(timeB4, 240, 159);
    myGLCD.printNumI(timeB6, 240, 199);
    Touch4_1 ();
  }
  if (flagTabel1 == 7) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(timeB6, 240, 199);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(timeB5, 240, 179);
    myGLCD.printNumI(chil, 164, 219);
    Touch4_1 ();
  }
}


void UpDown2 () {

  if (flagTabelWN == 1) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(WorkN[0], 144, 97);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(WorkN[1], 144, 117);
    myGLCD.printNumI(PauseN[6], 220, 217);
    TouchNasos ();
  }
  if (flagTabelWN == 2) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(WorkN[1], 144, 117);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(WorkN[2], 144, 137);
    myGLCD.printNumI(WorkN[0], 144, 97);
    TouchNasos ();
  }
  if (flagTabelWN == 3) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(WorkN[2], 144, 137);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(WorkN[1], 144, 117);
    myGLCD.printNumI(WorkN[3], 144, 157);
    TouchNasos ();
  }
  if (flagTabelWN == 4) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(WorkN[3], 144, 157);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(WorkN[2], 144, 137);
    myGLCD.printNumI(WorkN[4], 144, 177);
    TouchNasos ();
  }
  if (flagTabelWN == 5) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(WorkN[4], 144, 177);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(WorkN[3], 144, 157);
    myGLCD.printNumI(WorkN[5], 144, 197);
    TouchNasos ();
  }
  if (flagTabelWN == 6) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(WorkN[5], 144, 197);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(WorkN[4], 144, 177);
    myGLCD.printNumI(WorkN[6], 144, 217);
    TouchNasos ();
  }
  if (flagTabelWN == 7) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(WorkN[6], 144, 217);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(WorkN[5], 144, 197);
    myGLCD.printNumI(PauseN[0], 220, 97);
    TouchNasos ();
  }
  if (flagTabelWN == 8) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(PauseN[0], 220, 97);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(WorkN[6], 144, 217);
    myGLCD.printNumI(PauseN[1], 220, 117);
    TouchNasos ();
  }
  if (flagTabelWN == 9) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(PauseN[1], 220, 117);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(PauseN[0], 220, 97);
    myGLCD.printNumI(PauseN[2], 220, 137);
    TouchNasos ();
  }
  if (flagTabelWN == 10) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(PauseN[2], 220, 137);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(PauseN[1], 220, 117);
    myGLCD.printNumI(PauseN[3], 220, 157);
    TouchNasos ();
  }
  if (flagTabelWN == 11) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(PauseN[3], 220, 157);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(PauseN[2], 220, 137);
    myGLCD.printNumI(PauseN[4], 220, 177);
    TouchNasos ();
  }
  if (flagTabelWN == 12) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(PauseN[4], 220, 177);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(PauseN[3], 220, 157);
    myGLCD.printNumI(PauseN[5], 220, 197);
    TouchNasos ();
  }
  if (flagTabelWN == 13) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(PauseN[5], 220, 197);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(PauseN[4], 220, 177);
    myGLCD.printNumI(PauseN[6], 220, 217);
    TouchNasos ();
  }
  if (flagTabelWN == 14) {
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.printNumI(PauseN[6], 220, 217);
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.printNumI(PauseN[5], 220, 197);
    myGLCD.printNumI(WorkN[0], 144, 97);
    TouchNasos ();
  }
}


void UpDown3 () {
  byte p;
  if (flagTabelB == 1) {//_________________________________________________1
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.print("       ", 144, 97);
    if (BeerN[0] == 7) {
      myGLCD.print("-", 168, 97 + (0 * 20));
    }
    else {
      byte x = BeerN[0];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (0 * 20));
      myGLCD.print("/", 168, 97 + (0 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (0 * 20));
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("       ", 144, 97 + (1 * 20));
    if (BeerN[1] == 7) {
      myGLCD.print("-", 168, 97 + (1 * 20));
    }
    else {
      byte x = BeerN[1];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (1 * 20));
      myGLCD.print("/", 168, 97 + (1 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (1 * 20));
    }
    if (MelodiN[6] == 7) {
      myGLCD.print("-", 240, 217);
    }
    else {
      myGLCD.printNumI(MelodiN[6], 240, 217);
    }
    TouchBeer ();
  }
  if (flagTabelB == 2) {//_________________________________________________2
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.print("       ", 144, 97 + (1 * 20));
    if (BeerN[1] == 7) {
      myGLCD.print("-", 168, 97 + (1 * 20));
    }
    else {
      byte x = BeerN[1];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (1 * 20));
      myGLCD.print("/", 168, 97 + (1 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (1 * 20));
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("       ", 144, 97 + (2 * 20));
    if (BeerN[2] == 7) {
      myGLCD.print("-", 168, 97 + (2 * 20));
    }
    else {
      byte x = BeerN[2];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (2 * 20));
      myGLCD.print("/", 168, 97 + (2 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (2 * 20));
    }
    myGLCD.print("       ", 144, 97);
    if (BeerN[0] == 7) {
      myGLCD.print("-", 168, 97 + (0 * 20));
    }
    else {
      byte x = BeerN[0];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (0 * 20));
      myGLCD.print("/", 168, 97 + (0 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (0 * 20));
    }
    TouchBeer ();
  }
  if (flagTabelB == 3) {//_________________________________________________3
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.print("       ", 144, 97 + (2 * 20));
    if (BeerN[2] == 7) {
      myGLCD.print("-", 168, 97 + (2 * 20));
    }
    else {
      byte x = BeerN[2];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (2 * 20));
      myGLCD.print("/", 168, 97 + (2 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (2 * 20));
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("       ", 144, 97 + (1 * 20));
    if (BeerN[1] == 7) {
      myGLCD.print("-", 168, 97 + (1 * 20));
    }
    else {
      byte x = BeerN[1];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (1 * 20));
      myGLCD.print("/", 168, 97 + (1 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (1 * 20));
    }
    myGLCD.print("       ", 144, 97 + (3 * 20));
    if (BeerN[3] == 7) {
      myGLCD.print("-", 168, 97 + (3 * 20));
    }
    else {
      byte x = BeerN[3];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (3 * 20));
      myGLCD.print("/", 168, 97 + (3 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (3 * 20));
    }
    TouchBeer ();
  }
  if (flagTabelB == 4) {//_________________________________________________4
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.print("       ", 144, 97 + (3 * 20));
    if (BeerN[3] == 7) {
      myGLCD.print("-", 168, 97 + (3 * 20));
    }
    else {
      byte x = BeerN[3];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (3 * 20));
      myGLCD.print("/", 168, 97 + (3 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (3 * 20));
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("       ", 144, 97 + (2 * 20));
    if (BeerN[2] == 7) {
      myGLCD.print("-", 168, 97 + (2 * 20));
    }
    else {
      byte x = BeerN[2];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (2 * 20));
      myGLCD.print("/", 168, 97 + (2 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (2 * 20));
    }
    myGLCD.print("       ", 144, 97 + (4 * 20));
    if (BeerN[4] == 7) {
      myGLCD.print("-", 168, 97 + (4 * 20));
    }
    else {
      byte x = BeerN[4];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (4 * 20));
      myGLCD.print("/", 168, 97 + (4 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (4 * 20));
    }
    TouchBeer ();
  }
  if (flagTabelB == 5) {//_________________________________________________5
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.print("       ", 144, 97 + (4 * 20));
    if (BeerN[4] == 7) {
      myGLCD.print("-", 168, 97 + (4 * 20));
    }
    else {
      byte x = BeerN[4];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (4 * 20));
      myGLCD.print("/", 168, 97 + (4 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (4 * 20));
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("       ", 144, 97 + (3 * 20));
    if (BeerN[3] == 7) {
      myGLCD.print("-", 168, 97 + (3 * 20));
    }

    else {
      byte x = BeerN[3];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (3 * 20));
      myGLCD.print("/", 168, 97 + (3 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (3 * 20));
    }
    myGLCD.print("       ", 144, 97 + (5 * 20));
    if (BeerN[5] == 7) {
      myGLCD.print("-", 168, 97 + (5 * 20));
    }
    else {
      byte x = BeerN[5];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (5 * 20));
      myGLCD.print("/", 168, 97 + (5 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (5 * 20));
    }
    TouchBeer ();
  }
  if (flagTabelB == 6) {//_________________________________________________6
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.print("       ", 144, 97 + (5 * 20));
    if (BeerN[5] == 7) {
      myGLCD.print("-", 168, 97 + (5 * 20));
    }
    else {
      byte x = BeerN[5];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (5 * 20));
      myGLCD.print("/", 168, 97 + (5 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (5 * 20));
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("       ", 144, 97 + (4 * 20));
    if (BeerN[4] == 7) {
      myGLCD.print("-", 168, 97 + (4 * 20));
    }
    else {
      byte x = BeerN[4];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (4 * 20));
      myGLCD.print("/", 168, 97 + (4 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (4 * 20));
    }
    myGLCD.print("       ", 144, 97 + (6 * 20));
    if (BeerN[6] == 7) {
      myGLCD.print("-", 168, 97 + (6 * 20));
    }
    else {
      byte x = BeerN[6];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (6 * 20));
      myGLCD.print("/", 168, 97 + (6 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (6 * 20));
    }
    TouchBeer ();
  }
  if (flagTabelB == 7) {//_________________________________________________7
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    myGLCD.print("       ", 144, 97 + (6 * 20));
    if (BeerN[6] == 7) {
      myGLCD.print("-", 168, 97 + (6 * 20));
    }
    else {
      byte x = BeerN[6];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (6 * 20));
      myGLCD.print("/", 168, 97 + (6 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (6 * 20));
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("       ", 144, 97 + (5 * 20));
    if (BeerN[5] == 7) {
      myGLCD.print("-", 168, 97 + (5 * 20));
    }
    else {
      byte x = BeerN[5];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (5 * 20));
      myGLCD.print("/", 168, 97 + (5 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (5 * 20));
    }
    if (MelodiN[0] == 7) {
      myGLCD.print("-", 240, 97);
    }
    else {
      myGLCD.printNumI(MelodiN[0], 240, 97);
    }
    TouchBeer ();
  }
  if (flagTabelB == 8) {//_________________________________________________8
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    if (MelodiN[0] == 7) {
      myGLCD.print("-", 240, 97);
    }
    else {
      byte x = MelodiN[0];
      myGLCD.printNumI(x, 240, 97);
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    myGLCD.print("       ", 144, 97 + (6 * 20));
    if (BeerN[6] == 7) {
      myGLCD.print("-", 168, 97 + (6 * 20));
    }
    else {
      byte x = BeerN[6];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (6 * 20));
      myGLCD.print("/", 168, 97 + (6 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (6 * 20));
    }
    if (MelodiN[1] == 7) {
      myGLCD.print("-", 240, 117);
    }
    else {
      byte x = MelodiN[1];
      myGLCD.printNumI(x, 240, 117);
    }
    TouchBeer ();
  }
  if (flagTabelB == 9) {//_________________________________________________9
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    if (MelodiN[1] == 7) {
      myGLCD.print("-", 240, 117);
    }
    else {
      byte x = MelodiN[1];
      myGLCD.printNumI(x, 240, 117);
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    if (MelodiN[0] == 7) {
      myGLCD.print("-", 240, 97);
    }
    else {
      byte x = MelodiN[0];
      myGLCD.printNumI(x, 240, 97);
    }
    if (MelodiN[2] == 7) {
      myGLCD.print("-", 240, 137);
    }
    else {
      byte x = MelodiN[2];
      myGLCD.printNumI(x, 240, 137);
    }
    TouchBeer ();
  }
  if (flagTabelB == 10) {//_________________________________________________10
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    if (MelodiN[2] == 7) {
      myGLCD.print("-", 240, 137);
    }
    else {
      myGLCD.printNumI(MelodiN[2], 240, 137);
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    if (MelodiN[1] == 7) {
      myGLCD.print("-", 240, 117);
    }
    else {
      myGLCD.printNumI(MelodiN[1], 240, 117);
    }
    if (MelodiN[3] == 7) {
      myGLCD.print("-", 240, 157);
    }
    else {
      myGLCD.printNumI(MelodiN[3], 240, 157);
    }
    TouchBeer ();
  }
  if (flagTabelB == 11) {//_________________________________________________11
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    if (MelodiN[3] == 7) {
      myGLCD.print("-", 240, 157);
    }
    else {
      myGLCD.printNumI(MelodiN[3], 240, 157);
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    if (MelodiN[2] == 7) {
      myGLCD.print("-", 240, 137);
    }
    else {
      myGLCD.printNumI(MelodiN[2], 240, 137);
    }
    if (MelodiN[4] == 7) {
      myGLCD.print("-", 240, 177);
    }
    else {
      myGLCD.printNumI(MelodiN[4], 240, 177);
    }
    TouchBeer ();
  }
  if (flagTabelB == 12) {//_________________________________________________12
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    if (MelodiN[4] == 7) {
      myGLCD.print("-", 240, 177);
    }
    else {
      myGLCD.printNumI(MelodiN[4], 240, 177);
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    if (MelodiN[3] == 7) {
      myGLCD.print("-", 240, 157);
    }
    else {
      myGLCD.printNumI(MelodiN[3], 240, 157);
    }
    if (MelodiN[5] == 7) {
      myGLCD.print("-", 240, 197);
    }
    else {
      myGLCD.printNumI(MelodiN[5], 240, 197);
    }
    TouchBeer ();
  }
  if (flagTabelB == 13) {//_________________________________________________13
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    if (MelodiN[5] == 7) {
      myGLCD.print("-", 240, 197);
    }
    else {
      myGLCD.printNumI(MelodiN[5], 240, 197);
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    if (MelodiN[4] == 7) {
      myGLCD.print("-", 240, 177);
    }
    else {
      myGLCD.printNumI(MelodiN[4], 240, 177);
    }
    if (MelodiN[6] == 7) {
      myGLCD.print("-", 240, 217);
    }
    else {
      myGLCD.printNumI(MelodiN[6], 240, 217);
    }
    TouchBeer ();
  }
  if (flagTabelB == 14) {//_________________________________________________14
    myGLCD.setColor(VGA_BLUE);
    myGLCD.setBackColor(VGA_WHITE);
    if (MelodiN[6] == 7) {
      myGLCD.print("-", 240, 217);
    }
    else {
      myGLCD.printNumI(MelodiN[6], 240, 217);
    }
    myGLCD.setBackColor(VGA_BLACK);
    myGLCD.setColor(VGA_LIME);
    if (MelodiN[5] == 7) {
      myGLCD.print("-", 240, 197);
    }
    else {
      myGLCD.printNumI(MelodiN[5], 240, 197);
    }
    myGLCD.print("       ", 144, 97 + (0 * 20));
    if (BeerN[0] == 7) {
      myGLCD.print("-", 168, 97 + (0 * 20));
    }
    else {
      myGLCD.print("       ", 144, 97);
      byte x = BeerN[0];
      if (WorkN[x] < 10) {
        p = 16;
      }
      else {
        if (WorkN[x] < 100) p = 8;
      }
      if (WorkN[x] >= 100) p = 0;
      myGLCD.printNumI(WorkN[x], 144 + p, 97 + (0 * 20));
      myGLCD.print("/", 168, 97 + (0 * 20));
      myGLCD.printNumI(PauseN[x], 176, 97 + (0 * 20));
    }
    TouchBeer ();
  }
}

