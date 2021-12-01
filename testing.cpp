myVariable = 0

def when_started1():
    global myVariable
    drivetrain.set_drive_velocity(10000, RPM)

# define variable for remote controller enable/disable
remote_control_code_enabled = True
rc_auto_loop_thread_controller_1 = Thread(rc_auto_loop_function_controller_1)

when_started1()
