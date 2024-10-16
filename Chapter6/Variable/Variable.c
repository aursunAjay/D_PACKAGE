#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>

  EFI_GUID bootGuid =  {0x8be4df61, 0x93ca, 0x11d2, {0xaa,0x0d,0x00,0xe0,0x98,0x03,0x2b,0x8c}};
  EFI_GUID bootGuid1 = {0x6e4bd8d2,0x327d,0x4fb0,  {0xb2,0xd4,0xc4,0x80,0xb1,0x6f,0xa2,0xb2}};

  UINT8 info[100] = {0};
  UINTN size = 100;
  EFI_GUID VendorGuid;
  UINTN VariableNameSize = 512;

  CHAR16 VariableName [512];
  UINT8 data = 100;    


EFI_STATUS EFIAPI DRIVER_LOAD( IN EFI_HANDLE ImageHandle,IN EFI_SYSTEM_TABLE* SystemTable)
{     
 
     
    Print(L"Start the driver for reset system services !\r\n");        
 
    gRT->GetVariable(
        L"BootOrder",
        &bootGuid,
    (UINT32*)(
        EFI_VARIABLE_BOOTSERVICE_ACCESS |
        EFI_VARIABLE_RUNTIME_ACCESS | 
        EFI_VARIABLE_NON_VOLATILE) 
       ,&size
        ,(VOID*)info);    
    
    for(UINT8 a = 0;a < size; a++)
    {
        Print(L" %d ",info[a]);
    }
  
    Print(L"\r\n");
    Print(L"\r\n");
 
    gRT->SetVariable(L"AJAYSONI",&bootGuid1,(UINT32)(EFI_VARIABLE_BOOTSERVICE_ACCESS |
    EFI_VARIABLE_RUNTIME_ACCESS | 
    EFI_VARIABLE_NON_VOLATILE),sizeof(data),&data);

    size = 1; 
    data = 0;

    gRT->GetVariable(L"AJAYSONI",&bootGuid1,
    (UINT32*)(EFI_VARIABLE_BOOTSERVICE_ACCESS |
    EFI_VARIABLE_RUNTIME_ACCESS | 
    EFI_VARIABLE_NON_VOLATILE) 
    ,&size,&data);    
     
    Print(L" %d ",data);

 
    if (VariableName == NULL) 
    {
      Print(L"Error on AllocateZeroPool call\n");
      return EFI_OUT_OF_RESOURCES;
    }
     
    EFI_STATUS Status = gRT->GetNextVariableName(&VariableNameSize, VariableName, &VendorGuid);
           
    if (Status == EFI_SUCCESS) 
    {
        Print(L"%g: %s\n", VendorGuid, VariableName);
    }     
    else if (Status == EFI_NOT_FOUND) 
    { 
        return EFI_SUCCESS;
    }      
     
    return EFI_SUCCESS;
}
 