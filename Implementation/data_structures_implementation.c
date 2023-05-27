#include "data_structures_implementation.h"
#include <stdlib.h>
#include <stdio.h>

//Stack
stack CreateStack(){
    return NULL; 
}

int isEmptyStack(stack s){
    return (s == NULL);
}

int Pop(stack* s){
    if(isEmptyStack(*s))
        return 0;
    stack temp = *s; 
    *s = (*s)->next;
    free(temp);
    return 1;
}

int Push(stack* s, elementS e) {
    stack temp = (stack)malloc(sizeof(struct nodeS));
    if(temp == NULL) 
        return 0;
    temp->data = e;
    temp->next = *s; 
    *s = temp; 
    return 1;
}

int Top(stack s, elementS* e) {
    if(isEmptyStack(s)) 
        return 0;
    *e = s->data; 
    return 1;
}


//Queue
queue CreateQueue() {
    queue q;
    q.front = q.rear = NULL;
    return q;
}

int EnQueue(queue* q, elementQ e) {
    nodeQ* temp = (nodeQ*)malloc(sizeof(nodeQ));
    if(!temp)
        return 0; // no space in memory
    temp->data = e;
    temp->next = NULL; // insert in end
    if(q->rear == NULL) // was empty Q then front and rear pt to nodeQ
        q->front = q->rear = temp;
    else 
        q->rear = q->rear->next = temp; // last nodeQ now pts to new nodeQ
                                        // rear now pts to new last nodeQ
    return 1;
}

int DeQueue(queue* q) {
    if(isEmptyQueue(*q))
        return 0;
    nodeQ* temp = q->front;
    q->front = q->front->next; // shift front
    free(temp);
    // if it is empty, rear = front = null
    if(q->front == NULL)
        q->rear = NULL;
    return 1;
}

int Front(queue q, elementQ* e) {
    if(isEmptyQueue(q))
        return 0;
    *e = q.front->data;
    return 1;
}

int isEmptyQueue(queue q) {
    return (q.front == NULL);
}

//Btree
Btree CreateBtree() {
	return NULL; // empty
}

Btree Construct(elementB e, Btree L, Btree R) // unify root of left and right subtrees
{
	Btree temp = (Btree)malloc(sizeof(struct nodeB)); // or sizeof(*Btree)
	if(!temp)	
		return 0;
	temp->data = e;
	temp->right = R;
	temp->left  = L;
	return temp;
}

int isEmptyBtree(Btree B){
	return B == NULL;
}

int Root(Btree B, elementB* e){
	if(isEmptyBtree(B))
		return 0;
	*e = B->data;
	return 1;
}


// its allowed to use B->right and B->left instead since Btree struct is obvious like LL
int Right(Btree B, Btree* R){
	if(isEmptyBtree(B))
		return 0;
	*R = B->right;
	return 1;
}

int Left(Btree B, Btree* L){
	if(isEmptyBtree(B))
		return 0;
	*L = B->left;
	return 1;
}

// ana 3melta
void PushBtree(Btree* B, elementB e) {
    struct nodeB* n = (struct nodeB*)malloc(sizeof(struct nodeB));
    n->data = e;
    n->right = n->left = NULL;
    *B = n;
}


Heap CreateHeap(int capacity, int heap_type)
{
    Heap h = (Heap)malloc(sizeof(Heap));
    if(!h)
        return 0;
    h->array = (int*)malloc(sizeof(int)*capacity);
    if(!h->array)   
        return 0;

    h->heap_type = heap_type;
    h->capacity = capacity;  // capacity terms
    h->count = 0; // no element in heap
    return h;
} // O(1)

/*
    0
  1   2
3  4 5  6

parent of 6 = (6-1)/2 = 2
left of 2   = 2*2 + 1 = 5
rightof 2   = 2*2 + 2 = 6 
*/

int Parent(Heap h, int i)
{
    if(i<=0 || i>h->count) // root has no parent, no neg in arr, greater than curr nb of elements
        return -1;
    return ((i-1)/2); 
} // O(1)

int LeftChild(Heap h, int i)
{
    int left = 2*i+1;
    if(left >= h->count)
        return -1;
    return left;
} // O(1)

int RightChild(Heap h, int i)
{
    int right = 2*i+2;
    if(right >= h->count)
        return -1;
    return right;
} // O(1)

int GetMaximum(Heap h)
{
    if(h->count == 0)   
        return -1;
    return h->array[0];
}// O(1)

void PercolateDown(Heap *h, int i)
{
    int l = LeftChild(*h, i);
    int r = RightChild(*h, i);
    int max = i; //as if curr is max then compare with 2 children
    int temp;

    // if it has left and left>max which is i
    if(l != -1 && (*h)->array[l] > (*h)->array[max])
        max = l;
    //if it has right and right>max which is left aw i
    if(r != -1 && (*h)->array[r] > (*h)->array[max])
        max = r;
    
    // max changed
    if(max != i)
    {
        //swap current with max (need Heap* to edit root)
        temp = (*h)->array[i];
        (*h)->array[i] = (*h)->array[max];
        (*h)->array[max] = temp;
        
        // Percolate from the newly modified element
        PercolateDown(h, max);
    }
    // if max didnt change, i should perculate down kmn? No, since we are heapifying one element and not whole heap

} // O(logn)

int DeleteMax(Heap *h) 
{
    int data;
    
    if((*h)->count == 0)
        return -1;
    data = (*h)->array[0]; // store root 
    (*h)->array[0] = (*h)->array[(*h)->count-1]; // so now this is top
    (*h)->count--; //cant reach newly set root now
    PercolateDown(h,0); // percolate this element down
    return data; // data of heap

    // set min in heap and then percolated 
} // O(logn)

int Insert(Heap* h, int data)
{
    int i;
    if((*h)->count == (*h)->capacity) // full heap
        ResizeHeap(h); // allocate a bigger array

//(*h)->count was  empty space baaed ekhr element

    (*h)->count++; //increase size of heap, sar fi tnen fadyin
    i = (*h)->count -1; //index of where i want to insert 
    
    while(i>0 && data > (*h)->array[(i-1)/2]) //0 has no parent, data>data of parent
    {
        (*h)->array[i] = (*h)->array[(i-1)/2]; // data of current = data of parent so move parent down
        i = (i-1)/2; // move up to index of parent
    }
    (*h)->array[i] = data; // ekhr shi if ma kent > parent so hon mahalle
    return data; //yemken
}

void ResizeHeap(Heap* h)
{
    int i;
    int* array_old = (*h)->array;
    (*h)->array = (int* )malloc(sizeof(int)*(*h)->capacity*2);
    if(!(*h)->array)
        return;
    for(i=0; i<(*h)->capacity; i++)
        (*h)->array[i] = array_old[i];
    free(array_old);
}

void DestroyHeap(Heap* h)
{
    if(!h)
        return;
    free((*h)->array);
    free(h);
    h=NULL;
}

//heapifying an array
void Build(Heap* h, int A[], int n)
{   
    int i;
    if(!h)
        return;
    while(n > (*h)->capacity)
        ResizeHeap(h);
    for(i=0; i<n; i++)
        (*h)->array[i] = A[i];
    (*h)->count = n;
    for(i=(n-1)/2; i>=0; i--) //from the first nonleaf node upwards
        PercolateDown(h,i);

} // O(n) (other method takes nlogn)

