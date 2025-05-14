#include <iostream>
#include <queue>
struct Node
{
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) :data(data), next(next)
    {
    }
    ~Node()
    {
        data = 0;
        next = nullptr;
    }
};
struct AdjencyList
{
    int verts;
    int** adjencies;
    int* sizes;
    AdjencyList(int v=0) : verts(v)
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
        delete[] newList;
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
int* bfs(AdjencyList& g, int start)
{
    int CONST = 1e9;
    int* visited = new int[g.verts]();
    int* dist = new int[g.verts];
    for (int i = 0; i < g.verts; ++i)
    {
        dist[i] = CONST;
    }
    std::queue<int> q;
    visited[start] = 1;
    dist[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g.sizes[v]; ++i)
        {
            int to = g.adjencies[v][i];
            if (visited[to]!=1)
            {
                visited[to] = 1;
                dist[to] = dist[v] + 1;
                q.push(to);
                
            }
        }
        
     }
    delete[] visited;
    return dist;

}


