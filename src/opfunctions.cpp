
#include <math.h>
#include "main.h"

#define GROWTH 1.048489898
#define SHIFT 15

//lv_obj_t *debug_label = lv_label_create(lv_scr_act(),NULL);
//lv_obj_align(debug_label,NULL,LV_ALIGN_IN_TOP_RIGHT,0,0);
//lv_obj_align(debug_label, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 5, 0);


void driveOP() {
    int leftPower = (int) (con.get_analog(ANALOG_LEFT_Y) * 170.0/127);
    int rightPower = (int) (con.get_analog(ANALOG_RIGHT_Y)* 170.0/127);

    /*
    if(leftPower > 0){
      leftPower = pow(GROWTH,leftPower - SHIFT) - 1;
    }
    else if(leftPower < 0) {
      leftPower = -pow(GROWTH,abs(leftPower) - SHIFT) - 1;
    }

    if(rightPower > 0) {
      rightPower = pow(GROWTH,rightPower - SHIFT) - 1;
    }
    if(rightPower < 0) {
      rightPower = -pow(GROWTH,abs(rightPower) - SHIFT) - 1;
    }
    */


    if(abs(rightPower) < 30) {
      rightPower = 0;
    }
    else if(rightPower > 0) {
      rightPower -= 30;
    }
    else if(rightPower < 0) {
      rightPower += 30;
    }

    if(abs(leftPower) < 30) {
      leftPower = 0;
    }
    else if(leftPower > 0){
      leftPower -= 30;
    }
    else if(leftPower < 0){
      leftPower += 30;
    }


    //drive(leftPower, rightPower);
    front_left.move_velocity(leftPower);
    back_left.move_velocity(leftPower);
    front_right.move_velocity(rightPower);
    back_right.move_velocity(rightPower);
}


enum Direction {forward, reverse, stopped};
enum Direction intakeDirection = stopped;
int click_time = 0;

void intakeOP() {
  //std::to_string(click_time).c_str()
  //lv_label_set_text(debug_label, std::to_string(pros::millis() - click_time).c_str());


  if(con.get_digital(DIGITAL_R1)){
    intakeDirection = reverse;
  }
  else if(con.get_digital(DIGITAL_L1)){
    if(intakeDirection != forward  && pros::millis() - click_time > 300) {
      intakeDirection = forward;
    }
    else if(intakeDirection == forward && pros::millis() - click_time > 300) {
      intakeDirection = stopped;
    }
    if(pros::millis() - click_time > 300) {
      click_time = pros::millis();
    }
  }
  else if(intakeDirection == reverse && !con.get_digital(DIGITAL_R1)){
    intakeDirection = stopped;
  }


  /*
  if(con.get_digital(DIGITAL_R1)){
    if(intakeDirection != reverse && pros::millis() - click_time > 300) {
      intakeDirection = reverse;
    }
    else if(intakeDirection == reverse && pros::millis() - click_time > 300){
      intakeDirection = stopped;
    }
    if(pros::millis() - click_time > 300) {
      click_time = pros::millis();
    }
  }
  */

  int intakePower = 0;
  switch(intakeDirection) {
    case forward:
      intakePower = 180;
      break;
    case reverse:
      intakePower = -50;
      break;
    case stopped:
      intakePower = 0;
      break;
  }

  intake_left.move_velocity(intakePower);
  intake_right.move_velocity(intakePower);

}


void pivotOP() {
  if(con.get_digital(DIGITAL_R2) && con.get_digital(DIGITAL_L2)) {
      pivot.move_velocity(0);
      pivot.set_brake_mode(MOTOR_BRAKE_HOLD);
  }
  else if(con.get_digital(DIGITAL_R2))
      pivot.move_velocity(90);
  else if(con.get_digital(DIGITAL_L2))
      pivot.move_velocity(-90);
  else {
      pivot.move_velocity(0);
      pivot.set_brake_mode(MOTOR_BRAKE_HOLD);
  }
}


void liftOP() {
  if(con.get_digital(DIGITAL_X) && con.get_digital(DIGITAL_Y)) {
      lift.move_velocity(0);
      lift.set_brake_mode(MOTOR_BRAKE_HOLD);
  }
  else if(con.get_digital(DIGITAL_X))
      lift.move_velocity(120);
  else if(con.get_digital(DIGITAL_Y))
      lift.move_velocity(-70);
  else {
      lift.move_velocity(0);
      lift.set_brake_mode(MOTOR_BRAKE_HOLD);
  }
}

void xdriveOP(){

	int mthrottle = con.get_analog(ANALOG_RIGHT_Y)
	int mstrafe = -1 * con.get_analog(ANALOG_RIGHT_X)
	int mturn = -1 * con.get_analog(ANALOG_LEFT_X)
		
 
	front_right.move_voltage(-120 * (mthrottle + mstrafe + mturn));
	back_right.move_voltage(-120 * (mthrottle - mstrafe + mturn));
	front_left.move_voltage(120 * (mthrottle - mstrafe - mtrun));
	back_left.move_voltage(120 * (mthrottle + mstrafe - mturn));

}



/*
bool previous_intake_status = false, previous_flywheel_status = false;
bool isNewButtonPress (pros::controller_digital_e_t button) {
    bool current_button_status = con.get_digital(button);

    switch(button){

        case DIGITAL_B:
            if(previous_flywheel_status == false &&  current_button_status == true){
                previous_flywheel_status = current_button_status;
                return true;
            }
            previous_flywheel_status = current_button_status;
            break;

        case DIGITAL_A:
            if(previous_intake_status == false && current_button_status == true){
                previous_intake_status = current_button_status;
                return true;
            }
            previous_intake_status = current_button_status;
            break;
    }

    return false;
}

*/


/*
okapi::ControllerButton intakeForward(okapi::ControllerDigital::R1, false);
okapi::ControllerButton intakeReverse(okapi::ControllerDigital::L1, false);
void intakeOP() {

  lv_label_set_text(debug_label, std::to_string(intakeDirection).c_str());

  if(intakeForward.changedToPressed()){
    if(intakeDirection != forward) {
      intakeDirection = forward;
    }
    else {
      intakeDirection = stopped;
    }
  }
  if(intakeReverse.changedToPressed()){
    if(intakeDirection != reverse) {

      intakeDirection = reverse;
    }
    else {
      intakeDirection = stopped;
    }
  }


  int intakePower = 0;
  switch(intakeDirection) {
    case forward:
      intakePower = 200;
      break;
    case reverse:
      intakePower = -200;
      break;
    case stopped:
      intakePower = 0;
      break;
  }


  intake_left.move_velocity(intakePower);
  intake_right.move_velocity(intakePower);
}
*/

/*
void flipperOP() {


    if(con.get_digital(DIGITAL_L1)) {
        flipper.move_velocity(200);
    }
    else if(con.get_digital(DIGITAL_X) && con.get_digital(DIGITAL_Y)) {
        flipper.move_velocity(0);
        flipper.set_brake_mode(MOTOR_BRAKE_HOLD);
    }
    else if(con.get_digital(DIGITAL_X))
        flipper.move_velocity(80);
    else if(con.get_digital(DIGITAL_Y))
        flipper.move_velocity(-120);
    else {
        flipper.move_velocity(0);
        flipper.set_brake_mode(MOTOR_BRAKE_HOLD);
    }

}

*/

/*
void flywheelOP() {
    con.clear();

    if(isNewButtonPress(DIGITAL_B)){
        con.print(1,1,"true");
        if(flywheel.is_stopped())
            flywheel.move_velocity(200);
        else {
            flywheel.move_velocity(0);
            flywheel.set_brake_mode(MOTOR_BRAKE_COAST);
        }

    }
    else
        con.print(1,1,"false");

}*/
