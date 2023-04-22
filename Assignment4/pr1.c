//isfull,isempty,push,pop in stack(menu driven program)
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10
int stack[max],top=-1;
bool is_Full(){
    if(top==max-1)
    return 1;
    else
    return 0;
}
bool is_Empty(){
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(int ele){
    if(is_Full()){
        printf("\nstack overflow");
    }
    else{
        stack[++top]=ele;
    }
}
int pop(){
    int ele;
    if(is_Empty()){
        printf("\nstack underflow");
    }
    else{
        ele=stack[top--];
    }
    return ele;
}
int main(){
    int x,ch;
    do{
        printf("\nstack operation");
        printf("\n1:push\n2:pop\n3:exit");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter the element to be pushed:");
            scanf("%d",&x);
            push(x);
            break;
            case 2:
            x=pop();
            printf("\npopped element:%d\ntop element:%d",x,stack[top]);
            break;
            case 3:
            printf("\nprogram terminated");
            exit(0);
        }
    }
    while(ch!=3);
    return 0;
}
