mobile rover with obstacle avoider obstacle-avoider-
user must run the code along with the android application which will enable to operate the vehicle from cell phone to change the modes.
the application used here send the text from the cellphone to arduino uno by bluetooth module.
the application can be worked only on andoid phones, ios user can use other ways of sending text that enables the function .
programming changes can be made using arduino ide software.
Display of application 
![WhatsApp Image 2020-08-27 at 14 48 32](https://user-images.githubusercontent.com/64767345/91436561-674ce180-e879-11ea-8840-33b235e26379.jpeg)


ABOUT THE BOT

Bot can be used as remote control car using mobile .
obstacle avoider feature is for automatic diven non go to goal mode .
line following and obstacle avoider mode cannot be used at a time. 
they can be used simulteniously according to requirment.
Delay can be adjusted according to the power of motors and  surface of environment where the  bot is used.

Hardware components used

1. arduino uno
2. bluetooth module Hc-05
3. dc motors x 2
4. castor wheel 
5. l293d motor driver ic 
6. ultrasonoc sensor module
7. servo motor 
8. jumper wires
9. mobile phone 

** mobile application can be downloaded from the repository .**
application contains other features like 
1. line follower mode.
2. slow motion mode 
which can be used by adding hardware components like IR proximity sensors .

 libraries include
 
1. servo.h // to run the servo motor .
2. motor shield library (optionl if using any shield)
3. newping .h (optional for calculating distances)
 pins declaration of arduino
m1,m2     == right motor ,
m3,m4     == left motor,
trig,echo == pins of ultarsonic sensor,
head      == servo motor,

line following mode can be included at text '6' recieved by bluetooth module.
 about obstacle avoider
functon are set according to the distance range calculated by the ultrasonic sensor.
if there is noise and random false values is detected by the sensor , reset the mode by clicking obstacle avoider mode on the application. 
end
