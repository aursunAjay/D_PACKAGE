
#include <C_BASE_LIB.h>
#include <Library/UefiLib.h>
#include <C_DXE_LIB.h>

EFI_STATUS EFIAPI INIT (IN EFI_HANDLE  handle,IN   EFI_SYSTEM_TABLE *services)
{
    BASE_CUSTOM_PRINT("DXE Library");    
    BASE_CUSTOM_PRINT("DXE Library called INIT!\n");  
    return EFI_SUCCESS;
}

EFI_STATUS EFIAPI DEINIT (IN EFI_HANDLE handle,IN   EFI_SYSTEM_TABLE  *services)
{
    BASE_CUSTOM_PRINT("DXE Library\n");   
    BASE_CUSTOM_PRINT("DXE Library called DEINIT!\n"); 
    return EFI_SUCCESS;
}


