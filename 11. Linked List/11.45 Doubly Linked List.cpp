#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL,*endt=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;
    int i;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last=t;
    }
    endt=last;
}

void display(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;

}

void display2(struct Node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->prev;
    }
    cout<<endl;

}

int length(struct Node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;

}


int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);

    cout<<"Length is: "<<length(first);

    cout<<endl;

    display(first);
    display2(endt);

    return 0;
}


