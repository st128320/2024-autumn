#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	int k = n;
	int d = m;
	while (m != 0) {
		int temp = m;
		m= n % m;
		n= temp;
	}
	if (k == d)
		printf("1");
	else if (k % d == 0)
		printf("%d", k / d);
	else
		printf("%d", k / n);
	return 0;
}