#include <Motor_TB.h>

Motor_TB robot(9,8,7,3,5,4,11,10,2);

//global vars
//Dark = 1 | White = 0
int leftIR = 6;
int rightIR = 12;

int  leftIRdata;
int  rightIRdata;

void setup() {
  // put your setup code here, to run once:
  leftIRdata = digitalRead(leftIR); //read the left IR 
  rightIRdata = digitalRead(rightIR); //read the right IR 
  
  Serial.begin(9600);
  Serial.println("Intialization Complete!");

  robot.go(100,-100);
  delay(750);
  robot.stopMotors();

}

void lineAvoid() {
  //leftIRdata = digitalRead(leftIR); //read the left IR 
  //rightIRdata = digitalRead(rightIR); //read the right IR 

  if (leftIRdata == 0 && rightIRdata == 0){
    robot.go(90,90);
    delay(200);
    robot.stopMotors();
    delay(100);
    Serial.println("going forward");
  }
  else if (leftIRdata != 0 || rightIRdata != 0){
    robot.go(-100, -100);
    Serial.println("going backward");
    delay(1000);
    robot.go(-100,100);
    Serial.println("turning");
    delay(750);
    robot.stopMotors();
  }
  else if (leftIRdata != 0 && rightIRdata != 0){
    robot.go(-100, -100);
    Serial.println("going backward");
    delay(1000);
    robot.go(-100,100);
    Serial.println("turning");
    delay(750);
    robot.stopMotors();
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  lineAvoid();
}
