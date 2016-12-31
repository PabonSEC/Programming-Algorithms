#include<bits/stdc++.h>

using namespace std;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();

    newNode->data = data;

    newNode->left = newNode->right = NULL;

    return newNode;
}

BstNode* Insert(BstNode* root,int data)
{
    if(root==NULL)
    {
        root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

bool Search(BstNode* root, int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==data)
    {
        return true;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}
int main()
{

    BstNode* root = NULL; // pointer to root node

    root = Insert(root,1);
    root = Insert(root,2);
    root = Insert(root,3);
    root = Insert(root,4);
    root = Insert(root,5);
    root = Insert(root,6);
    root = Insert(root,7);
    root = Insert(root,9);
    root = Insert(root,10);

    int number;

    cout<<"Enter number be searched\n";

    cin>>number;

    if(Search(root,number)==true)
    {
        cout<<"Found\n";
    }
    else
    {
        cout<<"Not Found\n";
    }

    return 0;
}

