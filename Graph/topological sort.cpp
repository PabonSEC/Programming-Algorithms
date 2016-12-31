#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define max 101
using namespace std;
int mat[max][max];
int indeg[max];
int arr[max];
int main()
{
    int n,e,node,edge,M,N,i,j,u;
    while(scanf("%d%d",&node,&edge)==2)
    {
        memset(mat,0,sizeof(mat));
        memset(indeg,0,sizeof(indeg));
        memset(arr,0,sizeof(arr));
        for(e=1;e<=edge;e++)
        {
            scanf("%d%d",&M,&N);
            mat[M][N]=1;
            indeg[N]++;
        }
        queue<int>Q;
        j=0;
        for(n=1;n<=node;n++)
        {
            if(indeg[n]==0)
            {
                Q.push(n);
            }
        }
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
            arr[j++]=u;
            for(i=1;i<=node;i++)
            {
                if(mat[u][i]==1)
                {
                    indeg[i]--;
                    if(indeg[i]==0)
                    {
                        Q.push(i);
                    }
                }
            }
        }
        for(i=0;i<j;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    return 0;
}

