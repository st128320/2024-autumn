#include <iostream>
int main(int argc, char* argv[])
{
	int a[1000]{};
	int n = 0;
	int max = -1000;
	int min = 1000;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == max)
		{
			a[i] = min;
		}

	}
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	return 0;
}