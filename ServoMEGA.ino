#include <Servo.h>
#include <Brain.h>

int ServoP1 = 7; //Servo Pin
Servo regServ1; //Servo Object 
String inDat = " ";
void setup() {
  // put your setup code here, to run once:
  regServ1.attach(ServoP1); //Attach 
  regServ1.write(0);
  Serial.begin (9600); //Activate Serial Comms.
  //ServoWriter(&regServ1);
}
int recv_byte = 0; //
String inString = "";
void loop()
{
ServoWriter(&regServ1);
  
brainValue = serial.readCSV();      //character string with latest brain values
lgamma = serial.readLowGamma();     //reads low gamma waves
hgamma = serial.readHighGamma();    //reads high gamma waves
lbeta = serial.readLowBeta();       //reads low beta waves
hbeta = serial.readHighBeta();      //reads high beta waves
  
}
int ServoWriter(Servo *regServ1)
{
      // put your main code here, to run repeatedly:
  while (Serial.available()== 0) {
    //Check Serial for Data.
  }
  inDat = Serial.readString();
  Serial.print("Number Entered: ");
  Serial.println(inDat);
  recv_byte =inDat.toInt(); 
  if (isDigit(recv_byte) && (recv_byte >= 0) || (recv_byte <= 180)) {
  regServ1-> write(recv_byte);
  delayMicroseconds(100);
  }
  else {
      Serial.println ("Enter a Valid Number");
  }
}

