
#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 3
boolean DEBUG = 0;
// microphone sensitivity
// lower values higher sensitivity to low sound volume
// Good values between 3 to 10
int sensitivity = 7; 

int sensorPin = A0; // select the input pin for the potentiometer
int rgbPin[] = {RED_PIN, GREEN_PIN, BLUE_PIN}; // led array

// Initialisations
int sensorValue = 0; // variable to store the value coming from the sensor
int sensorValuePrevious = 0; // variable to store the value coming from the sensor
int delta = 0; // variable to store the value coming from the sensor
int ledValue = 0; // variable to store the value coming from the sensor
int ledPin = 0;

void setup ()
{
  Serial.begin (9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  randomSeed(analogRead(0));
}

void loop ()
{
  sensorValuePrevious = sensorValue;
  sensorValue = analogRead (sensorPin);
  delta = abs(sensorValue - sensorValuePrevious);
  if (delta < sensitivity) delta = 0;
  ledValue = constrain(delta, 0, 255);

  //ledPin = random(3);
  if (ledPin > 2) ledPin = 0;

  // Debugging
  if (DEBUG) {
    Serial.print("sensorValue: ");
    Serial.print(sensorValue, DEC);
    Serial.print(", Previous: ");
    Serial.print(sensorValuePrevious, DEC);
    Serial.print(", delta: ");
    Serial.print(delta, DEC);
    Serial.print(", ledValue: ");
    Serial.print(ledValue, DEC);
    Serial.println();
  }
  //digitalWrite (rgbPin[ledPin], HIGH);
  analogWrite (rgbPin[ledPin], ledValue);
  delay(3);
  /*for (int i=0; i <= 250; i = i + 10){
    analogWrite (rgbPin[ledPin], 250-i);
    Serial.println (250-i, DEC);
    }*/
  ledPin++;
}
