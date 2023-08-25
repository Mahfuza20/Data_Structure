/*
/// insert heap
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

void work(int tree[],int n,int i)
{
    int parent = (i-1)/2;

    if(tree[parent] > 0)
    {
        if(tree[i] > tree[parent])
        {
           swap(tree[i],tree[parent]);
            work(tree, n, parent);
        }
    }
}

void insertNode(int tree[], int& n, int item)
{
    n = n+1;
    tree[n-1] = item;
    work(tree, n, n-1);
}

void printTree(int tree[], int n)
{
    for(int i = 0;i<n;i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int tree[MAX];

    for(int i = 0;i<n;i++)
    {
        cin >> tree[i];
    }
    int item;
    cin >> item;

    insertNode(tree, n, item);
    printTree(tree, n);
    return 0;
}*/
/*
5
10 5 3 2 4

15
output
15 5 10 2 4 3
*/

#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int root)
{
    int i = root;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l] > arr[root])
        root = l;

    if(r<n && arr[r] > arr[root])
        root = r;

    if(root != i)
    {
        swap(arr[i], arr[root]);
        heapify(arr, n, root);
    }
}

void deleteRoot(int arr[], int n)
{
    int lastElement = arr[n-1];
    arr[0] = lastElement;
    n= n-1;
    heapify(arr, n ,0);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n-1; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
    }

    deleteRoot(arr, n);
    printArray(arr, n);
    return 0;
}

/*

5
10 5 3 2 4

output
5 4 3 2

*/
