from vpython import *
import serial
import time 

arduinoData = serial.Serial('COM3', 9600)
time.sleep(1)
arduinoData.reset_input_buffer() 

roomX = 12
roomY = 10
roomZ = 16
wallT = .5
wallColor = vector(1, 1, 1)
wallOpacity = .8
frontOpacity = .1
marbleR = .5
ballColor = vector(0, 0, 1)

myFloor = box(size=vector(roomX, wallT, roomZ), pos=vector(0, -roomY/2, 0), color=wallColor, opacity=wallOpacity)
myCeiling = box(size=vector(roomX, wallT, roomZ), pos=vector(0, roomY/2, 0), color=wallColor, opacity=wallOpacity)
leftWall = box(size=vector(wallT, roomY, roomZ), pos=vector(-roomX/2, 0, 0), color=wallColor, opacity=wallOpacity)
rightWall = box(size=vector(wallT, roomY, roomZ), pos=vector(roomX/2, 0, 0), color=wallColor, opacity=wallOpacity)
backWall = box(size=vector(roomX, roomY, wallT), pos=vector(0, 0, -roomZ/2), color=wallColor, opacity=wallOpacity)
frontWall = box(size=vector(roomX, roomY, wallT), pos=vector(0, 0, roomZ/2), color=wallColor, opacity=frontOpacity)
marble = sphere(color=ballColor, radius=marbleR)

paddleX = 2
paddleY = 2
paddleZ = .2
paddleOpacity = .8
paddleColor = vector(0, .8, .6)
paddle = box(size=vector(paddleX, paddleY, paddleZ), pos=vector(0, 0, roomZ/2), color=paddleColor, opacity=paddleOpacity)

marbleX, deltaX = 0, .1
marbleY, deltaY = 0, .1
marbleZ, deltaZ = 0, .1

while True:
    rate(50) 
    
    marbleX = marbleX + deltaX
    marbleY = marbleY + deltaY
    marbleZ = marbleZ + deltaZ

    if marbleX+marbleR > (roomX/2-wallT/2) or marbleX-marbleR < (-roomX/2+wallT/2):
        deltaX = deltaX * (-1)
        marbleX = marbleX + deltaX

    if marbleY+marbleR > (roomY/2-wallT/2) or marbleY-marbleR < (-roomY/2+wallT/2):
        deltaY = deltaY * (-1)
        marbleY = marbleY + deltaY

    if marbleZ+marbleR > (roomZ/2-wallT/2) or marbleZ-marbleR < (-roomZ/2+wallT/2):
        deltaZ = deltaZ * (-1)
        marbleZ = marbleZ + deltaZ

    marble.pos = vector(marbleX, marbleY, marbleZ)

    if arduinoData.in_waiting > 0:
        try:
            dataPacket = arduinoData.readline().decode('utf-8').strip()
            
            splitPacket = dataPacket.split(',')
            
            x = float(splitPacket[0])
            y = float(splitPacket[1])
            z = float(splitPacket[2]) 
            
            padX = (roomX/1023.) * x - roomX/2
            padY = (-roomY/1023.) * y + roomY/2
            
            paddle.pos = vector(padX, padY, roomZ/2)
            
        except (ValueError, IndexError, UnicodeDecodeError):
            pass