#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *S;

};

void create(struct stack *st)
{
    cout<<"Enter the size:";
    cin>>st->size;
    st->top=-1;                                     //st->top=-1 i.e stack is empty it always starts with top->-1
    st->S = (int*)malloc(st->size*sizeof(int));     //creating a space for size element i.e n=5 so S=5*4=20 (size of integer is 4)
    

}

void display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    cout<<st.S[i]<<endl;
    cout<<endl;

}

void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
    cout<<"Stack Overflow"<<endl;
    else
    {
        st->top++;
        st->S[st->top]=x;
    }

}

int pop(struct stack *st)
{
    int x=-1;
    if(st->top==1)
    cout<<"Stack Underflow"<<endl;
    else
    {
        x = st->S[st->top--];
    }
    return x;

}

int peek(struct stack st,int index)
{
    int x=-1;
    if(st.top-index+1<0)
        cout<<"Invalid Index";
    x = st.S[st.top-index+1];
    
    return x;

}

int isEmpty(struct stack st)
{
    if(st.top==-1)
        return true;
    return 0;

}

int isFull(struct stack st)
{
    return st.top==st.size-1;

}

int stackTop(struct stack st)
{
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;

}

int main()
{
    struct stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);


    display(st);

    cout<<peek(st,3);   //gives the value of the top most element in the stack

/*
    cout<<"Poping the element: "<<pop(&st)<<endl;
    cout<<"Poping the element: "<<pop(&st)<<endl;
    cout<<"Poping the element: "<<pop(&st)<<endl;

*/

//    display(st);



    return 0;
}




