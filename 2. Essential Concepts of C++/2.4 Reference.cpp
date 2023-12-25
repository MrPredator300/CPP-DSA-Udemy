#include <iostream>
using namespace std;

int main()
{
    int a=10;
    int &r = a;         // this means that now you can call the value by variable 'a' and 'r'
    cout<<"a="<<a<<endl;
    r++;
    cout<<"r="<<r<<endl;
    cout<<"a="<<a<<endl;

    return 0;
}