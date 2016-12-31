/*

Permutation of 1 to 4 by recursive backtracking

*/


#include<bits/stdc++.h>

using namespace std;

vector<int>result;

bool taken[15];

int arr[15];


void backtracking()
{
    int i;
    if(result.size()==4)
    {
        for(i=0;i<4;i++)
        {
            printf("%d ",result[i]);
        }
        puts("");
        return;
    }

    for(i=1;i<=4;i++)
    {
        if(taken[i]==0)
        {
            taken[i] = true;

            result.push_back(arr[i]);

            backtracking();

            taken[i] = false;

            result.pop_back();
        }
    }

}

int main()
{
    int i;

    for(i=1;i<=4;i++)
    {
        arr[i]=i;
    }

    backtracking();

    return 0;
}
