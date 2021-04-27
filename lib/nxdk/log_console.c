#include "log_console.h"
#include "log_console_font.h"

size_t console_log_function(const char* message, size_t length)
{
    // TODO: print message on screen
    return 0;
}

uint8_t nxLogConsoleRegister()
{
    return nxLogRegisterFunction(&console_log_function);
}

void nxLogConsoleUnregister()
{
    nxLogUnregisterFunction(&console_log_function);
}

uint8_t nxLogConsoleMoveCursor(uint32_t x, uint32_t y)
{
    return nxLogResult_Success;
}

uint8_t nxLogConsoleClear()
{
    return nxLogResult_Success;
}
