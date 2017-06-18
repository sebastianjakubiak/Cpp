#include <iostream>
using namespace std;
int * rez();
int main()
{
    cout << rez();
    return 0;
}
int * rez()
{
    int * b = new int;
    return b;
}
