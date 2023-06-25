// Stepper Lib
#include <Stepper.h>

const int stepsPerRev = 2038;
// bool turnOn = False;

// Define IR Pin INPUT
int ir_sensor = 2;

// Stepper Motor Pins
Stepper stepper1 = Stepper(stepsPerRev, 11,9,10,8);

void setup() {
  Serial.begin(115200);
	pinMode(ir_sensor,INPUT);
}

void loop() {

  int ir_status = digitalRead(ir_sensor);

  if (ir_status == 1) {
    spinCW();
    spinCCW();
  } else {
    Serial.println("Obstacle Detected");
    // Doesn't stop the motor (28BYJ-48) as intended because this motor doesn't receive instruction during it's rotation (I'm probably wrong so I'm gonna keep looking into it)
    // Signaling the IR doesn't stop the spinCCW() call either
    // To combat this I could place the ir_status condition inside of the spinCW/spinCCW functions to prevent the call of the next
  }

}

void spinCW () {
  // Clockwise (15 rpm)
	stepper1.setSpeed(15);
	stepper1.step(stepsPerRev);
	delay(1000);
}

void spinCCW () {
  // Counter-Clockwise (15 rpm)
	stepper1.setSpeed(15);
	stepper1.step(-stepsPerRev);
	delay(1000);
}

/*
Reference:
- https://lastminuteengineers.com/28byj48-stepper-motor-arduino-tutorial/
- https://forum.arduino.cc/t/stepper-motor-doesnt-turn-counter-clockwise-wrong-steps-number-indication/139845/6
- https://github.com/arduino-libraries/Stepper/blob/master/src/Stepper.h
- https://www.mouser.com/datasheet/2/758/stepd-01-data-sheet-1143075.pdf

Troubleshooting:
- With the practice code, I used from 'lastminuteengineers' I found that the stepper wasn't moving CCW (counter clockwise)
  to troubleshoot I grabbed another stepper motor I had lying around in case I thought I broke it. Same issue occured.
- With a quick google, and exploring the arduino forum I found that the IN1/2/3/4 were improperly placed
  - Line: 10; I modified the pin sequence from 11,10,9,8 to 11,9,10,8 because I sped-read the code and wrote down the
    pins that coordinate with the coils in the wrong order

    Correct order: IN1-IN3-IN2-IN4 (11,9,10,8)

    IN1 = COIL 4 -> Pin 8
    IN2 = COIL 2 -> Pin 10
    IN3 = COIL 3 -> Pin 9
    IN4 = COIL 1 -> Pin 11

Possible Applications with IR sensor:
- Automatic blinds
*/
