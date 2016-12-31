#include<bits/stdc++.h>

using namespace std;

int cumulative_sum[105][105];

int grid[105][105];

int main()
{
    int row,column,i,j,k;

    while(scanf("%d",&row)==1)
    {
        column=row;

        for(i=1; i<=row; i++)
        {
            for(j=1; j<=column; j++)
            {
                scanf("%d",&grid[i][j]);
            }
        }

        for(j=1; j<=column; j++)
        {
            for(i=1; i<=row; i++)
            {
                cumulative_sum[i][j]=grid[i][j]+cumulative_sum[i-1][j];
            }
        }

        int sub,sum,max_sum=0;

        for(k=0; k<row; k++)
        {

            for(i=k+1; i<=row; i++)
            {

                sum=0;

                for(j=1; j<=column; j++)
                {
                    sub = cumulative_sum[i][j]-cumulative_sum[k][j];

                    sum += sub;

                    max_sum = max(sum,max_sum);

                    if(sum<0)
                    {
                        sum=0;
                    }

                }
            }
        }

        printf("%d\n",max_sum);

        memset(cumulative_sum,0,sizeof(cumulative_sum));

    }

    return 0;
}
