#include <stdio.h>
#include <stdlib.h>

struct listnode
{
	int data;
	struct listnode *next;
};

struct treenode
{
	int data;
	struct treenode *left, *right;
};

int countnode (struct listnode *head)
{
	int count= 0;
	struct listnode *temp= head;
	while (temp != NULL)
	{
		temp= temp->next;
		count++;
	}
	return count;
}

void push (struct listnode **head, int item)
{
	struct listnode *temp= (struct listnode *) malloc (sizeof(struct listnode));
	temp->data= item;
	temp->next= *head;
	*head= temp;
}

void display (struct listnode *node)
{
	while (node != NULL)
	{
		printf ("%d     ", node->data);
        node= node->next;
	}
}

struct treenode *new (int item)
{
	struct treenode *temp= (struct treenode *) malloc (sizeof(struct treenode));
	temp->data= item;
	temp->left= temp->right= NULL;
	return temp;
}

struct treenode *recurBST (struct listnode **head, int n)
{
	if (n<1)
		return NULL;
	struct treenode *left= recurBST (head, n/2);
	struct treenode *temp= new((*head)->data);
	temp->left= left;
	*head= (*head)->next;
	temp->right= recurBST (head, n-n/2-1);
	return temp;
}


struct treenode *ListToBST (struct listnode *head)
{
	int n= countnode (head);
	return recurBST (&head, n);
}

void inorder (struct treenode *node)
{
	if (node==NULL)
		return;
	inorder (node->left);
	printf ("%d     ", node->data);
	inorder (node->right);
}

int main()
{
	struct listnode *head= NULL;
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("Linked List:		");
	display(head);

	struct treenode *root= ListToBST(head);
	printf("\nIn-order Traversal:	");
	inorder(root);
	printf("\n");
 	return 0;
}
