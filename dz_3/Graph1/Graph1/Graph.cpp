#include "Graph.h"
Graph::Graph()
{
}
Graph::Graph(const Graph& graph)
{
	m.init(graph.m.verts);
	for (int i = 1; i <= m.verts; ++i)
	{
		for (int j = 1; j <= m.verts; ++j)
		{
			m.data[i][j] = graph.m.data[i][j];
		}
	}
}

Graph::~Graph()
{
	m.free();
}

void Graph::readMatrix()
{
	int verts = 0;
	std::cin >> verts;
	m.init(verts);
	for (int i = 1; i <= m.verts; ++i)
	{
		for (int j = 1; j <= m.verts; ++j)
		{
			std::cin >> m.data[i][j];
		}
	}
}

void Graph::readAdjencyList()
{
	int verts = 0;
	std::cin >> verts;
	m.init(verts);
	for (int from = 1; from <= m.verts; ++from)
	{
		int count = 0;
		std::cin >> count;
		for (int j = 0; j < count; ++j)
		{
			int to = 0;
			std::cin >> to;
			m.data[from][to] = 1;
		}
	}
}

void Graph::readEdgeList()
{
	int verts = 0;
	std::cin >> verts;
	m.init(verts);
	int edges = 0;
	std::cin >> edges;
	for (int i = 0; i < edges; ++i)
	{
		int a = 0;
		int b = 0;
		std::cin >> a >> b;
		m.data[a][b] = 1;
	}
}

void Graph::printMatrix()
{
	std::cout << m.verts << "\n";
	for (int i = 1; i <= m.verts; ++i)
	{
		for (int j = 1; j <= m.verts; ++j)
		{
			std::cout << m.data[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Graph::printAdjencyList()
{
	std::cout << m.verts << "\n";
	for (int i = 1; i <= m.verts; ++i)
	{
		std::cout << m.edgesFrom(i) << " ";
		for (int j = 1; j <= m.verts; ++j)
		{
			if (m.data[i][j] != 0)
			{
				std::cout << j << " ";
			}
		}
		std::cout << "\n";
	}
}

void Graph::printEdgeList()
{
	std::cout << m.verts << " " << m.edges() << "\n";
	for (int i = 1; i <= m.verts; ++i)
	{
		for (int j = 1; j <= m.verts; ++j)
		{
			if (m.data[i][j] != 0)
			{
				std::cout << i << " " << j << "\n";
			}
		}
	}
}
void Graph::DegreesOfVertices() //Степени вершин
{
	for (int i = 1; i <= m.verts; ++i)
	{
		int count = 0;
		for (int j = 1; j <= m.verts; ++j)
		{
			if (m.data[i][j] != 0)
				++count;
		}
		std::cout << count << " ";
	}
}     
int Graph::Regular()   //Регулярный граф
{   int count = 0;
	int c = -1;
	for (int i = 1; i < m.verts; ++i)
	{
		if (m.count(i) == m.count(i + 1))
		{
		  ++count;
		}
		
	}
	if (count == m.verts - 1)
	{
		c = 1;
	}
	else
	{
		c = 0;
	}
	return c;
}
int Graph::Oriented() // Ориентированный граф
{
	int count = 0;
	int s = 0;
	int c = 0;
	for (int i = 1; i <= m.verts; ++i)
	{
		for (int j = 1; j <= m.verts; ++j)
		{
			if ( m.data[i][j]==1  &&  m.data[i][j] == m.data[j][i])
			{    
				++count;
			}
			if (m.data[i][i] != 0)
			{
				++s;
			}
			
		}
	}
	if (count-s == m.edges() and s==0)
	{
		c = 1;
	}
	else if (s!=0)
	{
		c = 1;
	}
	else
	{
		c = 0;
	}
	return c;
}
int Graph::Full()   //Полный граф
{
	int count = 0;
	int c = 0;
	for (int i = 1; i <= m.verts; ++i)
	{
		for (int j = 1; j <= m.verts; ++j)
		{
			if (m.data[i][j] != 0)
			{
				m.data[j][i] = 1;
			}
		}
	}
	for (int i = 1; i <= m.verts; ++i)
	{
		for (int j = 1; j <= m.verts; ++j)
		{
			if (m.data[i][j] != 0 )
			{
				++c;
			}
		}
	
	}
	std::cout << c;
	if (c==m.verts*(m.verts-1))
	{
		c = 1;
	}
	else
	{
		c = 0;
	}
	return c;
}
void Graph::DrainsAndOrigins() //истоки и стоки
{   
	std::cout << m.CountOrigins() << " ";
	for (int  i = 1; i <= m.verts; ++i)
	{
		int count = 0;
		for (int j = 1; j <= m.verts; ++j)
		{
			if (m.data[j][i]!= 0)
			{
				++count;
			}
		}
		if (count == 0)
		{
			std::cout<<i<<" ";
		}
	}
	std::cout << "\n"<<m.CountDrains()<< " ";
	for (int i = 1; i <= m.verts; ++i)
	{
		int count1 = 0;
		for (int j = 1; j <= m.verts; ++j)
		{
			if (m.data[i][j] != 0)
			{
				++count1;
			}
		}
		if (count1 == 0)
		{
			std::cout << i<< " ";
		}
		
	}   
}
int Graph::Tournament() //турнир (на 24 тесте ломается)
{
	int count = 0;
	int c = 0;
	int s = 0;
	for (int i = 1; i <= m.verts; ++i)
	{
		for (int j = 1; j <= m.verts; ++j)
		{
			if (m.data[i][j] == m.data[j][i] && m.data[i][j] != 0)
			{
				++count;
			}


		}

	}
	if (count == 0 && m.edges() == (m.verts * (m.verts - 1)) / 2)
	{
		c = 1;
	}
	else
	{
		c = 0;
	}
	return c;
}
int Graph::investigation()
{  
	int k = 0;
	std::cin >> k;
	m.init(k);
	int p1 = 0;
	int p2 = 0;
	int* a = new int[k + 1] { 0 };
	std::cin >> p1 >> p2;
	for (int i = 1; i < k; ++i)
	{
		std::cin >> a[i];
		if (a[i] > i)
		{
			return 0;
		}
	}
	for (int i = 1; i < k; ++i)
	{
		for (int j = i; j < k; ++j)
		{
			if (j + 1 < k)
			{
				m.data[a[i]][a[j + 1]] = 1;
			}
		}

	}
	delete[]a;
	return 0;
}

