from machine import Pin
import time

led = Pin(2, Pin.OUT) #Define onboard pin , external led should connect to D4 pin of esp8266 board

#led.low()
 
while True:
  led.high()
  time.sleep(0.5)
  led.low()
  time.sleep(0.5)
