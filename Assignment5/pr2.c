//queue using structure
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 10
typedef struct{
    int arr[max];
    int front,rear;
}QUEUE;
void create(QUEUE *q){
    q->front=-1;
    q->rear=-1;
}
bool is_Full(QUEUE *q){
    if(q->rear==max-1)
    return 1;
    else
    return 0;
}
bool is_Empty(QUEUE *q){
    if(q->front==-1||q->front>q->rear)
    return 1;
    else
    return 0;
}
void insert(QUEUE *q,int ele){
    if(is_Full(q))
    printf("queue overflow");
    else{
        q->arr[++q->rear]=ele;
        if(q->front==-1)
        q->front=0;
    }
}
int delete(QUEUE *q){
    int ele;
    if(is_Empty(q))
    printf("queue underflow");
    else{
        ele=q->arr[q->front];
        q->front++;
    }
    return ele;
}
void display(QUEUE *q){
    int i;
    if(is_Empty(q))
    printf("empty queue");
    else{
        printf("The content of the queue:\n");
        for(i=q->front;i<=q->rear;i++){
            printf("%d\t",q->arr[i]);
        }
    }
}
int main(){
    int ch,n;
    QUEUE *q;
    q=(QUEUE*)malloc(max*sizeof(QUEUE));
    create(q);
    do{
        printf("\nmenu:-\n");
        printf("1:insert\n2:delete\n3:display\n4:exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element to be pushed:");
            scanf("%d",&n);
            insert(q,n);
            break;
            case 2:
            n=delete(q);
            printf("The deleted element:%d",n);
            break;
            case 3:
            display(q);
            break;
            case 4:
            printf("program terminated");
            exit(0);
        }
    }
    while(ch!=4);
    return 0;
}
