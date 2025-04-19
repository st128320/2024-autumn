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

        for (int i = 0; i < verts; ++i) {
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
    int k = 0;
    int n = 0;
    std::cin >> n >> k;
    AdjencyList g(n);
    int u = -1;
    int v = 0;
    int* visited = new int[n] {0};
    while (true)
    {   
        std::cin >> u;
        u = u - 1;
        if (u == -1)
        {
            break;
        }
        std::cin >> v;
        v = v - 1;
        g.addEdge(u, v);
    }
    dfs(g, k - 1, visited);
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0)
        {
            std::cout << "No";
            return 0;
        }
    }
    std::cout << "Yes";
    delete[] visited;
    return 0;
}