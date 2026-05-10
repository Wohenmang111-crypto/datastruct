#define Stack_Size 100
typedef int Elemtype; /*与宏定义用法类似，这里是便于修改类型*/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
    Elemtype elem[Stack_Size];
    int top;
}Stack;

void init_Stack(Stack *S){
    S->top = -1;
}

bool IsEmpty(Stack *S){
    return (S->top == -1)?true:false;
}

void Push(Stack *S,Elemtype x){
//判满
if(S->top == Stack_Size-1){
    return;
}
    S->top++;
    S->elem[S->top] = x;
}

void Pop(Stack *S){
//判空
if(S->top == -1){
    return;
}
S->top--;
}

//Elemtype Get_top(Stack *S){
    //判空
//if(S->top == -1){
//    return -1;
//}
//    return S->elem[S->top];
//} 

bool Get_top(Stack *S,Elemtype *x){
if(S->top == -1){
    return false;
}
*x = S->elem[S->top];
   return true;
}

int main(){
    Stack S;
    Elemtype x,a;

    init_Stack(&S);

    Push(&S,3);
    Push(&S,9);
    Push(&S,1);
    Get_top(&S,&a);
    printf("%d",a);
    Push(&S,85);
    Push(&S,55);
    Push(&S,25);

    Pop(&S);
    Pop(&S);
    Pop(&S);

    Get_top(&S,&x);

    printf("%d",x);

}