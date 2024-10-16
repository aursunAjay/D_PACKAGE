#ifndef SampleProtocol_h
#define SampleProtocol_h
#include <Base.h>
#include <Uefi.h>


struct _SampleProtocol_
{
   int data;
};

extern EFI_GUID gGUID_SampleProtocol;
typedef  struct  _SampleProtocol_ SampleProtocol;
// gEfiResetArchProtocolGuid

#endif 
