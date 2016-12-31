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

int Z[10000],len;

string s;

void Z_Algo()
{
    len = s.length();

    int position,start_point,end_point;

    Z[0] = len;

    for(position=1,start_point=0,end_point=0;position<len;position++)
    {
        if(position<=end_point)
        {
            Z[position] = min(end_point-position+1,Z[position-start_point]);
        }

        while(position+Z[position]<len && s[Z[position]]==s[position+Z[position]])
        {
            ++Z[position];
        }

        if(position+Z[position]-1 > end_point)
        {
            start_point = position;
            end_point = position+Z[position]-1;
        }
    }

    return;
}

int main()
{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin>>s;

    int i;

    Z_Algo();

    for(i=0;i<len;i++)
    {
        cout<<Z[i]<<" ";
    }

    cout<<endl;

    return 0;
}

