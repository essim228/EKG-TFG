#include <SoftwareSerial.h>
//Parameters
SoftwareSerial BTSerial(2, 1); // RX, TX for the HC-06
const int ecgPin = A0; // Analog input pin for EKG signal
int ecgValue; // Variable to store the EKG reading
int ecgInterval;
int ecgTime;
unsigned long timestamp1 = 0; // Time of the last EKG peak
unsigned long timestamp2 = 0; // Time between successive EKG peaks
unsigned long currentMillis; // Time between successive EKG peaks
short value;
short bpm = 0; // Beats per minute
int wait_EKG = 0; // Timestamp to send EKG signals values
int wait_BPM= 0;// Timestamp to send BPM values




void setup() {
  //Init Serial USB
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.println(F("Initialize System"));
  //Init AnalogSmooth
  pinMode(ecgPin, INPUT);
}

void loop() {
  
value = analogRead(ecgPin);
//BTSerial.print(value);
Serial.print("a");
Serial.println(value);
  // Delay for a short period of time to avoid overwhelming the HC-06
delay(4);
}


int beats() {
  ecgValue = analogRead(ecgPin); // Read the EKG signal
  if (ecgValue > 650) { // If the signal is above a certain threshold
    if ((millis() - ecgTime) > 10) { // If enough time has passed since the last peak
      ecgInterval = millis() - ecgTime; // Calculate the time between peaks
      ecgTime = millis(); // Update the time of the last peak
      bpm = 60000 / ecgInterval; // Calculate beats per minute
      return bpm; // Return the BPM value
      
    }
  }
}

