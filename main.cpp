myVariable = 0

def onauton_autonomous_0():
    global myVariable
    motor_15.set_velocity(90, PERCENT)
    motor_15.set_velocity(75, PERCENT)
    motor_12.set_velocity(20, PERCENT)
    motor_18.spin(REVERSE)
    wait(1, SECONDS)
    drivetrain.drive_for(FORWARD, 200, MM, wait=True)
    drivetrain.stop()
    motor_18.spin(FORWARD)
    motor_15.spin(REVERSE)
    wait(4, SECONDS)
    motor_15.stop()
    drivetrain.drive_for(REVERSE, 200, MM, wait=True)
    motor_18.spin_for(REVERSE, 270, DEGREES, wait=True)
    motor_18.stop()

def ondriver_drivercontrol_0():
    global myVariable
    drivetrain.set_turn_velocity(50, PERCENT)
    motor_15.set_velocity(100, PERCENT)
    motor_18.set_velocity(50, PERCENT)
    motor_12.set_velocity(20, PERCENT)
    drivetrain.set_drive_velocity(75, PERCENT)

def onevent_controller_1buttonX_pressed_0():
    global myVariable
    motor_15.set_velocity(100, PERCENT)
    motor_15.spin(FORWARD)
    wait(1, SECONDS)
    motor_15.stop()
    motor_15.set_velocity(70, PERCENT)

def onevent_controller_1buttonR1_released_0():
    global myVariable
    motor_18.stop()

def onevent_controller_1buttonR1_pressed_0():
    global myVariable
    motor_18.spin(REVERSE)

def onevent_controller_1buttonR2_pressed_0():
    global myVariable
    motor_18.spin(FORWARD)

def onevent_controller_1buttonL2_pressed_0():
    global myVariable
    motor_15.spin(REVERSE)

def onevent_controller_1buttonL1_pressed_0():
    global myVariable
    motor_15.stop()

def onevent_controller_1buttonA_pressed_0():
    global myVariable
    motor_12.spin(REVERSE)

def onevent_controller_1buttonB_pressed_0():
    global myVariable
    motor_12.spin(FORWARD)

# create a function for handling the starting and stopping of all autonomous tasks
def vexcode_auton_function():
    # Start the autonomous control tasks
    auton_task_0 = Thread( onauton_autonomous_0 )
    # wait for the driver control period to end
    while( competition.is_autonomous() and competition.is_enabled() ):
        # wait 10 milliseconds before checking again
        wait( 10, MSEC )
    # Stop the autonomous control tasks
    auton_task_0.stop()

def vexcode_driver_function():
    # Start the driver control tasks
    driver_control_task_0 = Thread( ondriver_drivercontrol_0 )
    # wait for the driver control period to end
    while( competition.is_driver_control() and competition.is_enabled() ):
        # wait 10 milliseconds before checking again
        wait( 10, MSEC )
    # Stop the driver control tasks
    driver_control_task_0.stop()

# register the competition functions
competition = Competition( vexcode_driver_function, vexcode_auton_function )

# system event handlers
controller_1.buttonX.pressed(onevent_controller_1buttonX_pressed_0)
controller_1.buttonR1.released(onevent_controller_1buttonR1_released_0)
controller_1.buttonR1.pressed(onevent_controller_1buttonR1_pressed_0)
controller_1.buttonR2.pressed(onevent_controller_1buttonR2_pressed_0)
controller_1.buttonL2.pressed(onevent_controller_1buttonL2_pressed_0)
controller_1.buttonL1.pressed(onevent_controller_1buttonL1_pressed_0)
controller_1.buttonA.pressed(onevent_controller_1buttonA_pressed_0)
controller_1.buttonB.pressed(onevent_controller_1buttonB_pressed_0)
# add 15ms delay to make sure events are registered correctly.
wait(15, MSEC)
