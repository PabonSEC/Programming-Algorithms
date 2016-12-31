#include<bits/stdc++.h>

using namespace std;

int x,y,d;

int ExtendedEuclid(int a,int b)
{
    if(b==0)
    {
        x=1,y=0,d=a;

        return d;
    }

    int ret = ExtendedEuclid(b,a%b);

    int x1 = y;

    int y1 = x-(a/b)*y;

    cout<<"\nX = "<<x<<" Y = "<<y<<endl;

    cout<<"\nX1 = "<<x1<<" Y1 = "<<y1<<endl;

    x = x1;

    y = y1;

    return ret;
}

int main()
{
    int a,b;

    while(scanf("%d%d",&a,&b)==2)
    {
        int gcd = ExtendedEuclid(a,b);

        cout<<"\n\nGcd = "<<gcd<<"\nX = "<<x<<" Y = "<<y<<endl;
    }

    return 0;
}
