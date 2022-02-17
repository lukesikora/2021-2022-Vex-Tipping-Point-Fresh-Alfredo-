/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\lsikora25                                        */
/*    Created:      Thu Feb 10 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    4, 6, 5, 17     
// Motor18              motor         18              
// Motor15              motor         15              
// Motor14              motor         14              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
competition Competition;
float myVariable;

//**********************************************************************************************
// "when Controller1 ButtonX pressed" hat block
void onevent_Controller1ButtonX_pressed_0() {
  Motor15.setVelocity(100.0, percent);
  Motor15.spin(forward);
  wait(1.0, seconds);
  Motor15.stop();
  Motor15.setVelocity(70.0, percent);
}
// "when Controller1 ButtonA pressed" hat block
void onevent_Controller1ButtonA_pressed_0() {
  Motor14.setMaxTorque(100, percent); 
  Motor14.setVelocity(80, percent);
  Motor14.spin(forward);
}

// "when Controller1 ButtonA released" hat block
void onevent_Controller1ButtonA_released_0() {
  Motor14.stop();
}

// "when Controller1 ButtonB pressed" hat block
void onevent_Controller1ButtonB_pressed_0() { //   UP
  Motor14.setVelocity(80, percent);
  Motor14.setMaxTorque(100, percent); 
  Motor14.spinFor(reverse, 300.0, degrees, true);
}

// "when Controller1 ButtonB released" hat block
void onevent_Controller1ButtonB_released_0() {
  Motor14.stop();
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

//**********************************************************************************************
//SMILEYFACE
void drawSmileyAt(int x, int y){
  Brain.Screen.drawCircle(x, y, 40, yellow);
  Brain.Screen.drawCircle(x-20, y-10, 10, blue);
  Brain.Screen.drawCircle(x+20, y-10, 10, blue);
  Brain.Screen.drawRectangle(x-20, y+10, 40, 10, red);
}
//AUTONOMOUS
int onauton_autonomous_0() {
  Motor15.setVelocity(90.0, percent);
  Motor15.setVelocity(75.0, percent);
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
//AUTONOMOUS SETUP
void VEXcode_auton_task() {
  // Start the auton control tasks....
  vex::task auto0(onauton_autonomous_0);
  while(Competition.isAutonomous() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  auto0.stop();
  return;
}
//DRIVER CONTROLLED
int ondriver_drivercontrol_0() {
  Drivetrain.setTurnVelocity(50.0, percent); // TURN SPEED
  Motor15.setVelocity(100.0, percent);
  Motor18.setVelocity(50.0, percent);
  Drivetrain.setDriveVelocity(75.0, percent);
  return 0;
}
//DRIVER CONTROL SETUP
void VEXcode_driver_task() {
  // Start the driver control tasks....
  vex::task drive0(ondriver_drivercontrol_0);
  
  task rc_auto_loop_task_Controller1();
  while(Competition.isDriverControl() && Competition.isEnabled()) {this_thread::sleep_for(10);}
  drive0.stop();
  return;
}
//**********************************************************************************************
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vex::competition::bStopTasksBetweenModes = false;
  //Print words
  Controller1.Screen.print("Pizzahut"); 
  //draw face
  drawSmileyAt(50, 50);
  drawSmileyAt(400, 50);
  drawSmileyAt(50, 200);
  drawSmileyAt(400, 200);
  //setup
  Competition.autonomous(VEXcode_auton_task);
  Competition.drivercontrol(VEXcode_driver_task);
  vexcodeInit();
  // register event handlers
  Controller1.ButtonX.pressed(onevent_Controller1ButtonX_pressed_0);
  Controller1.ButtonR1.released(onevent_Controller1ButtonR1_released_0);
  Controller1.ButtonR1.pressed(onevent_Controller1ButtonR1_pressed_0);
  Controller1.ButtonR2.pressed(onevent_Controller1ButtonR2_pressed_0);
  Controller1.ButtonL2.pressed(onevent_Controller1ButtonL2_pressed_0);
  Controller1.ButtonL1.pressed(onevent_Controller1ButtonL1_pressed_0);
  Controller1.ButtonA.pressed(onevent_Controller1ButtonA_pressed_0);
  Controller1.ButtonB.pressed(onevent_Controller1ButtonB_pressed_0);
  Controller1.ButtonA.released(onevent_Controller1ButtonA_released_0);
  Controller1.ButtonB.released(onevent_Controller1ButtonB_released_0);
}
//**********************************************************************************************