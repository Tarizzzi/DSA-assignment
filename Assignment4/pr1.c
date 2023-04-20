//push and pop in stacka
#include<stdio.h>
#include<stdlib.h>
#define max 3
int stack[max],top=-1;
void push(int ele){
    if(top==max-1){
        printf("\nstack overflow");
    }
    else{
        top=top+1;
        stack[top]=ele;
    }
}
int pop(){
    int ele;
    if(top==-1){
        printf("\nstack underflow");
    }
    else{
        ele=stack[top];
        top=top-1;
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
