#include <iostream>

int main(int agrc, char* argv[])
{
	int a = 0;
	scanf_s("%d", &a);
	printf("%d", a / 100 + (a - (a / 100) * 100) / 10 + (a - (a / 100) * 100 - ((a - (a / 100) * 100) / 10) * 10));
	return EXIT_SUCCESS;
}
