// variabel pin komponen
#define pir 2
#define merah 3
#define kuning 4
#define hijau 5
#define pushButton1 6
#define pushButton2 7
#define pushButton3 8
#define speaker 9
#define MATI LOW
#define HIDUP HIGH

// variabel data
int pirState;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int count1 = 0;
int count2 = 0;
int count3 = 0;
int x = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(speaker, OUTPUT);
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);
  pirState=MATI;

}

void loop() {
  // put your main code here, to run repeatedly:
  pirState = digitalRead(pir);
  x=0;
  if (pirState == HIDUP)
  {    
    while(x!=1)
    {
      Serial.println(pirState);
      alarm(300, 160); // 5 kHz 160d
      buttonState1 = digitalRead(pushButton1);
      buttonState2 = digitalRead(pushButton2);
      buttonState3 = digitalRead(pushButton3);

      if (buttonState1 == HIDUP && buttonState2 == HIDUP && buttonState3 == HIDUP )
      {
        count1 += 1;
      }

      if (count1 == 3)
      {
        stopalarm();
        count1 = 0;
        count2 = 0;
        count3 = 0;
        delay(1000); //1000ms or 1 second
      }      
    }
  }
  else 
  {
   stopalarm(); 
  }
}

void alarm(long durasi, int frekuensi) {
  digitalWrite(hijau, MATI);
  digitalWrite(kuning, MATI);
  digitalWrite(merah, HIDUP);
  delay(300);
  digitalWrite(merah, MATI);
  digitalWrite(kuning, HIDUP);
  delay(300);
  play(durasi, frekuensi);
}

void play(long durasi, int frekuensi) {
  durasi = durasi*1000;
  int periode = (1.0/frekuensi)*1000000;
  long elapsed = 0;
  while(elapsed < durasi)
  {
    digitalWrite(speaker, HIDUP);
    delayMicroseconds(periode/2);
    digitalWrite(speaker, MATI);
    delayMicroseconds(periode/2);
    elapsed += periode;
  }
}

void stopalarm() {
  digitalWrite(hijau, HIDUP);
  digitalWrite(merah, MATI);
  digitalWrite(kuning, MATI);
  pirState = MATI;
  delay(700); // 700ms or 0.7 seconds
}
