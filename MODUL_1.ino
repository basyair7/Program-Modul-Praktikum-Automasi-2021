// variabel pin komponen
#define lampuMerah 13
#define lampuHijau 11
#define buzzer 4
#define PirSensor 3

// variabel nilai sensor
int pirState = 0;

// variabel nilai hidup dan mati
int HIDUP=HIGH;
int MATI=LOW;

void setup(){
  Serial.begin(9600);
  // konfigurasi pin sensor
  pinMode(PirSensor, INPUT);
  // konfigurasi komponen lampu & buzzer
  pinMode(lampuMerah, OUTPUT);
  pinMode(lampuHijau, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  // ambil nilai sensor, dan masukan ke pirState
  pirState = digitalRead(PirSensor);
  Serial.print("Nilai : ");
  Serial.println(pirState);

  // jika nilai sensor 1
  if(pirState == HIGH){
    digitalWrite(lampuHijau, MATI);
    digitalWrite(lampuMerah, HIDUP);
    tone(buzzer, 1000, 100); // Buzzer diaktifkan 1kHz
    delay(200); // jeda program 0.2 detik
    
    digitalWrite(lampuMerah, MATI);
    noTone(buzzer); // Buzzer di non aktifkan
  }

  // jika nila sensor 0
  else{
    digitalWrite(lampuHijau, HIDUP);
    digitalWrite(lampuMerah, MATI);
    noTone(buzzer); // buzzer di nonaktifkan
  }
  delay(300); // jeda program 0.3 detik
}
