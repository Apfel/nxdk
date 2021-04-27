#ifndef __NXDK_LOG_CONSOLE_H__
#define __NXDK_LOG_CONSOLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "log.h"

/**
 * Registers the console logging function.
 * This'll print messages on the connected TV.
 *
 * @return Returns an @link nxLogResult @endlink code.
 */
uint8_t nxLogConsoleRegister();

/**
 * Unregisters the console logging function.
 */
void nxLogConsoleUnregister();

/**
 * Moves the cursor on the screen.
 * 
 * @param x The x coordinate to move to.
 * @param y The y coordinate to move to.
 * 
 * @return Returns an @link nxLogResult @endlink code.
 */
uint8_t nxLogConsoleMoveCursor(uint32_t x, uint32_t y);

/**
 * Clears the screen.
 * 
 * @return Returns an @link nxLogResult @endlink code.
 */
uint8_t nxLogConsoleClear();

#ifdef __cplusplus
}
#endif

#endif
