#include <nxdk/log_console.h>
#include <hal/video.h>
#include <nxdk/mount.h>
#include <windows.h>

int main(void)
{
    XVideoSetMode(640, 480, 32, REFRESH_DEFAULT);
    nxLogConsoleRegister();

    // Mount some drives for demonstration purposes
    BOOL ret;
    ret = nxMountDrive('C', "\\Device\\Harddisk0\\Partition2\\");
    if (!ret) {
        nxLogPrintf("Failed to mount C: drive!\n");
        Sleep(5000);
        return 1;
    }
    ret = nxMountDrive('E', "\\Device\\Harddisk0\\Partition1\\");
    if (!ret) {
        nxLogPrintf("Failed to mount E: drive!\n");
        Sleep(5000);
        return 1;
    }

    // Retrieve drive bitmaks. Every bit represents one drive letter
    DWORD driveBits = GetLogicalDrives();
    if (driveBits == 0 && GetLastError() != ERROR_SUCCESS) {
        nxLogPrintf("Failed to retrieve drive bitmask!\n");
        Sleep(5000);
        return 1;
    }
    nxLogPrintf("Drive bitmask: 0x%x\n\n", driveBits);


    // Reserve buffer long enough for all possible drive strings plus null-terminator
    char buffer[26 * 4 + 1];
    // IMPORTANT: The size passed to GetLogicalDriveStringsA is WITHOUT the null-terminator, even though it gets written
    DWORD charsWritten = GetLogicalDriveStringsA(sizeof(buffer)-1, buffer);
    if (charsWritten == 0) {
        // Additional error info can be retrieved with GetLastError()
        nxLogPrintf("Failed to retrieve drive strings!\n");
        Sleep(5000);
        return 1;
    }

    if (charsWritten > sizeof(buffer) - 1) {
        // Can't happen here as our buffer is large enough to cover all possibilities
        nxLogPrintf("Buffer for GetLogicalDriveStringsA too small!\n");
        Sleep(5000);
        return 1;
    }

    nxLogPrintf("Drives found:\n");
    char *drive = buffer;
    while (drive < buffer + charsWritten) {
        nxLogPrintf("%s\n", drive);
        while(*drive++);
    }
    nxLogPrintf("\ndone");

    while(1) {
        Sleep(2000);
    }

    return 0;
}
