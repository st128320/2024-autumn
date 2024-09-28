#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	scanf_s("%d", &a);
	int b = a / 5;
	int c = a / 3;
	if (a % 5 == 0) {
		printf("%d\n", b);
		printf("0");
	}
	
	else if (a % 5 == 1) {
		printf("%d\n", b - 1);
		printf("2");
	}
	else if (a % 5 == 2) {
		printf("%d\n", b - 2);
		printf("4");
	}
	else if (a % 5 == 3) {
		printf("%d\n", b);
		printf("1");
	}

	else if (a % 10 == 4 and a>=24) {
		printf("%d\n",  b - 4);
		printf("8");
	}
	else if (a % 5 == 4) {
		printf("%d\n", b-1);
		printf("3");
	}
	else if (a % 3 == 0) {
		printf("0\n");
		printf("%d",  c);
	}
	return 0;
	}
	
	


	



