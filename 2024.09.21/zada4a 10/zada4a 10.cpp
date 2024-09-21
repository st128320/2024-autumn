#include <iostream>

int main(int argt, char* argv[])
{
	int s = 0;
	scanf_s("%d", &s);
	printf("%d %d %d", s / 6, (s / 3) * 2, s / 6);
	return EXIT_SUCCESS;
}
