#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int a[100]{ 0 };
	std::cin >> n;
	int symma = 0;
	int proizv = 1;
	int nmax = 0;
	int nmin = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}
	int max = *(a);
	int min = *(a);
	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > 0)
		{
			symma += *(a + i);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (max < *(a + i))
		{
			max = *(a + i);
			nmax = i;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (min > *(a + i))
		{
			min = *(a + i);
			nmin = i;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (nmin < nmax)
		{
			if (i > nmin and i < nmax)
			{
				proizv *= *(a + i);
			}
	    }
		else if (nmax < nmin) 
		{
			if (i < nmin and i > nmax)
			{
				proizv *= *(a + i);
			}
		}
		
	}
	std::cout << symma << " ";
	std::cout << proizv << " ";
	return 0;
}