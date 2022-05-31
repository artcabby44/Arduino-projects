#include <SoftwareSerial.h>
SoftwareSerial sim(10, 11); //tx rx
int inByte = '0';

int _timeout;
String _buffer;
String number = "+639951656160"; //-> change with your number
void setup() {
  delay(7000); //delay for 7 seconds to make sure the modules get the signal
  Serial.begin(9600);
  _buffer.reserve(50);
  Serial.println("Sistem Started...");
  sim.begin(9600);
  delay(1000);
}
void loop() {
  
    if (Serial.available() > 0) {
    inByte = (Serial.read());
    Serial.print("inByte "); Serial.println(inByte);

    if (inByte == '0') {

      SendMessage();

    }


  }
}
void SendMessage()
{
  //Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(200);
  //Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number + "\"\r"); //Mobile phone number to send message
  delay(200);
  String SMS = "Hello, I'm uder the water. Help me";
  sim.println(SMS);
  delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z
  delay(200);
  _buffer = _readSerial();
}

String _readSerial() {
  _timeout = 0;
  while  (!sim.available() && _timeout < 12000  )
  {
    delay(13);
    _timeout++;
  }
  if (sim.available()) {
    return sim.readString();
  }
}
