#define enableleft 5
#define inoneleft 3
#define intwoleft 4

#define enableright 9  //connect chip's enable 2 to slot 9
#define inoneright 10  //connect chip's in 3 to slot 10
#define intworight 12   //connect chip's in 4 to slot 12

//also the chips right side +v to 5v, 0 v to ground

int i;

#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void translateIR() 
{
  switch(results.value)
  {
  case 0xFFA25D: Serial.println("POWER"); break;
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+"); 
  case 0xFF22DD: Serial.println("FAST BACK");     //car turn left, only right wheels move
                 digitalWrite(enableright,HIGH); 
                 digitalWrite(inoneright,HIGH); 
                 digitalWrite(intworight,LOW);

                 digitalWrite(enableleft,HIGH); 
                 digitalWrite(inoneleft,LOW); 
                 digitalWrite(intwoleft,LOW);   
                 
                 delay (500);
                 digitalWrite(enableright,LOW);
  
                 break;
                 
  case 0xFF02FD: Serial.println("PAUSE");    
  case 0xFFC23D: Serial.println("FAST FORWARD");    //car turn right, only left wheels move
                digitalWrite(enableleft,HIGH); 
                  //right one way
                 digitalWrite(inoneleft,HIGH); 
                 digitalWrite(intwoleft,LOW);

                 digitalWrite(enableright,HIGH); 
                 digitalWrite(inoneright,LOW); 
                 digitalWrite(intworight,LOW);
                 
                 delay (500);
                 
                 digitalWrite(enableleft,LOW);
                 break;
  
  case 0xFFE01F: Serial.println("DOWN");     //car go back, both wheel move back
    digitalWrite(enableright,HIGH); 
    digitalWrite(inoneright,LOW);  
    digitalWrite(intworight,HIGH);
    
    digitalWrite(enableleft,HIGH); 
    digitalWrite(inoneleft,LOW);  
    digitalWrite(intwoleft,HIGH);
    delay (1000);

    digitalWrite(enableleft,LOW);
    digitalWrite(enableright,LOW);
    break; 
  
  case 0xFFA857: Serial.println("VOL-");    
  case 0xFF906F: Serial.println("UP");     //car go forward, both wheel move forward
                 digitalWrite(enableright,HIGH); 
                 digitalWrite(inoneright,HIGH); 
                 digitalWrite(intworight,LOW);
                 
                 digitalWrite(enableleft,HIGH); 
                 digitalWrite(inoneleft,HIGH); 
                 digitalWrite(intwoleft,LOW);   

                 delay (1000);

                 digitalWrite(enableleft,LOW);
                 digitalWrite(enableright,LOW);
                 break;
                 
  case 0xFF9867: Serial.println("EQ");    break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 0xFF6897: Serial.println("0");    break;
  case 0xFF30CF: Serial.println("1");    break;
  case 0xFF18E7: Serial.println("2");    break;
  case 0xFF7A85: Serial.println("3");    break;
  case 0xFF10EF: Serial.println("4");    break;
  case 0xFF38C7: Serial.println("5");    break;
  case 0xFF5AA5: Serial.println("6");    break;
  case 0xFF42BD: Serial.println("7");    break;
  case 0xFF4AB5: Serial.println("8");    break;
  case 0xFF52AD: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  
  
  default: 
    Serial.println(" other button   ");
  }

  delay(500); // Do not get immediate repeat
} 


 
void setup() 
{
  //set pin direction
  pinMode(enableleft,OUTPUT);
  pinMode(inoneleft,OUTPUT);
  pinMode(intwoleft,OUTPUT);
  Serial.begin(9600);

  pinMode(enableright,OUTPUT);
  pinMode(inoneright,OUTPUT);
  pinMode(intworight,OUTPUT);

  //for remote control
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver

  digitalWrite(enableleft,LOW);
  digitalWrite(enableright,LOW); // start with not moving
}

void loop() 
{

    if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  

}
