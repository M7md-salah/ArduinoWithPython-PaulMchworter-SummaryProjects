import serial
import time
from vpython import *

arduinoData = serial.Serial('COM3', 9600)
time.sleep(1) 

scene.title = "Voltage Changable"
scene.width = 600
scene.height = 600
scene.background = color.gray(0.15)

base = box(pos=vector(0, -1, 0), size=vector(4, 0.5, 4), color=color.white)

tube = cylinder(pos=vector(0, -0.75, 0), axis=vector(0, 1, 0), radius=1, length=0.01, color=color.red)

voltage_label = label(pos=vector(0, 6, 0), text='Voltage: 0.00 V', box=False, height=25)

while True:
    rate(20) 
    
    while arduinoData.in_waiting == 0:
        pass
    
    dataPacket = arduinoData.readline().decode('utf-8').strip() 
    
    try:
        rawValue = int(dataPacket) 
        voltage = (rawValue / 1023.0) * 5.0 
        
        tube.length = max(voltage, 0.01) 
        
        voltage_label.text = f'Voltage: {voltage:.2f} V'
        
    except ValueError:
        pass