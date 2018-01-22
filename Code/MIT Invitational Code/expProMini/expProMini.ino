void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(analogRead(A3) > 100) {
    digitalWrite(13, HIGH); 
  }
  else {
    digitalWrite(13, LOW);
  }
}
