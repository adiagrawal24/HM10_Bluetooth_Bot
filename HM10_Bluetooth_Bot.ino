#include <SoftwareSerial.h>

// Define SoftwareSerial object for HM10 Bluetooth module
SoftwareSerial HM10(2, 3); // RX = 2, TX = 3

char reading;
String inData = "";

// Define motor control pins
int D5 = 8;
int D6 = 9;
int D7 = 10;
int D8 = 11;

void setup()
{
  // Initialize Serial communication for debugging
  Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");

  // Initialize SoftwareSerial for communication with HM10 Bluetooth module
  HM10.begin(9600);

  // Set motor control pins as OUTPUT
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
}

void loop()
{
  // Listen for data from HM10 Bluetooth module
  HM10.listen();

  // Read incoming characters from Bluetooth module
  if (Serial.available())
  {
    reading = HM10.read();
    inData = String(reading);
    Serial.write(reading);
  }

  // Forward the received characters to the Bluetooth module
  if (Serial.available())
  {
    delay(10);
    HM10.write(Serial.read());
  }

  // Control the robot based on received commands
  if (reading == "F")
  {
    digitalWrite(D5, HIGH);
    digitalWrite(D6, LOW);
    digitalWrite(D7, HIGH);
    digitalWrite(D8, LOW);
    Serial.println("Forward");
  }
  else if (reading == "B")
  {
    digitalWrite(D5, LOW);
    digitalWrite(D6, HIGH);
    digitalWrite(D7, LOW);
    digitalWrite(D8, HIGH);
    Serial.println("Backward");
  }
  else if (reading == "R")
  {
    digitalWrite(D5, HIGH);
    digitalWrite(D6, LOW);
    digitalWrite(D7, LOW);
    digitalWrite(D8, HIGH);
    Serial.println("Right");
  }
  else if (reading == "L")
  {
    digitalWrite(D5, LOW);
    digitalWrite(D6, HIGH);
    digitalWrite(D7, HIGH);
    digitalWrite(D8, LOW);
    Serial.println("Left");
  }
  else if (reading == "S")
  {
    digitalWrite(D5, LOW);
    digitalWrite(D6, LOW);
    digitalWrite(D7, LOW);
    digitalWrite(D8, LOW);
    Serial.println("Stop");
  }
}
