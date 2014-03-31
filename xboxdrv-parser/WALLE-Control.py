from xboxdrv_parser import Controller
from time import sleep
import serial

def main ():
    # Get input from the two analog sticks as yaw, throttle, roll, and pitch. Take the (0 - 255) input value and
    # map it to a (-1 - 1) range.
    controller = Controller (["X1", "Y1", "X2", "Y2"], ["yaw", "throttle", "roll", "pitch"], (0, 255), (-1, 1))
    ser = serial.Serial ('/./dev/ttyACM0', 9600, timeout=1)
    while True:
        control_packet = controller.get_values ()

        print (control_packet)
	
        input = 0
        if (control_packet['yaw'] <= 1 and control_packet['yaw'] >= 0.05):
            input *= 255
            input += 255
            ser.write (input)
            print ("d")
        elif (control_packet['yaw'] >= -1 and control_packet['yaw'] <= -0.05):
            input *= 255
            input -= 255
            ser.write (input)
            print ("a")
        elif (control_packet['throttle'] >= -1 and control_packet['throttle'] <= -0.08):
            input *= 255
	    #make the value intuitive
            input = math.fabs(input)
            ser.write (input)
            print ("w")
        elif (control_packet['throttle'] <= 1 and control_packet['throttle'] >= 0.08):
            input *= 255
	    #make the value intuitive
            input = -input
            ser.write (input)
            print ("s")

        # Update at 20 messages a second
        sleep (.05)

if __name__ == '__main__':
    main()
