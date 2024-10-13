#include <iostream>
int main(int argc, char* argv[])
{
	int a[1000]{};
	int b = 0;
	scanf_s("%d", &b);
	for (int i = 0; i < b; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	int c = 0;
	scanf_s("%d", &c);
	int j = 0;
	for (int i = 0; i < b; ++i)
	{
		if (c == a[i]) {
			++j;
		}
	}
	printf("%d", j);
	return 0;
}
