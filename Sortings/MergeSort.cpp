#include <iostream>
#define sz 100
#define INF 0x3f3f3f3f

using namespace std;

long long num,arr[sz];


void Merge(long long p,long long q,long long r)
{

    long long left[sz],right[sz],i,j,k;

    long long n1 = q-p+1 , n2 = r-q;


    for(i=1; i<=n1; i++)
        left[i] = arr[p+i-1];

    for(i=1; i<=n2; i++)
        right[i] = arr[q+i];


    left[n1+1] = INF;

    right[n2+1] = INF;

    i=j=1;


    for(k=p; k<=r; k++)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];

            j++;
        }
    }
}


void merge_sort(long long p,long long r)
{

    long long q;


    if(p<r)
    {
        q=(p+r) /2;

        merge_sort(p,q);

        merge_sort(q+1,r);

        Merge(p,q,r);
    }
}


int main()
{

    long long i;

    cout<<"How many numbers are in the array : ";

    while(cin>>num)
    {
        cout<<endl;
        for(i=1; i<=num; i++)
            cin>>arr[i];

            cout<<"\n----------------\n\n";


        merge_sort(1,num);


        cout<<"Numbers in sorted order : \n\n";

        for(i=1; i<=num ; i++)
            cout<<"  "<<arr[i];

            cout<<endl;

            cout<<"\n----------------\n\n";

            cout<<"How many numbers are in the array : ";
    }
    return 0;
}
