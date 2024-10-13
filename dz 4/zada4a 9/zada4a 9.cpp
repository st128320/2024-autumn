#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int a[100]{};
	scanf_s("%d", &n);
	int c = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	int k = 0;
	scanf_s("%d", &k);
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < k)
		{
			c = i + 1;
			break;
		}
		if (c == 0)
			c = n + 1;

	}
	printf("%d", c);
	return 0;
}