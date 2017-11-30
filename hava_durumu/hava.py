import pyowm
import serial
import time

KEY = '6716ca9c2411e268225e2aa2e7853489'
 
owm = pyowm.OWM(KEY)
observation = owm.weather_at_place('dubai')
w = observation.get_weather()

PORT = "/dev/ttyACM0"
BAUD = 115200
s = serial.Serial(PORT)
s.baudrate = BAUD
s.parity   = serial.PARITY_NONE
s.databits = serial.EIGHTBITS
s.stopbits = serial.STOPBITS_ONE

icon_name = w.get_weather_icon_name()
print(icon_name)

while True:
    s.write(icon_name.encode('utf-8'))
    time.sleep(1)

s.close()
