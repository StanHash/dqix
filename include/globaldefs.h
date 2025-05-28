#pragma once

#ifdef __cplusplus
    #define EXTERN_C extern "C"
#else
    #define EXTERN_C
#endif

#define ARM _Pragma("thumb off")
#define THUMB _Pragma("thumb on")
#define NULL 0 // appeases vs code
