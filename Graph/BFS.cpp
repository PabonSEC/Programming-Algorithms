#include<bits/stdc++.h>

using namespace std;

vector<int>graph[1000];

bool color[1000];

int cost[1000],node,source,dest,par[1000];

void path(int v)
{
    if(source==v)
    {
        cout<<source;
        return;
    }
    else if(par[v]==0)
    {
        cout<<"No path"<<endl;
        return;
    }
    else
    {
        path(par[v]);

        cout<<" --> "<<v;
    }
}

void BFS(int source)
{
    memset(color,0,sizeof(color));

    memset(cost,0,sizeof(cost));

    queue<int>Q;

    int u,i,len;

    color[source] = true;

    cost[source] = 0;

    Q.push(source);

    while(!Q.empty())
    {
        u = Q.front();

        Q.pop();

        len = graph[u].size();

        for(i=0;i<len;i++)
        {
            if(color[graph[u][i]]==false)
            {
                color[graph[u][i]] = true;

                cost[graph[u][i]] = cost[u]+1;

                Q.push(graph[u][i]);

                par[graph[u][i]] = u;
            }
        }
    }
}

int main()
{

    int edge,i,u,v;

    cin>>node>>edge;

    for(i=1;i<=edge;i++)
    {
        cin>>u>>v;

        graph[u].push_back(v);

        graph[v].push_back(u);
    }

    cout<<"\nSource and Destination : \n";

    cin>>source>>dest;

    BFS(source);

    cout<<endl;

    cout<<"\nCost from "<<source<<" to "<<dest<<" is : "<<cost[dest]<<endl<<endl;

    cout<<"Path from "<<source<<" to "<<dest<<" is : ";

    path(dest);

    cout<<endl;

    return 0;
}
