#include<bits/stdc++.h>
#define mx 1000

using namespace std;

string lcsString="";

char A[mx],B[mx];

int dp[mx][mx];

int lenA,lenB;

bool visited[mx][mx];

int calcLCS(int i,int j)
{
    if(A[i]=='\0' || B[j]=='\0')
    {
        return 0;
    }

    if(visited[i][j])
    {
        return dp[i][j];
    }

    int ans = 0;

    if(A[i]==B[j])
    {
        ans = 1+calcLCS(i+1,j+1);
    }
    else
    {
        int val1 = calcLCS(i,j+1);

        int val2 = calcLCS(i+1,j);

        ans = max(val1,val2);
    }

    visited[i][j] = true;

    dp[i][j] = ans;

    return dp[i][j];
}

void printLCS(int i,int j)
{
    if(A[i]=='\0' || B[j]=='\0')
    {
        cout<<lcsString<<endl;

        return ;
    }

    if(A[i]==B[j])
    {
        lcsString+=A[i];

        printLCS(i+1,j+1);
    }
    else
    {
        if(dp[i][j+1]>dp[i+1][j])
        {
            printLCS(i,j+1);
        }
        else
        {
            printLCS(i+1,j);
        }
    }
}

void printAll(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0')
    {
        cout<<lcsString<<endl;

        return;
    }
    if(A[i]==B[j])
    {
        lcsString+=A[i];

        printAll(i+1,j+1);

        lcsString.erase(lcsString.end()-1); //Delete last character
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])
        {
            printAll(i+1,j);
        }
        else if(dp[i+1][j]<dp[i][j+1])
        {
            printAll(i,j+1);
        }
        else
        {
            printAll(i+1,j);

            printAll(i,j+1);
        }
    }
}

int main()
{
    scanf("%s%s",A,B);

    lenA = strlen(A);

    lenB = strlen(B);

    printf("%d\n",calcLCS(0,0));

    printLCS(0,0);

    return 0;
}
