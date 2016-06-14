
int led = 9;
int brightness = 20;
int fadeAmount = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode (led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(led, brightness);

  brightness = brightness+fadeAmount;

  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }

  delay(100);   

}
