#include <iostream>
using namespace std;

class Digonal
{
    int *A;
    int n;
public:
    Digonal()
    {
        n=2;
        A = new int[2];
    }
    Digonal(int n)
    {
        this->n=n;
        A = new int[n];
    }
    ~Digonal()
    {
        cout<<"Calling Destructor";
        delete []A;
    }
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();

};

void Digonal::Set(int i,int j,int x)
{
    if(i==j)
        A[i-1]=x;
}

int Digonal::Get(int i,int j)
{
    if(i==j)
        return A[i-1];
    return 0;
}

void Digonal::Display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}


int main()
{
    Digonal d(4);

    d.Set(1,1,5);
    d.Set(2,2,8);
    d.Set(3,3,9);
    d.Set(4,4,12);
    
    d.Display();

    return 0;
}
