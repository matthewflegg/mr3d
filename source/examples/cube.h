#ifndef ENGINE_H
#define ENGINE_H

#include <math.h>
#include "../include/olcConsoleGameEngine.h"
#include "../utils/mesh.h"
#include "../utils/vector4.h"

/**
 * @brief A basic test cube. 
 * 
 */
struct Cube
{
    Mesh mesh;

    // Rotation bias prevents the cube from spinning on 1 axis.
    float rotation;
    float rotationBiasZ;
    float zTranslation;
};

// This defines the triangles that will make up our cube mesh.
std::vector<Triangle> triangles = {
    { 0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f },
    { 1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 1.0f,  1.0f, 0.0f, 1.0f },
    { 1.0f, 0.0f, 1.0f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f },
    { 1.0f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 0.0f },
    { 0.0f, 0.0f, 1.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f },
    { 0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f,  0.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f }
};

/**
 * @brief Create a basic projection matrix.
 * 
 */
Matrix4 CreateProjection(float zNear, float zFar, float fov, float aspectRatio);

/**
 * @brief Get a rotation matrix for the cube.
 * 
 * Rotates by rotation around the X and Z axis. Adds rotationBias to the
 * Z rotation.
 * 
 */
Matrix4 GetCubeRotationMatrix(float rotation, float rotationBias);

/**
 * @brief A test engine using javidx9's console game engine.
 * 
 */
class Engine : public olcConsoleGameEngine
{
private:
    Cube cube;
    Matrix4 projection;

public:
    Engine();
    
    /**
     * @brief Called when the engine loads.
     * 
     */
    bool OnUserCreate() override;

    /**
     * @brief Called on each frame update.
     * 
     */
    bool OnUserUpdate(float fElapsedTime) override;
};

#endif