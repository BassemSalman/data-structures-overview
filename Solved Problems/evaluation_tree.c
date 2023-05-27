#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Header\DS.h"

int is_digit(char c)
{
    return (c>='0' && c<='9');
}

int to_digit(char c)
{
    return c-48;
}

int is_operator(char c)
{
    return (c == '+' || c == '/' || c == '*' || c == '-' || c == '#' || c=='^');
}

float operation(float x, char o, float y)
{
    switch(o)
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
        case'#':
            return -x;
    }

}

// BTREE
void printTree(Btree B)
{
    queue q = CreateQueue();
    elementQ x = B, track=B;
    EnQueue(&q, B);
    printf("\nTree:\n");
    while(Front(q, &x))
    {
        DeQueue(&q);
        if(x == track && x!=B) {
            printf("\n");    
            track = NULL;
        }
        if(x==track)    
            track=NULL;
        printf("%c ", x->data);
        
        if(x->left) 
            EnQueue(&q, x->left);
        if(x->right)
            EnQueue(&q, x->right);
        
        if(track == NULL) {
            if(x->left) 
                track=x->left;
            else if(x->right)
                track=x->right;
        }
    }       
}

void printStack(stack s)
{
    elementS x;
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

// stack of Btrees oops


ExpressionTree Build(char *postfix)
{
    stack s = CreateStack();
    ExpressionTree x,y,z;
    while(*postfix)
    {
        if(is_digit(*postfix))
        {
            z = Construct((*postfix), NULL,NULL);
            Push(&s,z);
        }
        else if(is_operator(*postfix))
        {
            if(Top(s,&x)) Pop(&s);
            else x=NULL;
            
            // pop once if # and init y
            if(*postfix != '#')
            {
                if(Top(s,&y)) Pop(&s);
                else y=NULL;
            }
            else
                y=NULL;

            
            z = Construct(*postfix, y,x);
            Push(&s, z);
        }
        postfix++;
    }
    Top(s, &x);
    Pop(&s);
    return x;
}

float result(ExpressionTree B)
{
    if(!B)
        return 0;
    else if(is_digit(B->data))
        return to_digit(B->data);
    
    if(is_operator((B->data)))
    {
        float x = result(B->right);
        float y = result(B->left );
        return operation(y, (B->data), x);   
    }
    return 1;
    // btefro2 eza y x aw x y ka operation
} 


void print2DUtil(Btree root, int space)
{
    // Base case
    if (root == NULL)
        return;
    space += 5;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%c\n", root->data);
    print2DUtil(root->left, space);
} 

int main()
{
    // char inf[] = "((6-(2+3))*(3+8/2))^2+3";
	// char infix[] = "7-(#(#(2+3)))^2";
    char p1[] = "72+##2^"; //9
    char x[] = "723+##2^-"; // 7(2^5)-
    char p2[] = "623+-382/+*2^3+"; //52
    
    ExpressionTree root = Build(x);
    printf("%d is the res", result(root));

    print2DUtil(root,0);
    return 0;
}