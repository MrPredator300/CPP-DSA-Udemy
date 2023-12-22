#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head=NULL;

void create(int A[],int n)
{
    struct Node *t,*last;
    int i;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for(i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        last->next = t;
        t->next = head;
        last = t;
    }

}

void display(struct Node *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
        /* code */
    } while (p!=head);
    
}

void Rdisplay(struct Node *p)
{
    static int flag=0;
    if(p!=head || flag==0)
    {
        flag=1;
        cout<<p->data<<" ";
        Rdisplay(p->next);
    }
    flag=0;

}

int length(struct Node *p)
{
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>length(head))
        return;

    if(index==0)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next = head;
        }
        else
        {
            while(p->next!=head)p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {
        for(i=0;i<index-1;i++)p=p->next;
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next = p->next;
        p->next = t;
    }

}

int main()
{
    int A[] = {1,2,3,4,5};
    create(A,5);
//    display(head);

//    Insert(head,2,10);
    Insert(head,5,20);
    Rdisplay(head);


    return 0;
}


