/*  Test controls 3 for CC.01
 *  Author - Alistair McLean
 */

// Arduino Pin assignments
const int motor1Pin1 = 3; // M1+ STEER - RIGHT
const int motor1Pin2 = 4; // M1- STEER - LEFT

const int motor2Pin1 = 5; // M2+ DRIVE - FORWARD
const int motor2Pin2 = 6; // M2- DRIVE - REVERSE

const int ledRPin = 9; //   9   -   digital
const int ledGPin = 10; //  10  -   digital
const int ledBPin = 11; //  11  -   digital


//Serial input
char input;


void setup() {
    // sets the pins as outputs:
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);

    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);

    pinMode(ledRPin, OUTPUT);
    pinMode(ledGPin, OUTPUT);
    pinMode(ledBPin, OUTPUT);

    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void emitColor(int R, int G, int B) {
  digitalWrite(ledRPin, R);
  digitalWrite(ledGPin, G);
  digitalWrite(ledBPin, B); 
}

void MotorControl() {
  // ------- Motor Controls -------
  //      w - DRIVE straight
  //      s - DRIVE reverse
  //      a - STEER left
  //      d - STEER right
  //      x - stop DRIVE motor
  //      f - stop STEER motor (STEER straight)
  //      r - stop DRIVE and STEER motors
  // --- OPTIONAL FOR NOW, ADD FOR LATER MODELS ---
  //      q - DRIVE straight STEER left - optional for now
  //      e - DRIVE straight STEER right - optional for now
  //      z - DRIVE reverse STEER left - optional for now
  //      c - DRIVE reverse STEER right - optional for now
  switch(input) {
    case('w'):
      //DRIVE STRAIGHT
      digitalWrite(motor2Pin1, LOW); // set pin 2 on L293D low
      digitalWrite(motor2Pin2, HIGH); // set pin 7 on L293D high

      emitColor(0, 255, 0);
      break;
    case('a'):
      //STEER LEFT
      digitalWrite(motor1Pin2, LOW); 
      digitalWrite(motor1Pin1, HIGH); 
      
      emitColor(255, 2, 0);
      break;      
    case('s'):
      //DRIVE REVERSE
      digitalWrite(motor2Pin2, LOW); // set pin 7 on L293D low
      digitalWrite(motor2Pin1, HIGH); // set pin 2 on L293D high
      
      emitColor(255, 255, 255);
      break;
    case('d'):
      //STEER RIGHT
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH); 
      
      emitColor(0, 0, 255);        
      break;
    case('x'):
      //STOP DRIVE MOTOR
      digitalWrite(motor2Pin1, LOW); // set pin 2 on L293D low
      digitalWrite(motor2Pin2, LOW); // set pin 7 on L293D low
      
      emitColor(0, 255, 0);
      break;
    case('f'):
      //STOP STEERING MOTOR
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW); 
      
      emitColor(255, 0, 0);
      break;
    case('r'):
      //STOP DRIVE MOTOR
      digitalWrite(motor2Pin1, LOW); // set pin 2 on L293D low
      digitalWrite(motor2Pin2, LOW); // set pin 7 on L293D low

      //STOP STEERING MOTOR
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, LOW); 
      
      emitColor(255, 0, 0);
      break;
    case('q'):
      //STEER LEFT
      digitalWrite(motor1Pin2, LOW); 
      digitalWrite(motor1Pin1, HIGH); 
      
      //DRIVE STRAIGHT
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      
      emitColor(255, 255, 0);        
      break;
    case('e'):
      //STEER RIGHT
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH); 
      
      //DRIVE STRAIGHT
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      
      emitColor(0, 0, 255);        
      break;
    case('z'):
      //STEER LEFT
      digitalWrite(motor1Pin2, LOW); 
      digitalWrite(motor1Pin1, HIGH); 
      
      //DRIVE REVERSE
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      
      emitColor(255, 255, 0);        
      break;
    case('c'):
      //STEER RIGHT
      digitalWrite(motor1Pin1, LOW); 
      digitalWrite(motor1Pin2, HIGH); 
      
      //DRIVE REVERSE
      digitalWrite(motor2Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      
      emitColor(0, 0, 255);        
      break;
  }
}

void loop() {
    //if some date is sent, reads it and saves in state
    if(Serial.available() > 0){     
      input = Serial.read();   
    }   
  MotorControl();
} 
