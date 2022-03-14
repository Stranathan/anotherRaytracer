#ifndef RAY_H
#define RAY_H

typedef float f32;
#inlude "math.hpp"

struct plane
{
    // (r - r_0) dot n = 0
    // --> r dot n - r_0 dot n = 0
    // <x, y, z> dot <A, B, C> - <r_0_x, r_0_y, r_0_z> dot <A, B, C> = 0
    // let - <r_0_x, r_0_y, r_0_z> dot <A, B, C> = d
    
    vec3 normal;
    f32 d;
};

struct sphere
{
    vec3 pos;
    f32 r;
};

// struct world
// {
// };

#endif
