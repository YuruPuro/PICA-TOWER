int n = 0 ;

void setup() {
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

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10,HIGH);
}

void loop() {
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  for (int i=0;i<8;i++) {
    digitalWrite(2, (i==0 ? HIGH : LOW));
    digitalWrite(3, (i==1 ? HIGH : LOW));
    digitalWrite(4, (i==2 ? HIGH : LOW));
    digitalWrite(5, (i==3 ? HIGH : LOW));
    digitalWrite(6, (i==4 ? HIGH : LOW));
    digitalWrite(7, (i==5 ? HIGH : LOW));
    digitalWrite(8, (i==6 ? HIGH : LOW));
    digitalWrite(9, (i==7 ? HIGH : LOW));
    digitalWrite(10,(i==8 ? HIGH : LOW));
    delay(1000) ;
  }
}
