#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*first=NULL;



void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;  
        last = t;
       // cout<<"content of last "<<&(last->next)<<" "<<&t<<"\n";

        
    }

}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

}

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        RDisplay(p->next);
        cout<<p->data<<" ";
    }
}

int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;

}

int Rcount(struct Node *p)
{
    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;

}

int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int Rsum(struct Node *p)
{
    if(p==NULL)
        return 0;
    else
        return Rsum(p->next)+p->data;
}

int Max(struct Node *p)
{
    int max = INT32_MIN;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p=p->next;
    }
    return max;
}

int RMax(struct Node *p)
{
    int x=0;
    if(p==0)
        return INT32_MIN;
    x=RMax(p->next);
    if(x>p->data)
        return x;
    else return p->data;
}

struct Node * LSearch(struct Node *p,int key)
{
    struct Node *q;

    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;

        }
        q=p;
        p=p->next;
    }
    return NULL;

}

struct Node * RSearch(struct Node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);
 
}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t; //A pointer '*t' created which will always point to type of struct Node
    int i;
    if(index<0 || index>count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node)); // Creates a new Node
    t->data=x;

    if(index ==0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next = p->next;
        p->next = t;

    }

}


int main()
{
/*
 int A[] = {3,5,7};
 create(A,3);
 */
 Insert(first,0,9);
 Insert(first,1,11);
 Insert(first,2,20);
 Insert(first,0,89);
 //Insert(first,3,9);
 //Insert(first,8,9);
 display(first);
 

    return 0;
}



