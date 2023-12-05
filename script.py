import serial
# Change the port and baud rate to match your Arduino's configuration
arduino_port = '/dev/ttyACM0'  # Update with the correct port on your system
baud_rate = 9600

# Open the serial connection
ser = serial.Serial(arduino_port, baud_rate)

# Open a file for writing
output_file = open('output.txt', 'w')

try:
    while True:
        # Read a line from the Arduino
        line = ser.readline().decode('utf-8').strip()
        
        # Print the line to the console
        print(line)
        
        # Write the line to the file
        output_file.write(line + '\n')
except KeyboardInterrupt:
    # Close the serial connection and file on keyboard interrupt
    ser.close()
    output_file.close()