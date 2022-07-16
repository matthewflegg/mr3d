#ifndef MESH_H
#define MESH_H

#include <vector>
#include "triangle.h"

/**
 * @brief A group of triangles that make up a shape.
 * 
 */
class Mesh
{
private:
    std::vector<Triangle> triangles;

public:
    Mesh();

    Mesh(std::vector<Triangle> triangles);

    /**
     * @brief Add multiple triangles to the mesh.
     * 
     */
    void Add(std::vector<Triangle> triangles);

    /**
     * @brief Add one triangle to the mesh.
     * 
     */
    void Add(Triangle t);

    /**
     * @brief Returns the triangles in the mesh.
     * 
     */
    std::vector<Triangle> GetTriangles();
};

#endif