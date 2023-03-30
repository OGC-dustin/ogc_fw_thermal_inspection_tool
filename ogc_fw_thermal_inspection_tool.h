#ifndef OGC_FW_THERMAL_INSPECTION_TOOL_H
#define OGC_FW_THERMAL_INSPECTION_TOOL_H

#include <stdint.h>

void hal_config( void );
void hal_init( void );

uint64_t hal_get_sys_tick( void );

#endif /* OGC_FW_THERMAL_INSPECTION_TOOL_H */
