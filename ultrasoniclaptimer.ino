const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int lap;
unsigned long firstMillis;
unsigned long startMillis;
unsigned long currentMillis;
unsigned long elapsedMillis;
float laptime,totaltime;
const int buzzer = 9;



void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   lap=0;
   startMillis = 0;
   pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}


void loop() {

//Ultrasonic setup
   long duration, inches, cm,lasttime;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);


   
   if (cm<40) { //If drone pass the gate the distance is less than 40cm
    //get current time
    currentMillis = millis();
    elapsedMillis = (currentMillis - startMillis);// calcuate lap time in million seconds
    laptime=elapsedMillis ; // calcuate 
    laptime=laptime/1000 ; // convert to seconds
       if (lap<=0) {  // ignore first lap stat to record time
          firstMillis=millis();
          Serial.print("<=================Start=================>");
          Serial.println();;
       }
    totaltime=(currentMillis-firstMillis);
    totaltime=totaltime/1000;
    //laptime=microsecondsToseconds(mtime);
   if(lap>0){
    Serial.print("lap:");
    Serial.print(lap);
    Serial.print(" Laptime: ");
    Serial.print(laptime,2);
    Serial.print("s, total:");
    Serial.print(totaltime);
    Serial.print("s ");
    Serial.println();
   }
   startMillis=millis(); //save this lap
   lasttime=laptime;
   lap=lap+1;
  tone(buzzer, 2000); // Send 2KHz sound signal...
  delay(90);        // ...for 0.1 sec
  noTone(buzzer);     // Stop sound...
    delay(20);   
   tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(90);        // ...for 0.1 sec
  noTone(buzzer);     // Stop sound...
   delay(4800);
   //laptime=5;
    }
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
long microsecondsToseconds(long microseconds) {
   return microseconds / 1000;
}
