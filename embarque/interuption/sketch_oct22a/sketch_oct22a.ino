// C++ code

int pinDetect = 2; 
volatile int eventCounter;
volatile bool eventFlag;

void myInterruptRoutine() {
  eventCounter+=1;
  eventFlag=true;
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pinDetect, INPUT);
  eventCounter=0;
  eventFlag=false;
  attachInterrupt (digitalPinToInterrupt (pinDetect), myInterruptRoutine,RISING);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  if (eventFlag){
    Serial.print("detection: ");
    Serial.println(eventCounter);
    eventFlag=false;
  }  
}