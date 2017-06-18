#include <iostream>
using namespace std;
int x;
int y;
int reference(int & a, int  & b);
int main()
{
    
    cout << "Podaj dwie liczby:" <<endl;
    cout << "Pierwsza:";
    cin >> x;
    cout << "Druga:";
    cin >> y;
    cout << reference(x,y);
    return 0;
}

int reference(int & a, int & b)
{
    int c;
    c = a;
    a= b;
    b =c;
    return a;
}
