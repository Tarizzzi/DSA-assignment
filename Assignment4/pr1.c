//isfull,isempty,push,pop in stack(menu driven program)
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10
int top=-1;
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
void push(int stack[],int ele){
    if(is_Full()){
        printf("\nstack overflow");
    }
    else{
        stack[++top]=ele;
    }
}
int pop(int stack[]){
    int ele;
    if(is_Empty()){
        printf("\nstack underflow");
    }
    else{
        ele=stack[top--];
    }
    return ele;
}
int display(int stack[]){
    int ele;
    ele=stack[top];
    return ele;
}
int main(){
    int x,ch,stack[max];
    do{
        printf("\nstack operation");
        printf("\n1:push\n2:pop\n3:display top element\n4:exit");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter the element to be pushed:");
            scanf("%d",&x);
            push(stack,x);
            break;
            case 2:
            x=pop(stack);
            printf("\npopped element:%d",x);
            break;
            case 3:
            x=display(stack);
            printf("\ntop element:%d",x);
            case 4:
            printf("\nprogram terminated");
            exit(0);
        }
    }
    while(ch!=3);
    return 0;
}
