void InOrder(Btree B) {
    Stack S = CreateStack();
    int proceed = 1;

    while(proceed) 
    {
        while(B) {
            Push(&S, B);
            B=B->left;
        }
        if(Top(S, &B))
        {
            Pop(&S);
            printf("%d ", B->data);
            B=B->right;
        }
        else 
            proceed = 0;
    }
}

void PreOrder(Btree B) {
    Stack S = CreateStack();
    int proceed = 1;

    while(proceed) 
    {
        while(B) {
            Push(&S, B);
            printf("%d ", B->data);
            B=B->left;
        }
        if(Top(S, &B))
        {
            Pop(&S);
            B=B->right;
        }
        else 
            proceed = 0;
    }
}


void PostOrder(Btree B)
{
    Stack S = CreateStack();
    Push(&S, B);
    Btree prev = NULL;
    while(proceed){
        while(B) {
            Push(&S, B);
            B=B->left;
        }
        if(!Top(S, &B))
        {
            if(!B->right || prev == B->right){
                Pop(&S);
                printf("%d ", B->data);
                prev=B;
                B=NULL;
            }
            else    
                B=B->right;
        }
        else
            proceed=0;

    }
}


void LevelOrder(Btree B) 
{
    queue Q = CreateQueue();
    EnQueue(&Q, B);

    while(Front(Q, &B)) {
        DeQueue(&B);
        printf("%d ", B->data);
        if(B->left)
            EnQueue(&Q, B->left);
        if(B->right)
            EnQueue(&Q, B->right);
    }
}


void postorder(Btree B)
{
    if(!B)
        return;
    postorder(B->left);
    postorder(B->right);
    printf("%d ", B->data);
}

void inorder(Btree B)
{
    if(!B)
        return;
    postorder(B->left);
    printf("%d ", B->data);
    postorder(B->right);
}

void preorder(Btree B)
{
    if(!B)
        return;
    printf("%d ", B->data);
    postorder(B->left);
    postorder(B->right);
}