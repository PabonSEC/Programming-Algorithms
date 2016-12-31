#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

#define MAX 250

using namespace std;




vector<int>connec[MAX];

int par[MAX],start[MAX],low[MAX],child,p,coun,tm,res[MAX][MAX];

int colour[MAX];



void dfs( int u)
{
    int v,j;


    tm++;

    colour[u]=1;

    low[u]=tm;

    start[u]=tm;

    child=0;

    for(j=0; j<connec[u].size(); j++)
    {

        v= connec[u][j];

        if(colour[v]==0)
        {

            child++;

            par[v]=u;

            dfs(v);

            if(low[v]>start[u])
            {


                res[v][u]=res[u][v]=1;
                p++;
                coun++;
            }

            low[u]=min(low[u],low[v]);

        }

        else if(v!=par[u])
        {
            low[u]=min(low[u],start[v]);
        }
    }

}


int main()
{

    int test=0,n,koyta_node,kon_node,koyta,i,j,n1,k,point,value,koyta_pair;


    while(scanf("%d %d",&koyta_node,&koyta_pair)==2)
    {

        p=0;
        coun=0;

        for(i=0; i<MAX; i++)
        {

            connec[i].clear();

        }


        for(i=1; i<=koyta_pair; i++)

        {


            scanf("%d %d",&n1,&kon_node);

            connec[kon_node].push_back(n1);

            connec[n1].push_back(kon_node);


        }


        for(i=1; i<=koyta_node; i++)
        {
            par[i]=-1;
        }

        tm=0;

        for(i=1; i<=koyta_node; i++)
        {

            if(colour[i]==0)
            {
                dfs(i);
            }
        }


        printf("%d critical links\n",coun);


        for(i=1; i<=koyta_node; i++)
        {

            for(j=1; j<=koyta_node; j++)
            {
                if(res[i][j]==1)
                {
                    printf("%d %d\n",i,j);
                }
            }

        }

        printf("\n");


        memset(colour,0,sizeof(colour));
        memset(start,0,sizeof(start));
        memset(low,0,sizeof(low));
        memset(res,0,sizeof(res));


    }

    return 0;
}


