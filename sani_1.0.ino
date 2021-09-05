const int IRSensor = 2; // connect ir sensor to arduino pin 2
const int motor1 = 4 ; // for motor
int motor2 = 5 ;



void setup()
{

  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (motor1, OUTPUT); // motor pins OUTPUT
  pinMode (motor2,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  //Serial.println(statusSensor);

  if (statusSensor == 1) {
    digitalWrite(motor1, LOW); // motor relay LOW
    digitalWrite(motor2,LOW);
    Serial.println("not dedected");
  }

  else
  {
    
    Serial.println("Dedected");
    motorON();
    checkexit();
  }
}

void motorON(){
  
  digitalWrite(motor1, HIGH); 
  digitalWrite(motor2,LOW);// motor relay  High
  delay(500);
  digitalWrite(motor1, LOW); 
  digitalWrite(motor2,LOW);// motor relay  High
  
  }
void checkexit(){
  Serial.println("checking");
  int status = digitalRead (IRSensor);
   while( status == 0 ){
    
    Serial.println("plz take the hand");
    status = status = digitalRead (IRSensor);
    
  }
  
  }
