/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lsikora25                                        */
/*    Created:      Wed Feb 09 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor15              motor         15              
// Drivetrain           drivetrain    6, 4, 5, 17     
// Motor18              motor         18              
// Motor12              motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----

//  28  --  Autonomous
//

#include "vex.h"

using namespace vex;

competition Competition;

float myVariable;

// "when autonomous" hat block
int onauton_autonomous_0() {
  Motor15.setVelocity(90.0, percent);
  Motor15.setVelocity(75.0, percent);
  Motor12.setVelocity(20.0, percent);
  Motor18.spin(reverse);
  wait(1.0, seconds);
  Drivetrain.driveFor(forward, 200.0, mm, true);
  Drivetrain.stop();
  Motor18.spin(forward);
  Motor15.spin(reverse);
  wait(4.0, seconds);
  Motor15.stop();
  Drivetrain.driveFor(reverse, 200.0, mm, true);
  Motor18.spinFor(reverse, 270.0, degrees, true);
  Motor18.stop();
  return 0;
}

// "when started" hat block
int whenStarted1() {
  Drivetrain.setTurnVelocity(50.0, percent);
  Motor15.setVelocity(100.0, percent);
  Motor18.setVelocity(50.0, percent);
  Motor12.setVelocity(20.0, percent);
  Drivetrain.setDriveVelocity(75.0, percent);
  return 0;
}

// "when driver control" hat block
int ondriver_drivercontrol_0() {
  Drivetrain.setTurnVelocity(50.0, percent);
  Motor15.setVelocity(100.0, percent);
  Motor18.setVelocity(50.0, percent);
  Motor12.setVelocity(20.0, percent);
  Drivetrain.setDriveVelocity(75.0, percent);
  return 0;
}

// "when Controller1 ButtonX pressed" hat block
void onevent_Controller1ButtonX_pressed_0() {
  Motor15.setVelocity(100.0, percent);
  Motor15.spin(forward);
  wait(1.0, seconds);
  Motor15.stop();
  Motor15.setVelocity(70.0, percent);
}

// "when Controller1 ButtonR1 released" hat block
void onevent_Controller1ButtonR1_released_0() {
  Motor18.stop();
}

// "when Controller1 ButtonR1 pressed" hat block
void onevent_Controller1ButtonR1_pressed_0() {
  Motor18.spin(reverse);
}

// "when Controller1 ButtonR2 pressed" hat block
void onevent_Controller1ButtonR2_pressed_0() {
  Motor18.spin(forward);
}

// "when Controller1 ButtonL2 pressed" hat block
void onevent_Controller1ButtonL2_pressed_0() {
  Motor15.spin(reverse);
}

// "when Controller1 ButtonL1 pressed" hat block
void onevent_Controller1ButtonL1_pressed_0() {
  Motor15.stop();
}

// "when Controller1 ButtonA pressed" hat block
void onevent_Controller1ButtonA_pressed_0() {
  Motor12.spin(reverse);
}

// "when Controller1 ButtonB pressed" hat block
void onevent_Controller1ButtonB_pressed_0() {
  Motor12.spin(forward);
}

// "when Controller1 Axis1 changed" hat block
/*
void onevent_Controller1Axis1Changed_0() {
  Drivetrain.drive(forward);
}
*/
void onevent_Controller1Axis2Changed_0() {
  Drivetrain.drive(reverse);
}


void VEXcode_driver_task() {
  // Start the driver control tasks....
  vex::task drive0(ondriver_drivercontrol_0);
  
  task rc_auto_loop_task_Controller1();
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
  return;
}

void VEXcode_auton_task() {
  // Start the auton control tasks....
  vex::task auto0(onauton_autonomous_0);
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  auto0.stop();
  return;
}
void drawSmileyAt(int x, int y){
  Brain.Screen.drawCircle(x, y, 40, yellow);
  Brain.Screen.drawCircle(x-20, y-10, 10, blue);
  Brain.Screen.drawCircle(x+20, y-10, 10, blue);
  Brain.Screen.drawRectangle(x-20, y+10, 40, 10, red);
}

int main() {
  vex::competition::bStopTasksBetweenModes = false;
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);
  
  drawSmileyAt(50, 50);
  drawSmileyAt(400, 50);
  drawSmileyAt(50, 200);
  drawSmileyAt(400, 200);
  task rc_auto_loop_task_Controller1();


  Controller1.Screen.print("Luke is the GOAT"); 
  // register event handlers
  Controller1.ButtonX.pressed(onevent_Controller1ButtonX_pressed_0);
  Controller1.ButtonR1.released(onevent_Controller1ButtonR1_released_0);
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonL2_pressed_0);
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonA.pressed(onevent_Controller1ButtonA_pressed_0);
  Controller1.ButtonB.pressed(onevent_Controller1ButtonB_pressed_0);
  //Controller1.Axis1.changed(onevent_Controller1Axis2Changed_0);

  wait(15, msec);
  whenStarted1();
}