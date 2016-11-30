
/*

You have reverse represented number as single-linked list where each node is a digit. 

Implement sum of numbers. 

Example: 503 is 3 -> 0 -> 5

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


node* sum(node* n1, node* n2, int carry) 
{
	if (n1 == NULL && n2 == NULL) 
	{
		node* res = new node; 
		res->data = carry; 
		res->next = NULL; 
		return res;
	}
	node* res = new node; 
	res->data = (carry + (n1 == NULL ? 0 : n1->data) + (n2 == NULL ? 0 : n2->data)) % 10;
	res->next = sum(n1 == NULL ? 0 : n1->next, n2 == NULL ? 0 : n2->next, 
		(carry + (n1 == NULL ? 0 : n1->data) + (n2 == NULL ? 0 : n2->data)) / 10
	);
	return res; 
}

void printNodes(node* n) 
{
	if (n != NULL && n->data >= 0) {
		cout << n->data << " ";
		printNodes(n->next);
	}
	else cout << endl;
}
int main() {
	node* n = createNode(3);
	node* n1 = n;
	n=insert(n, createNode(1));
	n=insert(n, createNode(5));

	cout << "First list: "; 
	printNodes(n1);

	n = createNode(5);
	node* n2 = n;
	n=insert(n, createNode(9));
	n=insert(n, createNode(2));
	cout << "Second list: "; 
	printNodes(n2);

	printNodes(sum(n1,n2, 0));
	return 0;
}

