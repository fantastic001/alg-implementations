
#include <stdio.h>
#include <stdlib.h> 

typedef struct node_st 
{
	int value; 
	struct node_st* next; 
} node; 

typedef struct list_st 
{
	node* start; 
} list; 

list* init() 
{
	list* l = malloc(sizeof(list));
	l->start = NULL; 
	return l;
}

node* create_node(int a) 
{
	node* n = malloc(sizeof(node));
	n->value = a; 
	n->next = NULL; 
	return n; 
}

void add_end(list* l, int a) 
{
	node* n = create_node(a);
	node* current = l->start; 
	if (l->start == NULL) 
	{
		l->start = n; 
	}
	else {
		while (current->next != NULL) 
		{
			current = current->next;
		}
		current->next = n; 
	}
}

void add_start(list* l, int a) 
{
	node* n = create_node(a);
	if (l->start == NULL) l->start = n; 
	else
	{
		n->next = l->start; 
		l->start = n; 
	}
}

void print(list* l) 
{
	node* curr = l->start; 
	while (curr != NULL) 
	{
		printf("%d ", curr->value);
		curr = curr->next; 
	}
}

void remove_node(node* x) 
{
	node* a = x->next; 
	if (a != NULL) {
		x->next = a->next; 
		free(a);
	}
}

int main() 
{
	list* l = init();
	add_start(l, 1);
	add_end(l, 2);
	add_end(l, 3);
	add_start(l, 0); 
	remove_node(l->start);
	print(l);

	return 0; 
}
