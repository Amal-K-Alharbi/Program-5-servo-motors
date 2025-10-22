// Program: Control 5 Servo Motors
// Function: Sweep for 2 seconds, then hold all at 90°

#include <Servo.h>

Servo servos[5];              // Create 5 servo objects
const int servoPins[5] = {3, 4, 5, 6, 7};  // Servo pins
int pos = 0;
unsigned long startTime;

void setup() {
  // Attach all servos
  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i], 500, 2500);
  }

  // Record start time
  startTime = millis();
}


void loop() {
  // Run sweep for 2 seconds
  if (millis() - startTime <= 2000) {

    // Sweep from 0° to 180°
    for (pos = 0; pos <= 180; pos++) {
      for (int i = 0; i < 5; i++) {
        servos[i].write(pos);
      }
      delay(15);
    }

    // Sweep from 180° to 0°
    for (pos = 180; pos >= 0; pos--) {
      for (int i = 0; i < 5; i++) {
        servos[i].write(pos);
      }
      delay(15);
    }

  } else {
    // After 2 seconds, hold all at 90°
    for (int i = 0; i < 5; i++) {
      servos[i].write(90);
    }

    // Stop the program permanently
    while (true);
  }
}
