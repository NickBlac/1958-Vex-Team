/*#include "main.h"
#include "pros/motors.h"

// Inches
#define WHEEL_DIAMETER 2.75 

int averageMotorPosition(void) {
    return (int) (front_left.get_position() + back_left.get_position()
            + front_right.get_position() + back_right.get_position()) / 4.0;

}

void powerMotorsStraight(int power) {
    front_left.move_velocity(power);
    back_left.move_velocity(power);
    front_right.move_velocity(power);
    back_right.move_velocity(power);
}

void driveStraight(int distance) {
    // Distance should be a literal in inches 
    front_left.set_encoder_units(MOTOR_ENCODER_DEGREES);
    back_left.set_encoder_units(MOTOR_ENCODER_DEGREES);
    front_right.set_encoder_units(MOTOR_ENCODER_DEGREES);
    back_right.set_encoder_units(MOTOR_ENCODER_DEGREES);
    
    int degrees = (360 * distance) / (WHEEL_DIAMETER * PI);

    // Define Values
    int error;
    int integral = 0;
    int derivative;

    int kp = 0.5, ki = 0.5, kd = 0.5;

    // Reset position of motors to current position tare_position
    front_left.set_zero_position(front_left.get_position());
    back_left.set_zero_position(back_left.get_position());
    front_right.set_zero_position(front_right.get_position());
    back_right.set_zero_position(back_right.get_position());


    int errorCount = 0;
    int power;
    int prevError = 0;
    while(errorCount) {

        // P
        error = abs(degrees - averageMotorPosition());
        
        // I
        if(error <= 0 || error > 200) {
            integral = 0;
        }
        else {
            integral += error;
        }

        //D
        derivative = error - prevError;
        prevError = error;

        // Power
        if(distance > 0) {
            power = error * kp + integral * ki + derivative * kd;
        }
        else {
            power = -(error * kp + integral * ki + derivative * kd);
        }

        
        // End Loop
        if(error < 15) {
            errorCount++;
        }
        else {
            errorCount = 0;
        }

        powerMotorsStraight(power);
        pros::delay(20);
    }

    powerMotorsStraight(0);
}

void turnRobot(int degrees) {
    // Distance should be a literal in inches 
    front_left.set_encoder_units(MOTOR_ENCODER_DEGREES);
    back_left.set_encoder_units(MOTOR_ENCODER_DEGREES);
    front_right.set_encoder_units(MOTOR_ENCODER_DEGREES);
    back_right.set_encoder_units(MOTOR_ENCODER_DEGREES);
    
    degrees = (360 * degrees) / (WHEEL_DIAMETER * PI);

    // Define Values
    int error;
    int integral = 0;
    int derivative;

    int kp = 0.5, ki = 0.5, kd = 0.5;

    // Reset position of motors to current position tare_position
    front_left.set_zero_position(front_left.get_position());
    back_left.set_zero_position(back_left.get_position());
    front_right.set_zero_position(front_right.get_position());
    back_right.set_zero_position(back_right.get_position());


    int errorCount = 0;
    int power;
    int prevError = 0;
    while(errorCount) {

        // P
        error = abs(degrees 
        - abs(front_left.get_position() + back_left.get_position() 
        - front_right.get_position() - back_right.get_position() )/ 4) ;
        
        // I
        if(error <= 0 || error > 200) {
            integral = 0;
        }
        else {
            integral += error;
        }

        //D
        derivative = error - prevError;
        prevError = error;

        // Power
        if(degrees > 0) {
            power = error * kp + integral * ki + derivative * kd;
        }
        else {
            power = -(error * kp + integral * ki + derivative * kd);
        }

        
        // End Loop
        if(error < 15) {
            errorCount++;
        }
        else {
            errorCount = 0;
        }

        front_left.move_velocity(-power);
        back_left.move_velocity(-power);
        front_right.move_velocity(power);
        back_right.move_velocity(power);
        pros::delay(20);
    }

    powerMotorsStraight(0);
}



void liftPID(int distance) {
    // Distance should be a literal in inches 
    pivot.set_encoder_units(MOTOR_ENCODER_DEGREES);
    int degrees = (360 * distance) / (WHEEL_DIAMETER * PI);

    // Define Values
    int error;
    int integral = 0;
    int derivative;

    int kp = 0.5, ki = 0.5, kd = 0.5;

    // Reset position of motors to current position tare_position
    pivot.tare_position();


    int errorCount = 0;
    int power;
    int prevError = 0;
    while(errorCount) {

        // P
        error = abs(degrees - averageMotorPosition());
        
        // I
        if(error <= 0 || error > 200) {
            integral = 0;
        }
        else {
            integral += error;
        }

        //D
        derivative = error - prevError;
        prevError = error;

        // Power
        if(distance > 0) {
            power = error * kp + integral * ki + derivative * kd;
        }
        else {
            power = -(error * kp + integral * ki + derivative * kd);
        }

        
        // End Loop
        if(error < 15) {
            errorCount++;
        }
        else {
            errorCount = 0;
        }

        pivot.move_velocity(power);
        pros::delay(20);
    }

    pivot.move_velocity(0);
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
*/

