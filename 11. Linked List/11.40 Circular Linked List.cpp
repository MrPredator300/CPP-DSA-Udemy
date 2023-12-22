#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*head;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for(i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
//        t->next = head;       can use this link also instead of "t->next = last->next" 
        last = t;
    }


}

void Display(struct Node *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
        /* code */
    } while (p!=head);
    cout<<endl;
    

}

void RDisplay(struct Node *p)
{
    static int flag=0;
    if(p!=head || flag==0)
    {
        flag=1;
        cout<<p->data<<" ";
        RDisplay(p->next);
    }
    flag=0;
}


int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
   // Display(head);
   RDisplay(head);



    return 0;
}


