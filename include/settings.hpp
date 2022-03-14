#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>

#define DEBUG (0)
#define CSTYLE (0)
#define CPPSTYLE (1)

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
//
typedef char  s8;
typedef short s16;
typedef int   s32;
//
typedef float f32;

#ifdef DEBUG
    #include <bitset>
#endif


#endif
