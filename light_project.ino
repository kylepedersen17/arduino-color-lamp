int trigPin=2;
int echoPin=3;
float signal; //time for pint to hit target and return 

int redPin=10;  //set red LED pin to 11
int greenPin=9; //set green LED pin to 10
int bluePin=5; //set blue LED pin to 6
int brightness=100; //Set brightness to 100
boolean onStatus = false;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);  
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
}

void loop() {
    // potentiometer
    digitalWrite(trigPin, LOW);
    delay(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // getting signal from potentiometer
    signal = pulseIn(echoPin, HIGH); //measure ping time in microseconds
    int newSignal = (int) signal;
    Serial.println(newSignal);

    
    //decide whether or not to turn on light
    if (newSignal < 500 && onStatus) { 
      analogWrite(redPin, 0); //turn off red pin
      analogWrite(greenPin, 0); //turn off green pin
      analogWrite(bluePin, 0); //write 100 (brightness) to blue pin
      onStatus = false;   
    }
    else if (newSignal < 500) {
      Serial.println("HI");    
      onStatus = true;
      analogWrite(redPin, brightness); //turn off red pin
      analogWrite(greenPin, 0); //turn off green pin
      analogWrite(bluePin, 0); //write 100 (brightness) to blue pin
    } 
   

  delay(400);
}
