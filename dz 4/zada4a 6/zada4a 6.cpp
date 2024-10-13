#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	scanf_s("%d", &n);
	float max = -1;
	int c = 0;
	int a[154]{};
	float b[100]{};
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%f", &b[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		float g = a[i] * b[i] / 100;
		if (g > max)
		{
			max = g;
			c = i + 1;
		}
	}
	printf("%d", c);
	return 0;
}