#include <Wire.h>

// define  slave 12c address 
#define SLAVE_ADDR 9

// define  slave answer size 
#define ANSWERSIZE 6

void setup() {
  // intialize I2C communication as MASTER 
  Wire.begin();

  Serial.begin(9600);

}

void loop() {
  delay(100);
  Serial.println("Write data to slave");

  // write a charecter to the slave 
  Wire.beginTransmission(SLAVE_ADDR);

  // Wire.write(0);
  // Wire.endTransmission();

  Serial.println("Received data ..........");
  // Read response from slave 
    // Read back 5 char 
    Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);

    // add char to string
    String response = "";
    while (Wire.available()) {
      char b = Wire.read();
      response += b;
    }

    Serial.print("Data : ");
    Serial.println(response);



}
