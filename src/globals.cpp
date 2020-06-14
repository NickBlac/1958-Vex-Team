#include "main.h"

using namespace pros;

Controller con (E_CONTROLLER_MASTER);

Motor pivot (20,false);
Motor lift(18,false);

Motor intake_right (10,true);
Motor intake_left (11,false);

Motor front_right (9,true);
Motor back_right (8,true);
Motor front_left (1,false);
Motor back_left (13,false);
