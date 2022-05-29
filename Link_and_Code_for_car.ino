char t;
#include<Servo.h>
Servo Myservo;
int pos;

void setup() {
  pinMode(11, OUTPUT);  //left motors forward
  pinMode(12, OUTPUT);  //left motors reverse
  pinMode(13, OUTPUT);  //right motors forward
  pinMode(10, OUTPUT);  //right motors reverse
  Serial.begin(9600);
  Myservo.attach(4);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'F') {          //move forward(all motors rotate in forward direction)
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
  }

  else if (t == 'B') {    //move reverse (all motors rotate in reverse direction)
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
  }

  else if (t == 'L') {
    digitalWrite(13, HIGH); //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  }

  else if (t == 'R') {    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite(11, HIGH);
  }



  else if (t == 'S') {    //STOP (all motors stop)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    for (pos = 90; pos >= 0; pos--) {
      Myservo.write(pos);
      delay(15);
    }
    delay(1000);

    for (pos = 0; pos <= 90; pos++) {
      Myservo.write(pos);
      delay(15);
    }
    delay(1000);


    for (pos = 90; pos <= 180; pos++) {
      Myservo.write(pos);
      delay(15);
    }

    delay(1000);

    for (pos = 180; pos <= 90; pos--) {
      Myservo.write(pos);
      delay(15);
    }

    delay(1000);
    //
    for (pos = 180; pos >= 90; pos--) {
      Myservo.write(pos);
      delay(15);
    }

  }


  delay(100);
}
//Link to the app used for coummunication is given below : 
//https://play.google.com/store/apps/details?id=com.buncaloc.carbluetoothrc
