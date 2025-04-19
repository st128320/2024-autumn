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
void dfs(AdjencyList& g, int v, int* visited,int color,bool& hastwo)
{
    visited[v] = color;
    for (int i = 0; i < g.sizes[v]; ++i)
    {
        int to = g.adjencies[v][i];
        if (visited[to] ==0)
        {
            dfs(g, to, visited,3-color,hastwo);
        }
        else if (visited[to] == color)
        {
            hastwo = false;
        }
    }

}

int main(int argc, char* argv)
{
   
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int* visited = new int[n] {0};
    AdjencyList g(n);
    int v = 0;
    int u = 0;
    bool hastwo = true;
    for (int i = 0; i < k; ++i)
    {
        std::cin >> u >> v;
        v = v - 1;
        u = u -1;
        g.addUndirectedEdge(u, v);
    }
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0)
        {
            dfs(g, i, visited, 1, hastwo);
        }
    }
    if (hastwo)
    {
        std::cout << "YES";
        return 0;
    } 
    std::cout << "NO";
    delete[] visited;
    return 0;
}