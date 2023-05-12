#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};

/*struct node *newNode(int info)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = info;
    temp->right = temp->left = NULL;
    return temp;
}*/
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
         printf("%d ", root->data);
        inorder(root->left);
        inorder(root->right);

    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        inorder(root->right);
         printf("%d ", root->data);

    }
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
       root=(struct node*)malloc(sizeof(struct node));
       root->data=key;
       root->right=root->left=NULL;
       return root;
    }
    if (key > root->data)
    
        root->right = insert(root->right, key);
    
    else if(key<root->data)
    
        root->left = insert(root->left, key);
    

    return root;
};

int main()
{
    struct node *root = NULL;
    root = insert(root, 20);
    insert(root, 32);
    insert(root, 19);
    insert(root, 36);
    insert(root, 9);
printf("Binary search tree in inorder\n");
    inorder(root);
    printf("\nBinary search tree in preorder\n");
    preorder(root);
    printf("\nBinary search tree in postorder\n");
    postorder(root);
    return 0;
}
