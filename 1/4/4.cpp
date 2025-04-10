#include <iostream>
void hanoi(int height, int from, int to)
{
	int reserve = 6-from-to;
	if (height == 1)
	{
		printf("%d %d %d\n", 1, from, to);
		return;
	}
	hanoi(height - 1, from, to);
	printf("%d %d %d\n", height, from, reserve);
	hanoi(height - 1, to, from);
	printf("%d %d %d\n", height, reserve, to);
	hanoi(height - 1, from, to);
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);
}