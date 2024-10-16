#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiBootServicesTableLib.h>

EFI_EVENT TimerEvent;

VOID EFIAPI myfun(IN EFI_EVENT Event, IN VOID *Context) 
{
    Print(L"Time is over!\n");
}

EFI_STATUS EFIAPI DRIVER_LOAD(IN EFI_HANDLE handle, IN EFI_SYSTEM_TABLE *table) 
{
    EFI_TIME time, t1;

    gRT->GetTime(&time, NULL);

    Print(L"Before set: %d %d %d %d %d %d\n",
          time.Hour, time.Minute, time.Second, time.Year, time.Month, time.Day);

    t1 = time;
    t1.Second += 5;
    
    gRT->SetTime(&time);

    Print(L"After set :%d %d %d %d %d %d\n",
          time.Hour, time.Minute, time.Second, time.Year, time.Month, time.Day);

    t1 = time;
    t1.Second += 5; 

    Print(L" %d %d %d %d %d %d\n",
          t1.Hour, t1.Minute, t1.Second, t1.Year, t1.Month, t1.Day);

    if (gRT->SetWakeupTime(TRUE, &t1) == EFI_SUCCESS) 
    {
        Print(L"Timer is set!\n");
    }
 
    gBS->CreateEvent(EVT_TIMER, TPL_CALLBACK, myfun, NULL, &TimerEvent);
 
    gBS->SetTimer(TimerEvent, TimerRelative, 5000000);
 
    gBS->WaitForEvent(1, &TimerEvent, NULL);
 
    gBS->CloseEvent(TimerEvent);

    return EFI_SUCCESS;
}

