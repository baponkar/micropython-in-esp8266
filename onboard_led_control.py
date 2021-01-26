#Onbard led of nodemcu esp8266 board blink
#Writer : Bapon Kar
#Last Update : 26/01/2021


from machine import Pin
import time

led = Pin(2, Pin.OUT) #Define onboard pin , external led should connect to D4 pin of esp8266 board through 1Kohom resistance

#led.low()
 
while True:
  led.high()  #led.value(1)
  time.sleep(0.5)
  led.low()  #led.value(0)
  time.sleep(0.5)
