#include <iostream>
int main(int argc, char* argv[])
{
    int n = 0;
    int a[100]{ 0 };
    std::cin >> n;
    int c = 0;
    int g = 0;
    int y = 0;
    int z = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> *(a + i);
    }
    int max = 0;
    int dni = 0;
    while (y < n)
    {
        max = 0;
        for (int i = y; i < n; ++i)
        {
            if (max < *(a + i))
            {
                max = *(a + i);
                dni = i + 1 - y;
                z = i + 1;
            }

        }
        y = z;
        c = dni * max;
        g += c;
    }
    std::cout << g << "";
    return 0;
}