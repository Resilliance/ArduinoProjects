// IR Pins (specifically non-PWM pins)
int f_sensor = 2;
int l_sensor = 4;
int r_sensor = 7;

// Motor related Pins
// Motor A
int ena = 3; // PWM
int in1 = 5;
int in2 = 6;

// Motor B
int enb = 10; // PWM
int in3 = 9;
int in4 = 8;


void setup() {
	// I/O Setup
	pinMode(f_sensor, INPUT);
	pinMode(l_sensor, INPUT);
	pinMode(r_sensor, INPUT);

	pinMode(ena, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);

	pinMode(enb, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);
	digitalWrite(in3,LOW);
	digitalWrite(in4,LOW);

}

void loop() {
	/*
	Reminders: 
	- IR Sensor == 0 (obstacle detected)
	- IR Sensor == 1 (NO obstacle)
	- ena/enb control the Voltage/Duty_Cycle of the motors (0-255)
		- Higher -> Faster (& vise verse)

	Abbreviations:
	- firs = Front IR Status
	- lirs = Left IR Status
	- rirs = Right IR Status

	- Commenting out lirs, firs, enb, in3, and in4 for preliminary testing
	*/

	int firs = digitalRead(f_sensor);
	// int lirs = digitalRead(l_sesnor);
	// int rirs = digitalRead(r_sesnor);

	if (firs == 1) {
		accelerate();
	}
	else {
	brake();
	}

}

void accelerate() {
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
	// digitalWrite(in3,HIGH);
	// digitalWrite(in4,LOW);

	for (int x = 150; x < 256; x++) {
		analogWrite(ena, x);
		// analogWrite(enb, x);
	}
}

void brake() {
	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);
	// digitalWrite(in3,LOW);
	// digitalWrite(in4,LOW);
}
