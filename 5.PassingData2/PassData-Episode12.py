import serial
from vpython import *

arduinoData = serial.Serial('COM3', 9600)

baseRadius = 1
baseHeight = baseRadius/5
bodyRadius = baseRadius*0.75
bodyHeight = bodyRadius*2.5
LEDTopRadius = bodyRadius
LEDTopPos = vector(0, bodyHeight, 0)
bulbRadius = bodyRadius*0.75
bulbPos = LEDTopPos
leg1Length = bodyRadius*8
leg2Length = bodyRadius*9
leg3Length = bodyRadius*10
leg4Length = bodyRadius*8
legWidth = 0.15
bulbOpacity = 0.9
topOpacity = bulbOpacity/2
bottomOpacity = bulbOpacity/5

myColor = vector(10, 10, 10) 
myAxis = vector(0, 1, 0)

LEDBase = cylinder(length=baseHeight, radius=baseRadius, color=myColor, axis=myAxis, opacity=bottomOpacity)
LEDBody = cylinder(length=bodyHeight, radius=bodyRadius, color=myColor, axis=myAxis, opacity=bottomOpacity)
LEDTop = sphere(radius=LEDTopRadius, color=myColor, pos=LEDTopPos, opacity=topOpacity)
bulb = sphere(radius=bulbRadius, color=myColor, pos=bulbPos, opacity=bulbOpacity)

leg1 = box(color=color.blue, axis=myAxis, pos=vector(-0.5*baseRadius, -leg1Length/2+baseHeight, 0), length=leg1Length, width=legWidth, height=legWidth)
leg2 = box(color=color.green, axis=myAxis, pos=vector(-0.15*baseRadius, -leg2Length/2+baseHeight, 0), length=leg2Length, width=legWidth, height=legWidth)
leg3 = box(color=color.white, axis=myAxis, pos=vector(0.15*baseRadius, -leg3Length/2+baseHeight, 0), length=leg3Length, width=legWidth, height=legWidth)
leg4 = box(color=color.yellow, axis=myAxis, pos=vector(0.5*baseRadius, -leg4Length/2+baseHeight, 0), length=leg4Length, width=legWidth, height=legWidth)

head = compound([bulb, LEDBase, LEDBody, LEDTop])

while True:
    myCmd = input('Please input the color: ')
    
    arduinoCmd = myCmd + '\r'
    arduinoData.write(arduinoCmd.encode('utf-8'))
    
    cleanCmd = myCmd.strip().upper()
    
    if cleanCmd == "BLUE":
        head.color = color.blue
    elif cleanCmd == "GREEN":
        head.color = color.green
    elif cleanCmd == "YELLOW":
        head.color = color.yellow
    else:
        head.color = vector(0.2, 0.2, 0.2)