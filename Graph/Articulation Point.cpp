#include<bits/stdc++.h>
#define NIL -1
#define MAX 100000

using namespace std;

vector<int>adj[MAX];

bool visited[MAX];
bool ap[MAX];

int parent[MAX];
int start[MAX];
int low[MAX];

void dfs(int u)
{
   static int time=0;
    int children=0;

    visited[u]=true;

    ++time;

    start[u]=time;
    low[u]=time;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];

        if(visited[v]==false)
        {
            children++;

            parent[v]=u;

            dfs(v);

            low[u]=min(low[u],low[v]);

            if(parent[u]==NIL && children>1) /// root
                ap[u]=true;

            if(parent[u]!=NIL && low[v]>=start[u])
                ap[u]=true;
        }

        else if(v!=parent[u])
        {
            low[u]=min(low[u],start[v]);
        }
    }
}

int main()
{

    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1; i<=m; i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++)
    {
        parent[i]=NIL;
        visited[i]=false;
        ap[i]=false;
    }

    for(int i=0; i<n; i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
        }
    }

    printf("Articulation Point:");

    for(int i=0; i<n; i++)
    {
        if(ap[i]==true)
        {
            printf(" %d",i);
        }
    }
    return 0;
}
