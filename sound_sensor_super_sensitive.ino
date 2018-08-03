//
// Super sensitive disco lights
//

#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 3

boolean DEBUG = 0;

// microphone sensitivity
// lower values higher sensitivity to low sound volume
// Good values between 3 to 10
int sensitivity = 7; 

int sensorPin = A0; // select the input pin for the microphone
int rgbPin[] = {RED_PIN, GREEN_PIN, BLUE_PIN}; // led pins

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

  // Init led color
  if (ledPin > 2) ledPin = 0;
  
  // Light the led 
  analogWrite (rgbPin[ledPin], ledValue);
  
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
  
  // Delay and shift led color
  delay(3);
  ledPin++;
}
