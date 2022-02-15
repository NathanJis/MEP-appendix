// first define what certain pins on the board do
#define enable 8
#define xDir 5
#define yDir 6
#define zDir 7
#define xStep 2
#define yStep 3
#define zStep 4

// define variables
int incomingData;
int numSteps;
bool side;
int steps = 3200;
// set current positions to the neutral positions (check if they actually are)
int currentPosx = 1600;
int currentPosy = 1600;
int currentPosz = 1600;
int stepDelay =60;

//function for defining which stepper motor needs to move, the direction pin, the pin that makes the motor step, and the amount of steps taken
void step(boolean dir, byte dirPin, byte stepperPin, int steps)
{
  digitalWrite(dirPin,dir);
  delay(100);
  for (int i =0; i <steps; i++) {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(stepDelay);
  }
}

// setup function for defining what certain pins do, and to initialize serial connection
void setup(){
  Serial.begin(9600);
  pinMode(xDir, OUTPUT);
  pinMode(yDir, OUTPUT);
  pinMode(zDir, OUTPUT);
  pinMode(xStep, OUTPUT);
  pinMode(yStep, OUTPUT);
  pinMode(zStep, OUTPUT);
  pinMode(enable, OUTPUT);
  digitalWrite(enable,LOW);
}

// main function, this listens if any signals come in, and based on that it moves the stepper in a certain direction
void loop(){
  if (Serial.available() >0){
    incomingData = Serial.read();

    if (incomingData == 'A') {
      if (currentPosx >= 1600){
        side = false;
      } else {
        side = true;
      }
      numSteps = abs(currentPosx-1600);
      step(side, xDir, xStep, numSteps);
      currentPosx = 1600;
      Serial.print("x position is: "); 
      Serial.println(currentPosx);
    }

    if (incomingData == 'B' ) {
      side = false;      
      numSteps = currentPosx;
      step(side, xDir, xStep, numSteps);
      currentPosx = 0;
      Serial.print("x position is: "); 
      Serial.println(currentPosx);
    }

    if (incomingData == 'C') {
      side = true;
      numSteps = abs(currentPosx-3200);
      step(side, xDir, xStep, numSteps);
      currentPosx = 3200;
      Serial.print("x position is: "); 
      Serial.println(currentPosx);
    }

    if (incomingData == 'D') {
      if (currentPosy >= 1600){
        side = false;
      } else {
        side = true;
      }
      numSteps = abs(currentPosy-1600);
      step(side, yDir, yStep, numSteps);
      currentPosy = 1600;
      Serial.print("y position is: "); 
      Serial.println(currentPosy);
    }

    if (incomingData == 'E' ) {
      side = false;      
      numSteps = currentPosy;
      step(side, yDir, yStep, numSteps);
      currentPosy = 0;
      Serial.print("y position is: "); 
      Serial.println(currentPosy);
    }

    if (incomingData == 'F') {
      side = true;
      numSteps = abs(currentPosy-3200);
      step(side, yDir, yStep, numSteps);
      currentPosy = 3200;
      Serial.print("y position is: "); 
      Serial.println(currentPosy);
    }

    if (incomingData == 'G') {
      if (currentPosz >= 1600){
        side = false;
      } else {
        side = true;
      }
      numSteps = abs(currentPosz-1600);
      step(side, zDir, zStep, numSteps);
      currentPosz = 1600;
      Serial.print("z position is: "); 
      Serial.println(currentPosz);
    }

    if (incomingData == 'H' ) {
      side = false;      
      numSteps = currentPosz;
      step(side, zDir, zStep, numSteps);
      currentPosz = 0;
      Serial.print("z position is: "); 
      Serial.println(currentPosz);
    }

    if (incomingData == 'I') {
      side = true;
      numSteps = abs(currentPosx-3200);
      step(side, zDir, zStep, numSteps);
      currentPosz = 3200;
      Serial.print("z position is: "); 
      Serial.println(currentPosz);
    }
  }
}
