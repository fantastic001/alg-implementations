
#include <stdio.h>
#include <stdlib.h>

typedef struct node_st 
{
	int value; 
	struct node_st* next; 
	struct node_st* prev; 
} node; 

typedef struct list_st 
{
	node* start; 
} list; 


list* init() 
{
	list* l = malloc(sizeof(list));
	l->start = NULL;
}

node* create_node(int a) 
{
	node* n = malloc(sizeof(node));
	n->next = NULL; 
	n->prev = NULL; 
	n->value = a; 
	return n;
}

void insert_after(node* n, int a) 
{
	node* nxt = n->next; 
	node* nn = create_node(a);
	if (nxt != NULL) {
		n->next = nn; 
		nn->prev = n; 
		nn->next = nxt; 
		nxt->prev = nn;
	} 
	else
	{
		n->next = nn; 
		nn->prev = n; 
		nn->next = NULL; 
	}
}

void add_end(list* l, int a) 
{
	if (l->start != NULL) {
		node* curr = l->start;
		while (curr->next != NULL) 
		{
			curr = curr->next;
		}
		insert_after(curr, a);
	} 
	else 
	{
		l->start = create_node(a);
	}
}

void add_start(list* l, int a) 
{
	if (l->start != NULL) {
		node* n = create_node(a);
		n->next = l->start; 
		n->prev = NULL;
	
		l->start = n; 
	} else 
	{
		l->start = create_node(a);
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

int main() 
{
	list* l = init();
	add_end(l, 1);
	add_end(l, 2);
	add_end(l, 3);
	add_end(l, 4);
	add_end(l, 5);
	add_start(l, 0);
	insert_after(l->start, 100);
	print(l);
	return 0; 
}
