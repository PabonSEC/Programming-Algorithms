#include<stdio.h>
#include<math.h>
#include<vector>
#define MAX 47000
#define MAX1 100005

using namespace std;

bool arr[MAX];

long long int N=1001;

void sieve()
{
    long long int i,j,k;

    k=sqrt(MAX);

    for(i=3;i<=k;i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<MAX;j+=i+i)
            {
                arr[j]=1;
            }
        }
    }

    arr[1]=1;

    for(i=4;i<MAX;i=i+2)
    {
        arr[i]=1;
    }
}

int main()
{
    sieve();
    long long int i;
    vector<int>prime;
    prime.push_back(2);
    for(i=3;i<MAX;i+=2)
    {
        if(arr[i]==0)
        {
            prime.push_back(i);
        }
    }
    //printf("")
    //long long int a=prime.size();
    for(i=46000;i<47000;i++)
    {
        if(arr[i]==0)
        printf("%d ",i);
    }
    //printf("%lld\n",a);
    return 0;
}
