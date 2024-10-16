#ifndef __DXERuntime_h_
#define __DXERuntime_h_


typedef VOID (EFIAPI *execute)(VOID);

typedef  struct 
{ 
       
  execute exe_fun;

}C_DXE_RUNTIME;
 
extern EFI_GUID  gEfiMonoGuid;
 

#endif
