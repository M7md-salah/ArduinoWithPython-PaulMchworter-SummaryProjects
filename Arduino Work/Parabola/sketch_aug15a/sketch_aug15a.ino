float sinval;
float cosval;
float j;
float parab;
float parab2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
for (j = -4 ; j<=4; j= j+0.01){
  parab = j*j;
  sinval = sin(j);
  parab2 = parab*sinval;
  Serial.print(parab);
Serial.print(sinval);
Serial.print(",");
Serial.println(cosval);
}


}
