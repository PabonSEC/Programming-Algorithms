#include<bits/stdc++.h>

using namespace std;

struct matrix
{
    int v[5][5];

    int row,col;

} identity,ans,mat;

int mod;

matrix multiply(matrix a, matrix b)
{
    assert(a.col==b.row);

    matrix r;

    r.row = a.row;

    r.col = b.col;

    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            int sum = 0;

            r.v[i][j] = 0;

            for(int k=0; k<a.col; k++)
            {
                sum+=a.v[i][k]*b.v[k][j];

                sum%=mod;
            }

            r.v[i][j] = sum;
        }
    }

    return r;
}

matrix power(int p)
{
    assert(p>=1);

    if(p==1)
    {
        return mat;
    }

    if(p%2==1)
    {
        return multiply(mat,power(p-1));
    }

    matrix ret = power(p/2);

    ret = multiply(ret,ret);

    return ret;
}

int main()
{
    int n,i,j;

    mat.row = mat.col = 2;

    for(i = 0; i < 2; ++i)
    {
        for(j = 0; j < 2; ++j)
        {
            mat.v[i][j] = 1;
        }
    }

    mat.v[1][1] = 0;

    while(cin>>n>>mod)
    {
        if(n == 0 || n == 1)
            printf("%d\n", n);

        else
        {
            ans = power(n - 1);

            printf("%d\n", ans.v[0][0]);
        }
    }

    return 0;
}
