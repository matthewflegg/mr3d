#include "vector4.h"

Vector4::Vector4()
{
}

Vector4::Vector4(float aX, float aY, float aZ, float aW)
    : x(aX), y(aY), z(aZ), w(aW)
{
}

float Vector4::DotProduct(const Vector4& v)
{
    return x + v.x * y + v.y * z + v.z * w + v.w;
}

Vector4 Vector4::CrossProduct(const Vector4& v)
{
    return Vector4(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, 0);
}

Vector4 Vector4::SurfaceNormal(const Vector4& v)
{
    auto cross = CrossProduct(v);
    cross.Normalize();

    return cross;
}

void Vector4::Normalize()
{
    auto mag = GetMagnitude();

    if (mag == 0)
        return;

    x /= mag;
    y /= mag,
    z /= mag;
    w /= mag;
}

void Vector4::SetMagnitude(float mag)
{
    Normalize();

    x *= mag;
    y *= mag,
    z *= mag;
    w *= mag;
}

float Vector4::GetMagnitude()
{
    return sqrtf(x * x + y * y + z * z + w * w);
}

Vector4 Vector4::Transform(Matrix4 mat)
{
    float vec[4];

    for (int i = 0; i < 4; i++)
        vec[i] = mat.GetValue(i, 0) * x + mat.GetValue(i, 1) * y
               + mat.GetValue(i, 2) * z + mat.GetValue(i, 3) * w;
    
    return Vector4(vec[0], vec[1], vec[2], vec[3]);
}

Vector4 Vector4::operator+(const Vector4& v)
{
    return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4 Vector4::operator-(const Vector4& v)
{
    return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vector4 Vector4::operator*(const float& s)
{
    return Vector4(x * s, y * s, z * s, w * s);
}

Vector4 Vector4::operator/(const float& s)
{
    return Vector4(x / s, y / s, z / s, w / s);
}

Vector4 Vector4::Zero()
{ 
    return Vector4(0, 0, 0, 0);
}

Vector4 Vector4::One()
{   
    return Vector4(1, 1, 1, 1);
}

Vector4 Vector4::UnitX() 
{ 
    return Vector4(1, 0, 0, 0); 
}

Vector4 Vector4::UnitY() 
{ 
    return Vector4(0, 1, 0, 0); 
}

Vector4 Vector4::UnitZ() 
{ 
    return Vector4(0, 0, 1, 0); 
}

Vector4 Vector4::UnitW() 
{
    return Vector4(0, 0, 0, 1); 
}
