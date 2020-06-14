#include "main.h"

using namespace okapi;

const int Apivot = 1;
const int Aintake_right = 8;
const int Aintake_left = 4;
const int Afront_right = 9;
const int Aback_right = 3;
const int Afront_left = 10;
const int Aback_left = 2;
//Chassis Width is the outer distance between wheels
const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 13.25_in;

auto chassis = ChassisControllerFactory::create(
    {-1, -13}, {9, 8},
    AbstractMotor::gearset::green,
    {WHEEL_DIAMETER, CHASSIS_WIDTH}
    );


void startSequence(void) {

    chassis.setMaxVelocity(50);
    front_left.set_brake_mode(MOTOR_BRAKE_HOLD);
    back_left.set_brake_mode(MOTOR_BRAKE_HOLD);
    front_right.set_brake_mode(MOTOR_BRAKE_HOLD);
    back_right.set_brake_mode(MOTOR_BRAKE_HOLD);
    pivot.set_brake_mode(MOTOR_BRAKE_HOLD);
}
void deploy(void) {
    chassis.moveDistance(1_in);
    chassis.turnAngle(90_deg);
    chassis.turnAngle(90_deg);
    chassis.turnAngle(90_deg);
    chassis.turnAngle(90_deg);
}

void front_red_1(void){
    startSequence();
    deploy();
    /*intake_left.move_velocity(200);
    intake_right.move_velocity(200);
    chassis.moveDistance(17_in);
    chassis.turnAngle(90_deg);
    chassis.moveDistance(12_in);
    pros::delay(2000);
    chassis.moveDistance(-15_in);
    chassis.turnAngle(-180_deg);
    chassis.moveDistance(25_in);
    chassis.turnAngle(-45_deg);
    chassis.moveDistance(1_ft);
    pivot.move_velocity(100);
     pros::delay(2000);
    chassis.moveDistance(-1.5_ft);
     pros::delay(1000);
    pivot.move_velocity(-100);
     pros::delay(3000);
    pivot.move_velocity(0);
    chassis.turnAngle(-45_deg);
    chassis.turnAngle(-180_deg);
    chassis.moveDistance(-10_in);
    intake_right.move_velocity(0);
    intake_left.move_velocity(0);
    */
}


void back_blue_1(void){
    startSequence();

    intake_left.move_velocity(200);
    intake_right.move_velocity(200);
    chassis.moveDistance(40_in);
    chassis.moveDistance(-25_in);
    chassis.turnAngle(-120_deg);
    chassis.moveDistance(17_in);
    pivot.move_velocity(100);
     pros::delay(2000);
    chassis.moveDistance(-10_in);
     pros::delay(1000);
    pivot.move_velocity(-100);
     pros::delay(3000);
    pivot.move_velocity(0);
    chassis.turnAngle(-45_deg);
    chassis.turnAngle(-180_deg);
    chassis.moveDistance(10_in);
    intake_right.move_velocity(0);
    intake_left.move_velocity(0);

}

void front_blue_1(void){
    startSequence();

    intake_left.move_velocity(200);
    intake_right.move_velocity(200);
    chassis.moveDistance(17_in);
    chassis.turnAngle(-90_deg);
    chassis.moveDistance(12_in);
    pros::delay(2000);
    chassis.moveDistance(-15_in);
    chassis.turnAngle(180_deg);
    chassis.moveDistance(30_in);
    chassis.turnAngle(45_deg);
    intake_right.move_velocity(0);
    intake_left.move_velocity(0);

}

void back_red_1(void){
    startSequence();

    intake_left.move_velocity(200);
    intake_right.move_velocity(200);
    chassis.moveDistance(40_in);
    chassis.moveDistance(-25_in);
    chassis.turnAngle(120_deg);
    chassis.moveDistance(17_in);
    pivot.move_velocity(100);
     pros::delay(2000);
    chassis.moveDistance(-10_in);
     pros::delay(1000);
    pivot.move_velocity(-100);
     pros::delay(3000);
    pivot.move_velocity(0);
    chassis.turnAngle(45_deg);
    chassis.turnAngle(180_deg);
    chassis.moveDistance(10_in);
    intake_right.move_velocity(0);
    intake_left.move_velocity(0);

  }

  void skills(void) {

       int start_time = pros::millis();
       while ((pros::millis() - start_time) < 1000) {
            front_left.move_velocity(-60);
            back_left.move_velocity(-60);
            front_right.move_velocity(-60);
            back_right.move_velocity(-60);
       }

       while ((pros::millis() - start_time) < 4000) {
            front_left.move_velocity(60);
            back_left.move_velocity(60);
            front_right.move_velocity(60);
            back_right.move_velocity(60);
       }

        front_left.move_velocity(0);
        back_left.move_velocity(0);
        front_right.move_velocity(0);
        back_right.move_velocity(0);


  }
