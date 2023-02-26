#include <SoftwareSerial.h>
//Parameters
SoftwareSerial espSerial(5, 6);
#define ecgPin A0 // Analog input pin for EKG signal
int ecgValue = 0; // Variable to store the EKG reading
unsigned long ecgTime = 0; // Time of the last EKG peak
unsigned long ecgInterval = 0; // Time between successive EKG peaks
int bpm = 0; // Beats per minute



void setup() {
  //Init Serial USB
  Serial.begin(9600);
  espSerial.begin(9600);
  Serial.println(F("Initialize System"));
  //Init AnalogSmooth
  pinMode(aisPin, INPUT);
}

void loop() {
  
  
  Serial.println(bpm());
  espSerial.print(bpm());
}


int bpm(){
  ecgValue = analogRead(ecgPin); // Read the EKG signal
  if (ecgValue > 650) { // If the signal is above a certain threshold
    if ((millis() - ecgTime) > 10) { // If enough time has passed since the last peak
      ecgInterval = millis() - ecgTime; // Calculate the time between peaks
      ecgTime = millis(); // Update the time of the last peak
      bpm = 60000 / ecgInterval; // Calculate beats per minute
      return bpm // Return the BPM value
      
    }
  }
}
