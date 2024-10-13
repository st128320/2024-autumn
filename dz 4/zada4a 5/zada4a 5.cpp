#include <iostream>
int main(int argc, char* argv[])
{
    int n = 0;
    scanf_s("%d", &n);
    int a[1000]{};
    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", &a[i]);
    }
    int c = 0;
    scanf_s("%d", &c);
    int p = a[0];
    int d = abs(c - a[0]);
    for (int i = 1; i < n; ++i)
    {
        int l = abs(c - a[i]);
        if (l < d)
        {
            d = l;
            p = a[i];
        }
        else if (l == d && a[i] < p)
        {
            p = a[i];
        }
    }
    printf("%d", p);

    return 0;
}
