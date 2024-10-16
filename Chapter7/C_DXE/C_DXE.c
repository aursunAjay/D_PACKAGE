#include <Uefi.h>
#include <C_DXE_LIB.h>
#include <C_BASE_LIB.h>
#include <Pi/PiDxeCis.h>
#include <Library/UefiLib.h>
#include <Guid/PEIM_HOB.h>
#include <Library/HOBLib.h>
#include <Library/DebugLib.h>
#include <Guid/PEIM_HOB.h>
#include <Library/PcdLib.h>
#include <Protocol/SampleProtocol.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/LocalApicLib.h>

UINT64                          size;
UINTN                           no_io;   
extern EFI_DXE_SERVICES         *gDS;   
EFI_GCD_IO_SPACE_DESCRIPTOR     *desp_io;
UINT64                          BaseAddress;
EFI_GCD_MEMORY_SPACE_DESCRIPTOR desp;
EFI_STATUS                      Status;

UINT32 info;
/*
EFI_STATUS AllocateMemory(EFI_SYSTEM_TABLE* table) 
{ 
  
    CHAR8 data[] = "OK boss";
    UINTN dataSize = sizeof(data);

    table->BootServices->AllocatePages(
        AllocateAnyPages,
        EfiRuntimeServicesData,
        1,
        &BaseAddress
    );
 
    table->BootServices->CopyMem((VOID*)BaseAddress, (VOID*)data, dataSize);
 
    return EFI_SUCCESS;
}
*/

EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_HANDLE handle,IN EFI_SYSTEM_TABLE *table)
{     

  UINTN MemoryMapSize = 0;
  EFI_MEMORY_DESCRIPTOR* MemoryMap = NULL;
  UINTN MapKey;
  UINTN DescriptorSize;
  UINT32 DescriptorVersion;
 
  Status = table->BootServices->GetMemoryMap(&MemoryMapSize, MemoryMap, &MapKey, &DescriptorSize, &DescriptorVersion);
 
  Print(L"MemoryMapSize:%d\r\n", (UINTN)MemoryMapSize);
  Print(L"MapKey:%d\r\n", (UINTN)MapKey);
  Print(L"DescriptorSize:%d\r\n", (UINTN)DescriptorSize);
  Print(L"DescriptorVersion:%d\r\n", (UINTN)DescriptorVersion);
 
  if (Status == EFI_BUFFER_TOO_SMALL)
  {
        MemoryMapSize += DescriptorSize;

        Status = table->BootServices->AllocatePool(EfiLoaderData, MemoryMapSize, (VOID**)&MemoryMap);

        Status = table->BootServices->GetMemoryMap(&MemoryMapSize,
        MemoryMap,
        &MapKey,
        &DescriptorSize,
        &DescriptorVersion);

        EFI_MEMORY_DESCRIPTOR *MemoryDescriptor = MemoryMap;

        for (UINTN a = 20; a < 40; a++)
        {
            DEBUG((DEBUG_INFO,"p: 0x%lx, v: 0x%lx, pages: 0x%lx, attr: 0x%x\r\n",
            MemoryDescriptor->PhysicalStart,
            MemoryDescriptor->VirtualStart,
            MemoryDescriptor->NumberOfPages,
            MemoryDescriptor->Attribute)); 
            MemoryDescriptor = (EFI_MEMORY_DESCRIPTOR*)((UINTN)MemoryDescriptor + DescriptorSize);
        }     
    }
    
    table->BootServices->FreePool(MemoryMap);   

    info = PcdGet32(C_DXE_Demo);

    DEBUG((DEBUG_INFO,"UNI FILE INFO: > %d\n",info));

    return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_HANDLE handle)
{
    BASE_CUSTOM_PRINT("DXE Module EXIT!\n");  
    return EFI_SUCCESS;
}