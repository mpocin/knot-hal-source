/*
 * Copyright (c) 2016, CESAR.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license. See the LICENSE file for details.
 *
 * Configuration file for KNOT THING
 */

#ifndef __HAL_CONFIG_H__
#define __HAL_CONFIG_H__

/*
 * User may modify the amount of data (sensors/actuators) to be connected
 * to THING
 * Default value = 5
 * Values allowed are: MIN = 1 and MAX = 5
 */
#define KNOT_THING_NUM_DATA             5

/*
 * User may modify the name of thing
 * Default value = "thingname"
 * Empty value is not allowed
 */
#define THING_NAME                      "thingname"


#endif /* __HAL_CONFIG_H__ */
