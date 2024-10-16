#include <C_APP_LIB.h>
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/C_BASE_LIB.h>

EFI_STATUS EFIAPI App(VOID)
{      
    BASE_CUSTOM_PRINT("Application is started !\n");
    
    return EFI_SUCCESS;
}