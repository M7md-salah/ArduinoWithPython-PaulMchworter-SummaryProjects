int x =1;
int y = 2;
int z = 3;

int cnt = 1;
int dt = 1000;


void setup() {
Serial.begin(9600);
}

void loop() {
x = x+ 3;
y = y+5;
z = z-4;
Serial.print(x);
Serial.print(" , ");
Serial.print(y);
Serial.print(" , ");
Serial.println(z);
delay(dt);
}
