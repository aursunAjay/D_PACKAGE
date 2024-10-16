#include <C_BASE_LIB.h>
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <C_BASE_LIB.h>
#include <C_UEFI_LIB.h>
#include <Library/DebugLib.h>
#include <Guid/PEIM_HOB.h>
#include <Protocol/SampleProtocol.h>
#include <Protocol/BlockIo.h>
 
EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_HANDLE handle, IN EFI_SYSTEM_TABLE *table)
{     
    
    return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_HANDLE handle)
{  
    return EFI_SUCCESS;
}