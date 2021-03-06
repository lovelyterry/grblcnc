/*
  grbl.h - main Grbl include file
  Part of Grbl

  Copyright (c) 2015-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Grbl versioning system
#define GRBL_VERSION       "1.1f"
#define GRBL_VERSION_BUILD "20180715"  //20170801


// Define standard libraries used by Grbl.
#include <stdbool.h>

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "misc.h"
#include "stm32f10x.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"

//#define NOEEPROMSUPPORT

// Define the Grbl system include files. NOTE: Do not alter organization.
#include "config.h"
#include "coolant_control.h"
#include "cpu_map.h"
#include "defaults.h"
#include "eeprom.h"
#include "gcode.h"
#include "jog.h"
#include "limits.h"
#include "motion_control.h"
#include "nuts_bolts.h"
#include "planner.h"
#include "print.h"
#include "probe.h"
#include "protocol.h"
#include "report.h"
#include "serial.h"
#include "settings.h"
#include "spindle_control.h"
#include "stepper.h"
#include "system.h"
#include "nuts_bolts.h"

// ---------------------------------------------------------------------------------------
// COMPILE-TIME ERROR CHECKING OF DEFINE VALUES:

#ifndef HOMING_CYCLE_0
#error "Required HOMING_CYCLE_0 not defined."
#endif

#if defined(USE_SPINDLE_DIR_AS_ENABLE_PIN) && !defined(VARIABLE_SPINDLE)
#error "USE_SPINDLE_DIR_AS_ENABLE_PIN may only be used with VARIABLE_SPINDLE enabled"
#endif


#if !defined(USE_SPINDLE_DIR_AS_ENABLE_PIN) && defined(SPINDLE_ENABLE_OFF_WITH_ZERO_SPEED)
#error "SPINDLE_ENABLE_OFF_WITH_ZERO_SPEED may only be used with USE_SPINDLE_DIR_AS_ENABLE_PIN enabled"
#endif

#if defined(USE_SPINDLE_DIR_AS_ENABLE_PIN)
#error "USE_SPINDLE_DIR_AS_ENABLE_PIN may only be used with AVRTARGET config"
#endif

#if defined(PARKING_ENABLE)
#if defined(HOMING_FORCE_SET_ORIGIN)
#error "HOMING_FORCE_SET_ORIGIN is not supported with PARKING_ENABLE at this time."
#endif
#endif

#if defined(ENABLE_PARKING_OVERRIDE_CONTROL)
#if !defined(PARKING_ENABLE)
#error "ENABLE_PARKING_OVERRIDE_CONTROL must be enabled with PARKING_ENABLE."
#endif
#endif

#if defined(SPINDLE_PWM_MIN_VALUE)
#if !(SPINDLE_PWM_MIN_VALUE > 0)
#error "SPINDLE_PWM_MIN_VALUE must be greater than zero."
#endif
#endif

#if (REPORT_WCO_REFRESH_BUSY_COUNT < REPORT_WCO_REFRESH_IDLE_COUNT)
#error "WCO busy refresh is less than idle refresh."
#endif
#if (REPORT_OVR_REFRESH_BUSY_COUNT < REPORT_OVR_REFRESH_IDLE_COUNT)
#error "Override busy refresh is less than idle refresh."
#endif
#if (REPORT_WCO_REFRESH_IDLE_COUNT < 2)
#error "WCO refresh must be greater than one."
#endif
#if (REPORT_OVR_REFRESH_IDLE_COUNT < 1)
#error "Override refresh must be greater than zero."
#endif

#if (defined(EXTRA_A_AXIS) && defined(EXTRA_AB_AXIS)) || (defined(EXTRA_A_AXIS) && defined(EXTRA_ABC_AXIS)) || (defined(EXTRA_AB_AXIS) && defined(EXTRA_ABC_AXIS))
#error "Use only one of EXTRA_A_AXIS, EXTRA_AB_AXIS, EXTRA_ABC_AXIS."
#endif
// ---------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------
// COMPILE-TIME ERROR CHECKING OF DEFINE VALUES:

// ---------------------------------------------------------------------------------------

