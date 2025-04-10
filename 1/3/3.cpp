#include <iostream>
void hanoi(int height, int from, int to)
{
	int reserve = 6 - from - to;
	if (height == 0)
	{
		return;
	}
	if ((from == 1 && to == 2) ||
		(from == 2 && to == 3) ||
		(from == 3 && to == 1) )
	{
		hanoi(height - 1, from, reserve);
	    printf("%d %d %d\n", height, from, to);
		hanoi(height - 1, reserve, to);
	}
	else
	{
		hanoi(height - 1, from, to);
		printf("%d %d %d\n", height, from, reserve);
		hanoi(height - 1, to, from);
		printf("%d %d %d\n", height, reserve,to);
		hanoi(height - 1, from, to);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);
}