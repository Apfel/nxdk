#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <nxdk/mount.h>
#include <nxdk/log_console.h>
#include <hal/video.h>
#include <hal/xbox.h>

int main(void)
{
    XVideoSetMode(640, 480, 32, REFRESH_DEFAULT);
    nxLogConsoleRegister();

    // Mount C:
    BOOL ret = nxMountDrive('C', "\\Device\\Harddisk0\\Partition2\\");
    if (!ret) {
        nxLogPrintf("Failed to mount C: drive!\n");
        Sleep(5000);
        return 1;
    }

    nxLogPrintf("Content of C:\\\n");

    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    // Like on Windows, "*.*" and "*" will both list all files,
    // no matter whether they contain a dot or not
    hFind = FindFirstFile("C:\\*.*", &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        nxLogPrintf("FindFirstHandle() failed!\n");
        Sleep(5000);
        return 1;
    }

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            nxLogPrintf("Directory: ");
        } else {
            nxLogPrintf("File     : ");
        }

        nxLogPrintf("%s\n", findFileData.cFileName);
    } while (FindNextFile(hFind, &findFileData) != 0);

    nxLogPrintf("\n");

    DWORD error = GetLastError();
    if (error == ERROR_NO_MORE_FILES) {
        nxLogPrintf("Done!\n");
    } else {
        nxLogPrintf("error: %x\n", error);
    }

    FindClose(hFind);

    while (1) {
        Sleep(2000);
    }

    return 0;
}
