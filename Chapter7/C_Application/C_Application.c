#include <C_APP_LIB.h>
#include <Library/UefiLib.h>
#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Protocol/LoadedImage.h>
#include <Protocol/SimpleFileSystem.h>
#include <Library/C_BASE_LIB.h>
#include <Protocol/SampleProtocol.h>
#include <Guid/PEIM_HOB.h>
#include <Library/DevicePathLib.h>

PEIM_HOB_DEMO *hob = NULL;
CHAR16    *info;

// Simple File system implementation 

EFI_STATUS EFIAPI main_point(IN EFI_HANDLE handle, IN EFI_SYSTEM_TABLE *table)
{       
   
   DEBUG((DEBUG_INFO,"Hello world !  UEFI Application\n"));

    EFI_STATUS STATUS;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *FILE       = NULL;
    EFI_LOADED_IMAGE_PROTOCOL       *IMAGE      = NULL;
    EFI_DEVICE_PATH_PROTOCOL        *DEVICE     = NULL;
    EFI_FILE_PROTOCOL               *FILE_PATH  = NULL;
    
    STATUS = table->BootServices->LocateProtocol(&gEfiLoadedImageProtocolGuid,NULL,(VOID**)&IMAGE);

    table->BootServices->HandleProtocol(handle,&gEfiLoadedImageProtocolGuid,(VOID **)&IMAGE);

    table->BootServices->HandleProtocol(IMAGE->FilePath,&gEfiLoadedImageDevicePathProtocolGuid,(VOID **)&DEVICE); 

    table->BootServices->HandleProtocol(IMAGE->DeviceHandle,&gEfiSimpleFileSystemProtocolGuid,(VOID **)&FILE);
    
    FILE->OpenVolume(FILE,&FILE_PATH);     

    STATUS = FILE_PATH->Open(FILE_PATH,NULL,L"soni",EFI_FILE_MODE_CREATE | EFI_FILE_MODE_WRITE | EFI_FILE_MODE_READ,EFI_FILE_DIRECTORY);
 
    info = ConvertDevicePathToText(IMAGE->FilePath,TRUE,FALSE); 
    
    Print(L"Location :%s\n",info);
    DEBUG((DEBUG_INFO,"Location: %s\n",info));
     
    if( table->BootServices->LocateProtocol(&gGUID_SampleProtocol,NULL,&hob) == EFI_SUCCESS )
    {
        DEBUG((DEBUG_INFO,"UEFI Located the PEIM HOB interfac!\n"));
    }
    
    DEBUG((DEBUG_INFO,"\r\nUEFI INFO: %d\n",hob->number));
 
    return EFI_SUCCESS;  
}

EFI_STATUS EFIAPI exit_point(IN EFI_HANDLE handle)
{
       DEBUG((DEBUG_INFO,"Good bye !    UEFI Application\n"));
       return EFI_SUCCESS;  
}