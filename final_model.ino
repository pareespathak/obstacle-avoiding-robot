#include<Servo.h>
const int trig = 12;
const int echo = 13;
#define max_dist 50
// unsigned int leftdist=0,rightdist=0,straight=0;     checking by array method in us loop
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
  delay(500);
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
  delay(50);
  head.write(a);
  delay(50);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  dist = (duration/2) / 28.5;
  return dist;
  }
int checkdist(unsigned int dist[])
{
  digitalWrite(m2,LOW);
  digitalWrite(m1,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
  dist[0] = readdist(36);
  dist[1] = readdist(90);
  dist[2] = readdist(144);
  for(int d=0;d<3;d++)
  {
    if(dist[d] > 80) // max dist taken as 100
    {
      dist[d] = 80;
    }
  }
}
void usmode()
{ 
  unsigned int dist[3]; // dist[0] = left , dist[1] = straight , dist[2]= right
  dist[0] = 0;
  dist[1] = 0;
  dist[2] = 0;
  checkdist(dist);
  Serial.println("left dist , straight dist , right dist");
  Serial.print(dist[0]);
  Serial.print(dist[1]);
  Serial.print(dist[2]);
  while(readdist(90) >= 15 && x == '7')
  {
    Serial.println(" moving straight");
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
  }
  while(dist[1] < 15 && x=='7')
  {
    int count1 = 0,count2 = 0,count3 = 0;
   /* digitalWrite(m2,LOW);
    digitalWrite(m1,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
    delay(100);*/
    
   /* leftdist=readdist(36);
    Serial.print(leftdist);
    Serial.println("l dist:");
    delay(1000);
    Serial.println("r dist:");
    Serial.print(rightdist);
    rightdist=readdist(144);
    delay(500);
   if(leftdist > rightdist && leftdist > 5)
   {
    moveleft();
   }
   */
   if(dist[0] > dist[2] && dist[0] > 2)
   {
    moveleft();
    //checkdist(dist);
   }
   /*if(rightdist > leftdist)
   {
    moveright();
   }
   */
   if(dist[2] > dist[0] && dist[2] > 2)
   {
    moveright();
   }
   checkdist(dist);
   if(dist[1] <= 4)
   {
    //rev
    if(count1 == 0)
    {
     movereverse();
     delay(800);
     count1=1;
     count2++;
     //checkdist(dist);
    }
    if(count2 == 1)
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,HIGH);
      digitalWrite(m4,LOW);
      digitalWrite(m3,HIGH);
      delay(500);
      count2++;
      count3++;
      checkdist(dist);
    }
    if(count3 == 1)
    {
      digitalWrite(m2,LOW);
      digitalWrite(m1,HIGH);
      digitalWrite(m3,LOW);
      digitalWrite(m4,HIGH);
      delay(1200);
      count1=0;
      count2=0;
      count3=0;
      checkdist(dist);
    }
   }
   else
   {
    //stop
    movestop();
    delay(1000);
    //checkdist(dist);
   }
  }
}
