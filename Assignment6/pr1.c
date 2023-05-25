//linked list
#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct node{
    int info;
    struct node *next;
}NODE;
NODE *create_Node(){
    NODE *nw;
    int data;
    nw=(NODE*)malloc(sizeof(NODE));
    if(nw==NULL){
        printf("no memory allocated");
        exit(0);
    }
    else{
        printf("Enter the data:");
        scanf("%d",&data);
        nw->info=data;
        nw->next=NULL;
    }
    return nw;
}
NODE *create_List(NODE *head){
    NODE *temp,*nw;
    int n,i;
    printf("Enter the number of node:");
    scanf("%d",&n);
    if(n!=0){
            nw=create_Node();
            head=nw;
            temp=head;
            for(i=1;i<n;i++){
                nw=create_Node();
                temp->next=nw;
                temp=nw;
            }
        }
    else
    printf("linked list not possible");
    return head;
}
void fwd_Traverse(NODE *head){
    NODE *temp;
    if(head==NULL)
    printf("no element");
    else{
        printf("The content of the linked list:\n");
        for(temp=head;temp->next!=NULL;temp=temp->next)
        printf("%d\t",temp->info);
        printf("%d",temp->info);
    }
}
int main(){
    int ch;
    NODE *head;
    do{
        printf("\nmenu:-\n");
        printf("1:create list\n2:forward traverse\n3:exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            head=create_List(head);
            break;
            case 2:
            fwd_Traverse(head);
            break;
            case 3:
            printf("program terminated");
            exit(0);
            default:
            printf("Invalid choice");
        }
    }
    while(ch!=3);
    return 0;
}
