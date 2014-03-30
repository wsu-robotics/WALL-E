#
#   Weather update server
#   Binds PUB socket to tcp://*:5556
#   Publishes random weather updates
#

import zmq
from random import randrange

# Set the context of the server
context = zmq.Context()

# Set the socket to PUBlish
socket = context.socket(zmq.PUB)

# Bind the socket to 5556
socket.bind("tcp://*:5556")

while True:
	# Randomly generate values
    zipcode = randrange(1, 100000)
    temperature = randrange(-80, 135)
    relhumidity = randrange(10, 60)

	# Send the random values to the SUBscriber/Client as a string
    socket.send_string("%i %i %i" % (zipcode, temperature, relhumidity))