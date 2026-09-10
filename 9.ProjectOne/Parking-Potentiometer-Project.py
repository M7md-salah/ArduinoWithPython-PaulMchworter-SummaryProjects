import serial
import time
from vpython import *

arduinoData = serial.Serial('COM3', 9600)
time.sleep(2)
arduinoData.reset_input_buffer()

scene.title = "Parking Gate Digital Twin"
scene.background = color.black

road = box(pos=vector(0, -1, 0), size=vector(30, 0.5, 10), color=color.gray(0.2))

gate_post = cylinder(pos=vector(-5, -1, 4), axis=vector(0, 5, 0), radius=0.5, color=color.yellow)

car = box(pos=vector(15, 0.5, 0), size=vector(4, 2, 2), color=color.blue)

dist_text = text(text='Distance: -- cm', pos=vector(-5, 6, 0), align='center', height=1.5, color=color.white)

while True:
    rate(50)
    
    if arduinoData.in_waiting > 0:
        try:
            dataPacket = arduinoData.readline().decode('utf-8').strip()
            
            splitData = dataPacket.split(',')
            
            if splitData[0] == 'dist':
                distance = float(splitData[1])
                
                dist_text.text = 'Distance: ' + str(int(distance)) + ' cm'
                
                carX = (distance / 300.0) * 20.0 - 5.0
                car.pos.x = carX
                
                if distance < 150:
                    car.color = color.green
                else:
                    car.color = color.blue
                    
        except (ValueError, IndexError, UnicodeDecodeError):
            pass