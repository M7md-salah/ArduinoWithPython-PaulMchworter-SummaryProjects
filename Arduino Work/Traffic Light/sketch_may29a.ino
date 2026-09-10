int yellow = 5;
int red = 6 ;
int green = 7 ;


void setup() {
  // put your setup code here, to run once:
 pinMode( yellow ,  OUTPUT);
 pinMode(  red , OUTPUT);
 pinMode( green , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite( yellow , HIGH);
delay(100);
digitalWrite( yellow , LOW);
delay(100);

digitalWrite( red , HIGH);
delay(100);
digitalWrite( red , LOW);
delay(100);

digitalWrite( green , HIGH);
delay(100);
digitalWrite( green , LOW);
delay(100);

}
