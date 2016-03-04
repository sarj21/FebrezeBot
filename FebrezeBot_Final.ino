int leftDrive, LBool1, LBool2;
int rightDrive, RBool1, RBool2;
int firePin, firePin2, firePWM;
int var;

enum direction {leftD, rightD, forwardD, backD, brakeD};

direction dir = brakeD;

/*       ^1
  <-4      ->2
       v3
*/
// brake = 5
// fire = 6
void setup() {
 LBool1 = 9; //forward
 LBool2 = 8; //back

 firePin = 4; // fire pin
 firePWM = 5; // pwm
 firePin2 = 3;
 
 RBool1 = 6; // forward
 RBool2 = 7; // back

 leftDrive = 11;
 rightDrive = 10;
 pinMode(leftDrive, OUTPUT);
 pinMode(LBool1, OUTPUT);
 pinMode(LBool2, OUTPUT);

 pinMode(rightDrive, OUTPUT);
 pinMode(RBool1, OUTPUT);
 pinMode(RBool2, OUTPUT);

 pinMode(firePin, OUTPUT);
 pinMode(firePin2, OUTPUT);
 pinMode(firePWM, OUTPUT);
 
 Serial.begin(9600);
}

void loop() {
 forward();
 // put your main code here, to run repeatedly:
 while (!Serial.available());
 var = Serial.read();
 if (var == '1') {
   //forward
   if (dir != forwardD) {
     brake();
   }
   forward();
   dir = forwardD;
 }
 else if (var == '3') {
   //backwards
   if (dir != backD) {
     brake();
   }
   back();
   dir = backD;
 }
 else if (var == '2') {
   //right
   if (dir != rightD) {
     brake();
   }
  turnRightDrive();
   dir = rightD;
 }
 else if (var == '4') {
   //left
   if (dir != leftD) {
     brake();
   }
   turnLeftDrive();
   dir = leftD;
 }
 else if (var == '5') {
   //brake
   brake();
   dir = brakeD;
 }
 else if (var == '6') {
  fire();
 }
 else {
   Serial.println("Read");
 }
 var = 0;
}

void leftDriveForw() {
 digitalWrite(LBool1, 1);
 digitalWrite(LBool2, 0);
 analogWrite(leftDrive, 255);
}

void leftDriveBack() {
 digitalWrite(LBool1, 0);
 digitalWrite(LBool2, 1);
 analogWrite(leftDrive, 255);
}

void rightDriveForw() {
 digitalWrite(RBool1, 1);
 digitalWrite(RBool2, 0);
 analogWrite(rightDrive, 255);
}

void rightDriveBack() {
 digitalWrite(RBool1, 0);
 digitalWrite(RBool2, 1);
 analogWrite(rightDrive, 255);
}

void brake() {
 digitalWrite(LBool1, 0);
 digitalWrite(LBool2, 0);
 digitalWrite(RBool1, 0);
 digitalWrite(RBool2, 0);
 analogWrite(rightDrive, 0);
 analogWrite(leftDrive, 0);
}

void forward() {
 leftDriveForw();
 rightDriveForw();
}

void back() {
 leftDriveBack();
 rightDriveBack();
}

void turnRightDrive() {
 rightDriveBack();
 leftDriveForw();
}

void turnLeftDrive() {
 rightDriveForw();
 leftDriveBack();
}

void fire() {
 /*
 digitalWrite(firePin, 1);
 digitalWrite(firePin2, 0);
 analogWrite(firePWM, 255);
 delay(1000);
 */
 digitalWrite(firePin, 0);
 digitalWrite(firePin2, 1);
 delay(500);
 digitalWrite(firePin, 0);
 digitalWrite(firePin2, 0);
 analogWrite(firePWM, 0);
 
}
//added firing pin2
