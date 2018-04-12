// Ground Control Station Arduino Code
// Final Year Project
// 'Autonomously Landing a Drone on a Moving Target'
// Dara Molloy - 4BP 

#include <SoftwareSerial.h>
SoftwareSerial HC12(8, 9); // HC-12 TX Pin, HC-12 RX Pin

void setup() {
  //Initialising both serial communication links and switch
  pinMode(2,INPUT);
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
}
void loop() {
  if (digitalRead(2) == HIGH){        //If the switch is asserted 
    while (Serial.available()) {      // If Serial monitor has data
        HC12.write(Serial.read());    // Send that data to HC-12
    }
  }
  else{                               //If switch isnt asserted
    HC12.write(",,X9999,,");          //Write 'OFF' string ,,X9999,, to HC-12
    HC12.flush();                     //Flush serial link
    delay(200);
  }
}
