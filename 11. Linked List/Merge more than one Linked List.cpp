#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*head=NULL,*head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL,*temp=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        last->next = t;
        t->next = NULL;
        last = t;
    }

}

int count(struct Node *p)
{
    int l;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;

}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
 cout<<endl;
}

void countNode(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count+=1;
        p=p->next;
    }
    cout<<count;

}

int sumNode(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;

}

int Maxelement(struct Node *p)
{
    int max = 0;
    max=p->data;
    while(p!=NULL)
    {
        if(max<p->data)
        {
            max = p->data;
        }
        p=p->next;

    }
    return max;

}

int searchelement(struct Node *p,int num)
{
    while(p!=NULL)
    {
        if(p->data == num)
            return 1;
        else
            p=p->next;
    }

    return 0;

}

void insert(struct Node *p,int idx,int num)
{
    int count=0;
    struct Node *t,*prev;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = num;
    t->next = NULL;
    prev=p;
    while(p!=NULL)
    {
        count+=1;
        if(count==idx)
        {
            t->next = p->next;
            prev->next = t;
            break;
        }
        prev=p;
        p=p->next;

    }

}

void sortedinsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if(head==NULL)
        head = t;
    else
    {
        while(p && p->data < x)
        {
            q=p;
            p=p->next;
        }
        if(p==head)
        {
            t->next = head;
            head = t;
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

    if(index<0 || index>count(p))
        return -1;
    if(index==1)
    {
        q=head;
        x = q->data;
        head=head->next;
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
        x = p->data;
        free(p);
        return x;
    }


}

int issorted(struct Node *p)
{
    int min = INT16_MIN;
    while(p!=NULL)
    {
        if(p->data < min)
            return 0;
        min = p->data;
        p=p->next;
    }
    return 1;

}

void Duplicate(struct Node *p)
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

void Reverse1(struct Node *p)   //Method1
{
    int *A,i=0;
    struct Node *q=p;
    A = (int*)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data = A[i];
        q=q->next;
        i--;
    }

}

void Reverse2(struct Node *p)       //Method2
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    head = q;

}

void Reverse3(struct Node *q,struct Node *p)       //Method3
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next = q;
    }
    else
        head = q;

}

void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        head4=last=p;
        p=p->next;
        head4->next = NULL;
    }
    else
    {
        head4=last=q;
        q=q->next;
        head4->next = NULL;
    }

    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p=p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q=q->next;
            last->next = NULL;
        }
    }
    if(p)
        last->next = p;
    if(q)
        last->next = q;


}

int main()
{

//    int A[] = {1,2,3,4,5};          
//    create(A,5);
    int A1[] = {10,30,50,70,90};
    int A2[] = {20,40,60,80,100};
    int A3[] = {120,140,160,180,200};
    int A4[] = {1,2,4,3,5};
    create(A1,5);
    head1=head;
    create(A2,5);
    head2=head;
    create(A3,5);
    head3=head;
    create(A4,5);
    head4=head;
    display(head1);
    display(head2);
    display(head3);
    display(head4);
  
    Merge(head1,head2);
    temp=head4;
    Merge(head3,temp);
    temp=head4;
    Merge(head,temp);
    cout<<endl;
    
    
    display(head4);
    

    cout<<endl;
    

    return 0;
}



