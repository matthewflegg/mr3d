#ifndef MATRIX4_H
#define MATRIX4_H

#include <algorithm>
#include "operators.h"

/**
 * @brief A 4x4 matrix of floats.
 * 
 */
class Matrix4
{
private:
    float values[4][4] = { 0 };

    /**
     * @brief Apply a matrix-matrix operation.
     * 
     */
    void Apply(float (*func)(float, float), Matrix4 mat);

    /**
     * @brief Apply a matrix-scalar operation.
     * 
     */
    void Apply(float (*func)(float, float), float scalar);

public:
    Matrix4();

    Matrix4(float aValues[4][4]);

    /**
     * @brief Get the value at a coordinate.
     * 
     */
    float Matrix4::GetValue(int row, int col)
    {
        return values[row][col];
    }

    /**
     * @brief Set the value at a coordinate.
     * 
     */
    void Matrix4::SetValue(int row, int col, float value)
    {
        values[row][col] = value;
    }

    /*
        I can NOT be fucked to write comments for
        all of these.
    */

    Matrix4 operator+(Matrix4 mat);

    Matrix4 operator-(Matrix4 mat);

    Matrix4 operator*(Matrix4 mat);

    Matrix4 operator/(Matrix4 mat);

    Matrix4 operator+(float s);

    Matrix4 operator-(float s);

    Matrix4 operator*(float s);

    Matrix4 operator/(float s);

    /**
     * @brief Returns a matrix with all values set to zero.
     * 
     */
    static Matrix4 Zero();

    /**
     * @brief Returns a matrix with all values set to one.
     * 
     */
    static Matrix4 One();
};

#endif