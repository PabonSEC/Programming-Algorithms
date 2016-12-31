#include<bits/stdc++.h>

using namespace std;

struct node
{
    int roll;

    node *next;
};

node *root = NULL;

void insert_into_LinkedList(int roll)
{
    if(root==NULL)
    {
        root = new node();

        root->roll = roll;

       // cout<<root->roll<<endl;

        root->next = NULL;
    }
    else
    {
        node *current_node = root;

        while(current_node->next!=NULL)
        {
            current_node = current_node->next;
        }

        node *newnode = new node();

        newnode->roll = roll;

       // cout<<newnode->roll<<endl;

        newnode->next = NULL;

        current_node->next = newnode;
    }
}

void delete_from_LinkedList(int roll)
{
    node *current_node = root;

    node *previous_node = NULL;

    while(current_node->roll!=roll)
    {
        previous_node = current_node;

        current_node = current_node->next;
    }

    if(current_node==root)
    {
        node *temp = root;

        root = root->next;

        delete(temp);
    }
    else
    {
        previous_node->next = current_node->next;

        delete(current_node);
    }

}

void print_LinkedList()
{
    node *current_node = root;

    while(current_node->next!=NULL)
    {
        cout<<" "<<current_node->roll;

        current_node = current_node->next;
    }

    cout<<" "<<current_node->roll<<endl;
}

int main()
{
    int choice,roll;

    cout<<"Enter Choice : ";

    while(cin>>choice)
    {
        if(choice==1)
        {
            cin>>roll;

            cout<<endl;

            insert_into_LinkedList(roll);
        }
        else if(choice==2)
        {
            cin>>roll;

            cout<<endl;

            delete_from_LinkedList(roll);
        }
        else if(choice==3)
        {
            cout<<endl;

            print_LinkedList();
        }
        else
        {
            cout<<"\nInvalid Choice"<<endl;
        }

        cout<<"Enter Choice : ";
    }
    return 0;
}

