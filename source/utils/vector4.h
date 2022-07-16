#ifndef VECTOR4_H
#define VECTOR4_H

#include <math.h>
#include "matrix4.h"

/**
 * @brief A 4D vector of floats.
 * 
 */
class Vector4
{
public:
    float x;
    float y;
    float z;
    float w;

    Vector4();

    Vector4(float aX, float aY, float aZ, float aW);

    /**
     * @brief Returns the scalar product of vectors.
     * 
     */
    float DotProduct(const Vector4& v);

    /**
     * @brief Returns the vector product of vectors.
     * 
     * NOTE: This takes the TERNARY cross product. What is returned is the
     * cross product of both vectors converted to 3D, i.e., [x, y, z].
     * 
     */
    Vector4 CrossProduct(const Vector4& v);

    /**
     * @brief Returns a vector of length 1 that's perpendicular to two vectors.
     * 
     * NOTE: This returns the surface normal of the 2D plane bounded by both
     * vectors converted to 3D, i.e., their [x, y, z] components.
     */
    Vector4 SurfaceNormal(const Vector4& v);

    /**
     * @brief Sets the magnitude to 1.
     * 
     */
    void Normalize();

    void SetMagnitude(float mag);

    float GetMagnitude();

    /**
     * @brief Multiply the vector by a 4D transformation matrix.
     * 
     */
    Vector4 Transform(Matrix4 mat);

    Vector4 operator+(const Vector4& v);

    Vector4 operator-(const Vector4& v);

    Vector4 operator*(const float& s);

    Vector4 operator/(const float& s);

    /**
     * @brief Returns a vector with all values set to zero.
     * 
     */
    static Vector4 Zero();

    /**
     * @brief Returns a vector with all values set to one.
     * 
     */
    static Vector4 One();

    /**
     * @brief Returns the unit X vector.
     * 
     */
    static Vector4 UnitX();

    /**
     * @brief Returns the unit Y vector.
     * 
     */
    static Vector4 UnitY();

    /**
     * @brief Returns the unit Z vector.
     * 
     */
    static Vector4 UnitZ();

    /**
     * @brief Returns the unit W vector.
     * 
     */
    Vector4 Vector4::UnitW();
};

#endif