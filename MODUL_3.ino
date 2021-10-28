// Variabel untuk pin komponen
// Lampu
#define lampuMerah 13
#define lampuKuning 12
#define lampuHijau 11

// Pin Sensor
int trigPin = 2;
int echoPin = 3;

// Pin Buzzer
#define buzzer 4

// Variabel Nilai
int HIDUP = HIGH;
int MATI = LOW;

// Variabel untuk jarak
int cm = 0;
int inch = 0;

long bacaJarakSensor(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);    //konfigurasi pin trigger
  digitalWrite(triggerPin, MATI);  //menonaktifkan pemancaran gelombang T
  delayMicroseconds(2);           //jeda program 0.02 detik
  digitalWrite(triggerPin, HIDUP); //mengaktifkan pemancar gelombang T
  delayMicroseconds(10);          //jeda program 0.10 detik
  digitalWrite(triggerPin, MATI);
  pinMode(echoPin, INPUT);        // konfigurasi pin echo
  
  return pulseIn(echoPin, HIDUP); /*mengaktifkan penerima gelombang R 
                                 /* dan mengembalikan nilainya pada 
                                 /* bacaJarakSensor */
}

void setup(){
  // konfigurasi baund rate serial monitor
  Serial.begin(9600); 
  // Konfigurasi awal untuk lampu led
  pinMode(lampuMerah, OUTPUT);
  pinMode(lampuKuning, OUTPUT);
  pinMode(lampuHijau, OUTPUT);
  // Konfigurasi awal untuk buzzer
  pinMode(buzzer, OUTPUT);
}

void loop(){
  // menghitung jarak ke dalam cm
  cm = 0.01723 * bacaJarakSensor(trigPin, echoPin);
  // konversi ke inch
  inch = (cm / 2.54);

  // Tampilkan data ke serial monitor
  Serial.print(inch);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(200); // jeda program 0.2 detik
  
  // jika jarak kurang dari 60 cm
  if(cm < 60){
    digitalWrite(lampuMerah, HIDUP);
    digitalWrite(lampuKuning, MATI);
    digitalWrite(lampuHijau, MATI);
    tone(buzzer, 1000, 100); // buzzer diaktifkan 1kHz
  }

  // jika jarak lebih dari 60 cm, kurang dari 100 cm
  else if(cm > 60 && cm < 100){
    digitalWrite(lampuMerah, MATI);
    digitalWrite(lampuKuning, HIDUP);
    digitalWrite(lampuHijau, MATI);
    noTone(buzzer); // Buzzer dinonaktifkan
  }

  // Jika jarak lebih dari 100 cm
  else if(cm > 100){
    digitalWrite(lampuMerah, MATI);
    digitalWrite(lampuKuning, MATI);
    digitalWrite(lampuHijau, HIDUP);
    noTone(buzzer); // Buzzer dinonaktifkan
  }
}

