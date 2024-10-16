#ifndef _PPI_PEIM_h
#define _PPI_PEIM_h
#include <Library/BaseLib.h>

typedef void (EFIAPI *_func)(void);

#pragma pack(1)
typedef struct 
{
   int info;
   _func fun;
}_PEIM_Data_Demo;
#pragma pack()

typedef  _PEIM_Data_Demo PPI_PEIM_demo;

#endif 