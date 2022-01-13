myVariable = 0

def when_started1():
    global myVariable
    drivetrain.set_drive_velocity(100, PERCENT)
    drivetrain.drive_for(FORWARD, 200, INCHES, wait=True)
    drivetrain.drive_for(REVERSE, 200, INCHES, wait=True)
    motor_15.set_velocity(100, PERCENT)
    drivetrain.drive_for(FORWARD, 1680, MM, wait=True)
    motor_15.spin_to_position(90, DEGREES, wait=True)
    drivetrain.drive_for(FORWARD, 2240, MM, wait=True)
    # pick-up function
    drivetrain.drive_for(REVERSE, 1120, MM, wait=True)
    motor_15.spin_to_position(-90, DEGREES, wait=True)
    drivetrain.drive_for(FORWARD, 1963, MM, wait=True)

when_started1()
