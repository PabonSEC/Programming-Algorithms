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

using namespace std;

int main()
{

    int n,i,j;

    string s;

    while(cin>>n)
    {
        char ch = 'a';

        for(i=0; i<n; i++)
        {
            s[i] = ch;

            ch++;
        }

        cout<<"\nAll Possible Subsets are : \n\n";

        bool tag = false;

        for(i=0; i<(1<<n); i++)
        {
            for(j=0; j<n; j++)
            {
                if(i & (1<<j))
                {
                    tag = true;

                    cout<<s[j];
                }
            }

            if(tag==false)
            {
                cout<<"{ }";
            }

            cout<<endl;
        }

        cout<<endl;
    }

    return 0;
}
