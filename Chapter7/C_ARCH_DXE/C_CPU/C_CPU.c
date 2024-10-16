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
#include <Protocol/Cpu.h>  

EFI_CPU_ARCH_PROTOCOL *CPU_ARCH;

BOOLEAN state = FALSE;
UINT64 timer = 0;
UINT64 period = 0;

EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_HANDLE handle,IN EFI_SYSTEM_TABLE *table)
{           
     
    EFI_STATUS s = 0;

    if( s == EFI_SUCCESS )
    {
      BASE_CUSTOM_PRINT("INSTALLED CPU PROTOCOL!\n");                       
    }

    s = table->BootServices->LocateProtocol(&gEfiCpuArchProtocolGuid,NULL,&CPU_ARCH);

    if( s == EFI_SUCCESS )
    {
      BASE_CUSTOM_PRINT("Locate CPU PROTOCOL!\n");                       
    }
     
    s = CPU_ARCH->GetInterruptState(CPU_ARCH,&state);

     if( s == EFI_SUCCESS )
    {
      print((DEBUG_INFO,"Interrupt state: %d\n",state));
    }
     
    s = CPU_ARCH->GetTimerValue(CPU_ARCH,0,&timer,&period);
 
    if( s == EFI_SUCCESS )
    {   
       print((DEBUG_INFO,"Timer  : %d\n",timer));
       print((DEBUG_INFO,"Period : %d\n",period));       
    }
     
     return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_HANDLE handle)
{ 
    return EFI_SUCCESS;
}