import time
import serial
from vpython import *

arduinoData = serial.Serial('COM3', 9600)
time.sleep(1)

scene.background = color.gray(0.2)
scene.title = "Real-Time Humidity Tank"

tank_glass = box(pos=vector(0, 5, 0), size=vector(4, 10, 4), color=color.cyan, opacity=0.2)
water = box(pos=vector(0, 0, 0), size=vector(3.8, 0.1, 3.8), color=color.blue)
hum_label = label(text='0 %', height=25, box=False, pos=vector(0, 12, 0))

while True:
    rate(25) 
    
    while arduinoData.in_waiting == 0:
        pass
        
    dataPacket = arduinoData.readline().decode('utf-8').strip()
    dataPacket = dataPacket.split(',')
    
    try:
        humidity = float(dataPacket[1])
        water_height = (humidity / 100.0) * 10.0
        water.size.y = max(water_height, 0.01)
        water.pos.y = water.size.y / 2
        hum_label.text = f'Humidity: {humidity:.1f} %'
        
    except (ValueError, IndexError):
        pass