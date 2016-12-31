/*

Complexity O(NLogN)

*/

#include<bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int sequence[32],n;

int L[32];

int I[32];

int LIS_sequence[32];

int LisNlogN()
{
    int i;

    I[0] = -inf;

    for(i=1; i<=n; i++)
    {
        I[i] = inf;
    }

    for(i=1; i<=n; i++)
    {
        L[i] = 1;
    }

    int Lislength = 0;

    for(i=0; i<n; i++)
    {
        int low,high,mid;

        low = 0;

        high = Lislength;

        while(low<=high)
        {
            mid = (low+high)/2;

            if(I[mid]<sequence[i])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        I[low] = sequence[i];

        L[i] = low;

        if(Lislength<low)
        {
            Lislength = low;
        }
    }

    return Lislength;
}

void findSequence(int maxLength)
{
    int i,j;

    i = 0;

    for(j=1;j<n;j++)
    {
        if(L[j]>L[i])
        {
            i = j;
        }
    }

    int top = L[i] - 1;

    LIS_sequence[top] = sequence[i];

    top--;

    for(j = i-1 ; j>=0 ; j--)
    {
        if( sequence[j]<sequence[i] && (L[j] == L[i]-1) )
        {
            i = j;

            LIS_sequence[top] = sequence[i];

            top--;
        }
    }

    cout<<"LIS is : ";

    for(i=0;i<maxLength;i++)
    {
        cout<<LIS_sequence[i]<<" ";
    }

    cout<<endl;
    cout<<endl;

    return ;
}


int main()
{

    int i;

    scanf("%d",&n);

    for(i=0; i<n; i++)
        scanf("%d",&sequence[i]);

    int result = LisNlogN();

    cout<<endl<<"Length of LIS is--> "<<result<<endl<<endl;

    findSequence(result);

    return 0;
}
