#include <hal/led.h>

#include <nxdk/log_udp.h>

#include <windows.h>

int main(void)
{
    nxLogUDPRegister(NULL, NULL, NULL);

    nxLogPrint("Hello nxdk!\n");
    while (1) SwitchToThread();

    return 0;
}
