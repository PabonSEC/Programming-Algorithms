#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#define SZ 10009
using namespace std;

long N,M,l;

vector<long>graph[SZ];

long color[SZ];
long topsort[SZ];

void DFS(long p)
{
    color[p]=1;
    for(long k=0; k<graph[p].size(); k++)
    {
        if(color[graph[p][k]]==0)
        {
            DFS(graph[p][k]);
        }
    }
    topsort[l++]=p;
}

int main()
{
    long i,j,counter,test,x,MIN,a,b,u;
    scanf("%ld",&test);
    for(x=1; x<=test; x++)
    {
        scanf("%ld%ld",&N,&M);

        for(i=1; i<=M; i++)
        {
            scanf("%ld%ld",&a,&b);
            graph[a].push_back(b);
        }

        l=0;

        for(j=1; j<=N; j++)
        {
            if(color[j]==0)
            {
                DFS(j);
            }
        }
        counter=0;
        for(i=l-1;i>=0;i--)
        {
            printf(" %d",topsort[i]);
        }

        printf("\n");
        for(i=0; i<=N; i++)
        {
            graph[i].clear();
        }
        memset(color,0,sizeof(color));
    }
    return 0;
}
