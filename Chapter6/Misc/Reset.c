#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>


EFI_STATUS EFIAPI DRIVER_LOAD( IN EFI_HANDLE ImageHandle,IN EFI_SYSTEM_TABLE* SystemTable)
{    
    Print(L"Start the driver for reset system services !");    

    gRT->ResetSystem(EfiResetWarm,EFI_SUCCESS,0,NULL);
    //gRT->ResetSystem(EfiResetShutdown,EFI_SUCCESS,0,NULL);
    //gRT->ResetSystem(EfiResetCold,EFI_SUCCESS,0,NULL);
     
    return EFI_SUCCESS;
}
