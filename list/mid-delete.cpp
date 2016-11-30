

/*
Delete middle node in the list given access only to that node and list is single linked 
*/

#include <iostream>

using namespace std; 

struct node_st
{
	int data;
	node_st* next;

};

typedef struct node_st node; 

node* createNode(int data) 
{
	node* n = new node;
	n->data = data; 
	n->next = NULL;
	return n;
}

node* insert(node* current, node* ne) 
{
	node* nxt = current->next; 
	current->next = ne; 
	ne->next = nxt;
	return ne;
}

int countNodes(node* current) 
{
	if (current != NULL) return 1 + countNodes(current->next);
	else return 0;
}

void deleteNode(node* n) 
{
	node* nxt = n->next; 
	if (nxt != NULL) {
		n->data = nxt->data;
		n->next = nxt->next;
		delete nxt; 
	}
	else 
	{
		n->data = -1;
	}
}

void printNodes(node* n) 
{
	if (n != NULL && n->data >= 0) {
		cout << n->data << " ";
		printNodes(n->next);
	}
	else cout << endl;
}

int main() 
{
	node* n = createNode(1);
	node* start = n;
	n = insert(n, createNode(2));
	n = insert(n, createNode(3));
	node* m = n;
	n = insert(n, createNode(4));
	n = insert(n, createNode(5));
	node* end = n;
	printNodes(start);
	deleteNode(m);
	printNodes(start);
	deleteNode(end);
	printNodes(start);
	return 0; 
}
