#include<stdio.h>
#define max 1000
int mat[max][max];
int cost[max],color[max],queue[max];
int main()
{
    int node,start,edge,i,m,n,front,rear,a,b,j;
    memset(cost,0,1000);
    memset(color,0,1000);
    printf("How many node & edge::\n");
    scanf("%d%d",&node,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d%d",&m,&n);
        mat[m][n]=1;
        mat[n][m]=1;
    }
    printf("Starting node::\n");
    scanf("%d",&start);
    front=rear=0;
    queue[rear++]=start;
    color[start]=1;
    while(front!=rear)
    {
        a=queue[front++];
        for(j=1;j<=node;j++)
        {
            if(mat[a][j]==1&&color[j]!=1)
            {
                color[j]=1;
                queue[rear++]=j;
                cost[j]=cost[a]+1;
            }
        }
    }
    printf("Whose cost::\n");
    scanf("%d",&b);
    printf("Cost is %d\n",cost[b]);
    return 0;
}
