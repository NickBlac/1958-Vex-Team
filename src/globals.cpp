#include "main.h"

using namespace pros;

Controller con (E_CONTROLLER_MASTER);

Motor outtake_right (20,false);
Motor outtake_left(18,false);

Motor intake_right (10,true);
Motor intake_left (13,false);

//Motor front_right (9,true);
//Motor front_left (1,false);

Motor back_right (1,true);
Motor back_left (2,false);

Motor rainbow1 (14,false);
Motor rainbow2 (15,false);