int buttonpin = 2;
int led = 9;
int brightness = 20;
int fadeAmount = 15;

int buttonState = LOW; //this variable tracks the state of the button, low if not pressed, high if pressed
int ledState = -1; //this variable tracks the state of the LED, negative if off, positive if on
 
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50; 

void setup() {
  // put your setup code here, to run once:
  pinMode (led, OUTPUT);
  pinMode (buttonpin, INPUT);
  Serial.begin(9600); 
  
}

void loop() {
 buttonState = digitalRead(buttonpin);
 
  //filter out any noise by setting a time buffer
  if ( (millis() - lastDebounceTime) > debounceDelay) {
 
    //if the button has been pressed, lets toggle the LED from "off to on" or "on to off"
    if ( (buttonState == HIGH) && (ledState < 0) ) {
      brightness = brightness + fadeAmount;
      if (brightness > 255){
        brightness = 255;
        ledState = -ledState;
      }
      analogWrite(led, brightness); //turn LED on
      Serial.println(brightness);
      //ledState = -ledState; //now the LED is on, we need to change the state
      lastDebounceTime = millis(); //set the current time
    }
    else if ( (buttonState == HIGH) && (ledState > 0) ) {
      brightness =0;
       Serial.println("reset ");
      analogWrite(led, brightness);  //turn LED off
      ledState = -ledState; //now the LED is off, we need to change the state
      lastDebounceTime = millis(); //set the current time
    }//close if/else
 
  }//close if(time buffer)

  
 
}//close void loop
