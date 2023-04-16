#ifndef OGC_FW_THERMAL_INSPECTION_TOOL_H
#define OGC_FW_THERMAL_INSPECTION_TOOL_H

#include <stdint.h>

/* =====================================================================================================================
 *                                                                         OGC.Engineering Layered Development Standards
 * =====================================================================================================================
 */

void hal_config( void ); /* ogc layered development standard - hardware configuration call */
void hal_init( void ); /* ogc layered development standard - hardware init call */

uint64_t hal_get_sys_tick( void ); /* ogc layered development standard - monotonic system tick */

/* =====================================================================================================================
 *                                                                                              General System Functions
 * =====================================================================================================================
 */
/*                                                                                                  Clocks - Watchdog */
/*                                                                                                      Clocks - RTCC */
/*                                                                                                    Clocks - System */

/* =====================================================================================================================
 *                                                                                                        User Interface
 * =====================================================================================================================
 */
/*                                                                          User Interface - RGB LED ( GPIO and PWM ) */
/*                                                                        User Interface - Encoder Phase A ( Button ) */
/*                                                                        User Interface - Encoder Phase B ( Button ) */
/*                                                                          User Interface - Encoder Click ( Button ) */
/*                                                                                      User Interface - Serial Comms */
/*                                                                                      User Interface - OLED Display */

/* =====================================================================================================================
 *                                                                                                               Sensors
 * =====================================================================================================================
 */
/*                                                                                               Sensors - RGB Camera */
/*                                                                                                Sensors - IR Camera */
/*                                                                                                    Sensors - LIDAR */


#endif /* OGC_FW_THERMAL_INSPECTION_TOOL_H */
