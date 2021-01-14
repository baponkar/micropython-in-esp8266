from machine import Pin
import time

led = Pin(2, Pin.OUT) #Define onboard pin

#led.low()
 
while True:
  led.high()
  time.sleep(0.5)
  led.low()
  time.sleep(0.5)
