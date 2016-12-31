#include<bits/stdc++.h>

using namespace std;

int queen[20],cnt;

int column[20],diagonal1[40],diagonal2[40];

void Eight_Queen(int _at,int n)
{
    int i;

    if(_at==n+1)
    {
        cnt++;

        printf("(row - column)\n");

        for(i=1; i<=n; i++)
        {
            printf("(%d - %d)\n",i,queen[i]);
        }

        return ;
    }


    for(i=1; i<=n; i++)
    {
        if(column[i] || diagonal1[i+_at] || diagonal2[n+i-_at])
            continue;

        queen[_at] = i;

        column[i] = diagonal1[i+_at] = diagonal2[n+i-_at] = 1;

        Eight_Queen(_at+1,n);

        column[i] = diagonal1[i+_at] = diagonal2[n+i-_at] = 0;
    }
}

int main()
{
    Eight_Queen(1,8);

    cout<<cnt<<endl;

    return 0;
}

