#include <iostream>
using namespace std;
int x;
int * xx = &x;
int y;
int *yy = &y;

void wskaznik (int * a, int * b);

int main()
{
    
    cout << "Podaj dwie liczby:" <<endl;
    cout << "Pierwsza:";
    cin >> x;
    cout << "Druga:";
    cin >> y;
    return 0;
}

void wskaznik (int * a, int * b)
{
    int * c = a;
    a = b;
    b = c;
}
