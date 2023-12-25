//2.3)
#include <iostream>
using namespace std;

int main()
{
   int a=10;    //data variable
   int *p;      //address variable
   p = &a;      //initialzing value to a pointer
   cout<<"a="<<a<<endl;
   cout<<"*p="<<*p;  //deferencing  gives the value of that address is holding
   cout<<endl;
   cout<<"p="<<p;   //this prints the address alone not the value

   return 0;
}

