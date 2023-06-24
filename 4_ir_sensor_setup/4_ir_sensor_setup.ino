/*
flir = Front Left IR
frir = Front Right IR
lir = Left IR
rir = Right IR

Two front IR sensors are used for 'redundancy'. 
In the case one of a malfunction or misreading for half a second it won't impede the forward movement.
*/

int flir = 3; 
int frir = 2;
int lir = 4; 
int rir = 5;

void setup() {
  Serial.begin(115200);
  pinMode(flir, INPUT);
  pinMode(frir,INPUT);
  pinMode(lir,INPUT);
  pinMode(rir,INPUT);

}

void loop() {
  // s is short for Status
  int flirs = digitalRead(flir);
  int frirs = digitalRead(frir);
  int lirs = digitalRead(lir);
  int rirs = digitalRead(rir);
  // == 0 or != 1 Obstacle detected
  // != 0 or == 1 Clear

  if (lirs != 1 && rirs != 1 && (flirs == 1 || frirs == 1)) 
  {
    // Move Straight (left and right are blocked)
    Serial.println("Gotta go fast!");    
  }
  else if (lirs == 1 && rirs != 1 && flirs != 1 && frirs != 1)
  {
    // Turn Left (front and right are blocked, but left is clear)
    Serial.println("Initiating left turn, commander.");
  }
  else if (lirs != 1 && rirs == 1 && flirs != 1 && frirs != 1)
  {
    // Turn Right (front and left are blocked, but right is clear)
    Serial.println("Initiating right turn, commander.");
  }
  else if (lirs != 1 && rirs != 1 && flirs != 1 && frirs != 1)
  {
    // Reverse (front, left, and right are blocked)
    Serial.println("Starting reverse propulsion!");
  }
  else 
  {
    Serial.println("Found an extra scenario!");
  }

  /*
  Notes:
  
  */


}
