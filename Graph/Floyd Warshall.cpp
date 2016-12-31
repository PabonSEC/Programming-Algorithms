

/*      Input:


       4 6
       1 3 4
       1 3 6
       1 2 2
       2 3 1
       2 4 5
       3 4 3


*/



#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#define MAX 1000
#define Infinity 100000
using namespace std;

long long  Matrix[MAX][MAX];
long long next[MAX][MAX];
long long a,b,cost,koyta_node,koyta_edge,i,j,k,Size;
vector<long long>path;


void Floyd()
{
    for(k=1; k<=koyta_node; k++)
    {
        for(i=1; i<=koyta_node; i++)
        {
            for(j=1; j<=koyta_node; j++)
            {
                if(Matrix[i][j]>Matrix[i][k]+Matrix[k][j])
                {
                    Matrix[i][j]=Matrix[i][k]+Matrix[k][j];

                    Matrix[j][i]=Matrix[i][j];           /// as directed


                    next[i][j]=next[i][k];
                    next[j][i]=next[i][k];
                }
            }
        }
    }
}

void find_path(long long st,long long ed)
{
    path.push_back(st);
    if(st!=ed)
    {
        st=next[st][ed];
        find_path(st,ed);
    }
    return;
}

int main()
{
    long long Start,End;
    while(cin>>koyta_node>>koyta_edge)
    {
        memset(Matrix,0,sizeof(Matrix));
        memset(next,0,sizeof(next));
        for(i=1; i<=koyta_node; i++)       /// Matrix Initialization
        {
            for(j=1; j<=koyta_node; j++)
            {
                if(i!=j)
                {
                    Matrix[i][j]=Infinity;
                }
            }
        }
        for(i=1; i<=koyta_edge; i++)    /// Get Input Connection between two nodes and their weights
        {
            cin>>a>>b>>cost;
            Matrix[a][b]=cost;          /// Put Cost into the Matrix which nodes have connection
            Matrix[b][a]=cost;

        }

        for(i=1; i<=koyta_node; i++)    /// Next matrix Initialization
        {
            for(j=1; j<=koyta_node; j++)
            {
                if(i!=j)
                {
                    next[i][j]=j;
                }
            }
        }

        Floyd();

        cout<<"Matrix is :"<<endl;    /// Print Matrix.
        for(i=1; i<=koyta_node; i++)
        {
            for(j=1; j<=koyta_node; j++)
            {
                cout<<" "<<Matrix[i][j];
            }
            cout<<endl;
        }

        cout<<endl;

        cout<<"Next Matrix is :"<<endl;    /// Print next matrix

        for(i=1; i<=koyta_node; i++)
        {
            for(j=1; j<=koyta_node; j++)
            {
                cout<<" "<<next[i][j];
            }
            cout<<endl;
        }

        cout<<endl;
        cin>>Start>>End;
        printf("The distance between %lld and %lld is : %lld\n",Start,End,Matrix[Start][End]);

        find_path(Start,End);

        Size=path.size();

        printf("The path from %lld to %lld is: ",Start,End);

        for(i=0;i<Size;i++)
        {
            cout<<path[i];
            if(i<Size-1)
            {
                cout<<"-->";
            }
        }
        cout<<endl;
        path.clear();
    }
    return 0;
}

