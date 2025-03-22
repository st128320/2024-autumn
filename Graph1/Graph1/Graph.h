#include<iostream>

struct Matrix
{
    int verts;
    int** data;
    Matrix() : verts(0), data(nullptr) {}
    void free()
    {
        if (data != nullptr)
        {
            for (int i = 0; i < verts; ++i)
            {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }
    void init(int verts)
    {
        if (data != nullptr)
        {
            free();
        }
        this->verts = verts;
        data = new int* [verts + 1] { 0 };
        for (int i = 0; i < verts + 1; ++i)
        {
            data[i] = new int[verts + 1] { 0 };
        }
    }
    int edgesFrom(int i)
    {
        int count = 0;
        for (int j = 1; j <= verts; ++j)
        {
            count += (data[i][j] == 0 ? 0 : 1);
        }
        return count;
    }
    int edges()
    {
        int count = 0;
        for (int i = 1; i <= verts; ++i)
        {
            count += edgesFrom(i);
        }
        return count;
    }
    int count(int i)
    {
        int count = 0;
        for (int j = 1; j <= verts; ++j)
        {
            if (data[i][j] != 0)
                ++count;
        }
        return count;

    }
    int CountDrains()
    {
        int count = 0;
        int c = 0;
        for (int i = 1; i <= verts; ++i)
        {
            for (int j = 1; j <= verts; ++j)
            {
                if (data[i][j] == 0)
                {
                    ++c;
                }
            }
            if (c == verts)
            {
                ++count;
            }
            c = 0;

        }
        return count;
    }

    int CountOrigins()
    {
        int count = 0;
        int c = 0;
        for (int i = 1; i <= verts; ++i)
        {
            for (int j = 1; j <= verts; ++j)
            {
                if (data[j][i] == 0)
                {
                    ++c;
                }
            }
            if (c == verts)
            {
                ++count;
            }
            c = 0;
        }
        return count;
    }

};

struct Edge
{   
    int from;
    int to;
};

struct EdgeList
{
    int count;
    Edge* edges;
};

struct AdjencyList
{
    int verts;
    int** adjencies;
};

class Graph
{
private:
    Matrix m;

public:
    Graph();
    Graph(const Graph& graph);
    ~Graph();
    int investigation();
    int Tournament();
    void DrainsAndOrigins();
    int Full();
    int Oriented();
    int Regular();
    void DegreesOfVertices();
    void readMatrix();
    void readAdjencyList();
    void readEdgeList();
    void printMatrix();
    void printAdjencyList();
    void printEdgeList();
};