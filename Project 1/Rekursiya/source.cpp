#include <iostream>
#include <string>
using namespace std;

bool Can(int s)
{
	if (s < 1)
	{
		return false;
	}
	if (s == 1)
	{
		return true;
	}
	if (s > 1)
	{
		return(Can(s - 5) || Can(s - 3));
	}
}
int Max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int Maxn(string str, int max = -1, int index = 0)
{
	if (str.length() <= index)
	{
		return max;
	}
	max = Max(max, str[index] - '0');
	return Maxn(str, max, index + 1);
} 
int Count(string str, int index=0)
{   
	if (str[index] == '\0')
	{
		return 0;
	}
	int count = (int)('\0' <= str[index] && str[index] <= '\9');
	return count + Count(str, index + 1);
}
void Stars(string str, int index = 0)
{
	if (index==str.length() - 1)
	{
		std::cout << str[index];
		return;
	}
	std::cout << str[index];
	std::cout << "*";
	Stars(str, index + 1);
}
void Skobki(string str, int index = 0)
{
	std::cout << str[index];
	if ( (index+1)*2<str.length())
	{
		std::cout << "(";
	    Skobki(str, index + 1);
		std::cout << ")";
	}
	if (index * 2 + 1 != str.length())
	{
		cout << str[str.length() - 1 - index];
	}
	
}
void Mirror(string str, int index = 0)
{
	if (str[index] == '\0')
	{
		return;
	}
	cout << str[index];
	Mirror(str, index + 1);
	cout << (str[index] == '(' ? ')' : str[index]);

}
void Reduction(string str, int index = 0)
{   
	if (index  >= str.length()/2)
	{
		if (index * 2 + 1 == str.length())
		{
			std::cout << str[index];
	    }
		
		return;
	}
	if (str[index] != str[str.length() - index - 1])
	{
		std::cout << str[index];
	}
	Reduction(str, index + 1);
	if (str[index] != str[str.length() - index - 1])
	{
		std::cout << str[str.length() - index - 1];
	}
}
int Nod(int a, int b)
{
	
	if (a % b == 0)
	{
		return b;
	}
	if (b % a == 0)
	{
		return a;
	}
	if (a > b)
	{
		return Nod(a - b, b);
	}
	if (a < b)
	{
		return Nod(b-a, a);
	}
}
int CountSquare(char a[12][12],int n,int x, int y)
{
	int count = 0;
	a[x][y] = '*';
	count = 1;
	if (x+1 <= n && a[x+1][y] == '.')
	{
		count+=CountSquare(a, n, x + 1, y);
	}
	if (y + 1 <= n && a[x][y + 1] == '.')
	{
		count+=CountSquare(a, n, x, y+1);
	}
	if (x - 1 <= n && x>=1 && a[x-1][y] == '.')
	{
		count += CountSquare(a, n, x - 1, y);
	}
	if (y-1<=n && y>=1 && a[x][y - 1] == '.')
	{
		count += CountSquare(a, n,x, y-1);
	}
	return count;
}
bool isfull(int a[11], int n)
{
	for (int i =1; i <= n; ++i)
	{
		if (a[i] == 0)
		{
			return false;
		}
	}
	return true;
}
int getfirst(int a[11], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == 1)
		{
			return i;
		}
	}
	return -1;
}
void chip(int a[11],int n,bool first=true)
{   
	if (isfull(a, n))
	{
		return;
	}
	int index = 1;
	if (!first)
	{
		index = getfirst(a, n) + 1;
	}
	if (a[index] == 0)
	{
		std::cout << index << " ";
		a[index] = 1;
	}
	else
	{
		std::cout << -index << " ";
		a[index] = 0;
	}
	chip(a, n, !first);
}
void print(int a[10][10], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << a[i][j] <<" ";
		}
		std::cout << endl;
	}
}
void fill(int a[10][10], int n,int circle = 0, int c=1)
{
	if (circle * 2 >= n)
	{
		if (n % 2 == 1)
		{
			a[circle-1][circle-1 ] = c;
		}
		return;
	}
	for (int i = circle; i < n-1-circle; ++i, ++c)
	{
		a[circle][i] = c;
	}
	for (int i = circle; i < n-1 - circle; ++i, ++c)
	{
		a[i][n - 1 - circle] = c;
	}
	for (int i = n-1-circle; i > circle; --i, ++c)
	{
		a[n - 1 - circle][i] = c;
	}
	for (int i = n-1-circle; i >  circle; --i, ++c)
	{
		a[i][circle] = c;
	}
	fill(a, n, circle+1, c);
}
bool cube(int n,int c=8)
{
	if (n == 0)
	{
		return true;
	}
	if (n < 0)
	{
		return false;
	}
	if (c < 0)
	{
		return false;
	}
	int i = 0;
	while (i * i * i < n)
	{
		++i;
	}
	for (; i > 0; --i)
	{   
		if (cube(n - i * i * i, c - 1))
		{
			cout << i << " ";
			return true;
		}
	}
}
int main(int argc, char* argv[])
{   
}