
#include <stdio.h>
#include <stdlib.h>

typedef struct darray_st 
{
	int* arr; 
	int size; 
	int filled;
} darray; 

darray* init() 
{
	darray* a = malloc(sizeof(darray));
	a->filled = 0;
	a->size = 10;
	a->arr = malloc(20 * sizeof(int)); 
	return a;
}

darray* resize(darray* a) 
{
	darray* b = malloc(sizeof(darray));
	b->size = 2*a->size; 
	b->filled = a->filled; 
	b->arr = malloc(b->size * sizeof(int)); 
	int i; 
	for (i=0; i<a->filled; i++) 
	{
		b->arr[i] = a->arr[i];
	}
	free(a);
	return b; 
}

void add(darray* a, int n) 
{
	if (a->filled == a->size) 
	{
		a = resize(a); 
	}
	a->filled++; 
	a->arr[a->filled - 1] = n; 
}

void print(darray* a) 
{
	int i; 
	for (i=0; i<a->filled; i++) 
	{
		printf("%d ", a->arr[i]);
	}
}

void remove_last(darray* a) 
{
	a->filled--;
}

int main(int argc, char* argv[]) 
{
	darray* a = init(); 
	add(a, 5);
	add(a, 6);
	add(a, 7);
	add(a, 8);
	add(a, 9);
	print(a);
	remove_last(a);
	print(a);
	return 0;
}


