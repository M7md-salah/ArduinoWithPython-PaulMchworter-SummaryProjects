import serial
import time
from vpython import *

arduinoData = serial.Serial('COM3', 9600)
time.sleep(1) 
tube = cylinder(color = color.red,radius=1, length =5)
lab=label(text = '5 Volts', box=False,pos= vector(0 , 0.2, 0))
while True:
    while arduinoData.in_waiting == 0:
        pass
    
    dataPacket = arduinoData.readline().decode('utf-8').strip() 
    try:
        rawValue = int(dataPacket) 
        voltage = (rawValue / 1023.0) * 5.0 
        print(f"Current Voltage: {voltage:.2f} V")
        tube.length = voltage
        voltage = round(voltage , 1)
        lab.text =str(voltage)
    except ValueError:
        pass