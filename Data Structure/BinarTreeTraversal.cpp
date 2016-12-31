/*Sample Input

10

6 4 2 1 3 5 10 7 9 11


*/


#include <bits/stdc++.h>

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

BstNode* Insert(BstNode* root, int data)
{
    if(root==NULL)
    {
         root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;

}

void printInOrder(BstNode* root)
{
    if(root==NULL)
    {
        return;
    }

    printInOrder(root->left);

    printf("%d ", root->data);

    printInOrder(root->right);
}

void printPreOrder(BstNode* root)
{
    if(root==NULL)
    {
        return;
    }

    printf("%d ", root->data);

    printPreOrder(root->left);

    printPreOrder(root->right);

}

void printPostOrder(BstNode* root)
{
    if(root==NULL)
    {
        return;
    }

    printPostOrder(root->left);

    printPostOrder(root->right);

    printf("%d ", root->data);
}

int main()
{
    BstNode* root = NULL;

    int n, data,i;

    printf("How many data's do you want to insert ?\n");

    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("Data %d: ", i);

        scanf("%d", &data);

        root = Insert(root, data);
    }

    printf("\n\n");

    printf("printInOrder Traversal: ");

    printInOrder(root);

    printf("\n\n");

    printf("printPreOrder Traversal: ");
    printPreOrder(root);
    printf("\n\n");

    printf("printPostOrder Traversal: ");
    printPostOrder(root);
    printf("\n\n");

    return 0;
}

