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

int arr[100];

void MakeHeap(int i, int n)
{
    int j, temp;

    temp = arr[i];

    j = 2*i;

    while (j <= n)
    {
        if (j < n && arr[j+1] > arr[j])
        {
            j++;
        }

        if (temp > arr[j])
            break;

        else if (temp <= arr[j])
        {
            arr[j/2] = arr[j];

            j = 2*j;
        }
    }

    arr[j/2] = temp;
}

void HeapSort(int n)
{
    int i, temp;

    for (i = n; i >= 2; i--)
    {
        temp = arr[i];

        arr[i] = arr[1];

        arr[1] = temp;

        MakeHeap(1, i - 1);
    }
}

void Build_MaxHeap(int n)
{
    int i;

    for(i = n/2; i >= 1; i--)
    {
        MakeHeap(i, n);
    }
}

int main()
{
    int n, i;

    printf("Enter the number of elements to sort : ");

    scanf("%d",&n);

    printf("\n\nElements are : ");

    for (i = 1; i <= n; i++)
    {
        scanf("%d",&arr[i]);
    }

    Build_MaxHeap(n);

    HeapSort(n);

    printf("\n\t------- Sorted elements -------\n\n");

    for(i=1; i<=n; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");

    return 0;
}
