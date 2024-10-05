#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
	int k = 0;
	int q = 0;
	int g = 0;
	int c = 0;
	scanf_s("%d", &k);
	for(int i=0;i<k;++i)
	{
		int v = 0;
		int s = 0;
		scanf_s("%d", &v);
		scanf_s("%d", &s);
		if (s == 1)
			++c;
		if (s == 1) {
			if (v > g ) {
				g = v;
				q = i + 1;
			}
			else if (v == g )
				q = std:: min(q, i + 1);
		}
	}
	if (c == 0)
		printf("-1");
	else
	printf("%d", q);
	return 0;
}
	
	


	
