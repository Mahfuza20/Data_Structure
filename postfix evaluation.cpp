
#include<bits/stdc++.h>
using namespace std;
int const MAX=100;
int top=-1;
char Stack[MAX];
vector<int>digit;
int isFull()
{
    if(top==MAX)
    return 1;
    else
    return 0;
}
int isEmpty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(int x)
{
    if(!isFull())
    {
        top++;
        Stack[top]=x;
    }
    else
    cout<<"Stack is overloaded" <<endl;
}
int pop()
{
    if(!isEmpty())
    {
        char temp=Stack[top];
        top--;
        return temp;
    }
    else
    cout<<"Stack is underloaded"<<endl;
    return -1;
}
void doOperator(char c)
{
    int digit1 =pop();
    int digit2 =pop();
    switch(c)
    {
        case'+':
        push(digit1 + digit2);
        break;
        case'-':
        push(digit1 - digit2);
        break;
        case'*':
        push(digit1 * digit2);
        break;
        case'/':
        push(digit1 / digit2);
        break;
        case'^':
        push(pow(digit1 , digit2));
        break;

    }
}
void addExactDigit()
{
    int len=digit.size();
    //int ien =digit.length();
    int value =0;
    if(len!=0)
    {
        for(int i=len-1,j=1; i>=0;i--,j=j*10 )
        {
            value = value+(digit[i]*j);
        }
        digit.clear();
        push(value);
    }
}
int main()
{
    string postfix;
    cin >>postfix;
    for(int i=0; i<postfix.length(); i++)
    {
        addExactDigit();

        if(postfix[i]>='0'&&postfix[i]<='9')
        {
            digit.push_back(postfix[i]-'0');
        }
        else if(postfix[i]!=',')
        {
            doOperator(postfix[i]);
        }
    }
    cout <<pop()<<endl;
}
//5,6,7,+,-
//output = 8
