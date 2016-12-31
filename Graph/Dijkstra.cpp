///**

///  Input :

///  4 5              ///city-->4 & number_of_road-->5
///  1 2 4
///  2 3 1
///  3 4 2
///  4 2 5
///  1 4 10
///  1 4

///  Output:

///  The shortest distance between 1 & 4 is 7



#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 100
using namespace std;

vector<int>mat[MAX],cost[MAX];
int koyta_node,koyta_edge,i,j,k,a,b,w,strt,nd,len;

int dist[MAX];

struct node
{
    int city,distance;
};

struct cmp
{
    bool operator()(node lhs,node rhs)
    {
        return lhs.distance<rhs.distance;
    }
};
void dijkstra(int source,int destination)
{
    memset(dist,63,sizeof(dist));

    priority_queue<node,vector<node>,cmp>q;

    node u,v;

    u.city=source;
    u.distance=0;
    q.push(u);

    dist[source]=0;

    while(!q.empty())
    {
        u = q.top();
        q.pop();
        int ucost = dist[u.city];

        len=mat[u.city].size();

        for(i=0; i<len; i++)
        {
            v.city = mat[u.city][i];
            v.distance = cost[u.city][i]+ucost;
            // relaxing :)
            if(dist[v.city] > v.distance)
            {
                dist[v.city] = v.distance;
                q.push(v);
            }
        }
    }
}

int main()
{
    while(cin>>koyta_node>>koyta_edge)
    {
        for(i=0; i<koyta_edge; i++)
        {
            cin>>a>>b>>w;

            mat[a].push_back(b);
            mat[b].push_back(a);
            cost[a].push_back(w);
            cost[b].push_back(w);

        }
        cin>>strt>>nd;

        dijkstra(strt,nd);

        printf("The shortest distance between %d & %d is %d\n",strt,nd,dist[nd]);

        //mat[MAX].clear();
        //cost[MAX].clear();
    }
    return 0;
}
