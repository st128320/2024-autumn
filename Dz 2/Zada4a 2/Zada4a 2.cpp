

#include <iostream>

int main(int argc,char* argv[])
{
    int a = 0;
    int b = 0;
    scanf_s("%d", &a);
    scanf_s("%d", &b);
    if (a == 1 and b == 1) {
        printf("0");
    }
    else if (a==b) {
        printf("2");
    }
    else
        printf("1");
    return 0;
}
