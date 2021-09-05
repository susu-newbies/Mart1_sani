const int IRSensor = 2; // connect ir sensor to arduino pin 2
const int motor = 4 ; // for motor 



void setup() 
{

  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (motor, OUTPUT); // motor pin OUTPUT
  Serial.begin(9600);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  
  Serial.println(statusSensor);
  
  if (statusSensor == 1){
    digitalWrite(motar, LOW); // motor relay LOW
    Serial.println("not dedected");
  }
  
  else
  {
    digitalWrite(motor, HIGH); // motor relay  High
    Serial.println("Dedected")
  }
  
}
