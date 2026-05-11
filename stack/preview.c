#define Stack_Size 100
typedef int Elemtype;

#include<stdio.h>
#include<stdbool.h>

typedef struct{
    Elemtype elem[Stack_Size];
    int top;
}Stack;

void init_Stack(Stack *S){
    S->top = -1;
}

bool Push(Stack *S,Elemtype x){
    if(S->top == Stack_Size - 1){
        return false;
    }
    S->top++;
    S->elem[S->top] = x;
    return true;
}

bool Pop(Stack *S,Elemtype *x){
    if(S->top == -1){
        return false;
    }
    *x = S->elem[S->top];
    S->top--;
    return true;
}

bool Get_top(Stack *S,Elemtype *x){
    if(S->top == -1){
        return false;
    }
    *x = S->elem[S->top];
    return true;
}

bool IsEmpty(Stack *S){
    if(S->top == -1){
        return true;
    }
    return false;
}

int main(){
    Stack S;
    Elemtype x;

    init_Stack(&S);

    Push(&S,20);
    Get_top(&S,&x);
    printf("%d\n",x);

    Push(&S,30);
    Get_top(&S,&x);
    printf("%d\n",x);

    Pop(&S,&x);
    printf("%d\n",x);

    return 0;
}