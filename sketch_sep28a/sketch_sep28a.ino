const int ledPin1 = 9;
const int ledPin2 = 10;  // Pin connected to the LED
int ledBrightness = 0;
int fadeAmount = 50;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'i') {
      ledBrightness = ledBrightness + fadeAmount;
      if (ledBrightness >= 255) {
        ledBrightness = 255;
      }
    } else if (command == 'd') {
      ledBrightness = ledBrightness - fadeAmount;
      if (ledBrightness <= 0) {
        ledBrightness = 0;
      }
    }

    analogWrite(ledPin1, ledBrightness);
    analogWrite(ledPin2, ledBrightness);
  }
}
