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
#include <Protocol/SampleProtocol.h>
#include <Protocol/SimpleFileSystem.h>
#include <Protocol/LoadedImage.h>
#include <Protocol/DevicePath.h>
#include <Library/DevicePathLib.h>

 CHAR16* info ;
EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_HANDLE handle,IN EFI_SYSTEM_TABLE *table)
{     

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
     
   return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_HANDLE handle)
{ 
    return EFI_SUCCESS;
}
 
