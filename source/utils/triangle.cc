#include "triangle.h"

Triangle::Triangle()
{
}

Triangle::Triangle(Vector4 a, Vector4 b, Vector4 c)
{
    points[0] = a;
    points[1] = b;
    points[2] = c;
}

Triangle::Triangle(
    float x0, float y0, float z0,
    float x1, float y1, float z1,
    float x2, float y2, float z2)
{
    points[0] = Vector4(x0, y0, z0, 0);
    points[1] = Vector4(x1, y1, z1, 0);
    points[2] = Vector4(x2, y2, z2, 0);
}

void Triangle::Transform(Matrix4 mat)
{
    for (auto vec : points)
        vec.Transform(mat);
}

Vector4 Triangle::operator()(int i) const
{
    return points[i];
}

Vector4& Triangle::operator()(int i)
{
    return points[i];
}