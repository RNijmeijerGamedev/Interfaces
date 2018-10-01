

// set pins
const int buttonPin1 = 8;
const int buttonPin2 = 9;
const int buttonPin3= 10;
const int X_pin = A1;

boolean bButtonPressed1 = false;
boolean bButtonPressed2 = false;
boolean bButtonPressed3 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  // button 1
  if (digitalRead(buttonPin1)) {
    bButtonPressed1 = false;
  } else {
    bButtonPressed1 = true;
  }

  // button 2
  if (digitalRead(buttonPin2)) {
    bButtonPressed2 = false;
  } else {
    bButtonPressed2 = true;
  }
  // button 3
  if (digitalRead(buttonPin3)) {
    bButtonPressed3 = false;
  } else {
    bButtonPressed3 = true;
  }

  
  Keyboard.begin();
  Serial.begin(38400);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print("X-axis: ");
  Serial.println(analogRead(X_pin));
  //int speed = map(analogRead(X_pin), 0, 1023, -5, 5);
  if ((analogRead(X_pin)) <10){
    Keyboard.press('a');
    Serial.println("Button a is pressed");
    Keyboard.release('a');
  }

   if ((analogRead(X_pin)) >1010h ){
    Keyboard.press('d');
    Serial.println("Button d is pressed");
    Keyboard.release('d');
  }

  
  delay(20);
  if(digitalRead(buttonPin1)){
    if (bButtonPressed1) {
      bButtonPressed1 = false;
      Serial.println("button 1 not pressed");
      
    }
  } else {
    if (!bButtonPressed1) {
      bButtonPressed1 = true;
      Keyboard.press('1');
      Serial.println("Button 1 is pressed");
      Keyboard.release('1');
    }
  }
  // button 2
    if(digitalRead(buttonPin2)){
    if (bButtonPressed2) {
      bButtonPressed2 = false;
      Serial.println("button 2 not pressed");
    }
  } else {
    if (!bButtonPressed2) {
      bButtonPressed2 = true;
      Keyboard.press('2');
      Serial.println("Button 2 is pressed");
      Keyboard.release('2');
    }
  }

  // button 3

    if(digitalRead(buttonPin3)){
    if (bButtonPressed3) {
      bButtonPressed3 = false;
      Serial.println("button 3 not pressed");
    }
  } else {
    if (!bButtonPressed3) {
      bButtonPressed3 = true;
      Keyboard.press('3');
      Serial.println("Button 3 is pressed");
      Keyboard.release('3');
    }
  }



  

}
