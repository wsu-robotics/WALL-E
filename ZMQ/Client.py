#
#   Weather update client
#   Connects SUB socket to tcp://localhost:5556
#   Collects weather updates and finds avg temp in zipcode
#

import sys
import zmq
import serial


ser = serial.Serial ('/../dev/ttyACM0', 9600, timeout=1)

# Set the context of the Client
context = zmq.Context()
# Set the socket as a SUBscriber
socket = context.socket(zmq.SUB)

ser.open ()

# Connect to the Server
# The socket is the connection to the server
print("Collecting updates from server...")
socket.connect("tcp://10.99.66.73:5556")

# Set the options for the socket
socket.setsockopt(zmq.SUBSCRIBE, "")
while True:
	control_packet = socket.recv_json()
	#Print out the results
	#print(control_packet)
	inp = 0
	if (control_packet['yaw'] <= 1 and control_packet['yaw'] >= 0.05):
	
			inp += abs((255 * control_packet["yaw"]))
			print("yaw", inp)

	elif (control_packet['yaw'] >= -1 and control_packet['yaw'] <= -0.05):
	
			inp -= abs((255 * control_packet["yaw"]))
			print("yaw", inp)
	inp = 0
	if (control_packet['throttle'] >= -1 and control_packet['throttle'] <= -0.08):
	
			inp += (abs((255 * control_packet["throttle"])))
			print("throttle", inp)
	
	elif (control_packet['throttle'] <= 1 and control_packet['throttle'] >= 0.08):
	
			inp -= (abs((255 *control_packet["throttle"])))
			print("throttle", inp)
	ser.write(str (inp) + '\n')