const int ledPin = 9;     // LED connected to digital pin 9
const int switchPin = 2;  // Switch connected to digital pin 2
int switchState = 0;      // variable to store the state of the switch
int dutyCycle = 50;       // initial duty cycle (in percentage)

void setup() {
  pinMode(ledPin, OUTPUT);    // sets the digital pin as output
  pinMode(switchPin, INPUT);  // sets the digital pin as input
}

void loop() {
  switchState = digitalRead(switchPin);  // read the state of the switch

  // If the switch is pressed, increase duty cycle
  if (switchState == HIGH) {
    dutyCycle += 10;  // increase duty cycle by 10%
    if (dutyCycle > 100) {
      dutyCycle = 100;  // cap duty cycle at 100%
    }
    delay(200);  // debounce delay
  }

  // calculate the ON time based on duty cycle
  int onTime = (dutyCycle * 1000) / 100;  // convert duty cycle percentage to milliseconds

  // turn the LED on for the calculated onTime
  digitalWrite(ledPin, HIGH);
  delay(onTime);

  // turn the LED off for the remaining time
  digitalWrite(ledPin, LOW);
  delay(1000 - onTime);
}
