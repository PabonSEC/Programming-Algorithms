#include<bits/stdc++.h>
#define M 1000005

using namespace std;

int phi[M];

void calculatePhi()
{
    int i,p,k;

    for(i=1 ; i<M ; i++) phi[i] = i;

    for(p=2 ; p<M ; p++)
    {
        if(phi[p]==p) // p যদি প্রাইম হয়
        {
            for(k=p ; k<M ; k+=p)
            {
                phi[k]-=phi[k]/p;
            }
        }
    }

    return ;
}


int main()
{
    int n;

    calculatePhi();

    while(cin>>n)
    {
        cout<<phi[n]<<endl;
    }

    return 0;
}
