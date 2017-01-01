
void setBeerN1 () {
  byte flagTabelB1 = 1;
  byte p;
  if (flagTabelB1 == 1) {//_________________________________________________1
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
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 2) {//_________________________________________________2
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
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 3) {//_________________________________________________3

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
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 4) {//_________________________________________________4

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
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 5) {//_________________________________________________5

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
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 6) {//_________________________________________________6

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
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 7) {//_________________________________________________7

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
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 8) {//_________________________________________________8

    if (MelodiN[0] == 7) {
      myGLCD.print("-", 240, 97);
    }
    else {
      byte x = MelodiN[0];
      myGLCD.printNumI(x, 240, 97);
    }
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 9) {//_________________________________________________9
    if (MelodiN[1] == 7) {
      myGLCD.print("-", 240, 117);
    }
    else {
      byte x = MelodiN[1];
      myGLCD.printNumI(x, 240, 117);
    }
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 10) {//_________________________________________________10

    if (MelodiN[2] == 7) {
      myGLCD.print("-", 240, 137);
    }
    else {
      myGLCD.printNumI(MelodiN[2], 240, 137);
    }
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 11) {//_________________________________________________11

    if (MelodiN[3] == 7) {
      myGLCD.print("-", 240, 157);
    }
    else {
      myGLCD.printNumI(MelodiN[3], 240, 157);
    }
    flagTabelB1 ++;
  }
  if (flagTabelB1 == 12) {//_________________________________________________12

    if (MelodiN[4] == 7) {
      myGLCD.print("-", 240, 177);
    }
    else {
      myGLCD.printNumI(MelodiN[4], 240, 177);
    }
flagTabelB1 ++;
  }
  if (flagTabelB1 == 13) {//_________________________________________________13

    if (MelodiN[5] == 7) {
      myGLCD.print("-", 240, 197);
    }
    else {
      myGLCD.printNumI(MelodiN[5], 240, 197);
    }
flagTabelB1 ++;
  }
  if (flagTabelB1 == 14) {//_________________________________________________14
    if (MelodiN[6] == 7) {
      myGLCD.print("-", 240, 217);
    }
    else {
      myGLCD.printNumI(MelodiN[6], 240, 217);
    }

  }
}

