#include <Uefi.h> 
#include <Library/PcdLib.h>
#include <Library/UefiLib.h> 
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiLib.h>  
#include <Protocol/LoadedImage.h>
#include <Library/DevicePathLib.h>
#include <Library/MemoryAllocationLib.h> 
#include <Library/DebugLib.h>

EFI_EXIT_BOOT_SERVICES  gOrigExitBootServices;
EFI_STATUS Status;
EFI_EVENT event;

void* pointer;
VOID EFIAPI notify(IN  EFI_EVENT Event, IN  VOID* Context)
{
  Print(L"Boot services is terminate!");
}

EFI_STATUS EFIAPI DRIVER_LOAD(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE* SystemTable)
{
  UINTN MemoryMapSize;
  EFI_MEMORY_DESCRIPTOR* MemoryMap;
  UINTN LocalMapKey;
  UINTN DescriptorSize;
  UINT32 DescriptorVersion;
  MemoryMap = NULL;
  MemoryMapSize = 0;

   
  do
  {
    Status = gBS->GetMemoryMap(&MemoryMapSize, MemoryMap, &LocalMapKey, &DescriptorSize, &DescriptorVersion);

    Print(L"UEFI driver status  = %r %d\n", Status, LocalMapKey);

    if (Status == EFI_BUFFER_TOO_SMALL)
    {
      MemoryMap = AllocatePool(MemoryMapSize + 1);
      Status = gBS->GetMemoryMap(&MemoryMapSize, MemoryMap, &LocalMapKey, &DescriptorSize, &DescriptorVersion);
      Print(L"UEFI driver status  = %r %d\n", Status, LocalMapKey);      
      //Status = gBS->ExitBootServices(ImageHandle, LocalMapKey);
      Print(L"UEFI driver status  = %r\n", Status);
    }
  } while (Status != EFI_SUCCESS);

  pointer = (UINTN*)20;
  Print(L"Physical to virtual Before : %d !\n",pointer);

  Status = gRT->ConvertPointer(EFI_OPTIONAL_PTR,&pointer);

  
  if (Status == EFI_SUCCESS)
  {
    Print(L"Physical to virtual converted !\n");
  }
  
  pointer = (UINTN*)10;
  
  Print(L"Physical to virtual After : %d !\n",pointer);

  return EFI_SUCCESS;
}

