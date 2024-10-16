#include <PiPei.h>
#include <private.h>
#include <IA32/ia32.h>
#include <Ppis/PPI_PEIM.h>
#include <Guid/PEIM_HOB.h>
#include <Library/HOBLib.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/C_BASE_LIB.h>
#include <Library/C_PEIM_LIB.h>
#include <Library/PeiServicesLib.h>
#include <Protocol/SampleProtocol.h>


EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_HANDLE handle,IN EFI_SYSTEM_TABLE *table)
{     
   return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_HANDLE handle)
{ 
    return EFI_SUCCESS;
}
 
