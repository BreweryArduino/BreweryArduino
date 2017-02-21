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
    if (EEPROM.read(50) != OnOffTerpNW) {
      EEPROM.write(50, OnOffTerpNW); //Записываем новые значения в память
    }
  }
  if (EEPROM.read(50) != OnOffTerpNW) {
      EEPROM.write(50, OnOffTerpNW); //Записываем новые значения в память
    }
    if (EEPROM.read(51) != maxTerpNW) {
      EEPROM.write(51, maxTerpNW); //Записываем новые значения в память
    }
}
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
}
