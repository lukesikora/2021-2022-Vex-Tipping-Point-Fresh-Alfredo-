myVariable = 0

def when_started1():
    global myVariable
    motor_15.set_velocity(80, PERCENT)

def onevent_controller_1axis3Changed_0():
    global myVariable
    motor_15.spin(FORWARD)

def onevent_controller_1buttonB_pressed_0():
    global myVariable
    motor_15.stop()

# define variable for remote controller enable/disable
remote_control_code_enabled = True
rc_auto_loop_thread_controller_1 = Thread(rc_auto_loop_function_controller_1)


# system event handlers
controller_1.buttonB.pressed(onevent_controller_1buttonB_pressed_0)
controller_1.buttonY.pressed(onevent_controller_1buttonY_pressed_0)
# add 15ms delay to make sure events are registered correctly.
wait(15, MSEC)

when_started1()
