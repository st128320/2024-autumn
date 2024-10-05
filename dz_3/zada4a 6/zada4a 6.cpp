#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	int k = a;
	int d = b;	
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else 
		 b = b - a;
	}
	printf("%d", k * d / a);
		return 0;
}







	
