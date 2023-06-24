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
    /* 
    Extra Scenarios:
    - lir and flir are blocked
    - lir and frir are blocked
    - rir and flir are blocked
    - rir and frir are blocked
    */
  }

  /*
  Notes:
  - Difficulties in figuring out how to deal with the data DURING a turn (left/right)
  - Possible solution: Having a gyroscope keep track of the current orientation vs the origin orientation
    this is only a possible solution given that I'm designing this under the assumption that I would use this 
    IR array in a micromouse for a way to solve a maze with standardized design principles
  - Considerations for future design decisions (still assuming this would be in a micromouse for competition):
    - Width of the PCB
    - How much affect would a height difference make when it comes to accuracy and reliability
    - Power consumption/storage: As more components are added onto this project
    - Is knowing the distance from the edge of the build to an obstacle necessary for operation?
  - I think the only way to find out all of the nuances of building an autonomous vehicle is to just go ahead
    and build it! (Buying Motors w/ gearboxes and wheels now)
  */


}
