#include<bits/stdc++.h>

using namespace std;

int dp[20000005];

void pre()
{
    int i;

    dp[1] = 0;

    for(i=2;i<=20000002;i++)
    {
        dp[i] = 1+dp[i-1];

        if(i%2==0) dp[i] = min(dp[i],1+dp[i/2]);

        if(i%3==0) dp[i] = min(dp[i],1+dp[i/3]);
    }

    return;
}

int main()
{

    pre();

    int test,n,i;

    scanf("%d",&test);

    for(i=1;i<=test;i++)
    {
        scanf("%d",&n);

        printf("Case %d: %d\n",i,dp[n]);
    }

    return 0;
}

