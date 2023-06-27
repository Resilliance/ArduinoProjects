#include <BMI160Gen.h>

const int select_pin = 10;
const int i2c_addr = 0x68;

void setup() {
  Serial.begin(9600); // initialize Serial communication
  while (!Serial);    // wait for the serial port to open

  // initialize device
  BMI160.begin(BMI160GenClass::SPI_MODE, select_pin);
  //BMI160.begin(BMI160GenClass::I2C_MODE, i2c_addr);
}

void loop() {
  int gx, gy, gz;         // raw gyro values
  int ax, ay, az;

  // read raw gyro measurements from device
  BMI160.readGyro(gx, gy, gz);
  BMI160.readAccelerometer(ax,ay,az);

  // display tab-separated accel x/y values
  Serial.print("a:\t");
  Serial.print(ax);
  Serial.print("\t");
  Serial.print(ay);
  Serial.print("\t");
  Serial.print(az);
  Serial.print("\t");

  // display tab-separated gyro x/y/z values
  Serial.print("g:\t");
  Serial.print(gx);
  Serial.print("\t");
  Serial.print(gy);
  Serial.print("\t");
  Serial.print(gz);
  Serial.println();

  delay(500);
}