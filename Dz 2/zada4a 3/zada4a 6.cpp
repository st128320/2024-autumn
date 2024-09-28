#include <iostream>

int main(int argc, char* argv[]) 
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	int D = b * b - 4 * a * c;
	if (a == 0 and c != 0 and b != 0 and b >= 0) {
		printf("1\n");
		printf("%f", (double) - c/ b);
	}
	else if (a == 0 and c != 0 and b != 0 and b <= 0) {
		printf("1\n");
		printf("%f", (double) c / b);
	}
	else if (a != 0 and c!= 0 and b != 0) {
		if (D > 0) {
			printf("2\n");
			printf("%f\n", (double) (-b + sqrt(D)) / 2 * a);
			printf("%f", (double)(-b - sqrt(D)) / 2 * a);
		}
		else if (D == 0) {
			printf("1\n");
			printf("%f", (double)-b / 2 * a);
		}
		else if (D < 0) {
			printf("0");
		}
		}
	else if (a == 0 and c == 0 and b == 0) {
		printf("-1");
	}
	else if (a == 0 and c == 0 and b != 0) {
		printf("0");
	}
	return 0;
}