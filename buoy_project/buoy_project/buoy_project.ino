int outPin = 9;

void setup() {
  pinMode(outPin, OUTPUT);  // sets the pin as output
}

void loop() {
  analogWrite(outPin, 101); // analogWrite values from 0 to 255
}
