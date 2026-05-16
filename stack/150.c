/*利用栈计算逆波兰表达式*/

#include <string.h> //strlen函数，strcmp函数(字符串比较函数)
#include <stdlib.h> //atoi函数(用于将字符串里的数字，直接变成int，对负数同样适用，
                    //这比利用double pow(10,j)，做循环计算值，要方便的多，还可以涵盖负数)

int evalRPN(char** tokens, int tokensSize) {//char** 字符串数组，char* 字符串
    int elem[tokensSize];
    int top = -1;

    for(int i = 0;i < tokensSize;i++){
        if(strcmp(tokens[i],"+") == 0){//strcmp(str1,str2);return 0/<0/>0(字典序);
            elem[top-1] = elem[top-1] + elem[top];
            top--;
        }
        else if(strcmp(tokens[i],"-") == 0){//'-'单个字符 "-"字符串（char**）
            elem[top-1] = elem[top-1] - elem[top];
            top--;
        }
        else if(strcmp(tokens[i],"*") == 0){//tokens[i]是指针(地址);"+"也是一个地址;应比较内容
            elem[top-1] = elem[top-1] * elem[top];
            top--;
        }
        else if(strcmp(tokens[i],"/") == 0){
            elem[top-1] = elem[top-1] / elem[top];
            top--;
        }
        else{
        elem[++top] = atoi(tokens[i]);
        }
    }
    return elem[0];
}