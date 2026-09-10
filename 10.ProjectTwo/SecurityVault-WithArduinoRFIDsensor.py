import serial
import time
from vpython import *

print("Connecting to Secure Vault...")
arduinoData = serial.Serial('COM3', 9600, timeout=1)
time.sleep(1)
arduinoData.reset_input_buffer()

scene.title = "RFID Secure Audio Vault"
scene.background = color.black
scene.camera.pos = vector(0, 2, 12)

vault_body = box(pos=vector(0, 0, 0), size=vector(10, 10, 10), color=color.gray(0.5), opacity=0.2)
vault_door = box(pos=vector(0, 0, 5), size=vector(10, 10, 0.5), color=color.red)
sound_bar = cylinder(pos=vector(0, -4, 0), axis=vector(0, 1, 0), radius=1.5, color=color.cyan, length=0.1)

# استبدلنا text() بـ label() عشان مشكلة "text is read-only"
status_text = label(pos=vector(-2, 6, 0), text='SYSTEM LOCKED', color=color.red,
                     height=16, box=False, opacity=0)

print("System Ready. Waiting for RFID scan...")

while True:
    rate(60)

    if arduinoData.in_waiting > 0:
            packet = arduinoData.readline().decode('utf-8').strip()

            if not packet:
                continue

            print("Arduino is sending:", packet)
            data = packet.split(',')

            if data[0] == 'status':
                if data[1] == 'locked':
                    vault_door.pos = vector(0, 0, 5)
                    vault_door.color = color.red
                    status_text.text = 'SYSTEM LOCKED'
                    status_text.color = color.red
                    sound_bar.length = 0.1
                    print(">> Vault state set to LOCKED")

                elif data[1] == 'unlocked':
                    vault_door.pos = vector(8, 0, 5)
                    vault_door.color = color.green
                    status_text.text = 'VAULT OPEN - RECORDING'
                    status_text.color = color.green
                    print(">> Vault state set to UNLOCKED")

                elif data[1] == 'denied':
                    scanned = data[2] if len(data) > 2 else '?'
                    print(f">> Access denied for tag: {scanned}")

            elif data[0] == 'sound':
                sound_value = float(data[1])
                mapped_height = (sound_value / 1023.0) * 8.0

                if mapped_height < 0.1:
                    mapped_height = 0.1

                sound_bar.length = mapped_height