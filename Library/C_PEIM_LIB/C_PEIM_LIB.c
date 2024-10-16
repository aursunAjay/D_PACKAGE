#include <PiPei.h>
#include <C_BASE_LIB.h>


EFI_STATUS EFIAPI INIT (IN EFI_PEI_FILE_HANDLE *handle,IN CONST EFI_PEI_SERVICES **services)
{
    BASE_CUSTOM_PRINT("PEIM Library");    
    BASE_CUSTOM_PRINT("PEIM Library called INIT!\n");  
    return EFI_SUCCESS;
}

EFI_STATUS EFIAPI DEINIT (IN EFI_PEI_FILE_HANDLE handle,IN CONST EFI_PEI_SERVICES **services)
{
    BASE_CUSTOM_PRINT("PEIM Library\n");   
    BASE_CUSTOM_PRINT("PEIM Library called DEINIT!\n"); 
    return EFI_SUCCESS;
}


