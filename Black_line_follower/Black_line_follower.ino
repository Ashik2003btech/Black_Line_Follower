#define MOTOR1_A D2
#define MOTOR1_B D1
#define MOTOR2_A D4
#define MOTOR2_B D3
#define LEFT_IR_PIN D6
#define RIGHT_IR_PIN D5

#define MOTOR_SPEED 150

// Setting up predefined conditions
void moveForward() {
  digitalWrite(MOTOR1_A, LOW);
  analogWrite(MOTOR1_B, MOTOR_SPEED);
  digitalWrite(MOTOR2_A, LOW);
  analogWrite(MOTOR2_B, MOTOR_SPEED);
}

void turnLeft() {
  digitalWrite(MOTOR1_A, LOW);
  analogWrite(MOTOR1_B, MOTOR_SPEED);
  analogWrite(MOTOR2_A, MOTOR_SPEED);
  digitalWrite(MOTOR2_B, LOW);
}

void turnRight() {
  analogWrite(MOTOR1_A, MOTOR_SPEED);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, LOW);
  analogWrite(MOTOR2_B, MOTOR_SPEED);
}

void halt() {
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, LOW);
}

void setup() {
  // put your setup code   here, to run once:
  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR1_B, OUTPUT);
  pinMode(MOTOR2_A, OUTPUT);
  pinMode(MOTOR2_B, OUTPUT);
  pinMode(LEFT_IR_PIN, INPUT);
  pinMode(RIGHT_IR_PIN, INPUT);

  Serial.begin(115200);
  halt();

  pinMode(D7, OUTPUT);
  analogWrite(D7, 200);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean leftSensorValue = digitalRead(LEFT_IR_PIN);
  boolean rightSensorValue = digitalRead(RIGHT_IR_PIN);

  int cmd;
  if (!leftSensorValue && !rightSensorValue) cmd = 1;
  else if (!leftSensorValue && rightSensorValue) cmd = 3;
  else if (leftSensorValue && !rightSensorValue) cmd = 2;
  else cmd = 4;
  
  Serial.println(cmd);
  switch(cmd) {
    case 1:
      moveForward();
      break;
    case 2:
      turnRight();
      break;
    case 3:
      turnLeft();
      break;
    case 4:
      halt();
      break;
  }
}
