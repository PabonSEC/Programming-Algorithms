#include<bits/stdc++.h>

using namespace std;

long long cal(long long N,long long x)
{

    long long cnt=0,dv=x;

    while(dv<=N)
    {
        cnt+=N/dv;
        dv*=x;
    }
    return cnt;
}

int main()
{
    long long cnt,N;

    while(cin>>N)
    {
        cnt=cal(N,5);
        if(cnt>1)
        cout<<"There are "<<cnt<<" trailing zeros of "<<N<<"!"<<endl;
        else
            cout<<"There is "<<cnt<<" trailing zero of "<<N<<"!"<<endl;
    }

    return 0;
}

