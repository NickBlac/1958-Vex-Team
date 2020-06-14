
#include "main.h"


void drive(int leftVelocity, int rightVelocity) {
   
    if(abs(leftVelocity) < 10) 
        leftVelocity = 0;
    if(abs(rightVelocity) < 10)
        rightVelocity = 0;


    front_left.move_velocity(leftVelocity);
    back_left.move_velocity(leftVelocity);
    front_right.move_velocity(rightVelocity);
    back_right.move_velocity(rightVelocity);
}