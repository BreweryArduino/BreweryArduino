/*Функции записи и чтения уставок системы в память МК
   Сохраняем с проверкой на дубликат следующие уставки:

   Температуру закипания сусла -
   Параметры режима продувки насоса.
   Коэффициент пропорциональности
   Коэффициент интегрирования
   Режимы работы насоса
   Привязка режима насоса к этапам пивоварни
   Сигнал
*/
void Save_sys () {
  if (EEPROM.read(1) != termKIP)
  {
    EEPROM.write(1, termKIP);//Записываем новые значения в память
  }
  if (EEPROM.read(2) != airW)
  {
    EEPROM.write(2, airW);//Записываем новые значения в память
  }
  if (EEPROM.read(3) != airP)
  {
    EEPROM.write(3, airP);//Записываем новые значения в память
  }
  if (EEPROM.read(4) != rep)
  {
    EEPROM.write(4, rep);//Записываем новые значения в память
  }
  if (EEPROM.read(5) != kP)
  {
    EEPROM.write(5, kP);//Записываем новые значения в память
  }
  if (EEPROM.read(6) != kI)
  {
    EEPROM.write(6, kI);//Записываем новые значения в память
  }
  if (EEPROM.read(7) != ReleOn)
  {
    EEPROM.write(7, ReleOn); //Записываем новые значения в память
  }
  if (EEPROM.read(8) != ReleOff)
  {
    EEPROM.write(8, ReleOff); //Записываем новые значения в память
  }
  for (byte i = 0; i <= 6; i++) {
    if (EEPROM.read(10 + i) != WorkN[i])
    {
      EEPROM.write(10 + i, WorkN[i]); //Записываем новые значения в память
    }
    if (EEPROM.read(20 + i) != PauseN[i])
    {
      EEPROM.write(20 + i, PauseN[i]); //Записываем новые значения в память
    }
    if (EEPROM.read(30 + i) != BeerN[i])
    {
      EEPROM.write(30 + i, BeerN[i]); //Записываем новые значения в память
    }
    if (EEPROM.read(40 + i) != MelodiN[i])
    {
      EEPROM.write(40 + i, MelodiN[i]); //Записываем новые значения в память
    }
  }
  if (EEPROM.read(50) != OnOffTerpNW) {
    EEPROM.write(50, OnOffTerpNW); //Записываем новые значения в память
  }
  if (EEPROM.read(51) != maxTerpNW) {
    EEPROM.write(51, maxTerpNW); //Записываем новые значения в память
  }
    if (EEPROM.read(52) != TermCk) {
    EEPROM.write(52, TermCk); //Записываем новые значения в память
  }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
void Read_sys () {
  termKIP =  EEPROM.read(1);//Читаем из памяти значение
  airW = EEPROM.read(2);//Читаем из памяти значение
  airP = EEPROM.read(3);//Читаем из памяти значение
  rep =  EEPROM.read(4);//Читаем из памяти значение
  kP =  EEPROM.read(5);//Читаем из памяти значение
  kI = EEPROM.read(6);//Читаем из памяти значение
  ReleOn = EEPROM.read(7);//Читаем из памяти значение
  ReleOff = EEPROM.read(8);//Читаем из памяти значение
  for (byte i = 0; i <= 6; i++) {
    WorkN[i] = EEPROM.read(10 + i);
    PauseN[i] = EEPROM.read(20 + i);
    BeerN[i] = EEPROM.read(30 + i);
    MelodiN[i] = EEPROM.read(40 + i);

  }
  OnOffTerpNW = EEPROM.read(50);//Читаем из памяти значение
  maxTerpNW = EEPROM.read(51);//Читаем из памяти значение
  TermCk = EEPROM.read(52);//Читаем из памяти значение
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
void SaveBackup () {
  // сохраняем рецепт в память МК
  if (EEPROM.read(200) != pauseB1) {
    EEPROM.write(200, pauseB1); //Записываем новые значения в память
  }
  if (EEPROM.read(201) != pauseB2) {
    EEPROM.write(201, pauseB2); //Записываем новые значения в память
  }
  if (EEPROM.read(202) != pauseB3) {
    EEPROM.write(202, pauseB3); //Записываем новые значения в память
  }
  if (EEPROM.read(203) != pauseB4) {
    EEPROM.write(203, pauseB4); //Записываем новые значения в память
  }
  if (EEPROM.read(204) != pauseB5) {
    EEPROM.write(204, pauseB5); //Записываем новые значения в память
  }
  if (EEPROM.read(205) != pauseB6) {
    EEPROM.write(205, pauseB6); //Записываем новые значения в память
  }
  if (EEPROM.read(206) != termB1) {
    EEPROM.write(206, termB1); //Записываем новые значения в память
  }

  if (EEPROM.read(207) != termB2) {
    EEPROM.write(207, termB2); //Записываем новые значения в память
  }
  if (EEPROM.read(208) != termB3) {
    EEPROM.write(208, termB3); //Записываем новые значения в память
  }
  if (EEPROM.read(209) != termB4) {
    EEPROM.write(209, termB4); //Записываем новые значения в память
  }
  if (EEPROM.read(210) != termB5) {
    EEPROM.write(210, termB5); //Записываем новые значения в память
  }
  if (EEPROM.read(211) != termB6) {
    EEPROM.write(211, termB6); //Записываем новые значения в память
  }
  if (EEPROM.read(212) != termB7) {
    EEPROM.write(212, termB7); //Записываем новые значения в память
  }
  if (EEPROM.read(213) != chil) {
    EEPROM.write(213, chil); //Записываем новые значения в память
  }
  if (EEPROM.read(214) != timeB1) {
    EEPROM.write(214, timeB1); //Записываем новые значения в память
  }
  if (EEPROM.read(215) != timeB2) {
    EEPROM.write(215, timeB2); //Записываем новые значения в память
  }
  if (EEPROM.read(216) != timeB3) {
    EEPROM.write(216, timeB3); //Записываем новые значения в память
  }
  if (EEPROM.read(217) != timeB4) {
    EEPROM.write(217, timeB4); //Записываем новые значения в память
  }
  if (EEPROM.read(218) != timeB5) {
    EEPROM.write(218, timeB5); //Записываем новые значения в память
  }
  if (EEPROM.read(219) != timeB6) {
    EEPROM.write(219, timeB6); //Записываем новые значения в память
  }
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // сохраняем перменные начала варки и шаг варки в память МК
  if (EEPROM.read(220) != statusBeer) {
    EEPROM.write(220, statusBeer); //Записываем новые значения в память
  }
  if (EEPROM.read(221) != BeerStep) {
    EEPROM.write(221, BeerStep); //Записываем новые значения в память
  }
  if (EEPROM.read(222) !=  SubBeerStep) {
    EEPROM.write(222,  SubBeerStep); //Записываем новые значения в память
  }
  if (EEPROM.read(223) !=  SubSubBeerStep) {
    EEPROM.write(223,  SubSubBeerStep); //Записываем новые значения в память
  }
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // сохраняем время заданное при этапе пауз в память МК
  if (EEPROM.read(224) !=   ho1) {
    EEPROM.write(224,   ho1); //Записываем новые значения в память
    Serial.println (ho1);
  }
  if (EEPROM.read(225) !=  mi1) {
    EEPROM.write(225,  mi1); //Записываем новые значения в память
    Serial.println (mi1);
  }
  if (EEPROM.read(226) !=  se1) {
    EEPROM.write(226,  se1); //Записываем новые значения в память
    Serial.println (se1);
  }
  if (EEPROM.read(227) !=  da1) {
    EEPROM.write(227,  da1); //Записываем новые значения в память
    Serial.println (da1);
  }

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // сохраняем время заданное при кипячении в память МК

  if (BeerStep == 24) {
    if (EEPROM.read(228) !=   hoB2) {
      EEPROM.write(228,   hoB2); //Записываем новые значения в память
    }
    if (EEPROM.read(229) !=  miB2) {
      EEPROM.write(229,  miB2); //Записываем новые значения в память
    }
    if (EEPROM.read(230) !=  seB2) {
      EEPROM.write(230,  seB2); //Записываем новые значения в память
    }
    if (EEPROM.read(231) !=  daB2) {
      EEPROM.write(231,  daB2); //Записываем новые значения в память
    }
    if (EEPROM.read(232) !=   hoB3) {
      EEPROM.write(232,   hoB3); //Записываем новые значения в память
    }
    if (EEPROM.read(233) !=  miB3) {
      EEPROM.write(233,  miB3); //Записываем новые значения в память
    }
    if (EEPROM.read(234) !=  seB3) {
      EEPROM.write(234,  seB3); //Записываем новые значения в память
    }
    if (EEPROM.read(234) !=  daB3) {
      EEPROM.write(234,  daB3); //Записываем новые значения в память
    }
    if (EEPROM.read(235) !=   hoB4) {
      EEPROM.write(235,   hoB4); //Записываем новые значения в память
    }
    if (EEPROM.read(235) !=  miB4) {
      EEPROM.write(235,  miB4); //Записываем новые значения в память
    }
    if (EEPROM.read(236) !=  seB4) {
      EEPROM.write(236,  seB4); //Записываем новые значения в память
    }
    if (EEPROM.read(237) !=  daB4) {
      EEPROM.write(237,  daB4); //Записываем новые значения в память
    }
    if (EEPROM.read(238) !=   hoB5) {
      EEPROM.write(238,   hoB5); //Записываем новые значения в память
    }
    if (EEPROM.read(239) !=  miB5) {
      EEPROM.write(239,  miB5); //Записываем новые значения в память
    }
    if (EEPROM.read(240) !=  seB5) {
      EEPROM.write(240,  seB5); //Записываем новые значения в память
    }
    if (EEPROM.read(241) !=  daB5) {
      EEPROM.write(241,  daB5); //Записываем новые значения в память
    }
    if (EEPROM.read(242) !=   hoB6) {
      EEPROM.write(242,   hoB6); //Записываем новые значения в память
    }
    if (EEPROM.read(243) !=  miB6) {
      EEPROM.write(243,  miB6); //Записываем новые значения в память
    }
    if (EEPROM.read(244) !=  seB6) {
      EEPROM.write(244,  seB6); //Записываем новые значения в память
    }
    if (EEPROM.read(245) !=  daB6) {
      EEPROM.write(245,  daB6); //Записываем новые значения в память
    }
  }



}
//----------------------------------------------------------------------------------------------------------------------------------------------------
//Считываем из памяти МК данные для Backup
void ReadBackup () {
  pauseB1 = EEPROM.read(200);
  pauseB2 = EEPROM.read(201);
  pauseB3 = EEPROM.read(202);
  pauseB4 = EEPROM.read(203);
  pauseB5 = EEPROM.read(204);
  pauseB6 = EEPROM.read(205);
  termB1 = EEPROM.read(206);
  termB2 = EEPROM.read(207);
  termB3 = EEPROM.read(208);
  termB4 = EEPROM.read(209);
  termB5 = EEPROM.read(210);
  termB6 = EEPROM.read(211);
  termB7 = EEPROM.read(212);
  chil = EEPROM.read(213);
  timeB1 = EEPROM.read(214);
  timeB2 = EEPROM.read(215);
  timeB3 = EEPROM.read(216);
  timeB4 = EEPROM.read(217);
  timeB5 = EEPROM.read(218);
  timeB6 = EEPROM.read(219);
  BeerStep = EEPROM.read(221);
  SubBeerStep = EEPROM.read(222);
  SubSubBeerStep = EEPROM.read(223);
  ho1 = EEPROM.read(224);
  mi1 = EEPROM.read(225);
  se1 = EEPROM.read(226);
  da1 = EEPROM.read(227);

  hoB2 = EEPROM.read(228);
  miB2 = EEPROM.read(229);
  seB2 = EEPROM.read(230);
  daB2 = EEPROM.read(231);
  hoB3 = EEPROM.read(232);
  miB3 = EEPROM.read(233);
  seB3 = EEPROM.read(234);
  daB3 = EEPROM.read(234);
  hoB4 = EEPROM.read(235);
  miB4 = EEPROM.read(235);
  seB4 = EEPROM.read(236);
  daB4 = EEPROM.read(237);
  hoB5 = EEPROM.read(238);
  miB5 = EEPROM.read(239);
  seB5 = EEPROM.read(240);
  daB5 = EEPROM.read(241);
  hoB6 = EEPROM.read(242);
  miB6 = EEPROM.read(243);
  seB6 = EEPROM.read(244);
  daB6 = EEPROM.read(245);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
