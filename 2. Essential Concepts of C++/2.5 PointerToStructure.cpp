#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r={10,5};
    struct Rectangle *p = &r;

    r.length = 15;
    cout<<"r="<<r.length;
    cout<<endl;
    //p.length = 20;                        //this is wrong method of pointing
    //*p.length = 20;                       //this is wrong as higher precendece is for "." (dot) operator
    (*p).length = 20;                       //this is the correct method
    cout<<"p="<<(*p).length<<endl;          //Instead of doing this much use arrow method C++ Provides
    p->length = 20;                         //This is the correct method
    cout<<"p="<<p->length;

    return 0;
}