/**
 * phoenix_globals.h
 **/

#pragma once

#include <Arduino.h>
#include "phoenix_joints.h"
#include "phoenix_drive.h"
#include "phoenix_line.h"
#include "phoenix_line_internal.h"
#include "bno055.h"
#include "phoenix_imu.h"

extern PhoenixJoint joints[NUM_JOINTS];
extern PhoenixDrive drive;
extern PhoenixLineSensor line_sensors[NUM_LINE_SENSORS];
extern PhoenixLineHandler line_handler;
extern BNO055 dev_bno055;
extern PhoenixImu imu;

