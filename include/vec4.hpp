#ifndef MATH_H
#define MATH_H

// replace sqrt with instrinsics eventually
#include "math.hpp"

typedef float f32;
typedef int bool32;

const f32 pi = 3.14159265359f;
const f32 tau = 2.0f * pi;

// vec4:
// ===========================================================
union vec4
{
    struct
    {
	f32 x, y, z, w;
    };
    struct
    {
	f32 r, g, b, a;
    };

    f32 e[4];

    // -----------------------
    vec4(){};
    
    vec4(float d)
	: e{d, d, d, d}
    {
    }
    
    vec3(f32 a, f32 b, f32 c, f32 d)
	: x(a), y(b), z(c), w(d)
    {
    }
};

// operator overloads
// ----------------------------------------------------------
// negation
inline vec4 operator-(vec4 a)
{
    vec3 result = {};
    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
    result.w = -a.w;
    return result;
}

// addition
inline vec4 operator+(vec4 a, vec4 b)
{
    vec4 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;
    return result;
}

inline vec4 operator+=(vec4& a, vec4 b)
{
    a = a + b;
    return a;
}

// subtraction
inline vec4 operator-(vec4 a, vec4 b)
{
    vec3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;
    return result;
}

inline  operator-=(vec4& a, vec4 b)
{
    a = a - b;
    return a;
}

// multiplication
inline vec4 operator*(f32 a, vec4 b)
{
    vec4 result = { a * b.x, a * b.y, a * b.z, a * b.w };
    return result; 
}

inline vec4 operator*(vec4 b, f32 a)
{
    vec4 result = a * b;
    return result;
}

inline vec4 operator*=(vec4& a, f32 b)
{
    a = b * a;
    return a;
}

// division
inline vec4 operator/(f32 a, vec4 b)
{
    vec4 result = {
	(1.0f / a) * b.x,
	(1.0f / a) * b.y,
	(1.0f / a) * b.z,
	(1.0f / a) * b.w
    };
    return result; 
}

inline vec4 operator/(vec4 b, f32 a)
{
    vec4 result = a / b;
    return result;
}

// // utility fucntions
// // ----------------------------------------------------------
inline f32 dot(vec4 a, vec4 b)
{
    f32 result = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    return result;
}

inline f32 lengthSquared(vec4 a)
{

    f32 result = dot(a, a);
    return result;
}

inline f32 length(vec4 a)
{
    return std::sqrt(lengthSquared(a));
}
    
// inline bool32 isZero(vec3 a)
// {
//     bool32 result = a.x == 0 && a.y == 0 && a.z == 0;
//     return result;
// }

inline vec4 normalize(vec4 a)
{
    vec4 result = a / (length(a));
    return result;
}

inline void normalized(vec4& a)
{
    a /= (length(a));
}

#endif
