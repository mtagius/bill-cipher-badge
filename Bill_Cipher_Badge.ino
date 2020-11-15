#define leftFirePin 0
#define rightFirePin 1
#define eyePin 2

int leftFire = 0;
int rightFire = 0;
boolean eye = LOW;
int eyeFrequency = 0;
int eyeFadeDirection = 0;

int counter = 1;

void setup() {
  pinMode(leftFirePin, OUTPUT);
  pinMode(rightFirePin, OUTPUT);
  pinMode(eyePin, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() { 

  //every time the loop counter hits 0 the eye will either turn off or on
  if(--counter == 0) {
    if(eye == HIGH) {
      eyeFadeDirection = -1;
      counter = 2000;
    } else {
      eyeFadeDirection = 1;
      counter = 10000 + random(5000);
    }
  }

  //this is a kinda hacky way of getting the eye to fade on and off because it is not a PWM pin
  eyeFrequency += eyeFadeDirection;
  if(eyeFrequency <= 0 || eyeFrequency >= 128) {
    eyeFadeDirection = 0;
  } else {
    if(eyeFrequency > random(128)) {
        eye = HIGH;
      } else {
        eye = LOW;
      } 
      digitalWrite(eyePin, eye);
  }

  //the two fire LEDs blink to looks like a flickering flame
  if(counter % 2 == 0) {
    analogWrite(leftFirePin, random(25) + 25);
    analogWrite(rightFirePin, random(25) + 25);
  }
}