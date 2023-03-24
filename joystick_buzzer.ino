int VRx = A0;
int VRy = A1;
int SW = 2;
int buzzer = 7;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

int led_status = HIGH;
int incomingByte = 0;
  
void setup() {
  Serial.begin(9600);

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(buzzer, LOW); 

}

void loop() {
   if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
  if (incomingByte == 'B')
  {    digitalWrite(buzzer, HIGH);
  delay(500);
       digitalWrite(buzzer, LOW);
    }
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  if (xPosition > 600)
    Serial.println("d");
  else if (xPosition < 400)
    Serial.println("a");
  else if (yPosition > 600)
    Serial.println("s");
  else if (yPosition <400)
    Serial.println("w");
  }
  else 


  delay(300);
}