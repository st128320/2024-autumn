#include <iostream>


int main(int argc, char* argv[])
{
	int N = 0;
	int a = 0;
	int b = 0;
	scanf_s("%d", &N);
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	printf("%d", N * a * b * 2);
	return EXIT_SUCCESS;
}
