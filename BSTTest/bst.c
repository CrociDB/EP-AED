#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define TRUE			1
#define FALSE			0

// Struct
struct NODE {
	int key;
	struct NODE *left;
	struct NODE *right;
};

typedef char bool;

typedef struct NODE* BST;
typedef struct NODE NODE;

// Functions
void bst_show(BST p, int h);
void bst_insert(BST *tree, int i_key);
bool bst_remove(BST *tree, int i_key);

// Private functions
bool __bst_remove_node(NODE **p);
void __bst_research_node(NODE **p, NODE **aux);

int main()
{
	BST tree = NULL;
	
	bst_insert(&tree, 10);
	bst_insert(&tree, 5);
	bst_insert(&tree, 13);
	bst_insert(&tree, 3);
	bst_insert(&tree, 20);
	bst_insert(&tree, 6);
	bst_insert(&tree, 12);
	bst_insert(&tree, 14);
	bst_insert(&tree, 7);
	
	bst_show(tree, 0);
	
	// Let's remove a NODE
	bool b = bst_remove(&tree, 10);
	
	printf("\n ---> REMOVE RETURN: %d\n\n", b);
	
	bst_show(tree, 0);

	return 0;
}

bool bst_remove(BST *tree, int i_key)
{
	// Let's first search the NODE we want to remove
	if (*tree)
	{
		if (i_key == (*tree)->key)
		{
			return __bst_remove_node(tree);
		}
		else if (i_key < (*tree)->key) return bst_remove(&((*tree)->left), i_key);
		else return bst_remove(&((*tree)->right), i_key);
	}
	else return FALSE;
}


bool __bst_remove_node(NODE **p)
{
	// Now I know I have to delete this NODE...
	NODE *aux = *p;
	
	if (!(*p)->left) *p = (*p)->right;
	else if (!(*p)->right) *p = (*p)->left;
	else __bst_research_node(&((*p)->left), &aux);
	
	free(aux);
	
	return TRUE;
}

void __bst_research_node(NODE **p, NODE **aux)
{
	if (!(*p)->right)
	{
		(*aux)->key = (*p)->key;
		if (!(*p)->left)
		{
			*aux = *p;
			*p = NULL;
		}
		else {
			*aux = *p;
			*p = (*p)->left;
		}
	}
	else
		__bst_research_node(&(*p)->right, aux);
}

void bst_insert(BST *tree, int i_key)
{
	if (!(*tree)) {
		*tree = (NODE *) malloc(sizeof(NODE));
		(*tree)->key = i_key;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
	else {
		if (i_key < (*tree)->key) bst_insert(&((*tree)->left), i_key);
		else bst_insert(&((*tree)->right), i_key);
	}
}

void bst_show(NODE *p, int h)
{
	int i;

	if (p) {
		bst_show(p->right, h + 1);

		for (i = 1; i <= h; i++) printf ("     ");
		printf("%d\n", p->key);

		bst_show(p->left, h + 1);
	}
}
