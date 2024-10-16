#include <C_BASE_LIB.h>
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <C_BASE_LIB.h>
#include <C_UEFI_LIB.h>
#include <Library/DebugLib.h>
#include <Guid/PEIM_HOB.h>
#include <Protocol/SampleProtocol.h>
#include <Protocol/BlockIo.h>


EFI_STATUS EFIAPI DRIVER_LOAD (IN EFI_HANDLE handle, IN EFI_SYSTEM_TABLE *table)
{      
    EFI_STATUS status;
    EFI_BLOCK_IO_PROTOCOL *blk = NULL;
    EFI_HANDLE *HandleBuffer = NULL;
    UINTN HandleCount = 0;
    UINT8 Buffer[512];

    status = table->BootServices->LocateHandleBuffer(ByProtocol,&gEfiBlockIoProtocolGuid,NULL,&HandleCount,&HandleBuffer);

    if (status == EFI_SUCCESS) 
    { 
        print((DEBUG_INFO,"%r",status )); 
        Print(L"%r",status);
    }

    for (UINTN Index = 0; Index < HandleCount; Index++) 
    {
        status = table->BootServices->HandleProtocol(HandleBuffer[Index],&gEfiBlockIoProtocolGuid,(VOID**)&blk );

        if (status == EFI_SUCCESS) 
        {
                if (blk->Media->RemovableMedia && blk->Media->MediaPresent) 
                {
                  
                  print((DEBUG_INFO,"Pendrive is detected .\n", blk->Media->MediaId)); 
                  Print(L"Pendrive is detected .\n", blk->Media->MediaId);

                  UINTN BufferSize = 512;  
                  
                  if (Buffer != NULL) 
                  { 
                    EFI_STATUS ReadStatus = blk->ReadBlocks(
                    blk,
                    blk->Media->MediaId,
                    0,               
                    BufferSize,  
                    Buffer
                  );

                  if (!EFI_ERROR(ReadStatus)) 
                  {
                    for (UINTN Index1 = 0; Index1 < 100; Index1++) 
                    {
                       print((DEBUG_INFO,"%x", Buffer[Index1]));
                       Print(L"%x", Buffer[Index1]);
                    }                
              } 
              else 
              {                
                  print((DEBUG_INFO,"Failed \n", ReadStatus));
                  Print(L"Failed \n", ReadStatus);
              }
          } else { 
              print((DEBUG_INFO,"Failed \n"));
              Print(L"Failed \n");
          }
      } 
      else 
      { 
          print((DEBUG_INFO,"Pendrive is not detected \n"));
          Print(L"Pendrive is not detected \n");
      }
        }
    }

    if (HandleBuffer != NULL) 
    {
        table->BootServices->FreePool(HandleBuffer);
    }

    return EFI_SUCCESS;
}

EFI_STATUS EFIAPI EXIT (IN EFI_HANDLE handle)
{  

    return EFI_SUCCESS;
}