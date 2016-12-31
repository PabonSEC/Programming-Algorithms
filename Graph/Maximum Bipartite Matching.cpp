/*

4 4
6
1 2
1 3
2 2
2 4
3 3
4 2

*/


#include<bits/stdc++.h>

using namespace std;

int visit[500],match[500];

vector<int>v[500];

int dfs(int node)
{
    int x=v[node].size();

    for(int i=0; i<x; i++)
    {
        int j=v[node][i];

        if(visit[j])
        {
            continue;
        }

        visit[j]=1;

        if(match[j]<0 || dfs(match[j]))
        {
            match[j] = node;

            return 1;
        }
    }
    return 0;
}



int main()
{

    int i,j,k,koyta_man,koyta_women,koyta_pair,a,b,cnt;

    scanf("%d %d",&koyta_man,&koyta_women);

    scanf("%d",&koyta_pair);

    for(i=1; i<=koyta_pair; i++)
    {
        scanf("%d %d",&a,&b);

        v[a].push_back(b);
    }

    cnt=0;

    memset(match,-1,sizeof(match));

    for(i=1; i<=koyta_man; i++)
    {

        memset(visit,0,sizeof(visit));

        if(dfs(i))
        {
            cnt++;
        }
    }

    printf("\nans= %d\n",cnt);

    for(i=1;i<=koyta_man;i++)
    {
        printf("%d %d\n",i,match[i]);
    }

    return 0;
}
