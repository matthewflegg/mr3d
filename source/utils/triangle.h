#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector4.h"

/**
 * @brief A 2D triangle in 3D space.
 * 
 * Triangle points must be passed in a clockwise
 * or anticlockwise order ONLY.
 * 
 */
class Triangle
{
private:
    Vector4 points[3];

public:
    Triangle();

    /**
     * @brief Create a triangle using vectors.
     * 
     */
    Triangle(Vector4 a, Vector4 b, Vector4 c);

    /**
     * @brief Create a triangle without vectors.
     * 
     */
    Triangle(
        float x0, float y0, float z0,
        float x1, float y1, float z1,
        float x2, float y2, float z2
    );

    /**
     * @brief Apply a transformation matrix to the triangle.
     *  
     */
    void Transform(Matrix4 mat);

    Vector4 operator()(int i) const;

    Vector4& operator()(int i);
};

#endif