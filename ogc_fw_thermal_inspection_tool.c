#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"

#include "ogc_fw_thermal_inspection_tool.h"
#include "hw_description.h"

//*****************************************************************************
//
// Monotonic clock that contains the current system tick value.
//
//*****************************************************************************
uint64_t sys_tick;

//*****************************************************************************
//
// Flags that contain the current value of the interrupt indicator.
//
//*****************************************************************************
uint32_t g_ui32Flags;

//*****************************************************************************
//
// The interrupt handler for the first timer interrupt.
//
//*****************************************************************************
void
Timer0IntHandler(void)
{
//    //
//    // Clear the timer interrupt.
//    //
//    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
//
//    //
//    // Toggle the flag for the first timer.
//    //
//    HWREGBITW(&g_ui32Flags, 0) ^= 1;
//
//    //
//    // Use the flags to Toggle the LED for this timer
//    //
//    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, g_ui32Flags << 1);

}

//*****************************************************************************
//
// The interrupt handler for the second timer interrupt.
//
//*****************************************************************************
void
Timer1IntHandler(void)
{
//    //
//    // Clear the timer interrupt.
//    //
//    TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
//
//    //
//    // Toggle the flag for the second timer.
//    //
//    HWREGBITW(&g_ui32Flags, 1) ^= 1;
//
//    //
//    // Use the flags to Toggle the LED for this timer
//    //
//    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, g_ui32Flags << 1);

}

void hal_config( void )
{
    watchdog_stop();
    watchdog_init();
    watchdog_start();

    sys_tick = 0U;

    system_clock_config();

    ui_status_indicator_init_as_gpio();

}

void hal_init( void )
{

}

uint64_t hal_get_sys_tick( void )
{
    return( sys_tick );
}

/* =====================================================================================================================
 *                                                                                              General System Functions
 * =====================================================================================================================
 */
/*                                                                                                  Clocks - Watchdog */
void watchdog_init( void ) /* configure watchdog clock */
{
    
}

void watchdog_stop( void ) /* stop watchdog clock */
{
    
}

void watchdog_start( void ) /* start watchdog clock */
{
    
}

void watchdog_reset( void ) /* reset watchdog clock */
{
    
}

/*                                                                                                      Clocks - RTCC */
/* configure rtcc clock */
/* start rtcc clock */
/* stop rtcc clock */
/* set rtcc clock */
/* get rtcc clock */

/*                                                                                                    Clocks - System */
void system_clock_config( void ) /* configure system clock */
{
        SysCtlClockSet( SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ );
}

/* enter low power mode */

/* init I2C module */

/* init SPI module */

/* =====================================================================================================================
 *                                                                                                        User Interface
 * =====================================================================================================================
 */
/*                                                                          User Interface - RGB LED ( GPIO and PWM ) */
void ui_status_indicator_init_as_gpio( void ) /* init rgb for gpio operation */
{
    SysCtlPeripheralEnable( HW_RGB_RED_PORT | HW_RGB_GREEN_PORT | HW_RGB_BLUE_PORT );
    while( false == SysCtlPeripheralReady( HW_RGB_RED_PORT | HW_RGB_GREEN_PORT | HW_RGB_BLUE_PORT ) );
    GPIOPinTypeGPIOOutput( HW_RGB_RED_PORT, HW_RGB_RED_PIN );
    ui_status_indicator_red_set_gpio( false );
    GPIOPinTypeGPIOOutput( HW_RGB_GREEN_PORT, HW_RGB_GREEN_PIN );
    ui_status_indicator_green_set_gpio( false );
    GPIOPinTypeGPIOOutput( HW_RGB_BLUE_PORT, HW_RGB_BLUE_PIN );
    ui_status_indicator_blue_set_gpio( false );
}

void ui_status_indicator_red_set_gpio( bool state ) /* set red state */
{
    if ( true == state )
    {
        GPIOPinWrite( HW_RGB_RED_PORT, HW_RGB_RED_PIN, HW_RGB_RED_PIN );
    }
    else
    {
        GPIOPinWrite( HW_RGB_RED_PORT, HW_RGB_RED_PIN, 0x0 );
    }
}

void ui_status_indicator_green_set_gpio( bool state ) /* set green state */
{
    if ( true == state )
    {
        GPIOPinWrite( HW_RGB_GREEN_PORT, HW_RGB_GREEN_PIN, HW_RGB_GREEN_PIN );
    }
    else
    {
        GPIOPinWrite( HW_RGB_GREEN_PORT, HW_RGB_GREEN_PIN, 0x0 );
    }
}

void ui_status_indicator_blue_set_gpio( bool state ) /* set blue state */
{
    if ( true == state )
    {
        GPIOPinWrite( HW_RGB_BLUE_PORT, HW_RGB_BLUE_PIN, HW_RGB_BLUE_PIN );
    }
    else
    {
        GPIOPinWrite( HW_RGB_BLUE_PORT, HW_RGB_BLUE_PIN, 0x0 );
    }
}

void ui_status_indicator_init_as_pwm( void ) /* init rgb for pwm operation */
{
    
}

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
