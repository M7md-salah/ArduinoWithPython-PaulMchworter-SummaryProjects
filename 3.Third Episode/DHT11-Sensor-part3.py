import time
import serial
from vpython import *
import numpy as np

arduinoData = serial.Serial('com3' , 9600)
time.sleep(0.5)

scene.center = vector(5,0,0)

boxX = 10
boxY = 6
boxZ = 0.4
offsetRight = boxX/2+2
myCase = box(size = vector(boxX,boxY,boxZ),color = color.white, pos = vector(offsetRight , 0 , boxZ/2))

arrowlength = boxY-2
arrowthickness = 0.15
arrowZoff = 0.5
myArrow = arrow(length = arrowlength, color = color.red, shaftwidth = arrowthickness, pos = vector(offsetRight , -0.9*boxY/2,arrowZoff ))

tickL = 0.3
tickW = 0.1
tichH = 0.1
tickF = 0.7
for theta in np.linspace(5*np.pi/6,np.pi/6,11):
    tickMajor = box(pos = vector(1.1*arrowlength*np.cos(theta)+offsetRight,1.1*arrowlength*np.sin(theta)-0.9*boxY/2,0.5), size = vector(tickL,tickW,tichH),color = color.black,axis = vector(arrowlength*np.cos(theta),arrowlength*np.sin(theta),0) )
for theta in np.linspace(5*np.pi/6,np.pi/6,51):
    tickMinor = box(pos = vector(1.1*arrowlength*np.cos(theta)+offsetRight, 1.1*arrowlength*np.sin(theta)-0.9*boxY/2,0.5), size = vector(tickF*tickL,tickF*tickW,tickF*tichH),color = color.black,axis = vector(arrowlength*np.cos(theta),arrowlength*np.sin(theta),0))
digvalue = label(text = '50',height = 20, box = False, pos = vector(0, -2.5,2))
num = 0
for theta in np.linspace(5*np.pi/6 , np.pi/6 , 11):
    lab = text(text =str(num), pos = vector(1.2*arrowlength*np.cos(theta)+offsetRight,1.2*arrowlength*np.sin(theta)-0.9*boxY/2,0.5),axis = vector(arrowlength*np.cos(theta),arrowlength*np.sin(theta),0), color = color.blue, height =0.4,align = 'center' )
    num = num+10

bulb = sphere(radius = 1,color = color.red, pos = vector(0 , -3 , 0))
cyl = cylinder(radius = 0.60, color = color.red, axis = vector(0,1,0), length = 6, pos = vector(0,-3,0))
bulbGlass = sphere(radius = 1.2, color = color.white, opacity = 0.25,pos = vector(0,-3 , 0))
cylGlass = cylinder(radius = 0.8, color = color.white, opacity= 0.25,axis = vector(0,1,0), length = 6,pos = vector(0,-3,0 ))

for temp in range(0,115,10):
    tickpos = 4.5/115*temp+1.5
    tick = cylinder(radius = 0.7, color = color.black, length = 0.1,axis = vector(0,1,0),pos = vector(0,tickpos-3,0))
    label = text(text = str(temp),color = color.white,pos = vector(-2,tickpos-3,0),height = 0.3 )


while True:
    while arduinoData.inWaiting == 0:
        pass

    dataPacket = arduinoData.readline()
    print(dataPacket)
    dataPacket = str(dataPacket , 'utf-8')
    dataPacket = dataPacket.strip('\r\n')
    dataPacket = dataPacket.split(',')
    temp = float(dataPacket[0])
    humdidity = float(dataPacket[1])
    len = (4.5/115)*temp+1.5
    cyl.length = len
    digvalue.text = str(temp)
    theta = -np.pi/150*humdidity+5*np.pi/6
    myArrow.axis= vector(arrowlength*np.cos(theta),arrowlength*np.sin(theta),0)
