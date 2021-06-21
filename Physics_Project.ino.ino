// Coded by Milica G.

// This line imports the stepper motor library 
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;

int ledPin = 13;

// This line chooses the ports where the stepper motor will be connected. 
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


void setup()
{
  // This part states the rotation speed of the motor which is measured in RPM
  myStepper.setSpeed(60);
  // This part initializes the serial port:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  // This is the top of the loop
  // This part makes the motor go right and turn on the LED
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  digitalWrite(ledPin, HIGH);
  delay(500);

  // This part make the motor go left and turn off the LED
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  digitalWrite(ledPin, LOW);
  delay(500); // This line waits half a second then the  will go back to the top of the loop
 
  
}
