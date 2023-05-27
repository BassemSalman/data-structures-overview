//Btree
#include <stdlib.h>

typedef int elementB;
typedef struct nodeB {
    elementB data;
    struct nodeB *left, *right;
}*Btree;

typedef int ElementTree;
typedef Btree ExpressionTree;

//Stack
typedef Btree elementS;
typedef struct nodeS{
    struct nodeS* next;
    elementS data;
}*stack;


//Queue
typedef Btree elementQ;
typedef struct nodeQ
{
  elementQ data;
  struct nodeQ* next;
}nodeQ;

typedef struct queue{
    nodeQ *front;
    nodeQ *rear ;
} queue;
//maxWidth Queue
// typedef struct el{
//     Btree tree;
//     int level;
// }elementQ;

//Heap
typedef struct {
    int* array;
    int  count;     // current nb of elements in heap
    int  capacity;  // size of heap 
    int  heap_type; // min or max 1 or 2
}*Heap;