#include <iostream>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char ch)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if(t==NULL)
        cout<<"Stack is Full";
    else
    {
        t->data = ch;
        t->next = top;
        top = t;
    }

}

char pop()
{
    struct Node *p;
    char x=-1;
    p=top;

    if(p==NULL)
        cout<<"Stack is Empty";
    else
    {
        x = p->data;
        top=top->next;
        free(p);
    }
    return x;

}

void display()
{
    struct Node *p;
    p=top;
    if(p!=NULL)
    {
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    else
        cout<<"Stack is Empty";

}

int isBlanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
            push(exp[i]);
        else if(exp[i]=='}' || exp[i]==')' || exp[i]==']')
        {
            cout<<"top value="<<top->data<<endl;
            if(top==NULL)
                return 0;
            char x=top->data;
            cout<<"value of char x="<<x<<endl;
            cout<<"value of exp[i] = "<<exp[i]<<endl;


//**************** if-else METHOD *****************************//
            // if(x=='{' && exp[i]=='}')
            //     pop();
            // else if(x=='(' && exp[i]==')')
            //     pop();
            // else if(x=='[' && exp[i]==']')
            //     pop();

//******************** swicth case METHOD ************************//
            switch(exp[i])
            {
                case '}':
                    if(x=='{' && exp[i]=='}')
                    pop();
                    break;

                case ')':
                    if(x=='(' && exp[i]==')')
                    pop();
                    break;

                case ']':
                    if(x=='[' && exp[i]==']')
                    pop();
                    break;
                
            }

           
        }
    }

    if(top==NULL)
        return true;
    else
        return false;
}


int main()
{
    char *exp = "{([a+b]*[c-d])/e}";
    // char *exp = "{}";
    cout<<isBlanced(exp);

    return 0;
}