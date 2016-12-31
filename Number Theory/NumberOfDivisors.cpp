#include<bits/stdc++.h>
#define MAX 1000005

using namespace std;

vector<long long>prime;

bool check[MAX];

long long NumOfDivisor[MAX];

void sieve()
{
    long long i,j,k;

    k = sqrt(MAX);

    prime.push_back(2);

    for(i=3; i<=k; i+=2)
    {
        if(check[i]==0)
        {
            prime.push_back(i);

            for(j=i*i; j<MAX; j+=i+i)
            {
                check[j]=1;
            }
        }
    }
}

long long countDivisor(long long n)
{
    long long cnt = 1,divisor = 1,i,len = prime.size();

    for(i=0; i<len; i++)
    {
        if(n%prime[i]==0)
        {
            cnt = 1;

            while(n%prime[i]==0)
            {
                n/=prime[i];

                cnt++;
            }

            divisor*=cnt;
        }
    }

    return divisor;
}

void solve()
{
    long long i;

    NumOfDivisor[1] = 1;

    for(i=2; i<MAX; i++)
    {
        NumOfDivisor[i] = countDivisor(i);
    }

    return ;
}

int main()
{
    sieve();

    solve();

    long long n;

    while(cin>>n)
    {
        cout<<NumOfDivisor[n]<<endl;
    }

    return 0;
}
