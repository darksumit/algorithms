#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newnode (int item)
{
    struct node *temp= (struct node*) malloc(sizeof (struct node));
    temp->data= item;
    temp->left= temp->right= NULL;
    return temp;
}

void preorder (node* temp)
{

    if(!temp)
        return;
    cout << temp->data << " ";
    preorder (temp->left);
    preorder (temp->right);
}

void inorder (node* temp, vector<int> &arr)
{
    if (temp==NULL)
        return;

    inorder (temp->left, arr);
    arr.push_back (temp->data);
    inorder (temp->right, arr);
}

void convert (node *temp, vector<int> arr, int *i)
{
	if (temp==NULL)
		return;
	temp->data= arr[++*i];
	convert (temp->left, arr, i);
	convert (temp->right, arr, i);
}

void BSTToMinHeap (node *root)
{
	vector<int> arr;
	int i= -1;

	inorder (root, arr);
	convert (root, arr, &i);
}

int main()
{
	struct node *root= newnode(4);
	root->left= newnode(2);
	root->right = newnode(6);
	root->left->left= newnode(1);
	root->left->right= newnode(3);
	root->right->left= newnode(5);
	root->right->right= newnode(7);

 	BSTToMinHeap (root);

	cout << "Preorder Traversal:	";
	preorder(root);
	cout << endl;
	return 0;
}
