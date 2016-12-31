///    Sample Input:
///           9 8     //*node,edge
///           0 1
///           0 2
///           0 3
///           0 8
///           2 4
///           4 5
///           5 6
///           5 7
///           3 5     //*LCA of p and q

///    Sample Output:
///    The LCA of 3 and 5 is 0

#include<bits/stdc++.h>
#define mx 100002
using namespace std;

int L[mx];
int par[mx];
int sparse_table[mx][22];
vector<int>graph[mx];

void dfs(int from,int u,int depth)
{
    par[u]=from;
    L[u]=depth;

    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(v==from)
        {
            continue;
        }
        dfs(u,v,depth+1);
    }
}

int LCA_query(int node,int p,int q)
{
    int temp,log,i;

    if(L[p]<L[q])
    {
        temp=p;
        p=q;
        q=temp;
    }

    log=1;

    for(;;)
    {
        int next=log+1;
        if(1<<next>L[p])
        {
            break;
        }
        log++;
    }

    for(i=log;i>=0;i--)
    {
        if(L[p]-(1<<i)>=L[q])
        {
            p=sparse_table[p][i];
        }
    }

    if(p==q)
    {
        return p;
    }

    for(i=log ; i>=0 ; i--)
    {
        if(sparse_table[p][i]!=-1 && sparse_table[p][i]!=sparse_table[q][i])
        {
            p = sparse_table[p][i];
            q = sparse_table[q][i];
        }
    }

    return par[p];
}

void LCA_init(int node)
{
    memset(sparse_table,-1,sizeof(sparse_table));
    int i,j;

    for(i=0;i<node;i++)
    {
        sparse_table[i][0]=par[i];
    }

    for(j=1; (1<<j) < node;j++)
    {
        for(i=0;i<node;i++)
        {
            if(sparse_table[i][j-1]!=-1)
            {
                sparse_table[i][j]=sparse_table[sparse_table[i][j-1]][j-1];
            }
        }
    }
}

int main()
{
    int node,edge,a,b,p,q,lca,i;
    while(scanf("%d%d",&node,&edge)==2)
    {
        for(i=0;i<edge;i++)
        {
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
        }
        dfs(0,0,0);

        LCA_init(node);
        scanf("%d%d",&p,&q);
        lca = LCA_query(node,p,q);
        printf("The LCA of %d and %d is %d\n",p,q,lca);
    }
    return 0;
}
