myVariable = 0

def when_started1():
    global myVariable
    drivetrain.set_drive_velocity(100, PERCENT)
    motor_15.set_velocity(70, PERCENT)
    drivetrain.turn_for(RIGHT, 90, DEGREES, wait=True)
    drivetrain.drive_for(FORWARD, 465, MM, wait=True)
    drivetrain.stop()
    # PICK UP BOX FUNCTION
    drivetrain.drive_for(FORWARD, 320, MM, wait=True)
    drivetrain.turn_for(LEFT, 90, DEGREES, wait=True)
    motor_15.spin(FORWARD)
    drivetrain.drive_for(FORWARD, 2668, MM, wait=True)
    motor_15.stop()
    drivetrain.turn_for(LEFT, 90, DEGREES, wait=True)
    drivetrain.drive_for(FORWARD, 546, MM, wait=True)
    # DROP BOX FUNCTION

# define variable for remote controller enable/disable
remote_control_code_enabled = True
rc_auto_loop_thread_controller_1 = Thread(rc_auto_loop_function_controller_1)

when_started1()
