
#include "IRLibAll.h"

#define MY_PROTOCOL NEC
#define RIGHT_ARROW   16761405
#define LEFT_ARROW    16720605 
#define SELECT_BUTTON 16712445
#define UP_ARROW      16736925 
#define DOWN_ARROW    16754775
#define BUTTON_0 16730805  
#define BUTTON_1 16738455  
#define BUTTON_2 16750695
#define BUTTON_3 16756815
#define BUTTON_4 16724175
#define BUTTON_5 16718055
#define BUTTON_6 16743045
#define BUTTON_7 16716015
#define BUTTON_8 16726215
#define BUTTON_9 16734885
#define BUTTON_DIEZ 16732845
#define BUTTON_STAR 16728765

IRrecvPCI myReceiver(2);

IRdecode myDecoder;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); 
  myReceiver.enableIRIn(); 
  Serial.println(F("Ready"));
  pinMode(3, OUTPUT);   
  digitalWrite(3, HIGH);   
  pinMode(4, OUTPUT);     
  digitalWrite(4, HIGH);   
  pinMode(5, OUTPUT);     
  digitalWrite(5, HIGH);   
  pinMode(6, OUTPUT);     
  digitalWrite(6, HIGH);   
}
uint32_t Previous;
void loop() {

  if (myReceiver.getResults()) {
    myDecoder.decode();         

    if (myDecoder.protocolNum == MY_PROTOCOL) {

      switch (myDecoder.value) {
        case LEFT_ARROW:
          Serial.println("left");
           //digitalWrite(13, LOW); 
          break;
        case RIGHT_ARROW:
          Serial.println("right");
          break;
        case SELECT_BUTTON:
          Serial.println("select");
          break;
        case UP_ARROW:
          Serial.println("up");
          break;
        case DOWN_ARROW:
          Serial.println("down");
          break;
        case BUTTON_0:
          Serial.println("t0");
          break;
        case BUTTON_1:
          toggleR1();
          Serial.println("t1");
          break;
        case BUTTON_2:
         toggleR2();
          Serial.println("t2");
          break;
        case BUTTON_3:
         toggleR3();
          Serial.println("t3");
          break;
        case BUTTON_4:
         toggleR4();
          Serial.println("t4");
          break;
        case BUTTON_5:
          Serial.println("t5");
            toggleR1();
            toggleR2();
            toggleR3();
            toggleR4();
          break;
        case BUTTON_6:
          Serial.println("t6");
          break;
        case BUTTON_7:
          Serial.println("7");
          break;
        case BUTTON_8:
          Serial.println("t8");
          break;
        case BUTTON_9:
          Serial.println("t9");
          break;
        case BUTTON_DIEZ:
          Serial.println("DIEZ");
        break;
        case BUTTON_STAR:
          Serial.println("STAR");
        break;
      }
      
      Serial.println(myDecoder.value);
      Serial.println(Previous);
    }
    myReceiver.enableIRIn();      
  }
}

int R1;
void toggleR1(){
  if(R1 == 0){
    digitalWrite(3, LOW); 
    R1 = 1;
  } else{
    R1 = 0;
    digitalWrite(3, HIGH); 
  }
}

int R2;
void toggleR2(){
  if(R2 == 0){
    digitalWrite(4, LOW); 
    R2 = 1;
  } else{
    R2 = 0;
    digitalWrite(4, HIGH); 
  }
}

int R3;
void toggleR3(){
  if(R3 == 0){
    digitalWrite(5, LOW); 
    R3 = 1;
  } else{
    R3 = 0;
    digitalWrite(5, HIGH); 
  }
}

int R4;
void toggleR4(){
  if(R4 == 0){
    digitalWrite(6, LOW); 
    R4 = 1;
  } else{
    R4 = 0;
    digitalWrite(6, HIGH); 
  }
}

