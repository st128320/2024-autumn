#include <iostream>

int main(int argc,char* argv[]) 
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int k = -101;
    int l = -101;
    int i = -101;
    int x = -100; 
    scanf_s("%d", &a);
    scanf_s("%d", &b);
    scanf_s("%d", &c);
    scanf_s("%d", &d);
    while (x <= 100) {
        int y= x * x * x * a + x * x * b + x * c + d;
        if (y == 0) {
            if (k == -101) {
                k = x; 
            }
            else if (l == -101 && x != k) {
                l = x; 
            }
            else if (i == -101 && x != k && x != l) {
                i = x; 
            }
        }
        ++x;
    }
        if (k != -101)
            printf("%d\n", k);
    if (l != -101) 
        printf("%d\n", l);
    if (i != -101) 
        printf("%d\n", i);

    return 0;
}