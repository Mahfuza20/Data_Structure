#include<bits/stdc++.h>
using namespace std;

int const MAX = 100;
int top =-1;
char Stack[MAX];

int isEmpty(){
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(){
    if(top==MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char x)
{
    if(!isFull())
    {
        top++;
        Stack[top]=x;
    }
    else
    {
        cout <<"Stack is overloaded"<<endl;
    }
}

char pop()
{
    if(!isEmpty())
    {
        char a=Stack[top];
        top--;
        return a;
    }
    else
    {
        cout <<"stack is underflow"<<endl;
    }
}

int precedence(char c)
{
    if(c== '(')
    return 0;
    else if(c== '+'|| c=='-')
    return 1;
    else if(c== '*'|| c=='/')
    return 2;
    else
    return 3;
}

int main()
{
    string infix;
    cin >> infix;

    push('(');
    infix = infix + ')';

    for(int i = 0; i <infix.length(); i++)
    {
        char symbol = infix[i];
        if(symbol>='A' && symbol <='Z')
        {
            cout << symbol;
        }
        else
        {
            char next = Stack[top];
            if(symbol==')')
            {
                while(Stack[top]!='(')
                {
                    cout <<pop();
                }
                pop();
            }
            else if((precedence(next)>precedence(symbol)) && symbol!= '(')
            {
                cout << pop();
                push(symbol);
            }
            else
            {
                push(symbol);
            }
        }
    }
}

//A+(B*C-(D/E^F)*G)*H
// output ABC*DEF^/G*-H*+


