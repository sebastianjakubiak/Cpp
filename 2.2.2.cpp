#include <iostream>
using namespace std;
int n;
int g = 1;
int silnia (unsigned int m)
{
    for (int i = 2; i <=m; i++) g *= i;
    return g;
}

int main()
{
    cout << "Podaj nieujemną liczbę całkowitą:";
    cin >> n;
    cout << silnia(n);
    return 0;
}
