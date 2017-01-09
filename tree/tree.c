
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

node* find_node(node* curr, int a) 
{
	if (curr == NULL) return NULL;
	if (a == curr->val) return curr; 
	else 
	{
		if (a > curr->val) 
		{
			return find_node(curr->right, a);
		}
		else 
		{
			return find_node(curr->left, a);
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

/*
This function deletes node in tree and returns node which will replace deleted node 

How to use?

for example, if we want to delete left child of root we will use function like this:

root->left = delete_node(root->left);
*/
node* delete_node(node* n) 
{
	node* res = NULL;
	if (n->right == NULL) 
	{
		res = n->left; 
		free(n);
	}
	else 
	{
		if (n->right->left == NULL) 
		{
			res = n->right;
			res->left = n->left;
			free(n);
		}
		else 
		{
			node* curr = n->right;
			node* p = n;
			while (curr->left != NULL) {
				p = curr;
				curr = curr->left;
			}
			p->left = curr->right;
			res = curr;
			res->left = n->left;
			res->right = n->right;
			free(n);
		}
	}
	return res;
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
	printf("\n");
	node* n = find_node(root, 2);
	printf("%d\n", n->val);
	while (root->left != NULL) 
	{
		root->left = delete_node(root->left);
		print_tree(root);
		printf("\n");
	}
	while (root->right != NULL) 
	{
		root->right = delete_node(root->right);
		print_tree(root);
		printf("\n");
	}
	print_tree(root);
	printf("\n");
	int max=0, min=1000000;
	update_boundaries(root, 0, &max, &min);;
	printf("max and min: %d %d\n", max, min);
	return 0; 
}

