#define enable 8
#define xDir 5
#define yDir 6
#define zDir 7
#define xStep 2
#define yStep 3
#define zStep 4


int steps = 3200;
int stepDelay =500;

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

void setup(){
  pinMode(xDir, OUTPUT);
  pinMode(yDir, OUTPUT);
  pinMode(zDir, OUTPUT);
  pinMode(xStep, OUTPUT);
  pinMode(yStep, OUTPUT);
  pinMode(zStep, OUTPUT);
  pinMode(enable, OUTPUT);
  digitalWrite(enable,LOW);
}

void loop(){
  Serial.println("message");
  step(false,yDir,yStep,3200);
  delay(2000);
  step(true,yDir,yStep,3200);
  delay(2000);
}
