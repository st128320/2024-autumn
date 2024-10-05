#include <iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int y = 0;
    int n = 0;
    int q = 0;
    int z = 0;
    scanf_s("%d", &a);
    for (int i = 0; i < a; ++i)
    {
        int t = 0;
        scanf_s("%d", &t);

        if (t > 0) {
            ++y; 
        }
        else {
            if (y > n) {
                n = y;  
            }
            y = 0;  
        }
    }
    if (y > n) {
        n = y;  
    }
    printf("%d", n);
    return 0;
}