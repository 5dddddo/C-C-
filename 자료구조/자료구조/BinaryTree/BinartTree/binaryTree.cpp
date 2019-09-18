#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "binaryTree.h"

void initTree(Tree *tr)
{

	tr->root = NULL;
	tr->nodeCnt = 0;
}

Node * makeNode(DataType *data, Node *left, Node *right)
{
	Node *node = (Node *)calloc(1,sizeof(Node));
	if (node != NULL)
	{
		node->data = *data;
		node->left = left;
		node->right = right;
	}
	return node;
}

Node *addNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *))
{
	Node *parent, *son, *np;
	np = makeNode(data, NULL, NULL);
	tr->nodeCnt++;
	parent = tr->root;
	son = tr->root;
	if (tr->root != NULL)
	{
		while (son!=NULL)
		{
			if (compare(&son->data, &np->data) == 1)
			{
				parent = son;
				son = son->left;
			}
			else
			{
				parent = son;
				son = son->right;
			}	
		}
		if (compare(&parent->data, &np->data) == 1)
			parent->left = np;
		else
			parent->right = np;
	}
	else
		tr->root = np;
	return NULL;
}

void inorderTraverse(Node *np, void(*print)(DataType *))
{
	if (np == NULL) return;
	inorderTraverse(np->left, print);
	print(&np->data);
	inorderTraverse(np->right, print);
}

void preorderTraverse(Node *np, void(*print)(DataType *))
{
	if (np == NULL) return;
	print(&np->data);
	preorderTraverse(np->left, print);
	preorderTraverse(np->right, print);
}

void postorderTraverse(Node *np, void(*print)(DataType *))
{
	if (np == NULL) return;
	postorderTraverse(np->left, print);
	postorderTraverse(np->right, print);
	print(&np->data);
}

Node * searchNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType*))
{
	Node *p;
	p = tr->root;
	while (1)
	{
		if (p != NULL)
		{
			if (compare(&p->data, data) == 1)
				p = p->left;
			else if (compare(&p->data, data) == -1)
				p = p->right;
			else
				return p;
		}
		else return p;
	}
}

Node * deleteNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *))
{
	Node *del;
	Node *parent, *son, *temp;
	del = searchNode(tr, data, compare);
	if (del == NULL) return NULL;

	temp = NULL;
	parent = tr->root;
	son = tr->root;

	while (son != NULL)
	{
		if (compare(&del->data, &son->data) == 1)
		{
			parent = son;
			son = son->right;
		}
		else if (compare(&del->data, &son->data) == -1)
		{
			parent = son;
			son = son->left;
		}
		else
		{
			son = del;
			break;
		}
	}

	if (del->left != NULL && del->right == NULL)
	{

		if (del->data > parent->data)parent->right = son->left;
		else parent->left = son->left;
		del->data = 0;

		del->left = NULL;
		del->data = 0;
		free(del);
		return parent;
	}
	else if (del->right != NULL && del->right->left == NULL)
	{
		del->right->left = son->left;

		if (parent->data > son->data) 
			parent->left = son->right;
		else 
			parent->right = son->right;

		del->right = NULL;
		del->left = NULL;
		del->data = 0;
		free(del);
		return parent;
	}
	else
	{
		if (tr->root == del)
		{
			son = del->right;
			while (son->left != NULL)
			{
				son = son->left;
				if (son->left != NULL && son->left->left == NULL)
					temp = son;
			}
			temp->left = son->right;
			son->right = del->right;
			son->left = del->left;

			tr->root = son;

			del->left = NULL;
			del->right = NULL;
			del->data = 0;
			free(del);
		}
		else
		{
			son = del->right;
			while (son->left != NULL)
			{
				son = son->left;
				if (son->left != NULL && son->left->left == NULL)
					temp = son;
			}
			temp->left = son->right;
			son->right = del->right;
			son->left = del->left;

			parent->left = son;

			del->left = NULL;
			del->right = NULL;
			del->data = 0;
			free(del);
		}
		return son;
	}
}

void destroyTree(Tree * tr, void(*print)(DataType *))
{
	postorderDelete(tr->root, print);
	tr->root->left = NULL;
	tr->root->right = NULL;
	tr->root->data = 0;
	tr->nodeCnt = 0;
	tr->root = NULL;
}

void postorderDelete(Node *np, void(*print)(DataType *))
{
	if (np == NULL) return;
	postorderDelete(np->left, print);
	postorderDelete(np->right, print);
	print(&np->data);
	np->left = NULL;
	np->right = NULL;
	np->data = 0;
	free(np);
}