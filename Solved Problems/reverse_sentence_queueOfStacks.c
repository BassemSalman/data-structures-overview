#include "data_structures_implementation.h"
#include <stdio.h>
//stack of queues
//queue of chars
void reverse(char *str)
{
    if(!str || !*str)
        return;
    stack s = CreateStack();
    queue x = CreateQueue();
    char y;
    int i=0;
    while(*(str+i))
    {
        if(*(str+i) != ' ')
        {
            EnQueue(&x, *(str+i));   
        }
        else // if space then new word msh mazbut then new queue
        {
            Push(&s, x);
            x = CreateQueue();
            EnQueue(&x, ' '); // push queue containing space
            Push(&s, x);

            x=CreateQueue();
        }
        i++;
    }

    // empty means space or nothing left, how to know?
    if(!isEmptyQueue(x))   
       Push(&s, x); // last word or space bel ekhr 
    
    i=0;
    while(Top(s,&x)) {
        while(Front(x, &y))
            {
                DeQueue(&x);
                *(str+i) = y;
                i++;
            }
        
        Pop(&s);
    }
        //he can put as much spaces as he wants and wherever       
        // // last word doesnt have space after it
        // if(!isEmptyStack(s)){
        //     *(str+i) = ' ';
        //     i++;
        // }
}

int main()
{

    char str[] = "my name is test      ! ";
    reverse(str);
    int i = 0;
    while(str[i]) {
        printf("%c", str[i]);
        i++;
    }
    return 0;
}