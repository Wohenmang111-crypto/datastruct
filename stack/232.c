#include <stdio.h>
#include <stdbool.h>//bool的
#include <stdlib.h>//malloc函数的头文件

#define Stack_Size 100
typedef int Elemtype;


typedef struct {
    Elemtype elem1[Stack_Size];
    Elemtype elem2[Stack_Size];
    int top1;
    int top2;
} MyQueue;


MyQueue* myQueueCreate() {
  MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));//动态分配内存以创建MyQueue
  obj->top1 = -1;//初始化MyQueue
  obj->top2 = -1;
  return obj;//返回MyQueue型
}
//元素分居于两个栈，在栈1进入，在栈2弹出，栈一栈二中的元素不相交，相并为全集，pop完了，把栈1中的元素转到栈2就行
void myQueuePush(MyQueue* obj, int x) {//
    obj->top1++;
    obj->elem1[obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->top2 == -1){ //
    while(obj->top1 > -1){
        obj->top2++;
        obj->elem2[obj->top2] = obj->elem1[obj->top1];
        obj->top1--;
    }
}
    int x;
    x = obj->elem2[obj->top2];
    obj->top2--;
    return x; 
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top2 == -1){
    while(obj->top1 > -1){
        obj->top2++;
        obj->elem2[obj->top2] = obj->elem1[obj->top1];
        obj->top1--;
    }
}
    return obj->elem2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->top1 == -1 && obj->top2 == -1){//判空条件
        return true;
    }
    return false;
}

void myQueueFree(MyQueue* obj) {
    obj->top1 = -1;
    obj->top2 = -1;
    free(obj);//动态分配内存后，释放内存，才算Free
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/