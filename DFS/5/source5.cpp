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
void dfs1(AdjencyList& g, int v, int* visited, int c)
{
    visited[v] = c;
    for (int i = 0; i < g.sizes[v]; ++i)
    {
        int to = g.adjencies[v][i];
        if (visited[to] == -1)
        {
            dfs1(g, to, visited, c);
        }
    }

}
void dfs(AdjencyList& g, int v, int* visited, int c)
{
    visited[v] = c;
    for (int i = 0; i < g.sizes[v]; ++i)
    {
        int to = g.adjencies[v][i];
        if (visited[to] == 0)
        {
            dfs(g, to, visited, c);
        }
    }

}

int main(int argc, char* argv[]) // не оптимально по времени (на 17 тесте Time limit exceeded)
{
    int n = 0;
    int k = 0;
    int u = 0;
    int v = 0;
    std::cin >> n >> k;
    AdjencyList g(n);
    for (int i = 0; i < k; ++i)
    {
        std::cin >> u >> v;
        u = u - 1;
        v = v - 1;
        g.addUndirectedEdge(u, v);
    }
    int count = 0;
    int c = 1;
    int* visited = new int[n] {0};
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0)
        {
            dfs(g, i, visited, c);
            ++c;
        }
    }
    std::cout << c - 1 << "\n";
    int l = c - 1;
    c = 1;

    for (int i = 0; i < l; ++i)
    {

        for (int i = 0; i < n; ++i)
        {
            if (visited[i] == c)
            {
                ++count;
            }

        }
        std::cout << count << "\n";
        for (int i = 0; i < n; ++i)
        {
            if (visited[i] == c)
            {
                std::cout << i + 1 << " ";

            }

        }
        c = c + 1;
        count = 0;
        std::cout << "\n";
    }
    delete[] visited;
    return 0;
}