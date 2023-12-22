#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;

};

void create(struct stack *st)
{
    cout<<"Enter the size of the stack: ";
    cin>>st->size;
    st->top=-1;                                                //st->top=-1 i.e stack is empty it always starts with top->-1
    st->arr = (int*)malloc(st->size*sizeof(int));              ////creating a space for size element i.e n=5 so S=5*4=20 (size of integer is 4)

}

void display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    cout<<st.arr[i]<<endl;
    cout<<endl;

}

void push(struct stack *st,int data)
{
   if(st->top==st->size-1)
        cout<<"Stack Overflow";
    else
    {
        st->top++;
        st->arr[st->top]=data;
    }

}

int pop(struct stack *st)
{
    int data=-1;
    if(st->top==-1)
        cout<<"Stack Underflow";
    else
    {
        data = st->arr[st->top--];
    }
    return data;


}


int main()
{
    struct stack st;
    int data;
    create(&st);
    for(int i=0;i<st.size;i++)
    {
        cout<<"Enter the elements: ";
        cin>>data;
        push(&st,data);
    }
//    push(&st,data);               //if you push another data it will give a message stack overflow
    cout<<endl;
    cout<<"The elemnets are:"<<endl;
    display(st);

    int x;
    cout<<"Enter the number of elements to pop:";
    cin>>x;

    for(int i=1;i<=x;i++)
    pop(&st);

    cout<<endl;

    display(st);



    return 0;
}




