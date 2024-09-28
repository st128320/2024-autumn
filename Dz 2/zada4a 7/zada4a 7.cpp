
#include <iostream>

int main(int argc, char* argv[])
{
	int k = 0;
	int m = 0;
	int n = 0;
	scanf_s("%d", &k);
	scanf_s("%d", &m);
	scanf_s("%d", &n);
	if (n > k) {
		printf("%d", (((2 * n + k - 1) / k) * m));
	}
	else {
		printf("%d", 2*m);
	}
		return 0;
}