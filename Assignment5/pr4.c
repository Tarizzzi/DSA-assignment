//queue using 2 stack(display not working)
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 10
typedef struct{
    int a[max];
    int top;
}QUEUE;
void create(QUEUE *a1,QUEUE *a2){
    a1->top=-1;
    a2->top=-1;
}
bool is_Empty(QUEUE *a1){
    if(a1->top==-1)
    return 1;
    else
    return 0;
}
bool is_Full(QUEUE *a1){
    if(a1->top==max-1)
    return 1;
    else
    return 0;
}
void insert(QUEUE *a1,int n){
    if(is_Full(a1))
    printf("queue overflow");
    else
    a1->a[++(a1->top)]=n;
}
void remov(QUEUE *a1,QUEUE *a2){
    int i,n;
    while(a1->top!=-1)
    a2->a[++(a2->top)]=a1->a[(a1->top)--];
    n=a2->a[(a2->top)--];
    printf("The deleted element is %d",n);
    while(a2->top!=-1)
    a1->a[++(a1->top)]=a2->a[(a2->top)--];
}
void display(QUEUE *a1,QUEUE *a2){
    int i;
    if(is_Empty(a1))
    printf("no element to display");
    else
    a2->a[++(a2->top)]=a1->a[(a1->top)--];
    printf("The queue:\n");
    for(i=(a2->top);i>=0;i--)
    printf("%d\t",a2->a[i]);
    while(a2->top!=-1)
    a1->a[++(a1->top)]=a2->a[(a2->top)--];
}
int main(){
    int ch,n;
    QUEUE *a1,*a2;
    a1=(QUEUE*)malloc(max*sizeof(QUEUE));
    a2=(QUEUE*)malloc(max*sizeof(QUEUE));
    create(a1,a2);
    do{
        printf("\nTHE MENU:\n");
        printf("1:insert\n");
        printf("2:remove\n");
        printf("3:display\n");
        printf("4:exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the value to be inserted:");
            scanf("%d",&n);
            insert(a1,n);
            break;
            case 2:
            remov(a1,a2);
            break;
            case 3:
            display(a1,a2);
            break;
            case 4:
            printf("PROGRAM TERMINATED");
            exit(0);
        }
    }
    while(ch!=4);
    return 0;
}
