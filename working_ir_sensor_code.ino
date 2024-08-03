#include <QTRSensors.h>

QTRSensors qtr;

unsigned int sensorValues[8];
const int threshold = 1000; // Set the threshold value to 1000

void setup() {
  Serial.begin(9600);
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t []){A0, A1, A2, A3, A4, A5, A6, A7}, 8);
  qtr.setEmitterPin(8); // If using the emitter
}

void loop() {
  qtr.read(sensorValues);

  Serial.print("Sensor Values: ");
  
  for (int i = 0; i < 8; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(" ");

    // Print "Black" if the sensor value is above the threshold, otherwise print "White"
    if (sensorValues[i] > threshold) {
      Serial.print("Black ");
    } else {
      Serial.print("White ");
    }
  }

  Serial.println(); // Print a newline at the end of the sensor values

  delay(500); // Adjust delay as needed
}
