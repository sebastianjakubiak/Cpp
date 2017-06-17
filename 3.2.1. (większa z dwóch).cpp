#include <iostream>
using namespace std;
int x;
int * xx = &x;
int y;
int * yy = &y;

int wieksza(int * a, int * b);

int main()
{
    cout << "Podaj dwie liczby" << endl;
    cout << "Pierwsza:";
    cin >> x;
    cout << endl << "Druga:";
    cin >> y;
    cout << "Wiksza jest:" << wieksza(xx, yy);
    return 0;
}

int wieksza(int * a, int * b)
{
    if (*a > *b) return *a;
    else return *b;
}
