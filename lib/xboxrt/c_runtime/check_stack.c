#include <errhandlingapi.h>
#include <nxdk/log.h>
#include <xboxkrnl/xboxkrnl.h>

#ifdef DEBUG_CONSOLE
    #define _print DbgPrint
#else
    #define _print nxLogPrintf
#endif

void _cdecl _xlibc_check_stack (DWORD requested_size, DWORD stack_ptr)
{
    PKTHREAD current_thread = KeGetCurrentThread();

    if (requested_size >= stack_ptr || stack_ptr - requested_size < (DWORD)current_thread->StackLimit)
    {
        _print("\n"
               "Stack overflow caught!\n"
               "stack pointer: 0x%x\n"
               "request size:  0x%x\n"
               "stack limit:   0x%x\n"
               "\n",
               stack_ptr, requested_size, (DWORD)current_thread->StackLimit);

        RaiseException(EXCEPTION_STACK_OVERFLOW, EXCEPTION_NONCONTINUABLE, 0, NULL);
    }
}
