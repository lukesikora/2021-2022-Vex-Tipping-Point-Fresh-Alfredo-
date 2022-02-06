myVariable = 0

def when_started1():
    global myVariable
    motor_15.set_velocity(90, PERCENT)
    drivetrain.set_drive_velocity(30, PERCENT)
    # starting next
    motor_18.spin(REVERSE)
    drivetrain.drive_for(REVERSE, 200, MM, wait=True)
    motor_18.spin(FORWARD)
    motor_15.spin(FORWARD)
    wait(8, SECONDS)

# define variable for remote controller enable/disable
remote_control_code_enabled = True
rc_auto_loop_thread_controller_1 = Thread(rc_auto_loop_function_controller_1)

when_started1()
