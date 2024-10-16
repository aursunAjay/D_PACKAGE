#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Protocol/DXERuntime.h>
#include <Protocol/MonotonicCounter.h>

C_DXE_RUNTIME *locate;

EFI_STATUS EFIAPI DRIVER_LOAD(IN EFI_HANDLE handle, IN EFI_SYSTEM_TABLE *table)
{
    UINT64 Count = 0;

    Print(L"Miscellaneous system \r\n");
    Print(L"Monolithic count \r\n");

    while (Count < 20)
    { 
        gBS->GetNextMonotonicCount(&Count);
        //gBS->Stall(1000000);
        Print(L"Count %d\r\n", Count);
    }
    
    gBS->LocateProtocol(&gEfiMonotonicCounterArchProtocolGuid,NULL,&locate);

    locate->exe_fun();

    // gEfiMonotonicCounterArchProtocolGuid

    return EFI_SUCCESS;
}
