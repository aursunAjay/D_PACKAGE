#include <Uefi.h>
#include <C_DXE_LIB.h>
#include <C_BASE_LIB.h>
#include <Pi/PiDxeCis.h>
#include <Library/UefiLib.h>
#include <Guid/PEIM_HOB.h>
#include <Library/HOBLib.h>
#include <Library/DebugLib.h>
#include <Guid/PEIM_HOB.h>
#include <Protocol/SampleProtocol.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/UefiBootServicesTableLib.h>

 
EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_HANDLE handle,IN EFI_SYSTEM_TABLE *table)
{    
     
     return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_HANDLE handle)
{ 
     return EFI_SUCCESS;
}
 
