#include <Wire.h>  // Include the Wire library for I2C communication

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  while (!Serial);     // Wait for serial port to connect

  Wire.begin();  // Initialize I2C communication
  Serial.println("\nI2C Scanner");  // Print message to Serial Monitor
}

void loop() {
  byte error, address;  // Declare variables for error and address
  int deviceCount = 0;  // Initialize device count to 0

  Serial.println("Scanning...");  // Print message to Serial Monitor

  // Loop through I2C addresses from 1 to 127
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);  // Begin transmission to address
    error = Wire.endTransmission();    // End transmission and store error code

    // If no error, print device address
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");  // Print leading 0 if address is less than 16
      Serial.print(address, HEX);  // Print address in hexadecimal format
      Serial.println(" !");  // Print exclamation mark
      deviceCount++;  // Increment device count
    } 
    // If error 4, print unknown error
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");  // Print leading 0 if address is less than 16
      Serial.println(address, HEX);  // Print address in hexadecimal format
    }
  }

  // Print message based on device count
  if (deviceCount == 0) {
    Serial.println("No I2C devices found\n");
  } 
  else {
    Serial.println("Scan complete\n");
  }

  delay(5000);  // Wait 5 seconds before scanning again
}
