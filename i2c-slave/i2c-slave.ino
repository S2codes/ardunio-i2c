#include <Wire.h>


// define  slave 12c address 
#define SLAVE_ADDR 9

// define  slave answer size 
#define ANSWERSIZE 5

String answer="Hello";

void setup() {
  // when we give address means intialize as slave 
  Wire.begin(SLAVE_ADDR);

  // funcation to run when data requested from master 
  Wire.onRequest(requestEvent);

  // funcation to run when data recived from master 
  Wire.onReceive(reciveEvent);

  Serial.begin(9600);
  Serial.println("Slave here .......");

}

void reciveEvent(){
  Serial.println("Reciveing data from master");
    // read while data received 
  while (0 < Wire.available()) {
    byte x = Wire.read();
    Serial.println(x);
  }
  Serial.println("Reciveing data from master end =======");

}

void requestEvent(){
  Serial.println("Request data from master");
  byte response[ANSWERSIZE];
    // format answer as array
    for (byte i = 0; i < ANSWERSIZE; i++) {
      response[i] = (byte)answer.charAt(i);
    }

    // send response back to master 
    Wire.write(response, sizeof(response));

  Serial.println("Data sended to master");

}


void loop() {
  delay(100);
}
