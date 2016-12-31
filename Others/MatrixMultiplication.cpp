#include<bits/stdc++.h>

using namespace std;

int matrix1[50][50],matrix2[50][50],result[50][50];

int main()
{
    int a,b,c,d,i,j,k;

    cout<<"Enter Row and Column for Matrix 1 : ";

    cin>>a>>b;

    for(i=1; i<=a; i++)
        for(j=1; j<=b; j++)
            cin>>matrix1[i][j];


    cout<<"\nEnter Row and Column for Matrix 2 : ";

    cin>>c>>d;

    if(a==d)
    {

        for(i=1; i<=c; i++)
            for(j=1; j<=d; j++)
                cin>>matrix2[i][j];

        int sum = 0;

        cout<<endl;

        for(i=1; i<=a; i++)
        {
            for(j=1; j<=d; j++)
            {
                for(k=1; k<=c; k++)
                {
                    sum+=matrix1[i][k]*matrix2[k][j];
                }

                result[i][j] = sum;
                sum = 0;
            }
        }


        cout<<"\nThe Result matrix is : \n";

        for(i=1; i<=a; i++)
        {
            for(j=1; j<=d; j++)
                cout<<result[i][j]<<"   ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"\nThe multiplication is impossible..."<<endl;
    }


    return 0;
}
