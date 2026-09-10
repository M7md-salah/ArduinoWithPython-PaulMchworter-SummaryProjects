int redPin = 9;
int count = 0;


void setup() {
  pinMode(redPin , OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("enter Y to turn on the Led : ");

}

void loop() { 
  if(Serial.available()){

    char ch = Serial.read();

    if(ch == 'y' || ch == 'Y'){
      digitalWrite(redPin , HIGH);
      Serial.println("you have turned on the led !! ");
      Serial.print("the led was off for ");
      Serial.print(count);
      Serial.println (" seconds ");
      Serial.println("if u want to switch it off , simply enter N or n !!");
      count = 0;
    }
    if (ch == 'n' || ch == 'N'){
      digitalWrite(redPin , LOW);
      Serial.println("you have turned off the led !! ");
      Serial.print("the led was on for ");
      Serial.print(count);
      Serial.println (" seconds ");
      Serial.println("if u want to switch it off , simply enter Y or y !!");
      count = 0;
    }
  }
  delay(1000);
  count += 1;
}
