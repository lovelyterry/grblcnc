/*
  defaults.h - defaults settings configuration file
  Part of Grbl

  Copyright (c) 2012-2016 Sungeun K. Jeon for Gnea Research LLC

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

/* The defaults.h file serves as a central default settings selector for different machine
   types, from DIY CNC mills to CNC conversions of off-the-shelf machines. The settings
   files listed here are supplied by users, so your results may vary. However, this should
   give you a good starting point as you get to know your machine and tweak the settings for
   your nefarious needs.
   NOTE: Ensure one and only one of these DEFAULTS_XXX values is defined in config.h */

#pragma once

#include "config.h"

#ifdef DEFAULTS_GENERIC
#define DEFAULT_X_STEPS_PER_MM 400.0f  // X axis step per mm
#define DEFAULT_Y_STEPS_PER_MM 400.0f  // Y axis step per mm
#define DEFAULT_Z_STEPS_PER_MM 400.0f  // Z axis step per mm
#if defined(EXTRA_A_AXIS) || defined(EXTRA_AB_AXIS) || defined(EXTRA_ABC_AXIS)
#define DEFAULT_A_STEPS_PER_MM 400.0f  // A axis step per mm
#endif
#if defined(EXTRA_AB_AXIS) || defined(EXTRA_ABC_AXIS)
#define DEFAULT_B_STEPS_PER_MM 400.0f  // B axis step per mm
#endif
#if defined(EXTRA_ABC_AXIS)
#define DEFAULT_C_STEPS_PER_MM 400.0f  // C axis step per mm
#endif
#define DEFAULT_X_MAX_RATE 3600.0f  // X axis mm/min
#define DEFAULT_Y_MAX_RATE 3600.0f  // Y axis mm/min
#define DEFAULT_Z_MAX_RATE 3600.0f  // Z axis mm/min
#if defined(EXTRA_A_AXIS) || defined(EXTRA_AB_AXIS) || defined(EXTRA_ABC_AXIS)
#define DEFAULT_A_MAX_RATE 3600.0f  // A axis mm/min
#endif
#if defined(EXTRA_AB_AXIS) || defined(EXTRA_ABC_AXIS)
#define DEFAULT_B_MAX_RATE 3600.0f  // B axis mm/min
#endif
#if defined(EXTRA_ABC_AXIS)
#define DEFAULT_C_MAX_RATE 3600.0f  // C axis mm/min
#endif
#define DEFAULT_X_ACCELERATION (100.0f * 60 * 60)  // X axis 10*60*60 mm/min^2 = 10 mm/sec^2
#define DEFAULT_Y_ACCELERATION (100.0f * 60 * 60)  // Y axis 10*60*60 mm/min^2 = 10 mm/sec^2
#define DEFAULT_Z_ACCELERATION (100.0f * 60 * 60)  // Z axis 10*60*60 mm/min^2 = 10 mm/sec^2
#if defined(EXTRA_A_AXIS) || defined(EXTRA_AB_AXIS) || defined(EXTRA_ABC_AXIS)
#define DEFAULT_A_ACCELERATION (100.0f * 60 * 60)  // A axis 10*60*60 mm/min^2 = 10 mm/sec^2
#endif
#if defined(EXTRA_AB_AXIS) || defined(EXTRA_ABC_AXIS)
#define DEFAULT_B_ACCELERATION (100.0f * 60 * 60)  // B axis 10*60*60 mm/min^2 = 10 mm/sec^2
#endif
#if defined(EXTRA_ABC_AXIS)
#define DEFAULT_C_ACCELERATION (100.0f * 60 * 60)  // C axis 10*60*60 mm/min^2 = 10 mm/sec^2
#endif
#define DEFAULT_X_MAX_TRAVEL 320.0f  // X axis mm
#define DEFAULT_Y_MAX_TRAVEL 320.0f  // Y axis mm
#define DEFAULT_Z_MAX_TRAVEL 320.0f  // Z axis mm
#if defined(EXTRA_A_AXIS) || defined(EXTRA_AB_AXIS) || defined(EXTRA_ABC_AXIS)
#define DEFAULT_A_MAX_TRAVEL 320.0f  // A axis mm
#endif
#if defined(EXTRA_AB_AXIS) || defined(EXTRA_ABC_AXIS)
#define DEFAULT_B_MAX_TRAVEL 320.0f  // B axis mm
#endif
#if defined(EXTRA_ABC_AXIS)
#define DEFAULT_C_MAX_TRAVEL 320.0f  // C axis mm
#endif
#define DEFAULT_SPINDLE_RPM_MAX         1000.0f  // rpm
#define DEFAULT_SPINDLE_RPM_MIN         0.0f     // rpm
#define DEFAULT_STEP_PULSE_MICROSECONDS 6        // usec
#define DEFAULT_STEPPING_INVERT_MASK    0x0
#define DEFAULT_DIRECTION_INVERT_MASK   0x1F
#define DEFAULT_STEPPER_IDLE_LOCK_TIME  0       // msec (0-254, 255 keeps steppers enabled)
#define DEFAULT_STATUS_REPORT_MASK      0       // 1 - MPos enabled, 0 - WPos enabled
#define DEFAULT_JUNCTION_DEVIATION      0.01f   // mm
#define DEFAULT_ARC_TOLERANCE           0.002f  // mm
#define DEFAULT_REPORT_INCHES           0
#define DEFAULT_INVERT_ST_ENABLE        1
#define DEFAULT_INVERT_LIMIT_PINS       1
#define DEFAULT_SOFT_LIMIT_ENABLE       0
#define DEFAULT_HARD_LIMIT_ENABLE       0
#define DEFAULT_INVERT_PROBE_PIN        0
#define DEFAULT_LASER_MODE              0
#define DEFAULT_HOMING_ENABLE           0
#define DEFAULT_HOMING_DIR_MASK         0x1f
#define DEFAULT_HOMING_FEED_RATE        10.0f   // mm/min
#define DEFAULT_HOMING_SEEK_RATE        100.0f  // mm/min
#define DEFAULT_HOMING_DEBOUNCE_DELAY   250     // msec (0-65k)
#define DEFAULT_HOMING_PULLOFF          1.5f    // mm
#endif
