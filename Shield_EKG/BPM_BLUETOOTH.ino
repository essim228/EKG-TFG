#include <SoftwareSerial.h>
//Parameters
SoftwareSerial BTserial(10, 11); // RX, TX for the HC-06
#define ecgPin A0 // Analog input pin for EKG signal
int ecgValue = 0; // Variable to store the EKG reading
unsigned long ecgTime = 0; // Time of the last EKG peak
unsigned long ecgInterval = 0; // Time between successive EKG peaks
int bpm = 0; // Beats per minute
int wait_EKG = 0; // Timestamp to send EKG signals values
int wait_BPM= 0;// Timestamp to send BPM values




void setup() {
  //Init Serial USB
  Serial.begin(9600);
  BTserial.begin(9600);
  Serial.println(F("Initialize System"));
  //Init AnalogSmooth
  pinMode(ecgPin, INPUT);
}

void loop() {
  
  
unsigned long currentMillis = millis();

  // Check if it's time to send the first signal
  if (currentMillis - waitEKG >= 40) { // send every 40ms
    // Send the ekg signal to the HC-06
¡    BTSerial.println(analogRead(ecgPin));

    // Update the timestamp for the first signal
    timestamp1 = currentMillis;
  }

  // Check if it's time to send the second signal
  if (currentMillis - timestamp2 >= 10000) { // send every 10 seconds
    // Send the bpm signal to the HC-06
    BTSerial.println(beats());

    // Update the timestamp for the second signal
    timestamp2 = currentMillis;
  }

  // Delay for a short period of time to avoid overwhelming the HC-06
  delay(10);
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
