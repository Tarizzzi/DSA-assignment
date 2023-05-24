//linked list
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 10
struct node{
    int info;
    struct node *next;
}Node;
Node *create_Node(){
    int data;
    Node *n;
    n=(Node*)malloc(sizeof(Node));
    if(n==NULL){
        printf("no memory allocated");
        exit(0);
    }
    else{
        printf("Enter the data:");
        scanf("%d",&data);
        n->info=data;
        n->=NULL;
    }
    return n;
}
void create_List(Node *head){
    Node *temp,*n;
    int data,n,i;
    printf("Enter the number of node:");
    scanf("%d",&n);
    if(n!=0){
        if(head==NULL){
            n=create_Node();
            head=n;
            temp=head;
        }
        else{
            for(i=1;i<n;i++){
                n=create_Node();
                temp->next=n;
                temp=n
            }
        }
    }
    else
    printf("linked list not possible");
}
void fwd_Traverse(Node *head){
    Node *temp;
    if(head==NULL)
    printf("no element");
    else{
        temp=head;
        while(temp->next!=NULL){
            printf("%d\t",temp->info);
            temp=temp->next;
        }
        printf("%d",temp->info);
    }
}
int main(){
    int ch,n;
    do{
        printf("\nmenu:-\n");
        printf("1:create node\n2:create list\n3:forward traverse\n4:exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element to be inserted in the linked list:");
            scanf("%d",&n);
            create_List(n);
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
