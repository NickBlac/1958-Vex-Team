
#ifndef SENSORS_H_
#define SENSORS_H_
#include "main.h"

static pros::ADIEncoder left_encoder ('A','B',false);
static pros::ADIEncoder right_encoder ('C','D',true);

static pros::ADIDigitalIn top_limit ('E');
static pros::ADIDigitalIn bot_limit ('D');


static pros::ADIGyro the_gyro ('H', 1);


#endif
