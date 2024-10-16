#ifndef C_BASE_LIB_H
#define C_BASE_LIB_H
#include <Base.h>

VOID BASE_PRINT(VOID);
VOID BASE_CUSTOM_PRINT(VOID *info);
VOID BASE_Print(VOID *level,...); 
#if !defined (MDEPKG_NDEBUG)
#define print(Expression)        \
    do {                           \
      if (DebugPrintEnabled ()) {  \
        _DEBUG (Expression);       \
      }                            \
    } while (FALSE)
#else
#define print(Expression)
#endif

VOID printf(VOID *base,VOID *info);


#endif