#include <iostream>
int main(int argc, char* argv[])
{
    int n = 0;
    int k = 0;
    int b[100]{ 0 };
    int a[100]{ 0 };
    int c = 0;
    int q = 0;
    std::cin >> n;
    std::cin >> k;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> *(a + i);
    }
    for (int j = 0; j < k; ++j)
    {
        std::cin >> *(b + j);
    }
    if (k < n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                if (*(a + i) == *(b + j))
                {
                    c = *(a + i);
                    ++q;
                }
            }
            if (i<q)
            std::cout << c << " ";
        } 
    }
    return 0;
    }
  






