from xboxdrv_parser import Controller
from time import sleep

def main ():
    # Get input from the two analog sticks as yaw, throttle, roll, and pitch. Take the (0 - 255) input value and
    # map it to a (-1 - 1) range.
    controller = Controller (["X1", "Y1", "X2", "Y2"], ["yaw", "throttle", "roll", "pitch"], (0, 255), (-1, 1))

    while True:
        control_packet = controller.get_values ()

        print control_packet

        # Update at 20 messages a second
        sleep (.05)

if __name__ == '__main__':
    main()
