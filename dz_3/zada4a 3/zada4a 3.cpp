#include <iostream>

int main(int argc,char* argv[])
{

    int n = 0;
    scanf_s("%d", &n);
    for (int i = 0; i < n; ++i) {
        int h = 0;
        scanf_s("%d", &h);

        if (h <= 437)
        {
            printf("Crash %d\n", i + 1);
            return 0;
        }
    }
    printf("No crash\n"); 
    return 0;
}