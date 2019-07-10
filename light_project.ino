int trigPin=2;
int echoPin=3;
float signal; //time for pint to hit target and return 

int potPin=A0; //assign potentiometer pin to A0
int readValue; //declare potentiometer readValue variable
float brightness;

int redPin=9;  //set red LED pin to 11
int greenPin=11; //set green LED pin to 10
int bluePin=10; //set blue LED pin to 6
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
    readValue = analogRead(potPin);
    brightness = (255./1000.) * readValue;
    Serial.println(brightness);
    
    // readValue = analogRead(potPin);
    digitalWrite(trigPin, LOW);
    delay(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // getting signal from ultrasonic
    signal = pulseIn(echoPin, HIGH); //measure ping time in microseconds
    int newSignal = (int) signal;
//    Serial.println(newSignal);

    
    //decide whether or not to turn on light
    if (newSignal < 500 && onStatus) { 
      analogWrite(redPin, 0); //turn off red pin
      analogWrite(greenPin, 0); //turn off green pin
      analogWrite(bluePin, 0); //write 100 (brightness) to blue pin
      onStatus = false;   
    }
    else if (newSignal < 500) { 
      analogWrite(redPin, brightness); //turn off red pin
      analogWrite(greenPin, 0); //turn off green pin
      analogWrite(bluePin, 0); //write 100 (brightness) to blue pin
      onStatus = true;
    } 

    if (onStatus) { //use serial disrupt in future for smoother function
      analogWrite(redPin, brightness);
    }
  
  delay(400);
}
