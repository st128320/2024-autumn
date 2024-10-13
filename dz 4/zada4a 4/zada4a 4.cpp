#include <iostream>

int main(int argc, char* argv[])
{
    int a[1000]{};
    int max = 0;
    int n = 0;
    int summa = 0;
    scanf_s("%d", &n);
    if (n >= 3)
    {

        for (int i = 0; i < n; ++i)
        {
            scanf_s("%d", &a[i]);
        }


        for (int i = 0; i < n; ++i)
        {

            summa = a[i] + a[(i + 1) % n] + a[(i + 2) % n];
            if (summa > max)
                max = summa;
        }
    }

    printf("%d", max);
    return 0;
}