#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_


#define LOGIC_HIGH (1u)
#define LOGIC_LOW  (0u)

            // Boolean values
typedef unsigned char bool_t;
#define TRUE    (1u)
#define FALSE   (0u)

            // Status
#define SUCCESS (0u)
#define FAILURE (1u)

            // Integer types
typedef unsigned char           u8;
typedef signed   char           s8;

typedef unsigned short          u16;
typedef signed   short          s16;

typedef unsigned long           u32;
typedef signed   long           s32;

typedef unsigned long long      u64;
typedef signed   long long      s64;

            // Floating-point types
typedef float  f32;
typedef double f64;

#endif 
