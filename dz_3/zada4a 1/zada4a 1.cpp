#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int c = 0;
	int b = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; ++i) 
	{
		int k=0;
		scanf_s("%d", &k);
		if (k == 0) {
			c++;
		}
		else if (k == 1)
		{
			b++;
		}
	
	}
	if (b >= c)
		printf("%d", c);
	else if (c >= b)
		printf("%d", b);
	

		return 0;
	}
	
	

	







	
