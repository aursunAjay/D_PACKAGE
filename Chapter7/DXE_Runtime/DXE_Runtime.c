#include <Uefi.h>
#include <C_DXE_LIB.h>
#include <C_BASE_LIB.h>
#include <Pi/PiDxeCis.h>
#include <Guid/PEIM_HOB.h>
#include <Library/HOBLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseLib.h> 
#include <Library/DebugLib.h>
#include <Library/UefiRuntimeLib.h> 
#include <Protocol/SampleProtocol.h> 
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Protocol/MonotonicCounter.h>
#include <Protocol/DXERuntime.h> 
 
VOID myexe(VOID);

UINT64      mycount;
EFI_STATUS  Status;
UINT32      HighCount;
UINTN       BufferSize;
EFI_HANDLE  handle;
C_DXE_RUNTIME demo = 
{
  myexe
};

EFI_STATUS EFIAPI mycounts ( OUT UINT64  *Count )
{
     EFI_TPL  OldTpl; 

     if (EfiAtRuntime ()) 
     {
          return EFI_UNSUPPORTED;
     }  
     if (Count == NULL) 
     {
          return EFI_INVALID_PARAMETER;
     } 

     OldTpl = gBS->RaiseTPL (TPL_HIGH_LEVEL);
     *Count = mycount;
     mycount++;
     gBS->RestoreTPL (OldTpl);     

     DEBUG ((DEBUG_INFO,"Counting .. %d!\n",mycount)); 

  return EFI_SUCCESS;
}

VOID myexe(VOID)
{
      DEBUG ((DEBUG_INFO,"System work properly .. %d!\n",mycount)); 
}

EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_HANDLE image_handle,IN EFI_SYSTEM_TABLE *table)
{           
     DEBUG ((DEBUG_INFO,"Driver Start funtion !\n"));

     gBS->GetNextMonotonicCount = mycounts; 

     gBS->InstallMultipleProtocolInterfaces (  
          &image_handle,
          &gEfiMonotonicCounterArchProtocolGuid,
          &demo,
          NULL );

     DEBUG ((DEBUG_INFO,"DXE Runtime exit !\n"));
     return EFI_SUCCESS;
}
 