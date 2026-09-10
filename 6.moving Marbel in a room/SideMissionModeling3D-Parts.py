from vpython import *
roomX = 12
roomY = 10
roomZ = 16
wallT = 0.5

wallColor = vector(10, 10, 10)
wallOpacity = 0.1
marbleRadius = 0.5
ballColor = vector(0, 0, 1)

myFloor = box(size = vector(roomX , wallT , roomZ),pos = vector(0 , -roomY/2 , 0), color = wallColor , opacity = wallOpacity ) 
myCeiling = box(size = vector(roomX , wallT , roomZ),pos = vector(0 , roomY/2 , 0), color = wallColor , opacity = wallOpacity )
leftWall = box(size = vector(wallT , roomY , roomZ),pos = vector(-roomX/2 , 0 , 0), color = wallColor , opacity = wallOpacity )
rightWall = box(size = vector(wallT , roomY , roomZ),pos = vector(roomX/2 , 0 , 0), color = wallColor , opacity = wallOpacity )
backWall = box(size = vector(roomX , roomY , wallT),pos = vector(0 , 0 , -roomZ/2), color = wallColor , opacity = wallOpacity )
marble = sphere(radius = marbleRadius , color = ballColor , pos = vector(0 , 0 , 0))

marbleX = 0
deltax = 0.1

while True:
    rate(100)
    while True:
        rate(20)

        marbleX = marbleX + deltax
        if marbleX+marbleRadius> roomX/2-wallT/2 or marbleX-marbleRadius< -roomX/2+wallT/2:
            deltax = -deltax
            marbleX = marbleX + deltax
        marble.pos = vector(marbleX , 0 , 0)