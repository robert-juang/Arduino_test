#include "pitches.h"

int soundpin = 13;
int buttonpin1 = 7;
int buttonpin2 = 6;
int buttonpin3 = 5;
int buttonpin4 = 4;
int buttonpin5 = 3;
int buttonpin6 = 2;
long last1DebounceTime = 0;
long last2DebounceTime = 0;
long last3DebounceTime = 0;
long last4DebounceTime = 0;
long last5DebounceTime = 0;
long last6DebounceTime = 0; 

int debounceDelay = 50;
int noteDuration = 250;

void setup() {
  // put your setup code here, to run once:
pinMode (soundpin, OUTPUT);
pinMode (buttonpin1, INPUT);
pinMode (buttonpin2, INPUT);
pinMode (buttonpin3, INPUT);
pinMode (buttonpin4, INPUT);
pinMode (buttonpin5, INPUT);
pinMode (buttonpin6, INPUT);
Serial.begin(9600);

}

int buttonPressed(int bp, long* ldt)
{
  int buttonState = digitalRead(bp);
  
    //if the button has been pressed, lets toggle the LED from "off to on" or "on to off"
    if (buttonState == HIGH){
      Serial.println("pressed");
      *ldt = millis(); //set the current time
      return 1;
    }
  }
void loop() {

  // put your main code here, to run repeatedly:
  int val1 = buttonPressed(buttonpin1, &last1DebounceTime);
  if (val1==HIGH){
    tone(soundpin, NOTE_C4, noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(soundpin);  
     Serial.println (val1);
  }
  int val2 = buttonPressed(buttonpin2, &last2DebounceTime);
  if (val2 == HIGH){
    tone(soundpin, NOTE_D4, noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(soundpin);  
     Serial.println (val2);
  }
  int val3 = buttonPressed(buttonpin3, &last3DebounceTime);
  if (val3==HIGH){
    tone(soundpin, NOTE_E4, noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(soundpin);  
     Serial.println (val3);
  }
  
 int val4 = buttonPressed(buttonpin4, &last4DebounceTime);
 // Serial.println("heelo  -  " + val4);
  if (val4==HIGH){
    tone(soundpin, NOTE_F4, noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(soundpin);  
     Serial.println("heelo " + val4);
  }
 
  int val5 = buttonPressed(buttonpin5, &last5DebounceTime);
  if (val5==HIGH){
    tone(soundpin, NOTE_G4, noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(soundpin);  
     Serial.println (val5);
  }

  int val6 = buttonPressed(buttonpin6, &last6DebounceTime);
  if (val6==HIGH){
    tone(soundpin, NOTE_A4, noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(soundpin);  
     Serial.println (val6);
  }
  
}

