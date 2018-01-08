#include <Servo.h>
Servo myservoTop;//Top Motor
Servo myservoBottom;//Bottom Motor
boolean stayleft = false;
boolean stayright = false;
boolean stayforward = false;
boolean staybackward = false;
//boolean restart=false;
int button = 52; // button that allows "Up" function (crane up and down)
int buttonstate = 1;
int moving[100];
int reverse[100];
int movenum = 0;
void setup() {
  pinMode(button, INPUT_PULLUP);
  myservoTop.attach(24);
  myservoBottom.attach(22);
  Serial.begin(9600);
  //  pinMode(A      if (reverse[i] == 1){
//  forward();
//} ;
//  pinMode(A7, INPUT_PULLUP);  // change the pinMode to INPUT_PULLUP to attach
//                   // an internal 10k resistor to the pin and make the button responsive
}
void forward() {// reponsible for forward movement

  moving[movenum] = 1;
  for (int i = 0; i < 10 ; i++) {
    myservoTop.write(0);
    myservoBottom.write(90);
    Serial.print("right");
    delay(10);
  }
  movenum += 1;
}
void backward() {// reponsible for forward movement

  moving[movenum] = 2;
  for (int i = 0; i < 10 ; i++) {
    myservoTop.write(180);
    myservoBottom.write(90);
    Serial.print("left");
    delay(10);
  }
  movenum += 1;
}
void left() {// reponsible for forward movement

  moving[movenum] = 3;
  for (int i = 0; i < 122 ; i++) {
    myservoTop.write(90);
    myservoBottom.write(0);
    Serial.print("forward");
    delay(10);
  }
  movenum += 1;
}
void right() {// reponsible for forward movement

  moving[movenum] = 4;
  for (int i = 0; i < 64 ; i++) {
    myservoTop.write(90);
    myservoBottom.write(180);
    Serial.print("backward");
    delay(10);
  }
  movenum += 1;
}
void still() {//acts to stop motors when no directions are in place or only x-axis is used

  myservoTop.write(90);
  myservoBottom.write(90);
  Serial.print("Still");

}
void loop() {
  buttonstate = digitalRead(button); // two lines that allow movement for checking button
  Serial.println(buttonstate);//prints button state
  int yIn = analogRead(A2); // senses where in the y axis the direction corresponds to
  int xIn = analogRead(A1); // senses where in the x axis the direction corresponds to
  if (yIn > 700) { // if joystick is moved in the down direction
    stayforward == true;
    forward();
  } else if (yIn < 300) { // if joystick is moved in the up direciton
    staybackward == true;
    backward();
    //  } else if {
  }
  //    still(); // sits still otherwise
  //  }
  if (xIn > 700) { // if joystick is moved in the right direction
    stayright == true;
    right();
  } else if (xIn < 300) { // if joystick is moved in the left direction
    stayleft == true;
    left();
  }
  //    else{

  //      still();// otherwise sits still
  //    }
  if (stayleft == true) {
    left();
    stayleft = false;
  }
  
  if (stayright == true) {
    right();
    stayright=false;
  }
  if (stayforward == true) {
    forward();
  }
  if (staybackward == true) {
    backward();
  }
  if (buttonstate == 0) { // if button in joystick is pressed
//    restart=false;
    for (int i = movenum; i >= 0; i--) {
      reverse[i] = moving[i];
    }
    for (int i = movenum; i >= 0; i--) {
      if (reverse[i] == 1) {
        forward();
      }
      else if (reverse[i] == 2) {
        backward();
      }
      else  if (reverse[i] == 3) {
        left();
      }
      else if (reverse[i] == 4) {
        right();
      }
    }
//    for (int i = 0; i <= movenum; i++) {
//      if (reverse[i] == 1) {
//        forward();
//      }
//      else if (reverse[i] == 2) {
//        backward();
//      }
//      else  if (reverse[i] == 3) {
//        left();
//      }
//      else if (reverse[i] == 4) {
//        right();
//      }
//    }
movenum=0;
  }
//  if buttonstate==1{
//   restart=true;
//  }
//  if restart=true(
//
//  //  forward();
//  //  backward();
//  //  left();
//  //  right();
}


