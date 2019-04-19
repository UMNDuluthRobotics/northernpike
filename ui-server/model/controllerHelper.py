import pygame
import numpy as np
import json
import time

from websocket import create_connection

# -------- Main Program Loop -----------
pygame.init()
pygame.joystick.init()
ws = create_connection("ws://0.0.0.0:8080")

while True:
    pygame.event.get()
    joystick = pygame.joystick.Joystick(0)
    joystick.init()

    # Roll right / Roll left
    roll = np.int8(joystick.get_axis(0) * 128)

    # Up / Down
    pitch = np.int8(joystick.get_axis(1) * 128)

    # Turn right / Turn left
    yaw = np.int8(joystick.get_axis(2) * 128)

    # Store the values as a list of list. Otherwise json doesn't like int8 arrays
    roll = roll.tolist()
    pitch = pitch.tolist()
    yaw = yaw.tolist()

    j = json.dumps({"Roll": roll,
                    "Pitch": pitch,
                    "Yaw": yaw}
                   , sort_keys=True, indent=4)

    # Delay
    time.sleep(.5)
    ws.send(j)

ws.close()