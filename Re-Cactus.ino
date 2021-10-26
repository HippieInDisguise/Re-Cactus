#include <Servo.h>

int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int servoAngle = 0;
int blueled = D12; // select the output pin for LED
int yellowled = D11; // select the output pin for LED
int honeybee = 0; // check for honeybee if its there on the flower
float honeybeestate = 0; //time the honeybee will stay on the flower
int honeyfly = 0; // honeybee fly check
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
  
  if( sensorValue <= 50 )
    {
       servoAngle = 90;
       for (int bloom = 0; bloom <= 90; bloom++) {
              myservo.write(bloom);
              delay(300000);
       }
      digitalWrite(blueled, HIGH);
     
    }
  if(sensorValue >= 110)
    {
      
      digitalWrite(blueled, LOW);
       for (int bloom = 90; bloom >= 0; bloom--) {
              myservo.write(bloom);
              delay(300000);
       }
      servoAngle = 0;  
    }
  
  if(servoAngle == 0){
     honeybee = random(0,25);
     if(honeybee == 7){
        digitalWrite(yellowled, HIGH);
        honeyfly = 1;
        honeybeestate = millis();
     }
    }
  if (honeyfly == 1){
    if (millis() - honeybeestate >= 300000 )
    digitalWrite(yellowled, LOW);
  }
  
}
