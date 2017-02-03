#ifndef _BFCONFIGH_
#define _BFCONFIGH_

#include <cstdint>

/* specify fixed int size */
#undef FIXED_INT_SIZE
#define FIXED_INT_SIZE 8

#if FIXED_INT_SIZE == 8
#define BF_INT int8_t

#elif FIXED_INT_SIZE == 16
#define BF_INT int16_t

#elif FIXED_INT_SIZE == 32
#define BF_INT int32_t

#else
#define BF_INT int

#endif
#endif
