#include <Servo.h>

int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int servoAngle = 0;
int blueled = D12; // select the output pin for LED
int yellowled = D11; // select the output pin for LED
Servo myservo;

void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(9600); //sets serial port for communication
  myservo.attach(A1);
  myservo.write(0);
  pinMode(blueled , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen
  
  if( sensorValue <= 8 )
    {
      servoAngle = 90;
      myservo.write(90);
      digitalWrite(blueled, HIGH);
     
    }
  else{
    myservo.write(0);
    digitalWrite(blueled, LOW);
    servoAngle = 0;  
  }
  
  if(servoAngle == 0){
     digitalWrite(yellowled, HIGH);
    }
  else{
    digitalWrite(yellowled, LOW);
  }
  
}
