#include<bits/stdc++.h>
#define sz 1010
using namespace std;
int lcs[sz][sz];
char s[sz];
char s1[sz];
int main()
{
    int lens,lens1,i,j,a,b;
    while(gets(s))
    {
        gets(s1);

        lens=strlen(s);
        lens1=strlen(s1);

        for(i=1;i<=lens;i++)
        {
            for(j=1;j<=lens1;j++)
            {
                if(s[i-1]==s1[j-1])
                {
                    lcs[i][j]=lcs[i-1][j-1]+1;
                }
                else
                {
                    a=lcs[i-1][j];
                    b=lcs[i][j-1];
                    lcs[i][j]=max(a,b);
                }
            }
        }

        printf("%d\n",lcs[lens][lens1]);

        memset(lcs,0,sizeof(lcs));

    }
    return 0;
}

