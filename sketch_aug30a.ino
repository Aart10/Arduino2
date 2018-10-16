const int sen=A0;
const int ledR=7;
const int ledV=6;
const int ledA=5;
int value=0;
const int umbral1=25;
const int umbral2=30;
float milivolts;
float temperatura;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledR,OUTPUT);
  pinMode(ledV,OUTPUT);
  pinMode(ledA,OUTPUT);
  pinMode(sen,INPUT);
}

void loop() {
  value=analogRead(sen);
  milivolts=5000*(value/1023.0);
  temperatura=milivolts/10;
  if(temperatura<umbral1){
    digitalWrite(ledA,LOW);
    digitalWrite(ledV,HIGH);
    digitalWrite(ledR,LOW);
    delay(300);
  }
  else{
    if(temperatura<umbral2){
      digitalWrite(ledA,HIGH);
      digitalWrite(ledV,LOW);
      digitalWrite(ledR,LOW);
      delay(300); 
    }
    else{
      digitalWrite(ledA,LOW);
      digitalWrite(ledV,LOW);
      digitalWrite(ledR,HIGH);
      delay(300);
    }
  }
  Serial.println("La temperatura es:");
  Serial.println(temperatura);
  delay(100);
}
