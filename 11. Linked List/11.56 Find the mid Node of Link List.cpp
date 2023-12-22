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
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last=t;
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

int lenLL(struct Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
        
    } while (p!=NULL);
    return len;
    
}

void mymidnode(struct Node *p)
{
    struct Node *q;
    q=head;
    while(p!=NULL && q->next!=NULL)
    {
        q=q->next->next;
        p=p->next;
    }
    cout<<p->data;

}

void midnode(struct Node *p)
{
    struct Node *q;
    q=head;
    while(q)
    {
        q=q->next;
        if(q) q=q->next;
        if(q) p=p->next;
    }
    cout<<p->data;

}

void midnode2(struct Node *p,int n)
{
    int count=0;
    while(count!=n)
    {
        count++;
        p=p->next;
    }
    cout<<p->data;

}


int main()
{
    int A[] = {1,2,3,4,5};
    create(A,5);

    display(head);
    cout<<endl;
    cout<<"lenght of linked list: "<<lenLL(head);
    cout<<endl;
    midnode(head);
//    midnode2(head,5/2);
//    mymidnode(head);




    return 0;
}