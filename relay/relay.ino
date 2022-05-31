const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int RELAY_PIN  = 3; // Arduino pin connected to relay's pin

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(RELAY_PIN, OUTPUT);        // set arduino pin to output mode
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN); // read new state

  if (buttonState == HIGH) {
    Serial.println("The button is being pressed");
    digitalWrite(RELAY_PIN, LOW); // turn on
  }
  else
  if (buttonState == LOW) {
    Serial.println("The button is unpressed");
    digitalWrite(RELAY_PIN, HIGH);  // turn off
  }                                                                                                                                                                                                                                                                                     
}
