#ifndef VEC3_H
#define VEC3_H

// 
// replace sqrt with instrinsics eventually
#include <iostream>
#include <cmath>

typedef float f32;
typedef int bool32;

const f32 pi = 3.14159265359f;
const f32 tau = 2.0f * pi;

// vec3:
// ===========================================================
union vec3
{
    struct
    {
	f32 x, y, z;
    };
    struct
    {
	f32 r, g, b;
    };

    f32 e[3];

    // -----------------------
    vec3(){};
    
    vec3(float d)
	: e{d, d, d}
    {
    }
    
    vec3(f32 a, f32 b, f32 c)
	: x(a), y(b), z(c)
    {
    }
};

// operator overloads
// ----------------------------------------------------------
// negation
inline vec3 operator-(vec3 a)
{
    vec3 result = {};
    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
    return result;
}

// addition
inline vec3 operator+(vec3 a, vec3 b)
{
    vec3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

inline vec3 operator+=(vec3& a, vec3 b)
{
    a = a + b;
    return a;
}

// subtraction
inline vec3 operator-(vec3 a, vec3 b)
{
    vec3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

inline vec3 operator-=(vec3& a, vec3 b)
{
    a = a - b;
    return a;
}

// multiplication
inline vec3 operator*(f32 a, vec3 b)
{
    vec3 result = { a * b.x, a * b.y, a * b.z };
    return result; 
}

inline vec3 operator*(vec3 b, f32 a)
{
    vec3 result = a * b;
    return result;
}

inline vec3 operator*=(vec3& a, f32 b)
{
    a = b * a;
    return a;
}

// division
inline vec3 operator/(f32 a, vec3 b)
{
    vec3 result = {
	(1.0f / a) * b.x,
	(1.0f / a) * b.y,
	(1.0f / a) * b.z };
    return result; 
}

inline vec3 operator/(vec3 b, f32 a)
{
    vec3 result = a / b;
    return result;
}

// // utility fucntions
// // ----------------------------------------------------------
inline f32 dot(vec3 a, vec3 b)
{
    f32 result = a.x * b.x + a.y * b.y + a.z * b.z;
    return result;
}

inline f32 lengthSquared(vec3 a)
{

    f32 result = dot(a, a);
    return result;
}

inline f32 length(vec3 a)
{
    return std::sqrt(lengthSquared(a));
}
    
// inline bool32 isZero(vec3 a)
// {
//     bool32 result = a.x == 0 && a.y == 0 && a.z == 0;
//     return result;
// }

inline vec3 normalize(vec3 a)
{
    vec3 result = a / (length(a));
    return result;
}

inline void normalized(vec3& a)
{
    a /= (length(a));
}

inline vec3 cross(const vec3& u, const vec3& v)
{
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}


#endif
