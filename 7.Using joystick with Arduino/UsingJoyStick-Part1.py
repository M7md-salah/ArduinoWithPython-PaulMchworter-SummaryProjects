import serial
import time
from vpython import *

arduinoData = serial.Serial('COM3', 9600)
time.sleep(1)
arduinoData.reset_input_buffer()

roomX = 25
roomY = 8
roomZ = 4
wallT = 0.5

wallColor = vector(0.5, 0.5, 0.5) 
wallOpacity = 0.1
marbleRadius = 0.5

myFloor = box(size=vector(roomX, wallT, roomZ), pos=vector(0, -roomY/2, 0), color=wallColor, opacity=wallOpacity) 
myCeiling = box(size=vector(roomX, wallT, roomZ), pos=vector(0, roomY/2, 0), color=wallColor, opacity=wallOpacity)
leftWall = box(size=vector(wallT, roomY, roomZ), pos=vector(-roomX/2, 0, 0), color=wallColor, opacity=wallOpacity)
rightWall = box(size=vector(wallT, roomY, roomZ), pos=vector(roomX/2, 0, 0), color=wallColor, opacity=wallOpacity)
backWall = box(size=vector(roomX, roomY, wallT), pos=vector(0, 0, -roomZ/2), color=wallColor, opacity=wallOpacity)
marble = sphere(radius=marbleRadius, color=color.blue, pos=vector(0, 0, 0))
marble2 = sphere(radius=marbleRadius, color=color.red, pos=vector(0, 0, 0))

marbleX, deltax = 0, 0.1
marbleY, deltay = 0, 0.1
marbleZ, deltaz = 0, 0.1

while True:
    rate(50)
    
    # === PART 1: THE BOUNCING BLUE MARBLE ===
    marbleX = marbleX + deltax
    marbleY = marbleY + deltay
    marbleZ = marbleZ + deltaz

    if marbleX+marbleRadius > roomX/2-wallT/2 or marbleX-marbleRadius < -roomX/2+wallT/2:
        deltax = -deltax
    if marbleY+marbleRadius > roomY/2-wallT/2 or marbleY-marbleRadius < -roomY/2+wallT/2:
        deltay = -deltay
    if marbleZ+marbleRadius > roomZ/2-wallT/2 or marbleZ-marbleRadius < -roomZ/2+wallT/2:
        deltaz = -deltaz
        
    marble.pos = vector(marbleX, marbleY, marbleZ)


    if arduinoData.in_waiting > 0:
        dataPacket = arduinoData.readline().decode('utf-8').strip()
        
        try:
            splitData = dataPacket.split(',')
            rawX = float(splitData[0])
            rawY = float(splitData[1])
            
            mappedX = (rawX / 1023.0) * roomX - (roomX / 2.0)
            mappedY = (rawY / 1023.0) * roomY - (roomY / 2.0)
            
            marble2.pos.x = mappedX
            marble2.pos.y = mappedY
            
        except(ValueError, IndexError , UnicodeDecodeError):
            pass