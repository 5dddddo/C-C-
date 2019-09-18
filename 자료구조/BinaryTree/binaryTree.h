#pragma once
#include "datatype.h"
typedef struct _node Node;
typedef struct _node
{
	DataType data;
	Node *left;
	Node *right;
}Node;

typedef struct _tree
{
	Node *root;
	int nodeCnt;
}Tree;

void initTree(Tree *tr);
Node *makeNode(DataType *data, Node *, Node *);
Node *addNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *));
void inorderTraverse(Node *np, void(*print)(DataType *));
void preorderTraverse(Node *np, void(*print)(DataType *));
void postorderTraverse(Node *np, void(*print)(DataType *));
void postorderDelete(Node *np, void(*print)(DataType *));
Node * searchNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType*));
Node * deleteNode(Tree *tr, DataType *data, int(*compare)(DataType *, DataType *));
void destroyTree(Tree * tr, void(*print)(DataType *));
void postorderDelete(Node *np, void(*print)(DataType *));