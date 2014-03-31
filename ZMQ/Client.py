#
#   Weather update client
#   Connects SUB socket to tcp://localhost:5556
#   Collects weather updates and finds avg temp in zipcode
#

import sys
import zmq

# Set the context of the Client
context = zmq.Context()
# Set the socket as a SUBscriber
socket = context.socket(zmq.SUB)

# Connect to the Server
# The socket is the connection to the server
print("Collecting updates from weather server...")
socket.connect("tcp://10.99.66.73:5556")

# Subscribe to zipcode, default is Pullman, 99163
# Can be changed by adding arguments to the command line initialization
zip_filter = sys.argv[1] if len(sys.argv) > 1 else "99163"

# Python 2 - ascii bytes to unicode str
# Converts the zip_filter from a string to an int
if isinstance(zip_filter, bytes):
    zip_filter = zip_filter.decode('ascii')
	
# Set the options for the socket
socket.setsockopt_unicode(zmq.SUBSCRIBE, zip_filter)

# Process 5 updates
total_temp = 0
for update_nbr in range(5):
    string = socket.recv()
    zipcode, temperature, relhumidity = string.split()
    total_temp += int(temperature)

# Print out the results
print("Average temperature for zipcode '%s' was %dF" % (
      zip_filter, total_temp / update_nbr)
)
