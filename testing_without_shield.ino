int m1=3,m2=5,m3=6,m4=9;
char x="";
void setup() {
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
Serial.begin(9600);
}

void moveforward()
{ digitalWrite(m2,LOW);
  digitalWrite(m1,HIGH);
  digitalWrite(m4,LOW);
  digitalWrite(m3,HIGH);
}
void movereverse()
{
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
}
void moveright()
{ digitalWrite(m2,LOW);
  digitalWrite(m1,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
}
void moveleft()
{ digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);
}
void movestop()
{ digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}
void slow()
{analogWrite(m1,60);
 digitalWrite(m2,LOW);
 analogWrite(m3,60);
 digitalWrite(m4,LOW);
}
void uturn()
{ digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,HIGH);
  digitalWrite(m4,LOW);
  delay(1500);
  moveforward();
}

void loop() {
  while(Serial.available()>0)
  { x=Serial.read();
    Serial.println(x);
  }
 if(x=='1')
 {
  Serial.println("forward");
  moveforward();  
 }
 if(x=='2')
 {
  Serial.println("reverse");
  movereverse();
 }
 if(x=='3')
 {
  Serial.println("right");
  moveright();
 }
 if(x=='4')
 {
  Serial.println("left");
  moveleft();
 }
 if(x=='5')
 {
  Serial.println("stop");
  movestop();
 }
if(x=='8')
 {
  Serial.println("u turn");
  uturn();
 }
 if(x=='9')
 {
  Serial.println("moving slow");
  slow();
 }
}
