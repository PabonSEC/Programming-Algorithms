#include<bits/stdc++.h>
#define mx 100005

using namespace std;

int arr[mx];

struct info
{
    int sum,lazy;

}tree[mx*3];

void init(int node,int b, int e)
{
    int left,right,mid;

    if(b==e)
    {
        tree[node].sum = arr[b];
        return;
    }

    left=node<<1;
    right=(node<<1)+1;
    mid=(b+e)>>1;

    init(left,b,mid);

    init(right,mid+1,e);

    tree[node].sum = tree[left].sum+tree[right].sum;

}

void update(int node, int b, int e, int i, int j,int x)
{
    if(i>e || j<b)        /// Outside from the Segment
    {
        return;
    }
    if(b>=i && e<=j)      /// Relevant Segment
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].lazy+=x;
        return;
    }

    int left, right, mid;

    left=node<<1;
    right=left+1;
    mid=(b+e)>>1;

    update(left,b,mid,i,j,x);

    update(right,mid+1,e,i,j,x);

    tree[node].sum=tree[left].sum+tree[right].sum+tree[node].lazy*(e-b+1);
}

int query(int node, int b, int e, int i, int j, int carry=0)
{
    if(i>e || j<b)       /// Outside from the Segment
    {
        return 0;
    }
    if(b>=i && e<=j)     /// Relevant Segment
    {
        return tree[node].sum+carry*(e-b+1);
    }

    int left,right,mid,p1,p2;

    left=node<<1;
    right=left+1;
    mid=(b+e)>>1;

    p1= query(left,b,mid,i,j,carry+tree[node].lazy);

    p2= query(right,mid+1,e,i,j,carry+tree[node].lazy);

    return p1+p2;
}

int main()
{
    int n,i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    init(1,1,n);

    //cout<<tree[1].sum<<endl;

    update(1,1,5,1,3,2);

    cout<<query(1,1,5,1,3,0)<<endl;



    return 0;
}
