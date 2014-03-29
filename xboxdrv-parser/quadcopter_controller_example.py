from xboxdrv_parser import Controller
from time import sleep
#import serial

def main ():
    # Get input from the two analog sticks as yaw, throttle, roll, and pitch. Take the (0 - 255) input value and
    # map it to a (-1 - 1) range.
    controller = Controller (["X1", "Y1", "X2", "Y2"], ["yaw", "throttle", "roll", "pitch"], (0, 255), (-1, 1))
    #ser = serial.Serial ('/./dev/ttyACM0', 9600, timeout=1)
    while True:
        control_packet = controller.get_values ()

        print (control_packet)

        if (control_packet['yaw'] == 1):
            #ser.write ('d')
            print ("d")
        elif (control_packet['yaw'] == -1):
            #ser.write ('a')
            print ("a")
        elif (control_packet['throttle'] == -1):
            #ser.write ('w')
            print ("w")
        elif (control_packet['throttle'] == 1):
            #ser.write ('s')
            print ("s")

        # Update at 20 messages a second
        sleep (.05)

if __name__ == '__main__':
    main()
