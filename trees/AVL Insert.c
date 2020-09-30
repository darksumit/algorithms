#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    int height;
    struct node *left, *right;
};

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int height(struct node *temp)
{
    if(temp!=NULL)
        return temp->height;
    return 0;
}

struct node *tempnode(int key)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->key=key;
    temp->height=1;
    temp->left=temp->right=NULL;
    return temp;
};

struct node *left(struct node *x1)
{
    struct node *x2= x1->right;
    struct node *temp= x2->left;

    x2->left= x1;
    x1->right= temp;

    x1->height= max(height(x1->left), height(x1->right))+1;
    x2->height= max(height(x2->left), height(x2->right))+1;

    return x2;
}

struct node *right(struct node *x2)
{
    struct node *x1= x2->left;
    struct node *temp= x1->right;

    x1->right= x2;
    x2->left= temp;

    x1->height= max(height(x1->left), height(x1->right))+1;
    x2->height= max(height(x2->left), height(x2->right))+1;

    return x1;
}

int balance(struct node *temp)
{
    if(temp==NULL)
        return 0;
    return height(temp->left)-height(temp->right);
}

struct node *insert(struct node *temp, int key)
{
    if(temp==NULL)
        return tempnode(key);
    if(key<temp->key)
        temp->left= insert(temp->left, key);
    else if(key>temp->key)
        temp->right= insert(temp->right, key);
    else
        return temp;

    temp->height= max(height(temp->left), height(temp->right))+1;
    int k= balance(temp);

    // Left Left Case
    if (k > 1 && key < temp->left->key)
        return right(temp);

    // Right Right Case
    if (k < -1 && key > temp->right->key)
        return left(temp);

    // Left Right Case
    if (k > 1 && key > temp->left->key)
    {
        temp->left =  left(temp->left);
        return right(temp);
    }

    // Right Left Case
    if (k < -1 && key < temp->right->key)
    {
        temp->right = right(temp->right);
        return left(temp);
    }

    return temp;
}

void inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of the constructed AVL tree is\n");
    inOrder(root);
    printf("\n");

    return 0;
}
