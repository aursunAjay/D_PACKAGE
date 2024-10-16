#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h> 
#include <Protocol/AcpiTable.h>
#include <Protocol/Smbios.h>

void* pointer;

EFI_STATUS EFIAPI DRIVER_LOAD(IN EFI_HANDLE handle, IN EFI_SYSTEM_TABLE* table)
{
  UINTN MemoryMapSize = 0;
  EFI_MEMORY_DESCRIPTOR* MemoryMap = NULL;
  UINTN MapKey;
  UINTN DescriptorSize;
  UINT32 DescriptorVersion;

  EFI_STATUS Status = gBS->GetMemoryMap(&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);


  Print(L"MemoryMapSize:%d\r\n", (UINTN)MemoryMapSize);
  Print(L"MapKey:%d\r\n", (UINTN)MapKey);
  Print(L"DescriptorSize:%d\r\n", (UINTN)DescriptorSize);
  Print(L"DescriptorVersion:%d\r\n", (UINTN)DescriptorVersion);


  if (Status == EFI_BUFFER_TOO_SMALL)
  {
    MemoryMapSize += DescriptorSize;

    Status = gBS->AllocatePool(EfiLoaderData, MemoryMapSize, (VOID**)&MemoryMap);

    Status = gBS->GetMemoryMap(&MemoryMapSize,
      MemoryMap,
      &MapKey,
      &DescriptorSize,
      &DescriptorVersion);

    EFI_MEMORY_DESCRIPTOR* MemoryDescriptor = MemoryMap;



    for (UINTN a = 0; a < 20; a++)
    {
      Print(L"p: 0x%lx, v: 0x%lx, pages: 0x%lx, attr: 0x%x\r\n",
        MemoryDescriptor->PhysicalStart,
        MemoryDescriptor->VirtualStart,
        MemoryDescriptor->NumberOfPages,
        MemoryDescriptor->Attribute
      );
      MemoryDescriptor = (EFI_MEMORY_DESCRIPTOR*)((UINTN)MemoryDescriptor + DescriptorSize);
    }

    gBS->FreePool(MemoryMap);
  }

  return EFI_SUCCESS;
}
