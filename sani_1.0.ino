/*Serial commands are used to debug the program , in the real time run they are are not needed .
  so the serial commands are commented in the code*/


const int IRSensor = 2; // connect ir sensor to arduino pin 2
const int motor1 = 4 ; // for motor
const int motor2 = 5 ;//  ""
const int buzzer = 1 ;// For buzzer
const int led = 2 ;// for led

void setup()
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (motor1, OUTPUT); // motor pins OUTPUT
  pinMode (motor2,OUTPUT);
  pinMode (buzzer,OUTPUT);
  pinMode (led,OUTPUT);
  //Serial.begin(9600);
}


void loop()
{
  int statusSensor = digitalRead (IRSensor);
  //Serial.println(statusSensor);
  if (statusSensor == 1) // 1mean idil 0 mean getting signal
  {
    digitalWrite(motor1, LOW); // motor relay LOW
    digitalWrite(motor2,LOW);
    //Serial.print(".");
  }
  else
  {
  //Serial.println("Dedected");
    motorON();
    checkexit();
  }
}

void motorON()
 {
  digitalWrite(motor1, HIGH); 
  digitalWrite(motor2,LOW);// motor on
  digitalWrite(buzzer,HIGH);
  digitalWrite(LED,HIGH);
  delay(300);
  digitalWrite(motor1, LOW); 
  digitalWrite(motor2,LOW);// motor off
  digitalWrite(buzzer,LOW);
  digitalWrite(LED,LOW);
 }


void checkexit()
 {
  //Serial.println("checking");
  int status = digitalRead (IRSensor); 
  while( status == 0 )
   {
    //Serial.println("plz take the hand");
    status = status = digitalRead (IRSensor);
   }
  }
