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


PPI_PEIM_demo points;

 EFI_PEI_PPI_DESCRIPTOR Dispatch = 
{
  EFI_PEI_PPI_DESCRIPTOR_PPI | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST,
  &gEmuC_PEIM_PPI_Guid,
  NULL
};

 EFI_STATUS EFIAPI PeiNotify(IN EFI_PEI_SERVICES **services, IN  EFI_PEI_NOTIFY_DESCRIPTOR *notify,VOID *ppi)
{
    DEBUG((DEBUG_INFO,"Firmware PHIM  notify is called !\n")); 
    return EFI_SUCCESS;
} 

 EFI_PEI_NOTIFY_DESCRIPTOR Notify = 
{
 (EFI_PEI_PPI_DESCRIPTOR_NOTIFY_CALLBACK | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
  &gEmuC_PEIM_PPI_Notify_Guid,
  PeiNotify
};

 EFI_PEI_PPI_DESCRIPTOR DataPPI = 
{
 (EFI_PEI_PPI_DESCRIPTOR_PPI | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
  &gEmuC_PEIM_PPI_PPI_Data_Guid,
  (VOID*)0X100
};

 EFI_PEI_PPI_DESCRIPTOR StructPPI = 
{
 (EFI_PEI_PPI_DESCRIPTOR_PPI | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST),
  &gEmuC_PEIM_PPI_PPI_struct_Guid,
  &points
};


EFI_STATUS EFIAPI DRIVER_LOAD (
IN EFI_PEI_FILE_HANDLE handle,IN CONST EFI_PEI_SERVICES **services)
{
   points.info = 99;

   BASE_CUSTOM_PRINT("PEIM 1 Dispatching is called !\n");  
   
   PeiServicesInstallPpi(&Dispatch);
   DEBUG((DEBUG_INFO,"\n PHIM 1 notify event is called !\n"));   
   PeiServicesNotifyPpi(&Notify);	   
   DEBUG((DEBUG_INFO,"\n PHIM 1  simple data communication is called ! \n"));  
   PeiServicesInstallPpi(&DataPPI); 
   DEBUG((DEBUG_INFO,"\n PHIM 1  Struct is called ! \n"));  
   PeiServicesInstallPpi(&StructPPI);
   DEBUG((DEBUG_INFO,"\n PHIM 1  NotifyDispatchPPI is called ! \n"));     

   PEIM_HOB_DEMO *info = BuildGuidHob(&gEmuC_DXE_HOB_Guid,sizeof(PEIM_HOB_DEMO));
   info->number = 55;
    
   DEBUG((DEBUG_INFO,"\n PHIM 1  Hobs is created  ! \n"));  

   return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_PEI_FILE_HANDLE handle)
{
    BASE_CUSTOM_PRINT("PEIM Module called exit!\n");
    return EFI_SUCCESS;
}
 
