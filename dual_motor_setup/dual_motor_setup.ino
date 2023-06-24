int ena = 9;
int enb = 10;
int in1 = 3;
int in2 = 4;
int in3 = 6;
int in4 = 7;




void setup() {
	pinMode(ena, OUTPUT);
	pinMode(enb, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void loop() {


	// Move Motor A 
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
  analogWrite(ena,255);

	// Move Motor B
	digitalWrite(in3,HIGH);
	digitalWrite(in4,LOW);
  analogWrite(enb,255);

	// Let the motors run before stopping for 5 seconds (measured in milliseconds)
	// delay(5000);
}

void emergencyBrake() {
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void accelerate() {
  for (int x = 20; x < 256; x++) {
    analogWrite(ena, x);
    analogWrite(enb, x);
  }
}

void decelerate(int speed) {
  for (int x = speed; x >= 0; --x) {
    analogWrite(ena,x);
    analogWrite(enb,x);
  }
}

/*
Notes:
- Next Steps:
  - Integrate a potentiometer as an analog input
  - Integrate a joystick as an analog input 
  - Have the motors trigger based off of a sensor
- Troubleshooting:
  - Wasted 30 minutes because I thought my code wasn't working, turned out the motors I was using
    required a minimum of 5V and I was only supplying it 4V
- Successfully runing a 3.3V motor through the driver with 4V was exciting
- I wrote those extra functions as a type of practice (active recall) of the concepts that I've learned (or in this case 're-learned')
  since I'm sticking my pinky back into this pool (John Wick reference) 
*/