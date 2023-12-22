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

void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }

}

int Delete(struct Node *p,int index)
{
    struct Node *q;
    int x=-1;
    int i;

    if(index<1 || index>count(p))
        return -1;
    
    if(index==1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x=p->data;
        free(p);
        return x;

    }

}

int issorted(struct Node *p)
{
    int x=INT16_MIN;
    while(p!=NULL)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p=p->next;
    }

    return 1;

}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q=p->next;
        }
    }

}

void Reverse1(struct Node *p)               //Method1
{
    int *A,i=0;
    struct Node *q=p;                               //q is a pointer and it has to point to where p is pointing i.e at first
    A = (int *)malloc(sizeof(int)*count(p));        //It allocates a space of size count(p)*integer for the array and returns a pointer to an integer        
    while(q!=NULL)
    {
        A[i]=q->data;                               //It stores the data in the array form linked list dynamically
        q=q->next;
        i++;
    }
    q=p;            //q is again pointing at the first where p is pointing
    i--;            //i-- is written because i=5 it was outside the array so it has come the array i.e the last position i=4
    while(q!=NULL)
    {
        q->data=A[i];           //the last element in the array is stored in the 1st linked list 
        q=q->next;
        i--;
    }

}

void Reverse2(struct Node *p)       //Method 2
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;

}

void Reverse3(struct Node *q,struct Node *p)    //Method 3
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next = q;
    }
    else
        first=q;
}

int main()
{

 int A[] = {10,20,30,40,50};
 create(A,5);
 display(first);
 cout<<endl;
 
 //Reverse1(first);
 //Reverse2(first);
 Reverse3(NULL,first);


 display(first);
 cout<<endl;
 
    return 0;
}



