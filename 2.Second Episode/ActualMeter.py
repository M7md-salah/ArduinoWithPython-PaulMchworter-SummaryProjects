
import serial
import time
from vpython import *
import numpy as np

# 1. Setup Arrow
arrowLength = 1
arrowWidth = 0.02
myArrow = arrow(length=arrowLength, shaftwidth=arrowWidth, color=color.red, axis=vector(1, 1, 0))

tickL = 0.1
tickW = 0.05
tickH = 0.05

# 2. Draw Minor Ticks (Small Slashes)
# 26 stops create exactly 5 small intervals between each of the 6 major ticks
for theta in np.linspace(5*np.pi/6, np.pi/6, 26):
    minor_pos = vector(arrowLength*np.cos(theta), arrowLength*np.sin(theta), 0)
    box(color=color.black, pos=minor_pos, size=vector(0.04, 0.01, 0.05), axis=minor_pos)

# 3. Draw Major Ticks and Numbers
# 6 stops for the main voltages (0, 1, 2, 3, 4, 5)
major_angles = np.linspace(5*np.pi/6, np.pi/6, 6)
voltages = [0, 1, 2, 3, 4, 5]

for i in range(6):
    theta = major_angles[i]
    major_pos = vector(arrowLength*np.cos(theta), arrowLength*np.sin(theta), 0)
    
    # Draw the big green slash
    box(color=color.green, pos=major_pos, size=vector(tickL, tickW, tickH), axis=major_pos)
    
    # Draw the number, pushing it outward by multiplying the radius by 1.15
    label_pos = vector(1.15*arrowLength*np.cos(theta), (1.15*arrowLength*np.sin(theta)) - 0.05, 0)
    text(text=str(voltages[i]), pos=label_pos, align='center', height=0.1, depth=0.01, color=color.black)

# 4. Background and Serial Setup
BoxX = 2.5
BoxY = 1.5
BoxZ = 0.1
myCase = box(color=color.white, size=vector(BoxX, BoxY, BoxZ), pos=vector(0, 0.9*BoxY/2, -BoxZ))

arduinoData = serial.Serial('COM3', 9600)
time.sleep(1) 

while True:
    rate(25)
    # Updated to the correct in_waiting syntax so the script does not freeze
    while arduinoData.in_waiting == 0:
        pass
        
    dataPacket = arduinoData.readline().decode('utf-8').strip()
    
    # Added a try-except block so garbage data on startup doesn't crash your assignment
    try:
        potval = float(dataPacket)
        theta = -2*np.pi/3069*potval + 5*np.pi/6
        myArrow.axis = vector(arrowLength*np.cos(theta), arrowLength*np.sin(theta), 0)
    except ValueError:
        pass

  # for theta in np.linspace(5*np.pi/6,np.pi/6,150):
   #   rate(25)
   #   myArrow.axis = vector(arrowLength*np.cos(theta),arrowLength*np.sin(theta),0)
   #for theta in np.linspace(np.pi/6,5*np.pi/6,150):
    #  rate(25)
     # myArrow.axis = vector(arrowLength*np.cos(theta), arrowLength*np.sin(theta),0)





