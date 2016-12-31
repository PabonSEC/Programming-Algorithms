#include<bits/stdc++.h>

using namespace std;

struct node
{
    bool endmark;

    node *next[27];

    node()
    {
        endmark = false;

        for(int i=0;i<26;i++)
        {
            next[i] = NULL;
        }
    }

}*root;


void Insert(char *str,int len)
{
    node *curr = root;

    for(int i=0;i<len;i++)
    {
        int id = str[i] - 'a';

        if(curr->next[id]==NULL)
        {
            curr->next[id] = new node();
        }

        curr = curr->next[id];
    }

    curr->endmark = true;
}

bool Search(char *str,int len)
{
    node *curr = root;

    for(int i=0;i<len;i++)
    {
        int id = str[i] - 'a';

        if(curr->next[id]==NULL)
        {
            return false;
        }

        curr = curr->next[id];
    }

    return curr->endmark;
}

void del(node *curr)
{
    for(int i=0;i<26;i++)
    {
        if(curr->next[i])
        {
            del(curr->next[i]);
        }
    }

    delete(curr);
}

int main()
{

    puts("Enter number of words : ");

    root = new node();

    int num,i,q;

    char str[50];

    cin>>num;

    for(i=1;i<=num;i++)
    {
        scanf("%s",str);

        Insert(str,strlen(str));
    }

    puts("Enter number of Query : ");

    cin>>q;

    for(i=1;i<=q;i++)
    {
        scanf("%s",str);

        cout<<(Search(str,strlen(str))?"Found\n":"Not Found\n");
    }

    del(root);

    return 0;
}
