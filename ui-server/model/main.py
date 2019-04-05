import serial
import json

# To find port on Mac, go to terminal and enter 'ls /dev/tty.*' hopefully you'll find it.
#  For windows, I have no clue :)
s = serial.Serial(port='/dev/tty.usbmodem141201', baudrate=9600)

# Discarding input buffer
s.flushInput()

while True:
    try:
        # Read line from arduino
        s_bytes = s.readline()

        # Decode bytes from arduino
        decode_b = (s_bytes.decode("utf-8")).split("|")

        # Store values given from decode_b list, indx are from arduinoSketch.ino
        magVals = decode_b[0]
        gyroVals = decode_b[1]
        eulerVals = decode_b[2]
        accelVals = decode_b[3]
        linAccelVals = decode_b[4]
        gravVals = decode_b[5]
        tempVal = decode_b[6].replace("\r\n", "")

        # Store the json object into j
        j = json.dumps({"MagVals": magVals,
                        "gyroVals": gyroVals,
                        "eulerVals": eulerVals,
                        "accelVals": accelVals,
                        "linAccelVals": linAccelVals,
                        "gravVals": gravVals,
                        "tempVal": tempVal}
                       , sort_keys=True, indent=4)

        # Display the json object
        print(j)



    except:
        # Something bad happened
        print("Keyboard Interrupt")
        break
