#include <iostream>
int main(int argc, char* argv[])
{
    int a[1000]{};
    int n = 0;
    int max = -1001;
    int nomer = 0;
    scanf_s("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", &a[i]);
    }
    int l = 0;
    int p = 0;
    scanf_s("%d", &l);
    scanf_s("%d", &p);
    for (int i = 0; i < n; ++i)
    {
        if (l <= i + 1 and i + 1 <= p)
        {
            if (a[i] > max)
            {
                max = a[i];
                nomer = i + 1;

            }

        }

    }
    printf("%d ", max);
    printf("%d", nomer);
    return 0;
}