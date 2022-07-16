#include "mesh.h"

Mesh::Mesh()
{
}

Mesh::Mesh(std::vector<Triangle> aTriangles)
{
    Add(aTriangles);
}

void Mesh::Add(std::vector<Triangle> aTriangles)
{
    for (const auto& t : aTriangles)
        Add(t);
}

void Mesh::Add(Triangle t)
{
    triangles.push_back(t);
}

std::vector<Triangle> Mesh::GetTriangles()
{
    return triangles;
}