#include<bits/stdc++.h>

using namespace std;
struct data
{
    int u,v;
} arr[205];

int color[205];

bool mat[203][203];

queue<int>Q;

int main()
{
    int n,l,i,a,b,c,counter;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&l);

        for(i=1; i<=l; ++i)
        {
            scanf("%d%d",&a,&b);
            mat[a][b]=1;
            mat[b][a]=1;
        }

        counter=1;
        Q.push(0);
        color[0]=1;

        while(!Q.empty())
        {
            c=Q.front();
            Q.pop();
            if(counter>0)
            {
                for(i=0; i<n; ++i)
                {
                    if(mat[c][i]==1 && color[c]==1 && (color[i]!=1&&color[i]!=2))
                    {
                        color[i]=2;
                        Q.push(i);
                        counter++;
                    }
                    else if(mat[c][i]==1 && color[c]==2 && (color[i]!=1&&color[i]!=2))
                    {
                        color[i]=1;
                        Q.push(i);
                        counter++;
                    }
                    else if(mat[c][i]==1 && color[c]==color[i])
                    {
                        counter=0;
                        break;
                    }
                }
            }
        }
        if(counter>0)
        {
            printf("BICOLORABLE.\n");
        }
        else
        {
            printf("NOT BICOLORABLE.\n");
        }

        memset(color,0,sizeof(color));
        memset(mat,0,sizeof(mat));
    }
    return 0;
}
