void CardInfo () {
  File myFile;
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setFont(SmallRusFont);
  myGLCD.print("\x86""\xA2""\x9D""\xA6""\x9D""a""\xA0""\x9D""\x9C""a""\xA6""\x9D""\xAF"" ""\x9F""ap""\xA4""\xAB"" ""\xA3""a""\xA1""\xAF""\xA4""\x9D""..", 5, 65);// Инициализация  карты памяти
  myGLCD.print("\x86""\xA2""\x9D""\xA6""\x9D""a""\xA0""\x9D""\x9C""a""\xA6""\x9D""\xAF"" ""\x9F""ap""\xA4""\xAB"" ""\xA3""a""\xA1""\xAF""\xA4""\x9D""...", 5, 65);// Инициализация  карты памяти
  myGLCD.print("\x86""\xA2""\x9D""\xA6""\x9D""a""\xA0""\x9D""\x9C""a""\xA6""\x9D""\xAF"" ""\x9F""ap""\xA4""\xAB"" ""\xA3""a""\xA1""\xAF""\xA4""\x9D""....", 5, 65);// Инициализация  карты памяти
  myGLCD.print("\x86""\xA2""\x9D""\xA6""\x9D""a""\xA0""\x9D""\x9C""a""\xA6""\x9D""\xAF"" ""\x9F""ap""\xA4""\xAB"" ""\xA3""a""\xA1""\xAF""\xA4""\x9D"".....", 5, 65);// Инициализация  карты памяти

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    myGLCD.setBackColor(VGA_RED);
    myGLCD.print("O""\xA8""\x9D""\x96""\x9F""a"" ""\x9D""\xA2""\x9D""\xA6""\x9D""a""\xA0""\x9D""\x9C""a""\xA6""\x9D""\x9D""."" ""\x89""po""\x97""ep""\x9D""\xA4""\xAC"":", 5, 80);//Ошибка инициализации.Проверить:
    myGLCD.print("*"" ""\x9F""ap""\xA4""a"" ""\xA3""a""\xA1""\xAF""\xA4""\x9D"" ""\x97""c""\xA4""a""\x97""\xA0""e""\xA2""a?", 5, 95);//карта памяти вставлена?
    myGLCD.print("*"" ""\xA3""o""\x99""\x9F""\xA0""\xAE""\xA7""e""\xA2""\x9D""e"" ""\x97""\xAB""\xA3""o""\xA0""\xA2""e""\xA2""o"" ""\x97""ep""\xA2""o?", 5, 110);//подключение выполнено верно?
    myGLCD.print("*"" ""chipSelect pin"" ""y""\x9F""a""\x9C""a""\xA2"" ""\x97""ep""\xA2""o?", 5, 125);//chipSelect pin указан верно?
    myGLCD.setColor(VGA_RED);
    myGLCD.fillRoundRect(100, 160, 220, 210);
    myGLCD.setBackColor(VGA_RED);
    myGLCD.setColor(VGA_LIME);
    SdTouch = true;
    myGLCD.print("\x89""OBTOP""\x86""T""\x92", CENTER, 180);


    return;
  } else {
    myGLCD.print("\x89""o""\x99""\x9F""\xA0""\xAE""\xA7""e""\xA2""o"" ""\x97""ep""\xA2""o"", ""\x9F""ap""\xA4""a"" ""yc""\xA4""a""\xA2""o""\xA0""e""\xA2""a", 5, 80);// подключено правильно,  карта установлена.
  }

  // print the type of card
  myGLCD.print("T""\x9D""\xA3"" ""\x9F""ap""\xA4""\xAB"": ", 5, 95);
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      myGLCD.print("SD1", 90, 95);
      break;
    case SD_CARD_TYPE_SD2:
      myGLCD.print("SD2", 90, 95);
      break;
    case SD_CARD_TYPE_SDHC:
      myGLCD.print("SDHC", 90, 95);
      break;
    default:
      myGLCD.print("He""\x9D""\x9C""\x97""ec""\xA4""\xA2""a", 90, 95);//неизвестна
  }


  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    myGLCD.setBackColor(VGA_RED);
    myGLCD.print("He""\xA4"" ""pa""\x9C""\x99""e""\xA0""a"" ""FAT16/FAT32.", 5, 110);//Не раздела FAT16 / FAT32.
    myGLCD.print("O""\xA4""\xA5""op""\xA1""a""\x9D""po""\x97""a""\xA4""\xAC"" ""\x9F""ap""\xA4""y"" ""\x97"" ""FAT16/FAT32.", 5, 125);//От фoрматируй карту в FAT16 / FAT32.
    myGLCD.setColor(VGA_RED);
    myGLCD.fillRoundRect(100, 160, 220, 210);
    myGLCD.setColor(VGA_LIME);
    SdTouch = true;
    myGLCD.print("\x89""OBTOP""\x86""T""\x92", CENTER, 180);
    return;
  }


  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  myGLCD.print("Pa""\x9C""\x99""e""\xA0"" FAT", 5, 110);// Раздел FAT
  myGLCD.printNumI(volume.fatType(), 85, 110);


  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize *= 512;                            // SD card blocks are always 512 bytes
  volumesize /= 1024;
  volumesize /= 1024;
  myGLCD.print("Pa""\x9C""\xA1""ep ""\x9F""ap""\xA4""\xAB"" (Mb): ", 5, 125);//размер тома (Мбайт)
  myGLCD.printNumI(volumesize, 141, 125);
  byte a = 140;
  byte b = 155;
  if (SD.exists("/BEER") == false) {
    a = 170;
    //myFile = SD.open("SYS.TXT", FILE_WRITE);
    // set date time callback function
    SdFile::dateTimeCallback(dateTime);
    SD.mkdir("/BEER");
    //myFile.close();
    myGLCD.print("co""\x9C""\x99""a""\x9A""\xA1""....BEER", 5, 140);//проверка существования папки для хранения рецептов
  }
  if (SD.exists("SYS.TXT") == false) {
    b = 185;
    // set date time callback function
    SdFile::dateTimeCallback(dateTime);
    myFile = SD.open("SYS.TXT", FILE_WRITE);
    myFile.close();
    myGLCD.print("co""\x9C""\x99""a""\x9A""\xA1""....SYS.TXT", 5, 155);//проверка существования папки для хранения рецептов
  }
  if (SD.exists("/BEER") == true) myGLCD.print("BEER Ok!", 5, a);//проверка существования папки для хранения рецептов
  if (SD.exists("SYS.TXT") == true) myGLCD.print("SYS.TXT Ok!", 5, b);//проверка существования папки для хранения рецептов

}
void SDSaveSys () {// Функция записи на карту файла sys.txt
  File myFile;
  ErroSD ();
  // set date time callback function
  SdFile::dateTimeCallback(dateTime);
  myFile = SD.open("sys.txt", FILE_WRITE);
  myGLCD.print("*", LEFT, 200);//
  myFile.seek(0);
  // if the file opened okay, write to it:
  if (myFile) {
    myGLCD.print("**", LEFT, 200);
    myFile.print(EEPROM.read(1));//termKIP
    myFile.print(";");
    myGLCD.print("***", LEFT, 200);//
    myFile.print(EEPROM.read(2));//airW
    myFile.print(";");
    myGLCD.print("****", LEFT, 200);//
    myFile.print(EEPROM.read(3));//airP
    myFile.print(";");
    myGLCD.print("*****", LEFT, 200);//
    myFile.print(EEPROM.read(4));//rep
    myFile.print(";");
    myGLCD.print("******", LEFT, 200);//
    myFile.print(EEPROM.read(5));//kP
    myFile.print(";");
    myGLCD.print("*******", LEFT, 200);//
    myFile.print(EEPROM.read(6));//kI
    myFile.print(";");
    myGLCD.print("********", LEFT, 200);//
    for (byte i = 0; i <= 6; i++) {
      myFile.print( EEPROM.read(10 + i));//WorkN
      myFile.print(";");
    }
    myGLCD.print("*********", LEFT, 200);//
    for (byte i = 0; i <= 6; i++) {
      myFile.print( EEPROM.read(20 + i));//PauseN
      myFile.print(";");
    }
    myGLCD.print("**********", LEFT, 200);//
    for (byte i = 0; i <= 6; i++) {
      myFile.print( EEPROM.read(30 + i));//BeerN
      myFile.print(";");
    }
    myGLCD.print("************", LEFT, 200);//
    for (byte i = 0; i <= 6; i++) {
      myFile.print( EEPROM.read(40 + i));//MelodiN
      myFile.print(";");
    }
    myGLCD.print("*************", LEFT, 200);
    myFile.print(EEPROM.read(7));//ReleOn
    myFile.print(";");
    myGLCD.print("**************", LEFT, 200);
    myFile.print(EEPROM.read(8));//ReleOff
    myFile.print(";");
    myGLCD.print("***************", LEFT, 200);
    myFile.print(EEPROM.read(50));//OnOffTerpNW
    myFile.print(";");
    myGLCD.print("***************", LEFT, 200);
    myFile.print(EEPROM.read(51));//maxTerpNW
    myFile.print(";");
    myFile.print(EEPROM.read(52));//TermCk
    myFile.print(";");
  }
  // close the file:
  myFile.close();
  myGLCD.print("*****************", LEFT, 200);//
  myGLCD.print("              ", LEFT, 200);//
}
void SDRead (String nameF) {// функция чтения с карты

  File myFile;
  // Open serial communications and wait for port to open:

  ErroSD ();

  int h = 0;        // считываем массив входящего конфигурвционного файла
  int num, i = 0;
  char array[150] = {};
  char *buffer;
  char symbol2 = 0;
  myFile = SD.open(nameF);
  if (myFile) {
    while (myFile.available()) {
      // считываем байт входящего файла
      symbol2 = myFile.read();
      array[h] = symbol2;
      Serial.print(array[h]);
      h++;
      delay(2);
    }
    array[h] = '\0';
    // Serial.println(array[h]);
    myFile.close();

  }


  char *p;
  byte t = 0;
  for ( buffer = strtok_r(array, ";", &p); buffer; buffer = strtok_r(NULL, ";", &p))
  {
    Serial.print(t); Serial.print(" = "); Serial.println(atoi(buffer));
    delay(2);
    outArray[t] = atoi(buffer);
    t++;
  }

}
void SDReadSys () {// Функция восстановления образа системы из файла sys.txt
  ErroSD ();
  SDRead ("sys.txt");//считываем данные из файла sys.txt во временный массив outArray
  termKIP = outArray[0];
  airW = outArray[1];
  airP = outArray[2];
  rep = outArray[3];
  kP =  outArray[4];
  kI = outArray[5];
  for (byte i = 0; i <= 6; i++) {
    WorkN[i] = outArray[6 + i];
    PauseN[i] = outArray[13 + i];
    BeerN[i] = outArray[20 + i];
    MelodiN[i] = outArray[27 + i];
    ReleOn = outArray[34];
    ReleOff = outArray[35];
  }
  OnOffTerpNW = outArray[36];
  maxTerpNW = outArray[37];
TermCk = outArray[38];
  Save_sys ();
}

void SDReadDir () {// функция чтения кол-ва и имен рецептов
  for (byte i = 0; i < 25; i++ ) {
    NameDir[i] = "";
  }
  SumDir = 0;
  File root;
  ErroSD ();
  root = SD.open("/BEER");
  while (true) {
    File entry =  root.openNextFile();
    if (! entry || SumDir == 25) {
      // no more files
      break;
    }

    NameDir[SumDir] = entry.name();
    SumDir ++;
    entry.close();

  }

}
void SDReadBeer () {
  ErroSD ();
  SDRead ( NameBeer);//считываем данные из файла sys.txt во временный массив outArray
  pauseB1 = outArray[0];
  pauseB2 = outArray[1];
  pauseB3 = outArray[2];
  pauseB4 = outArray[3];
  pauseB5 = outArray[4];
  pauseB6 = outArray[5];
  termB1 = outArray[6];
  termB2 = outArray[7];
  termB3 = outArray[8];
  termB4 = outArray[9];
  termB5 = outArray[10];
  termB6 = outArray[11];
  termB7 = outArray[12];
  timeB1 = outArray[13];
  timeB2 = outArray[14];
  timeB3 = outArray[15];
  timeB4 = outArray[16];
  timeB5 = outArray[17];
  timeB6 = outArray[18];
  chil = outArray[19];
  statusBeer = 1;//флаг начала варки для Backup
  SaveBackup ();
  Screen4_2 ();
}
void SDSaveBeer () {
  File myFile;
  ErroSD ();
  // set date time callback function
  SdFile::dateTimeCallback(dateTime);
  myFile = SD.open(NameBeer, FILE_WRITE);
  myFile.seek(0);
  // if the file opened okay, write to it:
  if (myFile) {
    myFile.print(pauseB1);//
    myFile.print(";");
    myFile.print(pauseB2);//
    myFile.print(";");
    myFile.print(pauseB3);//
    myFile.print(";");
    myFile.print(pauseB4);//
    myFile.print(";");
    myFile.print(pauseB5);//
    myFile.print(";");
    myFile.print(pauseB6);//
    myFile.print(";");
    myFile.print(termB1);//
    myFile.print(";");
    myFile.print(termB2);//
    myFile.print(";");
    myFile.print(termB3);//
    myFile.print(";");
    myFile.print(termB4);//
    myFile.print(";");
    myFile.print(termB5);//
    myFile.print(";");
    myFile.print(termB6);//
    myFile.print(";");
    myFile.print(termB7);//
    myFile.print(";");
    myFile.print(timeB1);//
    myFile.print(";");
    myFile.print(timeB2);//
    myFile.print(";");
    myFile.print(timeB3);//
    myFile.print(";");
    myFile.print(timeB4);//
    myFile.print(";");
    myFile.print(timeB5);//
    myFile.print(";");
    myFile.print(timeB6);//
    myFile.print(";");
    myFile.print(chil);//
    myFile.print(";");
  }

  // close the file:
  myFile.close();
}
void SDBeerName () {// функция отображения редактируемого имени
  myGLCD.setBackColor(VGA_BLACK);
  myGLCD.setColor(VGA_LIME);
  myGLCD.setFont(BigRusFont);
  myGLCD.print(BufName[0], 35, 100);
  myGLCD.print(BufName[1], 70, 100);
  myGLCD.print(BufName[2], 105, 100);
  myGLCD.print(BufName[3], 140, 100);
  myGLCD.print(BufName[4], 175, 100);
  myGLCD.print(BufName[5], 210, 100);
  myGLCD.print(BufName[6], 245, 100);
  myGLCD.print(BufName[7], 280, 100);
  myGLCD.setFont(BigRusFont);
  myGLCD.setColor(VGA_BLUE);
  myGLCD.fillRoundRect(50, 154, 270, 230);
  myGLCD.setBackColor(VGA_BLUE);
  myGLCD.setColor(VGA_LIME);
  myGLCD.print("COXPAH""\x86""T""\x92", 88, 188);//СОХРАНИТЬ
  myGLCD.setBackColor(VGA_BLACK);
  Touch5_2 () ;
}


