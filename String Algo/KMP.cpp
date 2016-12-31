#include<bits/stdc++.h>
#define mx 100005

using namespace std;

char text[mx],pattern[mx];

vector<int>Match_position;

vector<int> compute_prefix(const char *p)
{
    int m = strlen(p+1);

    vector<int>prefix(m+1);

    prefix[1] = 0;

    int k = 0,i;

    for(i=2; i<=m; i++)
    {
        while(k>0 && p[k+1]!=p[i])
        {
            k = prefix[k];
        }

        if(p[k+1]==p[i])
        {
            k++;
        }

        prefix[i] = k;
    }

    return prefix;
}

void KMP_match(const char *txt,const char *ptrn)
{
    int n = strlen(txt+1);

    int m = strlen(ptrn+1);

    vector<int>Prefix = compute_prefix(ptrn);

    int q = 0;

    for(int i = 1; i<=n; i++)
    {
        while(q>0 && ptrn[q+1]!=txt[i])
        {
            q = Prefix[q];
        }

        if(ptrn[q+1]==txt[i])
        {
            q++;
        }

        if(q==m)
        {
            Match_position.push_back(i-m);

            q = Prefix[q];
        }
    }
}


int main()
{

    scanf("%s%s",text+1,pattern+1);

    KMP_match(text,pattern);

    for(int i=0; i<Match_position.size(); i++)
    {
        printf("%d",Match_position[i]);
    }

    cout<<endl;

    return 0;
}
