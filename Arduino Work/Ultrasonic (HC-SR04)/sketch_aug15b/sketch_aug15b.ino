int triggerpin = 3;
int echopin  = 2;

float distance ;
long time;

void setup ()
{
Serial.begin(9600);
  pinMode(triggerpin , OUTPUT);
  pinMode(echopin , INPUT);
}

void loop ()
{

  digitalWrite(triggerpin , LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin , HIGH);
  delayMicroseconds(2);
  time = pulseIn (echopin, HIGH);
  distance = 0.01715* time;
  Serial.print("distance = ");
  Serial.println(distance);
}