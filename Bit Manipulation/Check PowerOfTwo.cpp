/***

Bismillahir Rahmanir Rahim

 _______
|   __  \           _____
|  |__|  )_______   |   /     ____    ______
|   ____/ \__    \  |  |__   /    \  |      \
|  (        / __  \ |  __ \ /  __  \ |   /\  \
|  |       (____  / |     / \      / |__/  \  )
|__|            \/  |____/   \____/         \/


***/

#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define sz 100005
#define sz1 1000005
#define inf 0x3f3f3f3f
#define endl "\n"

using namespace std;

bool isPowerOfTwo(int n)
{
    return (n && !(n & (n-1)));
}


int main()
{

    int n;

    while(cin>>n)
    {
        if(isPowerOfTwo(n))
        {
            cout<<endl<<n<<" can be written as a power of Two\n\n";
        }
        else
        {
            cout<<endl<<n<<" can't be written as a power of Two\n\n";
        }
    }

    return 0;
}
