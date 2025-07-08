# Self control through automation
*authered and maintained by* 

## **Benjamin Brown**
##

**S-C-T-A** is a contactless, local area room controller, designed to change the enviroment as well as an onboard display, based on requests within a time inveral. 
Multiple request within too short an interval will update the room and ultimatley disable the device. 

All counts and timers are set as variables that can be defined as desired.

Using an infrared detector, it takes a signal and processes a request to dispence. 
It then sets the "Green" condition, increments a count and sets a timer. 
If no more requests are received within a given amount of time, the system will reset and remain in the "Green" condition. 
The current code for this specifies that lights in a room are set green and local outlets are on. They correspnd with an imaginary "AC" nad Television. 

Continued requests update the room to "Yellow", clearly indicating that the preset limnit is approaching and urging the user to limit requests. 
Again. if the limit is not reached within the running timer, the system will reset to green. 

If the limit is activated, the system will set the "Red" condition, sending the signal to shut of the "AC" and "TV". 
It then disables the the machine and will not process any requests, based on the infrared sensor. 
A seperate, LONG timer is set, after which the machine will reset to a "blue" state and await a request. 

An over-ride has been designed in, where-in, a user who knows where the "secret" button is, can press it to activate full speed dispensing until the buitton is released.
This also resets the machine to the "Green" state. 
