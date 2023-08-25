/// Binary search tree

#include<bits/stdc++.h>
using namespace std;

int const mx = 100;
int a[mx];
int size = 0;

///searching a specific item , if not found insert its appropriate position
void itemSearch(int item)
{
    int i = 1;
    while(a[i] != -1)
    {
        if(item > a[i])
            i = i*2 + 1;
        else if(item < a[i])
            i = i*2;
        else
           {
            cout << "Index number : " << i << endl;
            return;
           }
    }
    a[i] = item;
    cout << "Not found" << endl;
}

///print binary search tree ; i.e  root and its left and right child respectively:
void print()
{
    for(int i = 1;i<=size;i++)
    {
        if(a[i] == -1)
        {
            continue;
        }

        else
        {
            cout << a[i] << " ";
            if(a[i*2] != -1)
            {
                cout << a[2*i] << " ";
            }
            else
            {
                cout << "-" << " ";
            }

            if(a[i*2 + 1] != -1)
            {
                cout << a[i*2 + 1] << " ";
            }
            else
            {
                cout << "-" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

}

void bst(int item)
{
    int i = 1;
    while(a[i] != -1)
    {
        if(item >= a[i])
            i = i*2 + 1;
        else
            i = i*2;
    }
    a[i] = item;
    if(size < i)
    {
        size = i;
    }
}

int main()
{
    for(int i = 0;i<mx;i++)
    {
        a[i] = -1;
    }

    string s;
    cin >> s;

    while(isdigit(s[0]))
    {
        bst(stoi(s));
        cin >> s;
    }

    cout << " Output " << endl;
     print();

    int item ;
    cout << "Item : ";
    cin >> item;

    itemSearch(item);
}
.....................................................................................................................
.....................................................................................................................
/// preOrder, postOrder, Inorder

#include<bits/stdc++.h>
using namespace std;

int const mx = 100;
int a[mx];

void inOrder(int i)
{
    if(a[1] == -1)
    {
        cout << "Tree is empty" << endl;
    }

    if(a[i*2] != -1)
    {
        inOrder(i*2);
    }
    cout << a[i] << " ";

    if(a[2*i + 1] != -1)
    {
        inOrder(2*i + 1);
    }
}

void preOrder(int i)
{
    if(a[1] == -1)
    {
        cout << "Tree is empty" << endl;
    }

    cout << a[i] << " ";

    if(a[i*2] != -1)
    {
        preOrder(i*2);
    }


    if(a[2*i + 1] != -1)
    {
        preOrder(2*i + 1);
    }
}

void postOrder(int i)
{
    if(a[1] == -1)
    {
        cout << "Tree is empty" << endl;
    }

    if(a[i*2] != -1)
    {
        postOrder(i*2);
    }


    if(a[2*i + 1] != -1)
    {
        postOrder(2*i + 1);
    }

    cout << a[i] << " ";
}

void bst(int item)
{
    int i = 1;

    while(a[i] != -1)
    {
        if(item >= a[i])
            i = 2*i + 1;
        else
            i = 2*i;
    }
    a[i] = item;
}

int main()
{
    for(int i = 0;i<mx;i++)
    {
        a[i] = -1;
    }

    string s;
    cin >> s;

    while(isdigit(s[0]))
    {
        bst(stoi(s));// convert string to int
        cin >> s;
    }

    cout << "Inorder :" << endl;
    inOrder(1);
    cout << endl;

    cout << "Preorder :" << endl;
    preOrder(1);
    cout << endl;

    cout << "Postorder :" << endl;
    postOrder(1);
    cout << endl;
}

/*
INPUT
6
5
1
2
4
d

OUTPUT
Inorder :
1 2 4 5 6
Preorder :
6 5 1 2 4
Postorder :
4 2 1 5 6

*/

