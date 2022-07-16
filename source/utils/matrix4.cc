#include "matrix4.h"

Matrix4::Matrix4()
{
}

Matrix4::Matrix4(float aValues[4][4])
{
    std::copy(&aValues[0][0], &aValues[0][0] + 4 * 4, &values[0][0]);  // Copy.
}

void Matrix4::Apply(float (*func)(float, float), Matrix4 mat)
{
    int i, j;

    for (int n = 0; n < 16; ++n) {
        j = n % 4;
        i = n / 4;

        values[j][i] = func(values[j][i], mat.GetValue(j, i));
    }
}

void Matrix4::Apply(float (*func)(float, float), float scalar)
{
    int i, j;

    for (int n = 0; n < 16; ++n) {
        j = n % 4;
        i = n / 4;

        values[j][i] = func(values[j][i], scalar);
    }
}

float Matrix4::GetValue(int row, int col)
{
    return values[row][col];
}

void Matrix4::SetValue(int row, int col, float value)
{
    values[row][col] = value;
}

Matrix4 Matrix4::operator+(Matrix4 mat)
{
    Apply(Add, mat);
}

Matrix4 Matrix4::operator-(Matrix4 mat)
{
    Apply(Subtract, mat);
}

Matrix4 Matrix4::operator*(Matrix4 mat)
{
    Apply(Multiply, mat);
}

Matrix4 Matrix4::operator/(Matrix4 mat)
{
    Apply(Divide, mat);
}

Matrix4 Matrix4::operator+(float s)
{
    Apply(Add, s);
}

Matrix4 Matrix4::operator-(float s)
{
    Apply(Subtract, s);
}

Matrix4 Matrix4::operator*(float s)
{
    Apply(Multiply, s);
}

Matrix4 Matrix4::operator/(float s)
{
    Apply(Divide, s);
}

Matrix4 Matrix4::Zero()
{
    float zeroes[4][4] = { 0 };
    return Matrix4(zeroes);
}

Matrix4 Matrix4::One()
{
    float ones[4][4] = { 1 };
    return Matrix4(ones);
}

