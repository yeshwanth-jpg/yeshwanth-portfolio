/*
 NEW RECONSTRUCTION STARTER — not recovered from the original college project.
 Hardware assumptions: Arduino Uno/Nano, dual H-bridge motor driver, 2 DC motors,
 and a servo-driven gripper. Verify every pin and actuator against your actual setup.
 This is manual serial control, NOT autonomous navigation or obstacle avoidance.
*/
#include <Servo.h>

// Example pin map only. Adapt to your motor driver.
const int L_FWD = 5, L_REV = 6;
const int R_FWD = 9, R_REV = 10;
const int GRIPPER_PIN = 3;
const int GRIPPER_OPEN = 80;   // calibrate safely
const int GRIPPER_CLOSED = 25; // calibrate safely
Servo gripper;

void setMotor(int fwdPin, int revPin, int speedVal) {
  speedVal = constrain(speedVal, -255, 255);
  if (speedVal >= 0) { analogWrite(fwdPin, speedVal); analogWrite(revPin, 0); }
  else { analogWrite(fwdPin, 0); analogWrite(revPin, -speedVal); }
}
void drive(int left, int right) { setMotor(L_FWD,L_REV,left); setMotor(R_FWD,R_REV,right); }
void stopDrive() { drive(0,0); }
void setup() {
  pinMode(L_FWD,OUTPUT); pinMode(L_REV,OUTPUT);
  pinMode(R_FWD,OUTPUT); pinMode(R_REV,OUTPUT);
  stopDrive(); gripper.attach(GRIPPER_PIN); gripper.write(GRIPPER_OPEN);
  Serial.begin(9600);
  Serial.println("Commands: w/s/a/d/x = movement, o/c = gripper open/close");
}
void loop() {
  if (!Serial.available()) return;
  char cmd=Serial.read();
  switch(cmd) {
    case 'w': drive(140,140); Serial.println("Forward"); break;
    case 's': drive(-120,-120); Serial.println("Reverse"); break;
    case 'a': drive(-110,110); Serial.println("Turn left"); break;
    case 'd': drive(110,-110); Serial.println("Turn right"); break;
    case 'x': stopDrive(); Serial.println("Stopped"); break;
    case 'o': gripper.write(GRIPPER_OPEN); Serial.println("Gripper open"); break;
    case 'c': gripper.write(GRIPPER_CLOSED); Serial.println("Gripper closed"); break;
  }
}
