#ifndef _PEIM_HOB_h
#define _PEIM_HOB_h
#include <Library/BaseLib.h>

extern EFI_GUID gEmuC_DXE_HOB_Guid;
extern EFI_GUID gEmuC_HOB_comm_Guid;

#pragma pack(1)
typedef struct 
{
       int number;
}_PEIM_HOB_DEMO_;
#pragma pack()

typedef  _PEIM_HOB_DEMO_ PEIM_HOB_DEMO;

#endif