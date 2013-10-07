import serial

def on():
    ser = serial.Serial(4,9600)
    ser.write('o')
    ser.close()
def off():
    ser = serial.Serial(4,9600)
    ser.write('f')
    ser.close()
