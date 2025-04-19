#include <iostream>

struct AdjencyList
{
    int verts;
    int** adjencies;
    int* sizes;
    AdjencyList(int v = 0) : verts(v)
    {
        adjencies = new int* [verts];
        sizes = new int[verts];

        for (int i =0; i < verts; ++i) {
            adjencies[i] = nullptr;
            sizes[i] = 0;
        }
    }
    ~AdjencyList()
    {
        for (int i = 0; i < verts; ++i) {
            delete[] adjencies[i];
        }
        delete[] adjencies;
        delete[] sizes;
    }
    void addEdge(int u, int v)
    {

        int* newList = new int[sizes[u] + 1];
        for (int i = 0; i < sizes[u]; ++i)
        {
            newList[i] = adjencies[u][i];
        }
        newList[sizes[u]] = v;
        delete[] adjencies[u];
        adjencies[u] = newList;
        sizes[u]++;
    }
    void addUndirectedEdge(int u, int v) {
        addEdge(u, v);
        addEdge(v, u);
    }
    void print()
    {
        for (int i = 0; i < verts; ++i) {
            std::cout << i << ": ";
            for (int j = 0; j < sizes[i]; ++j) {
                std::cout << adjencies[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

};
void dfs(AdjencyList& g, int v, int* visited)
{
    visited[v] = 1;
    for (int i = 0; i < g.sizes[v]; ++i)
    {
        int to = g.adjencies[v][i];
        if (visited[to] != 1)
        {
            dfs(g, to, visited);
        }
    }

}

int main(int argc, char* argv[])
{
  
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    AdjencyList g(n);
    int* visited = new int[n] {0};
    int** l = new int* [n] { 0 };
    for (int i = 0; i < n; ++i)
    {
        l[i] = new int[n] { 0 };
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> l[i][j];
            if (l[i][j] == 1)
            {
                g.addUndirectedEdge(i, j);
            }
        }
    }
    dfs(g, k-1, visited);
    int count=-1;
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] != 0)
        {
            ++count;
        }
    }
    std::cout << count;
    for (int i = 0; i < n; ++i)
    {
        delete[] l[i];
    }
    delete[] l;
    delete[] visited;
    return 0;
}