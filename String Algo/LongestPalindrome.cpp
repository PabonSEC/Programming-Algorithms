/***

Bismillahir Rahmanir Rahim

 _______
|   __  \           _____
|  |__|  )_______   |   /     ____    ______
|   ____/ \__    \  |  |__   /    \  |      \
|  (        / ___ \ |  __ \ /  __  \ |   /\  \
|  |       (____  / |     / \      / |__/  \  )
|__|            \/  |____/   \____/         \/


Algorithm  : Longest Palindrome

***/

#include<bits/stdc++.h>

#define sz 500

using namespace std;

int dp[sz][sz];

int main()
{
    string s;

    int len,i,j;

    while(cin>>s)
    {
        len = s.length();

        for(i=0; i<=len; i++)
            dp[0][i] = dp[i][0] = 0;

        for(i=1; i<=len; i++)
        {
            for(j=1; j<=len; j++)
            {
                if(s[i-1]==s[len-j]) dp[i][j] = dp[i-1][j-1]+1;

                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

            }
        }

        cout<<dp[len][len]<<endl;
    }
    return 0;
}
