'''
Network basics in esp8266
writer : bapon kar
Last Update : 26/01/2021
'''

def do_connect():
  import network
  sta_if = network.WLAN(network.STA_IF) #Act as station connect to a router
  ap_if = network.WLAN(network.AP_IF)
  if not sta_if.isconnected():
    print('connecting to network...')
    sta_if.active(True)
    sta_if.connect('<my ESSID>', '<my password>')
    while not sta_if.isconnected():
      pass
  print(sta_if.isconnect)
  print(sta_if.ifconfig())
  ap_if.active(False)
  
def make_router():
  import network
  ap_if = network.WLAN(network.AP_IF) #act as access point to connect other devices
  sta_if = network.WLAN(network.STA_IF)
  if sta_if.active():
    sta_if.active(false)
  #Checking
  if ap_if.active():
    pass
  else:
    ap_if.active(True)
    #check network configaration
  print(ap_if.ifconfig())

#make_router()
do_connect()
