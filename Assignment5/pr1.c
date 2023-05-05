#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 10
int queue[max],front=-1,rear=-1;
bool is_Full(){
    if(rear==max-1)
    return 1;
    else
    return 0;
}
bool is_Empty(){
    if(front==-1||front>rear)
    return 1;
    else
    return 0;
}
void insert(int ele){
    if(is_Full())
    printf("queue overflow");
    else{
        queue[++rear]=ele;
        if(front==-1)
        front=0;
    }
}
int delete(){
    int ele;
    if(is_Empty())
    printf("queue underflow");
    else{
        ele=queue[front];
        front++;
    }
    return ele;
}
void display(){
    int i;
    if(is_Empty())
    printf("empty queue");
    else{
        printf("The content of the queue:\n");
        for(i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
}
int main(){
    int ch,n;
    do{
        printf("\nmenu:-\n");
        printf("1:insert\n2:delete\n3:display\n4:exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element to be pushed:");
            scanf("%d",&n);
            insert(n);
            break;
            case 2:
            n=delete();
            printf("The deleted element:%d",n);
            break;
            case 3:
            display();
            break;
            case 4:
            printf("program terminated");
            exit(0);
        }
    }
    while(ch!=4);
    return 0;
}
