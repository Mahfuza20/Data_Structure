
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back

vector<ll>graph[1000];
bool vis[1000];
ll cnt;

void dfs(ll vertex)
{
    vis[vertex] = true;
    for(int i = 0;i<graph[vertex].size();i++)
    {
        if(vis[graph[vertex][i]] == false)
            dfs(graph[vertex][i]);
    }
    cnt++;
}

int main()
{
    int n, edge;
    cin >> n >> edge;

    int x, y, c = 0;
    for(int i = 1;i<=edge;i++)
    {
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    for(int i = 1;i<=n;i++)
    {
        if(vis[i] == false)
        {
            dfs(i);
            c++;
        }
    }

    if(c == 1)
        cout << "Connected" << endl;
    else
        cout << "Not connected" << endl;
}
/*
5 5
1 2
2 3
1 3
3 4
1 5

output connected
*/
