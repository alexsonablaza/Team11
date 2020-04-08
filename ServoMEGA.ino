#include <Servo.h>
//#include <Brain.h>

int ServoP1 = 7; //Servo Pin
Servo regServ1; //Servo Object 
String inDat = " ";

void setup() 
{
  // put your setup code here, to run once:
  regServ1.attach(ServoP1); //Attach 
  regServ1.write(0);
  Serial.begin (9600); //Activate Serial Comms.
  //ServoWriter(&regServ1);
}
byte ReadOneByte(){
  int ByteRead;
  while(!Serial.available());
  ByteRead = Serial.read();
  Serial.print((char)ByteRead);
  Byte = ByteRead.toInt(); 
  return ByteRead;
}
byte attention = 0;
int recv_byte = 0; //
String inString = "";

void loop()
{
ServoWriter(&regServ1);
  
/*brainValue = serial.readCSV();      //character string with latest brain values
lgamma = serial.readLowGamma();     //reads low gamma waves
hgamma = serial.readHighGamma();    //reads high gamma waves
lbeta = serial.readLowBeta();       //reads low beta waves
hbeta = serial.readHighBeta();      //reads high beta waves
*/
  
}

int ServoWriter(Servo *regServ1)
{
      // put your main code here, to run repeatedly:
  while (Serial.available()== 0) 
  {
    //Check Serial for Data.
  }
  
  /*inDat = Serial.readString();        
  Serial.print("Number Entered: ");
  Serial.println(inDat);
  recv_byte =inDat.toInt(); 

  intHgamma = hgamma.toInt();   //converts string to integer
  intLgamma = lgamma.toInt();
  intLbeta = lbeta.toInt();
  intHbeta = hbeta.toInt();
  */
  
  Serial.print(attention, DEC);
  pos = 180 //position
   
  if (isDigit(attention) && (attention >= 0) || (attention <= 180)) 
  {
  regServ1-> write(pos);
  delayMicroseconds(100);
  }
  else 
  {
      Serial.println ("Enter a Valid Number");
  }
}

