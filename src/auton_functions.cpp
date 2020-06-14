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


