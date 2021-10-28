// variabel pin komponen
#define lampuMerah 13
#define lampuHijau 11
#define buzzer 4
#define smokePin A0

// variabel batas keamanan
int nilai_aman = 30;

// variabel nilai Hidup dan Mati
int HIDUP=HIGH;
int MATI=LOW;

void setup() {
  // konfigurasi baund rate serial monitor
  Serial.begin(9600);
  // konfigurasi Pin Sensor Smoke
  pinMode(smokePin, INPUT);
  // konfigurasi komponen lampu & buzzer
  pinMode(lampuMerah, OUTPUT);
  pinMode(lampuHijau, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // mengambil data sensor dan memasukkan ke dalam variabel baru
  int data = map(analogRead(smokePin), 0, 1023, 0, 100);

  // tampilkan data di serial monitor
  Serial.print("DATA SENSOR : ");
  Serial.println(data);
  delay(200); // jeda program 0.2 detik

  // jika data sensor melebihi batas nilai aman
  if(data > nilai_aman){
    digitalWrite(lampuMerah, HIDUP);
    digitalWrite(lampuHijau, MATI);
    tone(buzzer, 1000, 100); // buzzer diaktifkan 1kHz
  }

  // jika data sensor kurang dari batas nilai aman
  else{
    digitalWrite(lampuMerah, MATI);
    digitalWrite(lampuHijau, HIDUP);
    noTone(buzzer); // buzzer dimatikan
  }
}
