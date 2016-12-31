

///** Sample Input:
///      7 11       number_of_node = 7 and number_of_edge = 11;
///      1 2 7      connection between u = 1 and v = 2 & the cost of edge 1-2 is---> cost = 7;
///      1 4 5
///      2 3 8
///      2 4 9
///      4 6 6
///      5 6 8
///      2 5 7
///      3 5 5
///      5 7 9
///      6 7 11
///      4 5 15


///** Sample Output:

///   Minimum Spanning Tree is : 39



#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 100009
using namespace std;
struct node
{
    int u,v,cost;
} arr[100009];
int par[MAX];
bool cmp(node lhs,node rhs)
{
    return lhs.cost<rhs.cost;
}
int khoj_rep(int r)
{
    if(par[r]==r)
    {
        return r;
    }
    else
    {
        return par[r]=khoj_rep(par[r]);
    }
}
int main()
{
    int n,m,i,j,u,v,cost,u1,v1,counter,sum;       ///**   n = koyta_node, m = koyta_pair;  **///
    while(cin>>n>>m)
    {
        for(i=0; i<m; i++)
        {
            cin>>arr[i].u>>arr[i].v>>arr[i].cost;
        }
        sort(arr,arr+m,cmp);
        cout<<endl<<endl;
//        for(i=0;i<m;i++)
//        {
//            cout<<arr[i].cost<<" "<<arr[i].u<<" "<<arr[i].v<<endl;
//        }
        for(j=1; j<=n; j++)
        {
            par[j]=j;
        }
        counter=0;
        sum=0;
        for(i=0; i<m; i++)
        {
            u1=khoj_rep(arr[i].u);
            v1=khoj_rep(arr[i].v);
            if(u1!=v1)
            {
                par[u1]=v1;
                counter++;
                sum+=arr[i].cost;
                if(counter==n-1)
                {
                    break;
                }

            }
        }
        cout<<"Minimum Spanning Tree is : "<<sum<<endl<<endl;
    }

    return 0;
}
