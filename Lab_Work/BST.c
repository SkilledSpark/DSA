#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

void init_BST(BSTNode **root);
void add_node(BSTNode **root, int x);
void inorder (BSTNode *root);
void preorder (BSTNode *root);
void postorder(BSTNode *root);
int delete_BST(struct BSTNode** root, int x);

int main()
{
    BSTNode *root;
    int x, choice;
    init_BST(&root);
    while(1)
    {
        scanf("%d", &choice);
        if(choice==0)
        {
            init_BST(&root);
        }
        else if(choice==1)
        {
            scanf("%d", &x);
            add_node(&root, x);
        }
        else if(choice==2)
        {
            inorder(root);
            printf("\n");
        }
        else if(choice==3)
        {
            preorder(root);
            printf("\n");
        }
        else if(choice==4)
        {
            postorder(root);
            printf("\n");
        }
        else
            break;
    }
    return 0;
}

void init_BST(BSTNode **root)
{
    (*root) = NULL;
}

void add_node(BSTNode **root, int x)
{
    BSTNode *new = (BSTNode*)malloc(sizeof(BSTNode*));
    new->data = x;
    if ((*root)==NULL)
    {
        *root = new;
        return;
    }
    else if ((*root)->data == x)
    {
        printf("DUPLICATE ELEMENT %d NOT INSERTED\n", x);
        return;
    }
    else if ((*root)->data > x)
        add_node(&((*root)->left), x);
    else if ((*root)->data < x)
        add_node(&((*root)->right), x);
}

void inorder(BSTNode *root)
{
    if (root!=NULL)
    {
        inorder (root->left);
        printf("%d, ", root->data);
        inorder (root->right);
    }
}

void preorder(BSTNode *root)
{
    if (root!=NULL)
    {
        printf("%d, ", root->data);
        preorder (root->left);
        preorder (root->right);
    }
}

void postorder(BSTNode *root)
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d, ", root->data);
    }
}

int delete_BST(struct BSTNode** root, int x)
{
    if (*root == NULL)
        return -9999; // Element not found
    if (x < (*root)->data)
        return delete_BST(&((*root)->left), x);
    else if (x > (*root)->data)
        return delete_BST(&((*root)->right), x);
    else
    {
        if ((*root)->left == NULL)
        {
            struct BSTNode* temp = *root;
            *root = (*root)->right;
            free (temp);
            return x;
        }
        else if ((*root)->right == NULL)
        {
            struct BSTNode* temp = *root;
            *root = (*root)->left;
            free (temp);
            return x;
        }

        struct BSTNode* minNode = (*root)->right;
        while (minNode->left != NULL)
        {
            minNode = minNode->left;
        }
        (*root)->data = minNode->data;
        delete_BST(&((*root)->right), minNode->data);
    }
    return x;
}
