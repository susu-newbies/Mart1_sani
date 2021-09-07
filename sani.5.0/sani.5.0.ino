/*Serial commands are used to debug the program , in the real time run they are are not needed .
  so the serial commands are commented in the code*/

  // ###### TEAM NEWBIES ########## 


const int IRSensor = 3; // connect ir sensor to arduino pin 2
const int motor1 = 4 ; // for motor
const int motor2 = 5 ;//  ""
const int buzzer = 2   ;// For buzzer
const int ledP = 0 ;// for led
const int ledN = 1 ;


void setup()
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (motor1, OUTPUT); // motor pins OUTPUT
  pinMode (motor2, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode (ledP, OUTPUT);
  pinMode (ledN, OUTPUT);
  //Serial.begin(9600);
}


void loop()
{
  int statusSensor = digitalRead (IRSensor);
 // Serial.println(statusSensor);
  if (statusSensor == 1) // 1 mean idil 0 mean getting signal
  {
    digitalWrite(motor1, LOW); // motor relay LOW
    digitalWrite(motor2, LOW);
    
    //Serial.print(".");
  }
  else
  {
    //Serial.println("Dedected");
    motorON();
    checkexit();
    digitalWrite(buzzer, LOW);
    digitalWrite(ledP, LOW);
    digitalWrite(ledN, LOW);
    delay(500);
  }
}

void motorON()
{
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW); // motor on
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledP,HIGH);
  digitalWrite(ledN,LOW);
  delay(500);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW); // motor off

}


void checkexit() // To confirm that the hand is taken and getting ready for nxt triger
{
  //Serial.println("checking");
  int status = digitalRead (IRSensor);
  while ( status == 0 )
  {
    //humaneffect();
    //Serial.println("plz take the hand");
    status = digitalRead (IRSensor);
  }
}

void humaneffect()
{
    digitalWrite(ledP, LOW);
    digitalWrite(ledN, LOW) ;
    //digitalWrite(buzzer,LOW);
    delay (1000);
    digitalWrite(ledP, HIGH);
    digitalWrite(ledN, LOW);
    //digitalWrite(buzzer,HIGH);
     
  }
