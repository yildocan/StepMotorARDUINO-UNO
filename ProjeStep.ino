#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin Definitions
const int led1 = 13; 
const int led2 = 12; 
const int motorPin1 = 2;
const int motorPin2 = 3;
const int motorPin3 = 4;
const int motorPin4 = 5;

// I2C address of the LCD screen
#define I2C_ADDRESS 0x27

// Create the LCD object
LiquidCrystal_I2C lcd(I2C_ADDRESS, 16, 2);

void setup() {
  // Start the I2C communication
  Wire.begin();
  
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  
  // Set LED and motor pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  // Start serial communication
  Serial.begin(9600);
  
  // Show the menu on the LCD screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1. Clockwise");
  lcd.setCursor(0, 1);
  lcd.print("2. Counter-Clockwise");
}

void loop() {
  // Read the serial value
  int direction = Serial.read();
  
  // Check if a value was received
  if (direction >= 0) {
    // Clear the LCD screen if a different direction is chosen
    if (direction == '1' || direction == '2') {
      lcd.clear();
    }
    
    // Rotate the motor in one direction
    if (direction == '1') {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      lcd.setCursor(0, 0);
      lcd.print("Clockwise");
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      delay(500);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin4, LOW);
    }
    
    // Rotate the motor in the other direction
    if (direction == '2') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("Counter-Clockwise");
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin3, LOW);
      digitalWrite(motorPin4, HIGH);
      digitalWrite(motorPin1, LOW);
      delay(500);
      digitalWrite(motorPin2, LOW);
      digitalWrite(motorPin3, LOW);
      }
  }
}




