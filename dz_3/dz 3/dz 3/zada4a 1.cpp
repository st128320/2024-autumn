#include <iostream>

int main(int argc,char* argv[]) {
    int n = 0;
    int c = 0;
    scanf_s("%d", &n);
     for (int i = 0; i < n; ++i) {
        int p=0;
        scanf_s("%d", &p);
        p >= 0 and p <= 1;
        if (p == 0)
            ++c;
        } 
     printf("%d", c);
     return 0;
}
