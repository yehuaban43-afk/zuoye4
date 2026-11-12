const int buttonPin = 2;  
const int ledPin = 3;     

int ledState = 0;        
int buttonState = LOW;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

unsigned long previousMillis = 0;
bool ledFlashState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        ledState++;
        if (ledState > 3) {
          ledState = 0; 
        }
      }
    }
  }
  lastButtonState = reading;

  unsigned long currentMillis = millis();

  switch (ledState) {
    case 0: 
      digitalWrite(ledPin, HIGH);
      break;

    case 1: 
      if (currentMillis - previousMillis >= 500) {
        previousMillis = currentMillis;
        ledFlashState = !ledFlashState;
        digitalWrite(ledPin, ledFlashState);
      }
      break;

    case 2:
      if (currentMillis - previousMillis >= 200) {
        previousMillis = currentMillis;
        ledFlashState = !ledFlashState;
        digitalWrite(ledPin, ledFlashState);
      }
      break;

    case 3:
      if (currentMillis - previousMillis >= 60) {
        previousMillis = currentMillis;
        ledFlashState = !ledFlashState;
        digitalWrite(ledPin, ledFlashState);
      }
      break;
  }
}