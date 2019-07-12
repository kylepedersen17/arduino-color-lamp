//ultrasonic sensor variables
int trigPin=2;
int echoPin=3;
int buttonPin=12;
float signal; //time for pint to hit target and return 

// potentiometer variables
int potPin=A0; 
int readValue;

// RBG color variables
int i = 0; // color index counter
int reds[]   = {255, 0, 0, 255,};
int greens[] = {0, 0, 255, 0, 255};
int blues[]  = {0, 255, 255, 255}; //red, blue, cyan, magenta
float brightnessRed = reds[i];
float brightnessBlue = greens[i];
float brightnessGreen = blues[i];
int redPin=9; 
int greenPin=11; 
int bluePin=10; 

//light starts at off position
boolean onStatus = false;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);  
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
}

void loop() {
    //sets brightness variables based on potentiometer position
    readValue = analogRead(potPin);
    brightnessRed = (255./1000.) * readValue;
    brightnessGreen = (255./1000.) * readValue;
    brightnessBlue = (255./1000.) * readValue;
    
    
    //sends out ultrasonic sensor ping signal
    digitalWrite(trigPin, LOW);
    delay(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // getting signal from ultrasonic
    signal = pulseIn(echoPin, HIGH); //measure ping time in microseconds
    int newSignal = (int) signal;
    
   
  //decide whether or not to turn on light
  if (newSignal < 500 && onStatus) { 
    //turns off led
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, 0); 
    onStatus = false;   
  } else if (newSignal < 500) { 
    //turns on led 
    analogWrite(redPin, brightnessRed); 
    analogWrite(greenPin, brightnessGreen); 
    analogWrite(bluePin, brightnessBlue); 
    onStatus = true;
  } 
  
  
  
  //changes color if button is pressed
  if (digitalRead(buttonPin) == 1) {
    brightnessRed = reds[i + 1];
    brightnessGreen = greens[i + 1];
    brightnessBlue = blues[i + 1];
    i++;
    if (i > sizeof(reds)) {
      i = 0;
    }
  }
  
  
  //sets brightness according to potentiometer changes
      if (onStatus) { 
        analogWrite(redPin, brightnessRed);
        analogWrite(greenPin, brightnessGreen);
        analogWrite(bluePin, brightnessBlue);
      }
    
    delay(400);
}
