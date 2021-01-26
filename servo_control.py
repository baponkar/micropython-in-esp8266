'''
Author : Bapon Kar
Purpose : Control a servo motor
Language : MicroPython
Harware : ESP8266, Servo motor
Last Update : 
'''
#The machine module contains specific functions related to the hardware on a particular board.
import machine
 
'''
The time module provides functions for getting 
1. the current date and time
2. for sleeping
'''
import time
 
'''
class Pin - Control I/O pins
The pin class has methods
1. to set the mode of pin (IN, OUT)
2. to get and set the digital logic level
'''
from machine import Pin
 
# set machine GPIO2 as p2
p2 = machine.Pin(2)  #or d4 pin of nodemcuesp8266 board
# configure PWM on pin p2
pwm2 = machine.PWM(p2)
# set the PWM frequency as 50Hz
# the frequency must be between 1Hz and 1kHz.
pwm2.freq(50)
 
while True:
    for d in range(0,100,1):
        # set the duty cycle to d .i.e. 18 through 115 with step of 1
        pwm2.duty(d)
        tSleep = (d/1023)*20
        time.sleep(tSleep)
        # print the pwm details like pin, freq, duty cycle
        print (pwm2)
    time.sleep(2)
