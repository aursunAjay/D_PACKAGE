#ifndef C_PEIM_LIB_H
#define C_PEIM_LIB_H
#include <Base.h>
#include <Pi/PiPeiCis.h>

EFI_STATUS EFIAPI DEINIT (IN EFI_PEI_FILE_HANDLE handle,IN EFI_PEI_SERVICES **table);
EFI_STATUS EFIAPI INIT (IN EFI_PEI_FILE_HANDLE handle,IN EFI_PEI_SERVICES **table);
 
#endif