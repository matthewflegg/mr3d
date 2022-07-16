#include "cube.h"

Matrix4 CreateProjection(float zNear, float zFar, float fov, float aspectRatio)
{
    float fovRadius = 1.0f / tanf(fov * 0.5f / 180.0f * 3.14159f);
    float planeDist = zFar - zNear;

    Matrix4 projection;

    projection.SetValue(0, 0, aspectRatio * fovRadius);
    projection.SetValue(1, 1, fovRadius);
    projection.SetValue(2, 2, zFar / planeDist);
    projection.SetValue(3, 2, -zFar * zNear / planeDist);
    projection.SetValue(2, 3, 1.0f);
    projection.SetValue(3, 3, 0.0f);

    return projection;
}

Matrix4 GetCubeRotationMatrix(float rotation, float rotationBias)
{
    // Calculate the Z rotation matrix.
    Matrix4 rotationZ;
    rotationZ.SetValue(0, 0, cosf(rotation + rotationBias));
    rotationZ.SetValue(0, 1, sinf(rotation + rotationBias));
    rotationZ.SetValue(1, 0, -sinf(rotation + rotationBias));
    rotationZ.SetValue(0, 0, cosf(rotation + rotationBias));
    rotationZ.SetValue(0, 0, 1);
    rotationZ.SetValue(0, 0, 1);

    // Calculate the X rotation matrix.
    Matrix4 rotationX;
    rotationX.SetValue(1, 1, 1);
    rotationX.SetValue(1, 1, cosf(rotation));
    rotationX.SetValue(1, 2, sinf(rotation));
    rotationX.SetValue(2, 1, -sinf(rotation));
    rotationX.SetValue(2, 2, cosf(rotation));
    rotationX.SetValue(3, 3, 1);

    return rotationZ * rotationX;
}

Engine::Engine()
{
    m_sAppName = L"3D Cubes!";
}

bool Engine::OnUserCreate()
{
    // Create a cube.
    cube.mesh = Mesh(triangles);
    cube.rotation = 0;
    cube.rotationBiasZ = 0.6f;

    // Create the projection matrix.
    float zNear = 0.1f;
    float zFar = 1000.0f;
    float fov = 90.0f;
    float aspectRatio = (float)ScreenHeight() / (float)ScreenWidth();

    projection = CreateProjection(zNear, zFar, fov, aspectRatio);
}

bool Engine::OnUserUpdate(float fElapsedTime)
{
    Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);

    // Update the cube's rotation and translation matrices.
    cube.rotation += fElapsedTime;

    auto cubeRotation = GetCubeRotationMatrix(cube.rotation, cube.rotationBiasZ);    
    auto cubeTranslation = Matrix4();

    cubeTranslation.SetValue(2, 3, cube.zTranslation);

    for (auto triangle : cube.mesh.GetTriangles()) {
        triangle.Transform(cubeRotation * cubeTranslation * projection);
    }
}