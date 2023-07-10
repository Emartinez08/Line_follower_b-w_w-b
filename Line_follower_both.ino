/*
  Line tracing program black && white change background
  E.Martinez
 */

const int analogInPin0 = A2;  // Analog input pin that the potentiometer is attached to
const int analogInPin1 = A1;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A0;  // Analog input pin that the potentiometer is attached to
const int LEDPin0 = 6; // Analog output pin that the LED is attached to
const int LEDPin1 = 7; // Analog output pin that the LED is attached to
const int LEDPin2 = 8; // Analog output pin that the LED is attached to

int RIGHT_DOWN=1;
int LEFT_DOWN=2;
int STRAIGHT=0;
int last_time=0; /*CoÅ«È¢AOÌóÔðÛ·éœßÌtO*/

int sensorValue0 = 0;        // value read from the pot
int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int outputValue0 = 0;        // value output to the PWM (analog out)
int outputValue1 = 0;        // value output to the PWM (analog out)
int outputValue2 = 0;        // value output to the PWM (analog out)
int RB0 = 0;        // value output to the PWM (analog out)
int RB1 = 0;        // value output to the PWM (analog out)
int RB2 = 0;        // value output to the PWM (analog out)

const int analogOutPin2 = 9; // Analog output pin that the LED is attached to
const int analogOutPin1 = 10; // Analog output pin that the LED is attached to

int outputValue = 0;        // value output to the PWM (analog out)
int i=0;

void small_right_down(void){
    analogWrite(analogOutPin1, 40);
    analogWrite(analogOutPin2, 80);
}

void right_down(void){
    analogWrite(analogOutPin1, 15);
    analogWrite(analogOutPin2, 80);
}

void small_left_down(void){
    analogWrite(analogOutPin1, 80);
    analogWrite(analogOutPin2, 40);
}

void left_down(void){
    analogWrite(analogOutPin1, 80);
    analogWrite(analogOutPin2, 15);
}

void straight(void){
    analogWrite(analogOutPin1, 80);
    analogWrite(analogOutPin2, 80);
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(LEDPin0, OUTPUT);
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
}
void white_line(void){
  
  if(sensorValue0>600){
      outputValue0 = 1;
  }
  else{
      outputValue0 = 0;
 }
 if(sensorValue1>600){
      outputValue1 = 1;
  }
  else{
      outputValue1 = 0;
 }
 if(sensorValue2>600){
      outputValue2 = 1;
  }
  else{
      outputValue2 = 0;
 }

  if(outputValue0==0){
    digitalWrite(LEDPin0,LOW);
  }
  else{
    digitalWrite(LEDPin0,HIGH);
  }

  if(outputValue1==0){
    digitalWrite(LEDPin1,LOW);
  }
  else{
    digitalWrite(LEDPin1,HIGH);
  }

  if(outputValue2==0){
    digitalWrite(LEDPin2,LOW);
  }
  else{
    digitalWrite(LEDPin2,HIGH);
  }

  delay(2);

  //sensor monitor 

  RB0=outputValue2;
  RB1=outputValue1;
  RB2=outputValue0;


  //last_time=STRAIGHT;
  //  led_sens();
    if(RB0==1 && RB1==1 && RB2==1 && last_time==LEFT_DOWN){
      left_down();  /*"White White White" and "LEFT_DOWN last time"*/
      last_time=LEFT_DOWN;       /* turn left */
    }
    else if(RB0==1 && RB1==1 && RB2==1 && last_time==RIGHT_DOWN){
      right_down(); /*"White White White" and "RIGHT_DOWN last time"*/
      last_time=RIGHT_DOWN;      /* turn right */
    }
    else if(RB0==0 && RB1==0 && RB2==1){ /* Black Black White */
      small_left_down();           /* turn left a little */
      last_time=LEFT_DOWN;
    }
    else if(RB0==0 && RB1==1 && RB2==1){ /* Black White White */
      left_down();                 /* turn left */
      last_time=LEFT_DOWN;
    }
    else if(RB0==1 && RB1==0 && RB2==0){ /* White Black Black */
      small_right_down();          /* turn right a little */
      last_time=RIGHT_DOWN;
    }
    else if(RB0==1 && RB1==1 && RB2==0){ /* White White Black */
      right_down();                /* turn right */
      last_time=RIGHT_DOWN;
    }
    else{                                /* The other case */
      straight();                  /* go to straight */
      //last_time=STRAIGHT;
    } 
  
  
  } 
void black_line(void){
  if(sensorValue0>600){
      outputValue0 = 1;
  }
  else{
      outputValue0 = 0;
 }
 if(sensorValue1>600){
      outputValue1 = 1;
  }
  else{
      outputValue1 = 0;
 }
 if(sensorValue2>600){
      outputValue2 = 1;
  }
  else{
      outputValue2 = 0;
 }

  if(outputValue0==0){
    digitalWrite(LEDPin0,LOW);
  }
  else{
    digitalWrite(LEDPin0,HIGH);
  }

  if(outputValue1==0){
    digitalWrite(LEDPin1,LOW);
  }
  else{
    digitalWrite(LEDPin1,HIGH);
  }

  if(outputValue2==0){
    digitalWrite(LEDPin2,LOW);
  }
  else{
    digitalWrite(LEDPin2,HIGH);
  }

  delay(2);

  //sensor monitor 

  RB0=outputValue2;
  RB1=outputValue1;
  RB2=outputValue0;


  //last_time=STRAIGHT;
  //  led_sens();
    if(RB0==0 && RB1==0 && RB2==0 && last_time==LEFT_DOWN){
      left_down();  /*"White White White" and "LEFT_DOWN last time"*/
      last_time=LEFT_DOWN;       /* turn left */
    }
    else if(RB0==0 && RB1==0 && RB2==0 && last_time==RIGHT_DOWN){
      right_down(); /*"White White White" and "RIGHT_DOWN last time"*/
      last_time=RIGHT_DOWN;      /* turn right */
    }
    else if(RB0==1 && RB1==1 && RB2==0){ /* Black Black White */
      small_left_down();           /* turn left a little */
      last_time=LEFT_DOWN;
    }
    else if(RB0==1 && RB1==0 && RB2==0){ /* Black White White */
      left_down();                 /* turn left */
      last_time=LEFT_DOWN;
    }
    else if(RB0==0 && RB1==1 && RB2==1){ /* White Black Black */
      small_right_down();          /* turn right a little */
      last_time=RIGHT_DOWN;
    }
    else if(RB0==0 && RB1==0 && RB2==1){ /* White White Black */
      right_down();                /* turn right */
      last_time=RIGHT_DOWN;
    }
    else{                                /* The other case */
      straight();                  /* go to straight */
      //last_time=STRAIGHT;
    } 
  


  
  }

// the loop function runs over and over again forever
void loop() {

    //sensor monitor 

  // read the analog in value:
  sensorValue0 = analogRead(analogInPin0);
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  delay(2);

  //sensor monitor 

  RB0=outputValue2;
  RB1=outputValue1;
  RB2=outputValue0;

  
  if(RB1==1){
    white_line();
    }
  else{
    black_line();
    }
}
