#include <Uefi.h>
#include <C_BASE_LIB.h>
#include <Library/UefiLib.h>


EFI_STATUS EFIAPI INIT (IN EFI_HANDLE handle,IN EFI_SYSTEM_TABLE *table)
{
    BASE_CUSTOM_PRINT("UEFI Library");
    BASE_CUSTOM_PRINT("UEFI Library called INIT!\n");
    return EFI_SUCCESS;
}

EFI_STATUS EFIAPI DEINIT (IN EFI_HANDLE handle,IN EFI_SYSTEM_TABLE *table)
{
    BASE_CUSTOM_PRINT("UEFI Library");
    BASE_CUSTOM_PRINT("UEFI Library called DEINIT!\n"); 
    return EFI_SUCCESS;
}

