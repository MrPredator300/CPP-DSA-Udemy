#include <iostream>
using namespace std;

struct Node             //Creates a Node of type Struct which contains a data and pointer called *next
{
    int data;
    struct Node *next;

}*first=NULL;



void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];  //first is pointing to the first node (OR) first head i.e '3' here
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node)); //Allocates a space for node and returns a pointer to Struct
        t->data = A[i];
        t->next = NULL;
        last->next = t;  //Connects prev node to newly created Node i.e first create a link and then move the last pointer to the newly created node
        last = t;       //moves the *last pointer to current i.e 't'
    }

}

void display(struct Node *p)
{
    while(p!=NULL)      //*p is the pointer which keeps moving forward until it reaches the last node which stores NULL i.e pointing to nothing
    {
        cout<<p->data<<" "; //prints the vlaues in the linked list i.e '3 5 7 10 15'
        p=p->next;          //It shifts to the next to print 
    }

}


int main()
{
 int A[] = {3,5,7,10,15};
 create(A,5);
 display(first);

    return 0;
}



