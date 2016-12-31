#include<bits/stdc++.h>
#define sz 100
using namespace std;

int profit[sz][sz];
int track[sz];
int values[sz];
int weight[sz];

int main()
{
    int items,knapsack_weight,i,j,w,a,b;
    while(scanf("%d%d",&items,&knapsack_weight)==2)
    {
        for(i=0;i<=items;i++)
        {
            profit[i][0]=0;

        }

        for(j=0;j<=knapsack_weight;j++)
        {
            profit[0][j]=0;
        }

        for(i=1;i<=items;i++)
        {
            scanf("%d%d",&weight[i],&values[i]);
        }

        for(i=1;i<=items;i++)
        {
            for(w=1;w<=knapsack_weight;w++)
            {
                if(weight[i]>w)
                {
                    profit[i][w]=profit[i-1][w];
                }
                else
                {
                    a = profit[i-1][w];
                    b = profit[i-1][w-weight[i]]+values[i];
                    if(a>b)
                    {
                        profit[i][w]=a;
                    }
                    else
                    {
                        profit[i][w]=b;
                        track[profit[i][w]]=i;
                    }
                }
            }
        }

        printf("\n%d\n",profit[items][knapsack_weight]);
    }


    return 0;
}
