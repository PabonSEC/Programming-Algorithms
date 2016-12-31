///  Sample Input:

///  8 14      ///node = 8  && Edge = 14
///  2 1
///  1 5
///  5 2
///  6 2
///  6 5
///  6 7
///  7 6
///  3 4
///  4 3
///  3 2
///  7 3
///  8 7
///  8 8
///  8 4

/// Sample Output:

/// There are 4 strongly connected components for the given graph.

#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#define SZ 50
using namespace std;
vector<int>graph1[SZ],graph2[SZ];


int color[SZ],topsort[SZ],k,counter;

void DFS(int p)
{
    color[p]=1;
    int len=graph1[p].size();
    for(int x=0; x<len; x++)
    {
        if(!color[graph1[p][x]])
        {
            DFS(graph1[p][x]);
        }
    }
    topsort[k]=p;
    k++;

}

void DFS1(int q)
{
    color[q]=1;
    int len=graph2[q].size();
    for(int y=0; y<len; y++)
    {
        if(!color[graph2[q][y]])
        {
            DFS1(graph2[q][y]);
        }
    }
}
int main()
{
    int koyta_node,koyta_edge,i,j,a,b,x,y;
    while(cin>>koyta_node>>koyta_edge)
    {
        for(i=1; i<=koyta_edge; i++)
        {
            cin>>a>>b;
            graph1[a].push_back(b);
            graph2[b].push_back(a);
        }
        k=0;
        for(i=1; i<=koyta_node; i++)
        {
            if(color[i]==0)
            {
                DFS(i);
            }
        }
        memset(color,0,sizeof(color));
        counter=0;
        for(i=k-1; i>=0; i--)
        {
            int u=topsort[i];
            if(!color[u])
            {
                counter++;
                DFS1(u);
            }
        }

        printf("\n");
        printf("There are %d strongly connected components for the given graph.\n\n",counter);
        for(i=0; i<koyta_node; i++)
        {
            graph1[i].clear();
        }
        memset(color,0,sizeof(color));
    }
    return 0;
}
