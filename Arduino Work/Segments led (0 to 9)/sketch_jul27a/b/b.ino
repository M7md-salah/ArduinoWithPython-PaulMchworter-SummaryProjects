
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

int buttonPin = 9;


int counter = 0;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  
  
  pinMode(buttonPin, INPUT_PULLUP);
}


void showNumber(int vA, int vB, int vC, int vD, int vE, int vF, int vG) {
  digitalWrite(a, vA);
  digitalWrite(b, vB);
  digitalWrite(c, vC);
  digitalWrite(d, vD);
  digitalWrite(e, vE);
  digitalWrite(f, vF);
  digitalWrite(g, vG);
}


void displayDigit(int num) {
  switch (num) {
    case 0: showNumber(1, 1, 1, 1, 1, 1, 0); break;
    case 1: showNumber(0, 1, 1, 0, 0, 0, 0); break;
    case 2: showNumber(1, 1, 0, 1, 1, 0, 1); break;
    case 3: showNumber(1, 1, 1, 1, 0, 0, 1); break;
    case 4: showNumber(0, 1, 1, 0, 0, 1, 1); break;
    case 5: showNumber(1, 0, 1, 1, 0, 1, 1); break;
    case 6: showNumber(1, 0, 1, 1, 1, 1, 1); break;
    case 7: showNumber(1, 1, 1, 0, 0, 0, 0); break;
    case 8: showNumber(1, 1, 1, 1, 1, 1, 1); break;
    case 9: showNumber(1, 1, 1, 1, 0, 1, 1); break;
  }
}

void loop() {
  
  int buttonState = digitalRead(buttonPin);

  
  if (buttonState == LOW) {
    displayDigit(2); 
    
    
  } 
  
  
  else {
    displayDigit(counter); 
    delay(1000);           
    
    counter = counter + 1; 

    if (counter > 9) {
      counter = 0;
    }
  }
}
