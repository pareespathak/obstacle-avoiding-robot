#include<Servo.h>
const int trig = 12;
const int echo = 13;
#define max_dist 50
unsigned int leftdist=0,rightdist=0,straight=0;
int m1=5,m2=6,m3=9,m4=10;
char x="";
Servo head;
void setup() {
  Serial.begin(9600);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  head.attach(11);
 
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
 if(x=='7')
 {
  Serial.println("us mode");
  usmode();
 }
}
//================================stop================================
void movestop()
{ digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}
//==============================forward=====================
void moveforward()
{ 
  delay(200);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
  
}
//===============================reverse=====================
  void movereverse()
{
  delay(200);
  digitalWrite(m2,LOW);
  digitalWrite(m1,HIGH);
  digitalWrite(m4,LOW);
  digitalWrite(m3,HIGH);
  
}
//==================================right===============
void moveright()
{
  delay(200);
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m4,LOW);
  digitalWrite(m3,HIGH);
}
//===================================left===============
void moveleft()
{ 
  delay(200);
   digitalWrite(m2,LOW);
  digitalWrite(m1,HIGH);
  digitalWrite(m3,LOW);
  digitalWrite(m4,HIGH);
  
}

//============================u turn==================================
void uturn()
{ 
  delay(200);
  digitalWrite(m1,LOW);
  digitalWrite(m4,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite(m3,HIGH);
  delay(3500);
  x='1';
}
//===========================us==========================
//==========================readfunc==================
int readdist(int a){
  long int duration,dist;
  delay(100);
  head.write(a);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(100);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  dist=(duration/2) / 28.5;
  delay(100);
  return dist;
  }
void usmode()
{ 
  straight=readdist(90);
  Serial.println("straight");
    Serial.print(straight);
  while(readdist(90)>18 && x=='7')
  {
    Serial.println(" moving straight");
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
  }
 
 if(x=='7')
 {
  while(readdist(90)<18 && x=='7')
  {
    int count=0;
    digitalWrite(m2,LOW);
    digitalWrite(m1,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
    delay(1000);
    leftdist=readdist(36);
    Serial.print(leftdist);
    Serial.println("l dist:");
    delay(1000);
    Serial.println("r dist:");
    rightdist=readdist(144);
    Serial.print(rightdist);
    delay(1000);
   if(readdist(36)>readdist(144) && readdist(36)>3 )
   {
    moveleft();
   }
   if(readdist(144)>readdist(36))
   {
    moveright();
   }
     if(readdist(90)< 2)
   {
    //rev
    
    if(count==0)
    {movereverse();
     count++;
     delay(800);
    }
    if(count==2)
    {
      digitalWrite(m2,LOW);
      digitalWrite(m1,HIGH);
      digitalWrite(m3,LOW);
      digitalWrite(m4,HIGH);
      delay(1200);
      count=0;
    }
    if(count == 1)
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,HIGH);
      digitalWrite(m4,LOW);
      digitalWrite(m3,HIGH);
      delay(500);
      count++;
    }
   }
   else
   {
    //stop
    movestop();
    delay(1000);
   }
  }
}
}
