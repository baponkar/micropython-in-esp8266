# [Micropython](https://en.wikipedia.org/wiki/MicroPython#:~:text=From%20Wikipedia,%20the%20free%20encyclopedia%20MicroPython%20is%20a,and%20runtime%20that%20runs%20on%20the%20microcontroller's%20hardware.)-in-[NodeMCUesp8266](https://en.wikipedia.org/wiki/NodeMCU)

![Micropython Badge](https://img.shields.io/badge/micro-python-yellowgreen)
![Nodemcu esp8266](https://img.shields.io/badge/NodeMCU-esp8266-red)
![uPycraft](https://img.shields.io/badge/uPyCraft-IDE-brightgreen)
![Windows 10 pro](https://img.shields.io/badge/Windows-10-blue)

![GitHub Logo](NodeMCU-ESP8266-Pinout.jpg)

 
 ## Step by step micropython test in esp8266

- [x] My System is [Windows-10](https://www.amazon.in/Windows-10-Home-OEM-Lifetime/dp/B08CN5887S/ref=sr_1_1_sspa?dchild=1&keywords=windows+10&qid=1611655557&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzVjRLQTlMUFo3SktZJmVuY3J5cHRlZElkPUEwNzI5OTk3MlROTVlTWktGSjFMUSZlbmNyeXB0ZWRBZElkPUEwMjA5NTI0MjVIUTRCWkNHWkoxMiZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=) 

- [x] Board - [NodeMCU ESP8266](https://www.amazon.in/Generic-Nodemcu-Esp8266-Internet-Development/dp/B07262H53W/ref=sr_1_2?dchild=1&keywords=esp8266&qid=1610616571&sr=8-2)

- [x] System Python version - [Python-3.7.9 ](https://www.python.org/ftp/python/3.9.1/python-3.9.1-amd64.exe)

- [x] [Micropython Firmwaire](http://micropython.org/resources/firmware/esp8266-20170108-v1.8.7.bin) or [Micropython-v1.8.7.bin](https://github.com/baponkar/micropython-in-esp8266/blob/main/esp8266-20170108-v1.8.7.bin)

- [x] [UPyCraft v1.1 IDE](https://randomnerdtutorials.com/uPyCraftWindows) or [uPyCraft v1.1 IDE](https://github.com/baponkar/micropython-in-esp8266/blob/main/uPyCraft_V1.1.exe)

* firmeware install into esp8266 board
![GitHub Logo](upycraft_frimeware_install.png)
![GitHub Logo](upycraft_frimeware_install1.png)


## Installing tool for esp8266 in Ubuntu

- [x]  ``` sudo pip3 install esptool ```
- [x] ``` esptool.py --port /dev/ttyUSB0 erase_flash ```
- [x] ``` esptool.py --port /dev/ttyUSB0 --baud 460800 write_flash --flash_size=detect 0 esp8266-20170108-v1.8.7.bin ```
- [x] ``` esptool.py --port /dev/ttyUSB0 --baud 460800 write_flash --flash_size=detect -fm dio 0 esp8266-20170108-v1.8.7.bin ```
- [x] ``` picocom /dev/ttyUSB0 -b115200 ```
- [x] ```  ```

###### [Micropython Documentation](https://docs.micropython.org/en/latest/esp8266/tutorial/intro.html)


* [Onboard Led blink](https://github.com/baponkar/micropython-in-esp8266/blob/main/onboard_led_control.py)
* [Network Control]( https://github.com/baponkar/micropython-in-esp8266/blob/main/network_control.py)
* [Servo Control](https://github.com/baponkar/micropython-in-esp8266/blob/main/servo_control.py)
* [File Manipulation](https://github.com/baponkar/micropython-in-esp8266/blob/main/file_manipulation.py)

Sometimes you may have this kind error:
```download ok
exec(open('main.py').read(),globals())
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
MemoryError: memory allocation failed, allocating 10496 bytes
```
Then you need to make a custom firmwire and add [frozen module](https://learn.adafruit.com/micropython-for-samd21/frozen-modules) to save memory.
Now you need to change file.py to file.mpy which generally takes lower ram than .py file to change into .mpy file you need to install following software into your Ubuntu device.If you are using widows then you need to install virtual box inside of windows and then you need to install ubuntu os on that virtualbox and then you need to install following software on ubuntu. 
Installing virtualbox on Ubuntu :
```
sudo apt-get update
sudo apt install virtualbox-qt

```
Installing [Vagrant](https://linuxize.com/post/how-to-install-vagrant-on-ubuntu-20-04/) on Ubuntu:
```
sudo apt install curl
curl -O https://releases.hashicorp.com/vagrant/2.2.9/vagrant_2.2.9_x86_64.deb
sudo apt install ./vagrant_2.2.9_x86_64.deb
vagrant --version
```
Getting Started with Vagrant 
```
mkdir ~/my-vagrant-project
cd ~/my-vagrant-project

```
[Vagrant Catalog box](https://www.vagrantup.com/docs/boxes)
```
vagrant init centos/8
```
```
vagrant up
```


