# OGC.Engineering
## ogc_fw_thermal_inspection_tool
Developer contact - dustin < at > ogc.engineering

---
### Location:

- Hardware Abstraction Layer ( HAL ):
    - location: firmware/ogc_fw_thermal_inspection_tool/
    - repo: https://github.com/OGC-dustin/ogc_fw_thermal_inspection_tool

---
### Resources - TM4C123GXL Launchpad development board:
- To support general OGC OS build layers:
    - void hal_config( void ) - single call at start of operation to configure hardware ( watchdog, clocks, etc. )
    - void hal_init( void ) - call location if there are firmware level tasks that need to be scheduled ( depending on Operating System (OS ) )
    - uint64_t sys_tick & uint64_t hal_get_sys_tick( void ) - monotonic clock available for task handling
    - ?? ?? - RTCC clock and calendar functionality for timestamps, alarms, etc.

### Resources - User Interface ( UI ) daughter board:
- To support the UI RGB Encoder:
    - RGB Led ( software libraries provide higher level color mixing in either mode ):
        - Basic GPIO color mixing ( 7 colors )
            - init, deinit, get, & set functions 
        - Advanced PWM color mixing ( ? colors depending on PWM resolution )
            - init, deinit, get, & set functions
        - hardware and deployment definitions provide desired functionality selection and hal_config branch as needed to call desired init function
    - Encoder phases:
        - HAL provides interrupt handling, change of state reporting, ( software libraries provide software debouncing and encoder interpretation )
- To support the UI OLED Display:
    - HAL provides pin configurations and SPI functionality ( OLED driver uses HAL to achieve higher level sequenced functions )
- To support the SD Card:
    - Card Detection:
        - HAL provides interrupt handling, change of state reporting, ( software libraries provide SD Card handling directed through SPI functions )

### Resources - Sensor daughter board:
- To support the Color Camera:
    - HAL provides Interrupt ( sync ) and GPIO functionality ( drivers provide higher level functionality )
- To support the NeoPixel light ring:
    - HAL provides GPIO functionality ( drivers provide higher level functionality )
- To support the Thermal Camera:
    - HAL provides I2C functionality ( drivers provide higher level functionality )
- To support the LIDAR Lite v3 distance sensor:
    - HAL provides I2C and GPIO functionality ( drivers provide higher level functionality )
