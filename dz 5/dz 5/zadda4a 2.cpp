#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int a[100]{ 0 };
	std::cin >> n;
	int c = 0;
	int d = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}
	for (int i = 0; i < n; ++i)
	{
		if ( *(a + i) % 2 != 0)
		{
			++d;
			std::cout << *(a + i) << " ";
		}
	}
	std::cout << "\n";
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) % 2 == 0)
		{
			++c;
			std::cout << *(a + i) << " ";
		}
	
	}   
	std::cout << "\n";
	if (d<=c)
		std::cout <<"YES ";
	else 
		std::cout << "NO ";
	return 0;
}

