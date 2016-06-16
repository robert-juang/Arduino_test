
int buttonuppin = 2;
int buttondownpin = 4;
int led = 9;
int brightness = 20;
int fadeAmount = 15;

//int buttonState = LOW; //this variable tracks the state of the button, low if not pressed, high if pressed
int ledState = -1; //this variable tracks the state of the LED, negative if off, positive if on
 
long lastupDebounceTime = 0;  // the last time the output pin was toggled
long lastdownDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50; 


void setup() {
  // put your setup code here, to run once:
  pinMode (led, OUTPUT);
  pinMode (buttonuppin, INPUT);
  pinMode (buttondownpin, INPUT);
  Serial.begin(9600); 
  
}

int buttonPressed(int bp, long* ldt)
{
  int buttonState = digitalRead(bp);
 
  //filter out any noise by setting a time buffer
  if ( (millis() - *ldt) > debounceDelay) {
 
    //if the button has been pressed, lets toggle the LED from "off to on" or "on to off"
    if (buttonState == HIGH){
      *ldt = millis(); //set the current time
      return 1;
    }
  }

  return 0;
}

void loop() {
  int valup = buttonPressed(buttonuppin, &lastupDebounceTime);
  int valdown = buttonPressed(buttondownpin, &lastdownDebounceTime);
  Serial.println (valdown);
  // check button up is pressed
  if (valup == 1) {
      brightness = brightness + fadeAmount;
      if (brightness > 255){
        brightness = 255;
      }
      analogWrite(led, brightness); //turn LED on

  }
  //check button down is pressed
 if (valdown == 1){
      brightness = brightness - fadeAmount;
      if (brightness < 0){
        brightness = 0;
      }
      analogWrite(led, brightness); //turn LED on
  }

  
}

 
 

