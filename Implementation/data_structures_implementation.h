#include "structs.h" 

//Stack
extern stack CreateStack();
extern int Push(stack* s, elementS e);
extern int Pop(stack* s);
extern int isEmptyStack(stack s);
extern int Top(stack s, elementS* t);

//Queue
extern queue CreateQueue();
extern int EnQueue(queue* q, elementQ e);
extern int DeQueue(queue* q);
extern int Front(queue q, elementQ* e);
extern int isEmptyQueue(queue q);

//Btree
extern Btree CreateBtree();
extern Btree Construct(elementB e, Btree L, Btree R);
extern int isEmptyBtree(Btree B);
extern int Root ( Btree B, elementB* e);
extern int Right( Btree B, Btree* R);
extern int Left ( Btree B, Btree* L);
extern void PushBtree(Btree* B, elementB e);

//Heaps
extern Heap CreateHeap(int capacity, int heap_type);
extern int  Parent(Heap h, int i);
extern int  LeftChild(Heap h, int i);
extern int  RightChild(Heap h, int i);
extern int  GetMaximum(Heap h);
extern int  DeleteMax(Heap *h) ;
extern void PercolateDown(Heap *h, int i);
extern void Build(Heap* h, int A[], int n);
extern void DestroyHeap(Heap* h);
extern void ResizeHeap(Heap* h);