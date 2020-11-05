import serial
port= "/dev/ttyUSB0"
Arduino = serial.Serial(port,9600)
Arduino.write("Inainte");

