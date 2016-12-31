

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
///   2nd Minimum Spanning Tree is : 40



#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX 100009
using namespace std;
struct node
{
    int u,v,cost;
} arr[100009];
int par[MAX];
int arr1[MAX];
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
    int n,m,i,j,u,v,cost,u1,v1,counter,sum,a,sum1,minimum,value,b;       ///**   n = koyta_node, m = koyta_pair;  **///
    while(cin>>n>>m)
    {
        for(i=0; i<m; i++)
        {
            cin>>arr[i].u>>arr[i].v>>arr[i].cost;
        }
        sort(arr,arr+m,cmp);
        cout<<endl<<endl;
        for(j=1; j<=n; j++)
        {
            par[j]=j;
        }
        counter=0;
        sum=0;
        a=0;
        for(i=0; i<m; i++)
        {
            u1=khoj_rep(arr[i].u);
            v1=khoj_rep(arr[i].v);
            if(u1!=v1)
            {
                par[u1]=v1;
                counter++;
                arr1[a++]=i;
                sum+=arr[i].cost;
                if(counter==n-1)
                {
                    break;
                }

            }
        }
//        for(i=0; i<a; i++)
//        {
//            printf("%d\n",arr1[i]);
//        }
        minimum=10000;
        a=0;
        memset(par,0,sizeof(par));
        for(i=0; i<counter; i++)
        {
            for(j=1; j<=n; j++)
            {
                par[j]=j;
            }
            sum1=0;
            for(j=0; j<m; j++)
            {
                if(j==arr1[i])
                {
                    continue;
                }
                u1=khoj_rep(arr[j].u);
                v1=khoj_rep(arr[j].v);
                if(u1!=v1)
                {
                    par[u1]=v1;
                    sum1+=arr[j].cost;
                }
            }
            if(sum1>sum)
            {
                b=min(sum1,minimum);
                minimum=sum1;
                a=1;
            }
            memset(par,0,sizeof(par));
        }
        cout<<"Minimum Spanning Tree is : "<<sum<<endl<<endl;
        if(a==1)
        {
            cout<<"2nd Minimum Spanning Tree is : "<<b<<endl;
        }
        else
        {
            cout<<"2nd Minimum Spanning Tree is : "<<sum<<endl;
        }
        memset(par,0,sizeof(par));
        memset(arr1,0,sizeof(arr1));
    }
    return 0;
}

