#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node{
	int data;
	struct node* next;
}node;

void Push(node** ptrRef, int data)
{
	node* N = (node*)malloc(sizeof(node));
	N->data = data;
	N->next = *ptrRef;
	*ptrRef = N;
}

node* Build(int nb)
{
	node* head = NULL;
	node** ptrRef = &head;

	while(nb>0)
	{
		Push(ptrRef, nb%2);
		ptrRef = &((*ptrRef)->next);
		nb--;
	}
	return head;
}

void Print(node* head)
{
	if(head == NULL)
	{
		printf(" Bye\n");
		return;
	}

	printf("%d ", head->data);
	if(head->next != NULL)
		printf("-> ");
	Print(head->next);
}
int count(node* head)
{
	if(!head)
		return 0;
	return count(head->next)+1;
}


int helper(node* head, int *x)
{
	if(!(head)) 
		return 0;
	int S = helper(head->next, x); 
	S+=(head->data)*(*x);
	*x *= 2;
	return S;
}

int toDecimal(node* head)
{
	int x=1;
	return helper(head, &x);
}

int main()
{
	node* binary = Build(5);
	Print(binary);
	printf("%d",toDecimal(binary));
	return 0;
}
