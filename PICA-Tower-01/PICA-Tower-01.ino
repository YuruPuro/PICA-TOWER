int n = 0 ;
uint16_t ledTb[3] ;

void setup() {
  Serial.begin(9600) ;

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void loop() {
  ledTb[0] = 0b1000000100010000 ;
  ledTb[1] = 0b1000000000001000 ;
  ledTb[2] = 0b1000000000000100 ;
  for (int j=0;j<3;j++) {
    for (int i=0;i<8;i++) {
      ledControl(ledTb,2000) ;
Serial.print("--") ;
Serial.println(i) ;
Serial.println(ledTb[0],BIN) ;
Serial.println(ledTb[1],BIN) ;
Serial.println(ledTb[2],BIN) ;
      ledTb[0] = (j==0 ? 0x8100 : 0x8000) | (0x00FF & (ledTb[0] << 1)) | ((ledTb[0] & 0x0080) != 0 ? 0x0001 : 0);
      ledTb[1] = (j==1 ? 0x8100 : 0x8000) | (0x00FF & (ledTb[1] << 1)) | ((ledTb[1] & 0x0080) != 0 ? 0x0001 : 0);
//      ledTb[1] = (j==1 ? 0x8100 : 0x8000) | ((0x00FF &ledTb[1]) >> 1) | ((ledTb[1] & 0x0001) != 0 ? 0x0080 : 0);
      ledTb[2] = (j==2 ? 0x8100 : 0x8000) | (0x00FF & (ledTb[2] << 1)) | ((ledTb[2] & 0x0080) != 0 ? 0x0001 : 0);
    }
  }
}

void ledControl(uint16_t bitMap[],int t) {
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);

  unsigned long time = millis();
  while (millis() - time < t) {
    for (int i=0;i<3;i++) {
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      if (bitMap[i] & 0x0001) digitalWrite(2, HIGH); else digitalWrite(2, LOW);
      if (bitMap[i] & 0x0002) digitalWrite(3, HIGH); else digitalWrite(3, LOW);
      if (bitMap[i] & 0x0004) digitalWrite(4, HIGH); else digitalWrite(4, LOW);
      if (bitMap[i] & 0x0008) digitalWrite(5, HIGH); else digitalWrite(5, LOW);
      if (bitMap[i] & 0x0010) digitalWrite(6, HIGH); else digitalWrite(6, LOW);
      if (bitMap[i] & 0x0020) digitalWrite(7, HIGH); else digitalWrite(7, LOW);
      if (bitMap[i] & 0x0040) digitalWrite(8, HIGH); else digitalWrite(8, LOW);
      if (bitMap[i] & 0x0080) digitalWrite(9, HIGH); else digitalWrite(9, LOW);
      if (bitMap[i] & 0x0100) digitalWrite(10,HIGH); else digitalWrite(10,LOW);
      if (bitMap[i] & 0x8000) digitalWrite(11 + i,LOW);
      delay(1) ;
    }
  }
}
