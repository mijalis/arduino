
#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 3
#define LASER 12
int sensorPin = A0; // select the input pin for the potentiometer
int sensorValue = 0; // variable to store the value coming from the sensor
int sensorValuePrevious = 0; // variable to store the value coming from the sensor
int tmp = 0; // variable to store the value coming from the sensor
int tmpm = 0; // variable to store the value coming from the sensor
int ledValue = 0; // variable to store the value coming from the sensor
int threshold = 490; // microphone min value
int rgbPin[] = {RED_PIN, GREEN_PIN, BLUE_PIN}; // led array
int ledPin = 0;

int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor

void setup ()
{
  Serial.begin (9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(LASER, OUTPUT);
  randomSeed(analogRead(0));
}

void loop ()
{
  sensorValuePrevious = sensorValue;
  sensorValue = analogRead (sensorPin);
  tmp = abs(sensorValue - sensorValuePrevious);
  if (tmp < 3) tmp = 0;
  ledValue = constrain(tmp, 0, 255);

  //ledPin = random(3);
  if (ledPin > 2) ledPin = 0;

  // Debugging
  /*Serial.print("sensorValue: ");
  Serial.print(sensorValue, DEC);
  Serial.print(", Previous: ");
  Serial.print(sensorValuePrevious, DEC);
  Serial.print(", tmp: ");
  Serial.print(tmp, DEC);
  Serial.print(", ledValue: ");
  Serial.print(ledValue, DEC);
  Serial.println();
*/
  //digitalWrite (rgbPin[ledPin], HIGH);
  analogWrite (rgbPin[ledPin], ledValue);
   delay(1);
  /*for (int i=0; i <= 250; i = i + 10){
    analogWrite (rgbPin[ledPin], 250-i);
    Serial.println (250-i, DEC);
    }*/
  ledPin++;
}
