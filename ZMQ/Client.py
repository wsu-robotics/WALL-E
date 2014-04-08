#
#   Weather update client
#   Connects SUB socket to tcp://localhost:5556
#   Collects weather updates and finds avg temp in zipcode
#

import sys
import zmq
import serial

ser = serial.Serial ('/./dev/tty/ACM0', 9600, timeout=1)

# Set the context of the Client
context = zmq.Context()
# Set the socket as a SUBscriber
socket = context.socket(zmq.SUB)

# Connect to the Server
# The socket is the connection to the server
print("Collecting updates from server...")
socket.connect("tcp://10.99.66.73:5556")

# Set the options for the socket
socket.setsockopt_unicode(zmq.SUBSCRIBE, "WALLE")
while True:
	control_packet = socket.recv_json()
	#Print out the results
	print(control_packet)
	input = 0
    if (control_packet['yaw'] <= 1 and control_packet['yaw'] >= 0.05):
        input *= 255
        input += 255
        print ("d")
    elif (control_packet['yaw'] >= -1 and control_packet['yaw'] <= -0.05):
        input *= 255
        input -= 255
        print ("a")
    elif (control_packet['throttle'] >= -1 and control_packet['throttle'] <= -0.08):
        input *= 255
		#make the value intuitive
        input = math.fabs(input)
        print ("w")
    elif (control_packet['throttle'] <= 1 and control_packet['throttle'] >= 0.08):
        input *= 255
	    #make the value intuitive
        input = -input
        print ("s")
	ser.write(input)