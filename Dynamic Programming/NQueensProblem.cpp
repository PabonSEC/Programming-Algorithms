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

int result[1000]; // this array will store the result

int counter;

// result[i]=j; means queen at i-th row is placed at j-th column.
// Queens placed at (x1, y1) and (x2,y2)
// x1==x2 means same rows, y1==y2 means same columns, |x2-x1|==|y2-y1| means
// they are placed in diagonals.

bool canPlace(int x2, int y2)
{
    // This function will check if queen can be placed (x2,y2), or we can
    // say that Can queen at x2 row is placed at y2 column.
    // for finding the column for x2 row, we will check all the columns for
    // all the rows till x2-1.

    for (int i = 0; i <x2; i++)
    {
        //result[i] == y2 => columns are same

        //|i - x2| == |result[i] - y2| => in diagonals.

        if ((result[i] == y2) || (abs(i - x2) == abs(result[i] - y2)))
        {
            return false;
        }
    }
    return true;
}

void placeQueens(int x, int sz)
{
    for(int i=0; i<sz; i++)
    {
        //check if queen at xth row can be placed at i-th column.

        if(canPlace(x,i))
        {
            result[x] = i; // place the queen at this position.

            if(x==sz-1)
            {
                //string header = new string(result, 1000).c_str());

                cout<<endl<<"Order of "<<sz<<" Queens :";

                for(int j=0; j<sz; j++)
                {
                    cout<<" "<<result[j];
                }
                cout<<endl;

                counter++;
            }

            placeQueens(x + 1, sz);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int n,i,j;

    printf("Enter board size : ");

    while(cin>>n)
    {
        counter = 0;

        placeQueens(0,n);

        cout<<endl<<"Possible ways to place "<<n<<" queens on the board"<<endl<<"so that they can't attack each other: "<<counter<<endl<<endl;

        printf("Enter board size : ");
    }

    return 0;
}
