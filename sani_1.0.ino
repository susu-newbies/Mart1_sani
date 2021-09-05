int IRSensor = 2; // connect ir sensor to arduino pin 2
int motor = 4 ; // conect Led to arduino pin 13



void setup() 
{

  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (motor, OUTPUT); // Led pin OUTPUT
  Serial.begin(9600);
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  
  Serial.println(statusSensor);
  
  if (statusSensor == 1){
    digitalWrite(motar, LOW); // LED LOW
    Serial.println("not dedected");
  }
  
  else
  {
    digitalWrite(motor, HIGH); // LED High
    Serial.println("Dedected")
  }
  
}
