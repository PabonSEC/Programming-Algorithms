#include<bits/stdc++.h>

using namespace std;

void ConvertToBinary(int n)
{
    if (n / 2 != 0)
    {
        ConvertToBinary(n / 2);
    }

    printf("%d", n % 2);
}

int main()
{
    int a;

    while(cin>>a)
    {
        cout<<"\nBinary of "<<a<<" is : ";

        ConvertToBinary(a);

        cout<<endl<<endl;
    }

    return 0;
}
