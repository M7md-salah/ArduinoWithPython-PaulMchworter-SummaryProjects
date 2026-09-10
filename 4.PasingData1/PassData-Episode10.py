import serial
import time


arduinoData = serial.Serial('COM3', 9600)
time.sleep(1)

while True:
    cmd = input('please enter you command : ')
    cmd = cmd+'\r'
    arduinoData.write(cmd.encode('utf-8'))

