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
int main(int argc, char* argv[])
{
	string str;
	cin >> str;
	Mirror(str);

}