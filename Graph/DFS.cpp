#include<bits/stdc++.h>

using namespace std;

int mat[50][50],node;

int par[100],color[100];

void dfs(int x)
{
    if(color[x]==1)
    {
        return ;
    }

    int i;

    color[x] = 1;

    for(i=1;i<=node;i++)
    {
        if(mat[x][i]==1 && color[i]==0)
        {
            par[i] = x;

            dfs(i);
        }
    }
}

void path(int s,int e)
{
    if(s==e)
    {
        return;
    }

    if(par[e]==0)
    {
        printf(" --> No path");
        return;
    }

    path(s,par[e]);

    printf(" --> %d",e);
}

int main()
{
    int edge,i,j,a,b,x,start,nd;

    scanf("%d%d",&node,&edge);

    for(i=1;i<=edge;i++)
    {
        scanf("%d%d",&a,&b);

        mat[a][b] = 1;

        mat[b][a] = 1;
    }

    dfs(1);

    for(i=1;i<=node;i++)
    {
        printf(" %d",par[i]);
    }

    printf("\n");

    scanf("%d%d",&start,&nd);

    printf("%d",start);

    path(start,nd);

    printf("\n");

    return 0;
}

