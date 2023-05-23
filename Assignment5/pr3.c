#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 5
int queue[max],rear=-1,front=-1;
bool is_Empty(){
    if(front==-1&&rear==-1)
    return 1;
    else
    return 0;
}
bool is_Full(){
    if((front==0&&rear==max-1)||(front-1==rear))
    return 1;
    else
    return 0;
}
void insert(int n){
    if(is_Full())
    printf("Queue overflow");
    else
    queue[++rear]=n;
    if(front==-1)
    front=0;
}
int delete(){
    int n;
    if(is_Empty())
    printf("Queue underflow");
    else{
        n=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else
        front=(front+1)%max;
    }
    return n;
}
void display(){
    int i=front;
    if(is_Empty())
    printf("no content to display");
    else{
        printf("The content of the queue:\n");
        while(i!=rear){
            printf("%d\t",queue[i]);
            i=(i+1)%max;
        }
        printf("%d",queue[rear]);
    }
}
int  main(){
    int ch,n;
    do{
        printf("\nTHE MENU:\n");
        printf("1:insert\n");
        printf("2:delete\n");
        printf("3:display\n");
        printf("4:count\n");
        printf("5:exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter the value to be inserted:");
            scanf("%d",&n);
            insert(n);
            break;
            case 2:
            n=delete();
            printf("The deleted element: %d",n);
            break;
            case 3:
            display();
            break;
            case 4:
//            n=count();
//            printf("The number of elements of the queue: %d",n);
//            break;
            case 5:
            printf("PROGRAM TERMINATED");
            exit(0);
            default:
            printf("Invalid choice");
        }
    }
    while(ch!=5);
    return 0;
}
