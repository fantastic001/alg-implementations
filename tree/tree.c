
#include <stdio.h>
#include <stdlib.h>

typedef struct node_st {
	struct node_st *left; 
	struct node_st *right; 
	int val; 
} node; 


node* create_node(int a) 
{
	node* n = malloc(sizeof(int));
	n->val = a; 
	n->left = NULL; 
	n->right = NULL;
	return n; 
}

void insert(node* curr, int a) 
{
	if (a > curr->val) 
	{
		if (curr->right == NULL) curr->right = create_node(a);
		else 
		{
			insert(curr->right, a);
		}
	}
	if (a < curr->val) 
	{
		if (curr->left == NULL) curr->left = create_node(a);
		else 
		{
			insert(curr->left, a);
		}
		
	}
}

int intree(node* curr, int a) 
{
	if (a == curr->val) return 1; 
	else 
	{
		if (a > curr->val) 
		{
			if (curr->right == NULL) return 0; 
			else return intree(curr->right, a);
		}
		else 
		{
			if (curr->left == NULL) return 0; 
			else return intree(curr->left, a);
		}
	}
}

void update_boundaries(node* curr, int depth, int* max, int* min) 
{
	if (curr->left == NULL && curr->right == NULL) 
	{
		if (*max < depth) *max = depth;
		if (*min > depth) *min = depth;
	}
	else 
	{
		if (curr->left != NULL) update_boundaries(curr->left, depth+1, max, min);
		if (curr->right != NULL) update_boundaries(curr->right, depth+1, max, min);
	}
}

void print_tree(node* root) 
{
	if (root != NULL) 
	{
		// we first print left subtree
		print_tree(root->left);
		
		// now we print root
		printf("%d ", root->val);

		// and then we print right subtree
		print_tree(root->right);
		
	}
}

int main() {
	node* root = create_node(0);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, -1);
	insert(root, -2);
	insert(root, -3);
	insert(root, -4);
	insert(root, -5);
	print_tree(root);
	int max=0, min=1000000;
	update_boundaries(root, 0, &max, &min);;
	printf("max and min: %d %d\n", max, min);
	return 0; 
}

