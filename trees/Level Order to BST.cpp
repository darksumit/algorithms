#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct detail
{
    int min, max;
    struct node *ptr;
};

struct node *newnode(int item)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *constructBST(int arr[], int n)
{
    if (n == 0)
        return NULL;

    int i=0;
    struct node *root;
    queue<struct detail> q;

    struct detail temp;
    temp.ptr = newnode(arr[i++]);
    temp.min = INT_MIN;
    temp.max = INT_MAX;
    q.push(temp);

    root = temp.ptr;

    while (i != n)
    {
        struct detail value = q.front();
        q.pop();

        if (i < n && (arr[i]<value.ptr->data && arr[i]>value.min))
        {
            temp.ptr = newnode(arr[i++]);
            temp.min = value.min;
            temp.max = value.ptr->data;
            q.push(temp);

            value.ptr->left = temp.ptr;
        }

        if (i < n && (arr[i]>value.ptr->data && arr[i]<value.max))
        {
            temp.ptr = newnode(arr[i++]);
            temp.min = value.ptr->data;
            temp.max = value.max;
            q.push(temp);

            value.ptr->right = temp.ptr;
        }
    }

    return root;
}

void inorder(node *root)
{
    if (!root)
        return;

    inorder (root->left);
    cout << root->data << " ";
    inorder (root->right);
}

int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    node *root = constructBST(arr, n);

    cout << "Inorder Traversal: ";
    inorder (root);
    cout << endl;
    return 0;
}
