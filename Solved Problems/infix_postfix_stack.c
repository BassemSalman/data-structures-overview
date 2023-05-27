#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Stack.h"

void printStack(stack s)
{
    element x;
    if(!Top(s,&x))
    {
        printf("Empty Stack\n");
        return;
    }
    while(Top(s,&x)) 
    {
        printf("| %c |\n", x);
        Pop(&s);
    }
    printf("------\n");
}

float calc(float x, float y, char c)
{
    switch(c)
    {
        case'+':
            return x+y;
        case'-':
            return y-x;
        case'*':
            return x*y;
        case'/':
            return y/x; 
        case'^':
            return pow(y,x);
    }
    return 0;
}

int stackable(char o1, char o2)
{
    switch (o1)
    {
        case '(': return 1;
        case '+': case '-': return (o2 == '(');
        case '#': return (o2 != '#');
        case '*':case '/': return (o2 == '(' || o2 == '+' || o2 == '-');
        case '^': return (o2 != '#' && o2 != '^');
        case ')': return (o2 == '(');
    }
    return 0;
}


void infixToPostfix(char* infix, char* postfix, stack* s) // postfix points to where we can fill str
{
    element x;
    // loop over infix string
    while(*infix){
        // digit to postfix directly
        if(*infix >= '0' && *infix <= '9') {
            *postfix = *infix; 
            postfix++;
            infix++;
            continue;
        }
        // operator then check if push to stack or put in str
        // prec(outside) > prec(inside) then Push else then Pop all till we reach prec(in)>prec(out) and push
        if(isEmptyStack(*s))
            Push(s, *infix);
        else {
            // empty till it becomes stackable if needed
            while(Top(*s, &x) && !stackable(*infix, x))
            {
                Pop(s);
				*postfix = x;
				printf("X  is equal to %c", *postfix);

                postfix++;
            }
			if(x == '(' && *infix == ')')
				Pop(s);
			if(*infix != ')')
	            Push(s, *infix); // either its now stackable, or its empty
        }
        infix++;
    }    
    
    // emptying stack in postfix after infix is done
    while(Top(*s, &x))
    {
        *postfix = x;
        Pop(s);
        postfix++;
    }
    *postfix = '\0';
	printf("Put \\0 after %c", *(postfix-1));
}


 
float postToRes(char * postfix, stack* s)
{
    float x,y;
    while(*postfix)
    {
        if(*postfix >= '0' && *postfix <= '9'){
            Push(s, *postfix - 48);
            printf("pushing :%d\n", *postfix-48);
        }
        else
        {
            if(Top(*s, &x))     
                Pop(s);
            if(*postfix == '#') 
            {
                printf("Pushed -x = %f\n", -x);
                Push(s, -x );
                postfix++;
                continue;
            }
            if(Top(*s, &y)) {
                Pop(s);
                Push(s, calc(x,y,*postfix));
                printf("popped %f and %f, pushed %f\n", x,y,calc(x,y,*postfix));
            }
        }
        postfix++;
    }
    Top(*s, &x);
    return x;
}

float infix_evaluation(char* infix)
{   
    stack s = CreateStack();
    char* postfix = (char*)malloc(sizeof(char)*(strlen(infix)+1));
    *(postfix + strlen(infix)+1) = '\0'; // not necessary since done it somewhere else
    
    // infix is a local variable and doesnt change if infix++
    infixToPostfix(infix, postfix,  &s);

    printf("in: %s \npos: %s\n", infix, postfix);
    printStack(s); // empty

    float res = postToRes(postfix, &s);
    return res;
}

int main()
{
    // char inf[] = "((6-(2+3))*(3+8/2))^2+3";
	char inf[] = "7-(#(#(2+3)))^2";
	// char inf[] = "
    printf("%f", infix_evaluation(inf));
    return 0;
}