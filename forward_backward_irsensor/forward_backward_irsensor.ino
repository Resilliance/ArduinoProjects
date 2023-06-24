int forwardsensor = 3; // Forward Sensor on GPIO 3
int backwardsensor = 2; // Backward Sensor on GPIO 2

void setup() {
  Serial.begin(115200);
  pinMode(forwardsensor, INPUT);
  pinMode(backwardsensor,INPUT);
}

void loop() {
  int forwardsensor_status = digitalRead(forwardsensor);
  int backwardsensor_status = digitalRead(backwardsensor);

  if (forwardsensor_status != 1 && backwardsensor_status != 1)
  {
    Serial.println("Object Detected: FRONT AND BEHIND. SPOCK WE GOTTA TURN!!!!");
  }
  else if (forwardsensor_status != 1) // 1 = High 0 = Low
  {
    Serial.println("Object Detected: FRONT");
  }
  else if (backwardsensor_status != 1) 
  {
    Serial.println("Object Detected: BEHIND");
  }
  else {
    Serial.println("All Clear Chief!");
  }


}
