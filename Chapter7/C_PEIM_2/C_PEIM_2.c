#include <PiPei.h>
#include <private.h>
#include <IA32/ia32.h>
#include <Guid/PEIM_HOB.h>
#include <Library/HOBLib.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/C_BASE_LIB.h>
#include <Library/C_PEIM_LIB.h>
#include <Library/PeiServicesLib.h>
#include <Library/PeiServicesTablePointerLib.h>
#include <Ppis/PPI_PEIM.h>
#include <Guid/PEIM_HOB.h>

VOID *info;
EFI_PEI_PPI_DESCRIPTOR *data; 
PPI_PEIM_demo          *PPI_PEIM_data;

EFI_PEI_PPI_DESCRIPTOR Dispatch = 
{
  EFI_PEI_PPI_DESCRIPTOR_PPI | EFI_PEI_PPI_DESCRIPTOR_TERMINATE_LIST,
  &gEmuC_PEIM_PPI_Notify_Guid,
  NULL
};

EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_PEI_FILE_HANDLE handle,IN CONST EFI_PEI_SERVICES **services)
{  
    BASE_CUSTOM_PRINT("PEIM 2 Module called start!\n"); 
    
    DEBUG((DEBUG_INFO,"\n PHIM 2 Notify driver installed ! \n"));   
    PeiServicesInstallPpi(&Dispatch); 
    
    PeiServicesLocatePpi(&gEmuC_PEIM_PPI_PPI_Data_Guid,0,&data,&info);        
    DEBUG((DEBUG_INFO,"\n PHIM 2 data: ! %d\n",(INTN*)info));
    
    PeiServicesLocatePpi(&gEmuC_PEIM_PPI_PPI_struct_Guid,0,&data,&PPI_PEIM_data); 
    DEBUG((DEBUG_INFO,"\n PHIM 2 struct data: ! %d\n",(int)PPI_PEIM_data->info));    
    
    VOID *Hobs = GetFirstGuidHob(&gEmuC_DXE_HOB_Guid);
    PEIM_HOB_DEMO *hob = GET_GUID_HOB_DATA(Hobs);
    DEBUG((DEBUG_INFO,"\n PHIM 2 HOBS data: ! %d\n",(int)hob->number));    

  /*
    Hobs = GetFirstGuidHob(&gEmuC_HOB_comm_Guid);    
    hob  = GET_GUID_HOB_DATA(Hobs);         
    DEBUG((DEBUG_INFO,"UEFI  Hobs data ! %d \n",hob->number));    
  */

    return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_PEI_FILE_HANDLE handle)
{
    BASE_CUSTOM_PRINT("PEIM 2 Module called exit!\n");
    return EFI_SUCCESS;
} 
 