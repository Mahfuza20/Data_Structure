
///question 1, adjacent matrix a with m vertices as input and output......
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enyer the number of vertices"<<endl;
    int n;
    cin >> n;
    int a[n][n];
    cout<<"enter the adjacency matrix" <<endl;
    int mat[n][n][n];
    //for leter use
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
            mat[0][i][j]=a[i][j];
        }
    }
    for(int i=0; i<n;i++)
    {
        cout <<"Adjacent of: "<<i+1<<":";
        for(int j=0; j<n;j++)
        {
            if(a[i][j]!=0)
                cout << j+1<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    int var[n][n];
    for(int l=0;l<n;l++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                var[i][j]=0;
                for(int k=0;k<n;k++)
                {
                    var[i][j] += mat[l][i][k]*mat[0][k][j];
                }
                mat[l+1][i][j] = var[i][j];
            }
        }
    }
    for(int l=1;l<n;l++)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[l][i][j]>0)
                cnt++;
            }
        }
        cout <<"no of path length"<< l+1 <<" is "<<cnt <<endl;
    }

}
//output
enter the number of vertices
4
enter the adjacency matrix
0 0 0 1
1 0 1 1
1 0 0 1
0 0 1 0
Adjacent of : 1 : 4
Adjacent of : 2 : 1 3 4
Adjacent of : 3 : 1 4
Adjacent of : 4 : 3


no of path length2 is 8
no of path length3 is 10
no of path length4 is 11
//end


///check out strong or not, question 2, calculate path matrix
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int adjMatrix[n][n];
    int mulMatrix[n][n];
    int sumMatrix[n][n];
    int pathMatrix[n][n];
    int tempMatrix[n][n];
    int numOfZero =0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >>adjMatrix[i][j];
        }
    }
    mempcpy(mulMatrix,adjMatrix,n*n*sizeof(int));
    mempcpy(sumMatrix,adjMatrix,n*n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                int temp =0;
                for(int l=0;l<n;l++)
                {
                    temp += adjMatrix[j][l] * mulMatrix[l][k];
                }
                tempMatrix[j][k] = temp;
                sumMatrix[j][k] += temp;
            }
        }
        mempcpy(mulMatrix,tempMatrix,n*n*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(sumMatrix[i][j]==0)
            {
                pathMatrix[i][j]=0;
                numOfZero++;
            }

            else
                pathMatrix[i][j]=1;
        }
    }
    cout <<"output"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << pathMatrix[i][j]<<" ";
        }
        cout <<endl;
    }
    cout << "check out strong or not" <<endl;
    if(numOfZero==0)
        cout<< "graph is strongly connected" << endl;
    else
        cout <<"not Strongly" <<endl;
}

/* input output
        4
	1 1 1 0
 	0 1 0 1
  	1 0 1 0
   	0 1 0 1
	
	output
	1 1 1 1
 	0 1 0 1
  	1 1 1 1
   	0 1 0 1
not strong
*/

///weightwed graph, with m nodes v1,.. each edge is using warshall's algorith
#include<bits/stdc++.h>
using namespace std;
#define inf 100000000;

int main()
{
    int n;
    cin >> n;

    int adjMatrix[n][n];
    int tempMatrix[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> adjMatrix[i][j];
            if(adjMatrix[i][j] == 0)
            {
                adjMatrix[i][j]=inf;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0; k<n;k++)
            {
                tempMatrix[j][k]= min(adjMatrix[j][k],(adjMatrix[j][i] + adjMatrix[i][k]));
            }
        }
        mempcpy(adjMatrix,tempMatrix,n*n*(sizeof(int)));
    }

    cout << "weighted graph" <<"\n";

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << adjMatrix[i][j] <<" ";
        }
        cout <<endl;
    }
    for(int i = 0;i<n;i++)
    {
        cout << (i+1)<<"th node has direct path to : ";
        for(int j = 0;j<n;j++)
        {
            if(adjMatrix[i][j] >= 1)
                cout<<(j+1)<<" ";
        }
        cout << endl;
    }
}

/*input output
    4
	2 5 0 0
	2 0 1 4
	5 3 3 3
	4 2 3 0
	weighted graph
	2 5 6 9
	2 4 1 4
	5 3 3 3
	4 2 3 6
	1th node has direct path to : 1 2 3 4
	2th node has direct path to : 1 2 3 4
	3th node has direct path to : 1 2 3 4
	4th node has direct path to : 1 2 3 4
*/


///path matrix using warshall's algorithm
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int adjMatrix[n][n];
    int tempMatrix[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >>adjMatrix[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n;k++)
            {
                tempMatrix[j][k] = adjMatrix[j][k] || (adjMatrix[j][i] && adjMatrix[i][k]);
            }
        }
        mempcpy(adjMatrix,tempMatrix,n*n*(sizeof(int)));
    }

    cout <<"Sortest path warshall's algorithm"<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << adjMatrix[i][j] <<" ";
        }
        cout << endl;
    }
}
/*input output
	4
	1 1 1 0
	0 1 0 1
	1 0 1 0
	0 1 0 1
	output
	1 1 1 1
	0 1 0 1
	1 1 1 1
	0 1 0 1
*/


