#include <iostream>
int main(int argc,char* argv[])
{
    int n = 0;
    int k = 0;
    std::cin >> n;
    int a[100000];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> *(a+i);
    }
    std::cin >> k;
    int s = ((k % n) + n) % n;
    for (int i = 0; i < n; ++i) 
    {
        std::cout << *(a +(i + n - s) % n) << " ";
    }
    return 0;
}