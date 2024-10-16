#include <Library/C_BASE_LIB.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>


VOID BASE_PRINT(VOID)
{
    DEBUG((DEBUG_INFO,"C_BASE Library called! \n"));
}

VOID printf(VOID *base,VOID *info)
{
    //Print((CHAR16*)base,(CHAR16*)info);
}

VOID BASE_CUSTOM_PRINT(VOID *info)
{ 
   DEBUG((DEBUG_INFO,"BASE_CUSTOM_PRINT function called! [%a] \n",(CHAR8*) info));     
}
