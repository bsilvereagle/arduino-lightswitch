#include <Servo.h>

const int ledPin = 3;
const int switchUpPin = 4;
const int servoPin = 11;

boolean upPushed = false;
boolean downPushed = false;
boolean elsePushed = false;

Servo lightSwitch;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Alive");
  
  //Set Pin Modes
  pinMode(ledPin,OUTPUT);
  pinMode(switchUpPin,INPUT);
  pinMode(switchDownPin,INPUT);
  pinMode(switchElsePin,INPUT);
  //Enable Pullups
  digitalWrite(switchUpPin,HIGH);
  digitalWrite(switchElsePin,HIGH);
  digitalWrite(switchDownPin,HIGH);
  //Set LED false
  digitalWrite(ledPin,LOW);
  //Attach Servo  
  lightSwitch.attach(servoPin);
  lightSwitch.write(40); //Set initial position
}

// the loop routine runs over and over again forever:
void loop() {
  //Check for Xbee communication
  if(Serial.available() > 0)
  {
    switch(Serial.read())
    {
      case 'o':
        moveSwitchUp();
        break;
      case 'f':
        moveSwitchDown();
        break;
      default:
        break;
    }
  }
  
  //Check for switches
  // If pressed up, turn on light
  // If pressed down, turn off light
  // If pressed any other way, invert the state
  if(!digitalRead(switchUpPin) && (upPushed==false))
  {
    //UpHas been hit
    upPushed==true;
    moveSwitchUp();
    delay(250);
  }
  if(digitalRead(switchUpPin) && (upPushed==true))
  {
    upPushed=false;
  }
  //Check Down
  if(!digitalRead(switchDownPin) && (downPushed==false))
  {
    //UpHas been hit
    downPushed==true;
    moveSwitchDown();
    delay(250);
  }
  if(digitalRead(switchUpPin) && (upPushed==true))
  {
    upPushed=false;
  }
  //Check Else
  if(!digitalRead(switchElsePin) && (elsePushed==false))
  {
    //UpHas been hit
    elsePushed==true;
    digitalRead(ledPin) ? moveSwitchDown() : moveSwitchUp(); 
    delay(250);
  }
  if(digitalRead(switchElsePin) && (elsePushed==true))
  {
    upPushed=false;
  }
}

void moveSwitchUp()
{
   digitalWrite(ledPin,HIGH);
   Serial.println("On"); 
   lightSwitch.write(80);
}

void moveSwitchDown()
{
  digitalWrite(ledPin,LOW);
  Serial.println("Off");
  lightSwitch.write(20);
}
