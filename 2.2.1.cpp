#include <iostream>
using namespace std;
int n;
int wartoscbezwzgledna(int m)
{
    if (m<0)return m * (-1);
    else return m;
}
int main()
{
    cout << "Podaj liczbę całkowita:";
    cin >> n;
    cout << wartoscbezwzgledna(n);
    return 0;
}
