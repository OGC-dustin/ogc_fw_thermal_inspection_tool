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
void watchdog_init( void ); /* configure watchdog clock */
void watchdog_stop( void ); /* stop watchdog clock */
void watchdog_start( void ); /* start watchdog clock */
void watchdog_reset( void ); /* reset watchdog clock */

/*                                                                                                      Clocks - RTCC */
/* configure rtcc clock */
/* start rtcc clock */
/* stop rtcc clock */
/* set rtcc clock */
/* get rtcc clock */

/*                                                                                                    Clocks - System */
/* configure system clock */
/* enter low power mode */

/* init I2C module */

/* init SPI module */

/* =====================================================================================================================
 *                                                                                                        User Interface
 * =====================================================================================================================
 */
/*                                                                          User Interface - RGB LED ( GPIO and PWM ) */
void ui_status_indicator_init_as_gpio( void ); /* init rgb for gpio operation */
void ui_status_indicator_red_set_gpio( bool state ); /* set red state */
void ui_status_indicator_green_set_gpio( bool state ); /* set green state */
void ui_status_indicator_blue_set_gpio( bool state ); /* set blue state */

/* init rgb for pwm operation */
/* set red pwm */
/* set green pwm */
/* set blue pwm */

/*                                                                        User Interface - Encoder Phase A ( Button ) */
/* init phase a as input with interrupt */
/* get phase a current state */

/*                                                                        User Interface - Encoder Phase B ( Button ) */
/* init phase b as input with interrupt */
/* get phase b current state */

/*                                                                          User Interface - Encoder Click ( Button ) */
/* init click as input with interrupt */
/* get click current state */

/*                                                                                      User Interface - Serial Comms */
/* init serial uart to give baud rate, etc. */
/* get char */
/* get string
/* put char */
/* put string */

/*                                                                                      User Interface - OLED Display */
/* init oled select pin */
/* set oled select pin */
/* init oled data type pin */
/* set oled data type pin */
/* init oled reset pin */
/* set oled reset pin */
/* send command to oled */
/* send data to oled */

/*                                                                                           User Interface - SD Card */
/* init sd card select pin */
/* get sd card select pin */
/* set sd card select pin */
/* init sd card detect pin */
/* get sd card detect state */

/* =====================================================================================================================
 *                                                                                                               Sensors
 * =====================================================================================================================
 */
/*                                                                                               Sensors - RGB Camera */
/* init camera color pin data port */
/* get camera color state data port */
/* set camera color state data port */
/* init camera color pin vsync */
/* get camera color state vsync */
/* set camera color state vsync */
/* init camera color pin href */
/* get camera color state href */
/* set camera color state href */
/* init camera color pin pclk */
/* get camera color state pclk */
/* set camera color state pclk */
/* init camera color pin xclk */
/* get camera color state xclk */
/* set camera color state xclk */
/* init camera color pin powerdown */
/* get camera color state powerdown */
/* set camera color state powerdown */
/* init camera color pin reset */
/* get camera color state reset */
/* set camera color state reset */
/* i2c/spi camera color send command */

/*                                                                                                Sensors - IR Camera */
/* i2c camera ir send command */

/*                                                                                                    Sensors - LIDAR */
/* init lidar mode pin */
/* get lidar mode state */
/* set lidar mode state */
/* init lidar enable pin */
/* get lidar enable state */
/* set lidar enable state */
/* i2c lidar send command */

#endif /* OGC_FW_THERMAL_INSPECTION_TOOL_H */
