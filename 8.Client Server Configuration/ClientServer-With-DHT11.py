import serial
import time

arduinoData = serial.Serial('COM3', 9600)

time.sleep(2) 

arduinoData.reset_input_buffer() 

while True:
    cmd = input('What measurement do you want to see? (temp/hum) : ')
    
    arduinoCmd = cmd + '\r'
    arduinoData.write(arduinoCmd.encode('utf-8'))
    
    while arduinoData.in_waiting == 0:
        pass
        
    dataPacket = arduinoData.readline().decode('utf-8').strip()
    
    try:
        splitPacket = dataPacket.split(',')
        
        if splitPacket[0] == 'temp':
            print('Temperature: ', float(splitPacket[1]), 'degrees fahrenheit')
        elif splitPacket[0] == 'hum':
            print('Humidity: ', float(splitPacket[1]), '% humidity')
        else:
            print("Unrecognized response from Arduino:", dataPacket)
            
    except (IndexError, ValueError):
        print("Error: Could not parse data. Make sure you only type 'temp' or 'hum'.")