#include<bits/stdc++.h>

using namespace std;

int phi(int n)
{
    int ret = n,i;

    for(i=2 ; i*i<=n ; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }

            ret-=ret/i;
        }
    }

    if(n>1)
    {
        ret-=ret/n;
    }

    return ret;
}

int main()
{

    int n;

    while(cin>>n)
    {
        cout<<"\nThere are "<<phi(n)<<" numbers from 1 to "<<n<<" each of which with "

        <<n<<" the GCD is 1\n"<<endl;
    }

    return 0;
}

