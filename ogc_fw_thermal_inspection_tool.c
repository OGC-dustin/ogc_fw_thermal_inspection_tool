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
    sys_tick = 0U;

    //
    // Set the clocking to run directly from the crystal.
    //
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);


    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    //
    // Enable the GPIO pins for the LED_RED.
    //
    GPIOPinTypeGPIOOutput( HW_RGB_RED_PORT, HW_RGB_RED_PIN );

    //
    // Enable the GPIO pins for the LED_BLUE.
    //
    GPIOPinTypeGPIOOutput( HW_RGB_BLUE_PORT, HW_RGB_BLUE_PIN );

    //
    // Enable the GPIO pins for the LED_GREEN.
    //
    GPIOPinTypeGPIOOutput( HW_RGB_GREEN_PORT, HW_RGB_GREEN_PIN );


    GPIOPinWrite( HW_RGB_RED_PORT, HW_RGB_RED_PIN, 0x0 );
    GPIOPinWrite( HW_RGB_BLUE_PORT, HW_RGB_BLUE_PIN, 0x0 );
    GPIOPinWrite( HW_RGB_GREEN_PORT, HW_RGB_GREEN_PIN, 0x0 );

}

void hal_init( void )
{

}

uint64_t hal_get_sys_tick( void )
{
    return( sys_tick );
}
