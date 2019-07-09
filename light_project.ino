int trigPin=2;
int echoPin=3;
float signal; //time for pint to hit target and return 

int redPin=10;  //set red LED pin to 11
int greenPin=9; //set green LED pin to 10
int bluePin=5; //set blue LED pin to 6
int brightness=100; //Set brightness to 100

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);  
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
}

void loop() {
  analogWrite(redPin, brightness); //turn off red pin
  analogWrite(greenPin, 0); //turn off green pin
  analogWrite(bluePin, 0); //write 100 (brightness) to blue pin
  
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  signal = pulseIn(echoPin, HIGH); //measure ping time in microseconds
  
  int newSignal = (int) signal;
  Serial.println(newSignal);
  
  if (newSignal < 500) {
    analogWrite(redPin, 0); 
    analogWrite(greenPin, 0); 
    analogWrite(bluePin, 0); 
  }

  delay(4000);
}
