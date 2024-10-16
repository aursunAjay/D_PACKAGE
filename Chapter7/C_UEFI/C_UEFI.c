#include <C_BASE_LIB.h>
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <C_BASE_LIB.h>
#include <C_UEFI_LIB.h>
#include <Library/DebugLib.h>
#include <Guid/PEIM_HOB.h>
#include <Protocol/SampleProtocol.h>

PEIM_HOB_DEMO        *hob = NULL;
EFI_PHYSICAL_ADDRESS addr;
VOID *buffer;
UINTN mms;
UINTN mk;
UINTN desS;
UINT32 desVer;
EFI_MEMORY_DESCRIPTOR *buf;


EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_HANDLE handle, IN EFI_SYSTEM_TABLE *table)
{     
    BASE_CUSTOM_PRINT("UEFI Module called loaded!\n");

    if( table->BootServices->LocateProtocol(&gGUID_SampleProtocol,NULL,&hob) == EFI_SUCCESS )
    {
        DEBUG((DEBUG_INFO,"UEFI Located the PEIM HOB interfac!\n"));
    }
    
    table->BootServices->AllocatePages(AllocateAnyPages,EfiLoaderCode,1,&addr);
    
    DEBUG((DEBUG_INFO,"Address of allocated page: !\n %lx",addr));
    
   /*    
    table->BootServices->FreePages(addr,1);
    
    DEBUG((DEBUG_INFO,"Address of Free page: !\n %lx",addr));
    
    table->BootServices->AllocatePool(EfiLoaderCode,sizeof(INTN),&buffer);

    DEBUG((DEBUG_INFO,"Address of Allocate page: !\n %lx",addr));

    table->BootServices->FreePool(buffer);

    DEBUG((DEBUG_INFO,"Address of Allocate free page: !\n %lx",addr));
    
    table->BootServices->AllocatePool(EfiLoaderCode,sizeof(EFI_MEMORY_DESCRIPTOR),&buf);
    
    table->BootServices->GetMemoryMap(&mms,buf,&mk,&desS,&desVer);

    DEBUG((DEBUG_INFO,"\r\nMemory map size : !\r\n %d",mms));
    DEBUG((DEBUG_INFO,"\r\nMemory key  : ! %d\n",mk));
    DEBUG((DEBUG_INFO,"\r\nDescription size : ! %lx\n",desS));
    DEBUG((DEBUG_INFO,"\r\nDescription version : ! %lx\n",desVer));
    DEBUG((DEBUG_INFO,"\r\nUEFI INFO: %d\n",hob->number));
    */
    return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_HANDLE handle)
{ 
    BASE_CUSTOM_PRINT("UEFI Module called exit!\n");
    return EFI_SUCCESS;
}
