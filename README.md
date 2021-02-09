mobile rover with obstacle avoider obstacle-avoider-
user must run the code along with the android application which will enable to operation of the vehicle from a cell phone to change the modes.
the application used here sends the text from the cellphone to Arduino Uno by Bluetooth module.
the application can be worked only on android phones, ios user can use other ways of sending a text that enables the function.
programming changes can be made using Arduino ide software.

Display of application 

<img src="images/WhatsApp%20Image%202020-08-27%20at%2014.48.32.jpeg" height="800">

ABOUT THE BOT

The bot can be used as a remote control car using mobile.
obstacle avoider feature is for automatically driven non go to goal mode.
line following and obstacle avoider mode cannot be used at a time. 
they can be used simultaneously according to requirements.
Delay can be adjusted according to the power of motors and the surface of the environment where the bot is used.

Hardware components used

1. Arduino Uno
2. Bluetooth module Hc-05
3. dc motors x 2
4. castor wheel 
5. l293d motor driver ic 
6. ultrasonic sensor module
7. servo motor 
8. jumper wires
9. mobile phone 

** mobile application can be downloaded from the repository .**
The application contains other features like 
1. line follower mode.
2. slow-motion mode 
which can be used by adding hardware components like IR proximity sensors.

 libraries include
 
1. servo.h // to run the servo motor.
2. motor shield library (optional if using any shield)
3. newping .h (optional for calculating distances)
 pins declaration of Arduino
m1,m2     == right motor ,
m3,m4     == left motor,
trig,echo == pins of ultrasonic sensor,
head      == servo motor,

line following mode can be included at text '6' received by the Bluetooth module.
 about obstacle avoider
The function is set according to the distance range calculated by the ultrasonic sensor.
if there is noise and random false values are detected by the sensor, reset the mode by clicking obstacle avoider mode on the application. 
end


