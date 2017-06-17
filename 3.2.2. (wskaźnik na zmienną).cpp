#include <iostream>
using namespace std;
int x;
int * xx = &x;
int y;
int *yy = &y;

int wskaznik (int * a, int * b);

int main()
{
    
    cout << "Podaj dwie liczby:" <<endl;
    cout << "Pierwsza:";
    cin >> x;
    cout << "Druga:";
    cin >> y;
    cout << "Adres mniejszej to:" << wskaznik(xx,yy);
    
    return 0;
}

int wskaznik (int * a, int * b)
{
    if (*a < *b) return *a;
        else return *b;
}
