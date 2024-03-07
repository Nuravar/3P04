// ARDUINO RC CAR WITH 2 REAR WHEELS MOTORS AND SG90 SERVO STEERING 

char t;
#include <Servo.h>
Servo myservo;  // create servo object to control a servo 

void setup()

{

pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(9,OUTPUT);   //Led
pinMode(5,OUTPUT);   //SG90 steering motor
myservo.attach(5);  // attaches the servo on pin 5 to the servo object
Serial.begin(9600);

}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}

if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  myservo.write(90);                  // sets the servo position according to the scaled value
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  myservo.write(90);                  // sets the servo position according to the scaled value
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  digitalWrite(11,HIGH);
  myservo.write(60);                  // sets the servo position according to the scaled value
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(13,HIGH);
  myservo.write(120);                  // sets the servo position according to the scaled value
}

 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  myservo.write(90); 
}
delay(100);
}
