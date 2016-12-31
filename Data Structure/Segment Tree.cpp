#include<cstdio>
#include<iostream>
#include<algorithm>
#define mx 100001

using namespace std;

int arr[mx];

int tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }

    int left=node*2;

    int right=node*2+1;

    int mid=(b+e)/2;

    init(left,b,mid);

    init(right,mid+1,e);

    tree[node]=tree[left]+tree[right];

}

int query(int node,int b,int e,int i,int j)
{

    if(i>e||j<b)           /// Outside from the Segment
    {
        return 0;
    }

    if(b>=i && e<=j)       /// Relevant Segment
    {
        return tree[node];
    }

    int left=node*2;

    int right=node*2+1;

    int mid=(b+e)/2;

    int p1=query(left,b,mid,i,j);

    int p2=query(right,mid+1,e,i,j);

    return p1+p2;
}

void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e||i<b)           /// Outside from the Segment
    {
        return;
    }

    if(b>=i && e<=i)       /// Relevant Segment
    {
        tree[node]=newvalue;
        return ;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    update(left,b,mid,i,newvalue);

    update(right,mid+1,e,i,newvalue);

    tree[node]=tree[left]+tree[right];
}

int main()
{
    int n,x,i;

    while(scanf("%d",&n)==1)
    {
        for(x=1; x<=n; x++)
        {
            scanf("%d",&arr[x]);
        }
        init(1,1,n);

        cout<<query(1,1,n,2,6)<<endl;

        update(1,1,n,2,0);

        cout<<query(1,1,n,2,6)<<endl;
    }

    return 0;
}
