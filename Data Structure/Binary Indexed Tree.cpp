#include<bits/stdc++.h>
#define mx 100003
using namespace std;
int BITree[mx],n;
int arr[mx];
long long Query(int index)
{
    long long sum=0;
    while(index>0)
    {
        sum+=BITree[index];
        index = index - (index & -index);
    }
    return sum;
}

void update(int index,int add)
{
    index++;
    while(index<=n)
    {
        BITree[index]+=add;
        index = index + (index & -index);
    }
}

void makeBIT()
{
    for(int i=0;i<n;i++)
    {
        update(i,arr[i]);
    }
}

int main()
{
    int query,i,j,choice,index,add;
    long long result;
    while(scanf("%d%d",&n,&query)==2)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }

        makeBIT();

        for(j=0;j<query;j++)
        {
            scanf("%d",&choice);
            if(choice==1)
            {
                scanf("%d%d",&index,&add);
                update(index+1,add);
            }
            else if(choice==2)
            {
                scanf("%d",&index);
                result=Query(index+1);
                printf("The total sum from index 0 to index %d is %lld\n\n",index,result);
            }
        }
        memset(BITree,0,sizeof BITree);
    }
    return 0;
}
