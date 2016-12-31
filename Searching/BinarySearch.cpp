/*
Sample Input:
5
1 4 7 10 15

10
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, first, last, middle, n, m, arr[100];

    scanf("%d",&n);

    for ( i = 0 ; i < n ; i++ )
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&m);

    int found=0;

    first = 0;

    last = n - 1;

    middle = (first+last)/2;

    while( first <= last )
    {
        if ( arr[middle] < m )
        {
            first = middle + 1;
        }

        else if ( arr[middle] == m )
        {
            found=1;
            break;
        }
        else
        {
            last = middle - 1;
        }

        middle = (first + last)/2;
    }

    if (found == 1 )
        printf("%d found at location %d.\n", m, middle+1);

    else
        printf("Not found! %d is not present in the list.\n", m);

    return 0;
}


