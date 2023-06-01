//menu driven implementation of linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next,*prev;
}NODE;
NODE *create_Node(){
    int data;
    NODE *nw;
    nw=(NODE*)malloc(sizeof(NODE));
    if(nw==NULL){
        printf("no memory allocated");
        exit(0);
    }
    else{
        printf("Enter the number:");
        scanf("%d",&data);
        nw->info=data;
        nw->next=NULL;
        nw->prev=NULL;
    }
    return nw;
}
NODE *create_List(NODE *head){
    int n,i;
    NODE *temp,*nw;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    if(n>0){
        head=create_Node();
        temp=head;
        for(i=1;i<n;i++){
            nw=create_Node();
            temp->next=nw;
            nw->prev=temp;
            temp=nw;
        }
    }
    else
    printf("linked list not possible");
    printf("List successfully created\n");
    return head;
}
void fwd_Traverse(NODE *head){
    NODE *temp;
    temp=head;
    if(head==NULL)
    printf("traverse not possible");
    else{
        printf("Forward traverse:\n");
        while(temp!=NULL){
            printf("%d\t",temp->info);
            temp=temp->next;
        }
    }
}
void back_Traverse(NODE *head){
    NODE *temp;
    temp=head;
    if(head==NULL)
    printf("traverse not possible");
    else{
        while(temp->next!=NULL)
        temp=temp->next;
        printf("\nBackward traverse:\n");
        while(temp!=NULL){
            printf("%d\t",temp->info);
            temp=temp->prev;
        }
    }
}
int main(){
    NODE* head;
    int ch;
    head=NULL;
    do{
        printf("\nTHE MENU:\n1:create list\n2:forward traverse\n3:backward traverse\n4:exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            head=create_List(head);
            break;
            case 2:
            fwd_Traverse(head);
            break;
            case 3:
            back_Traverse(head);
            break;
            case 4:
            printf("PROGRAM TERMINATED");
            exit(0);
            deafult:
            printf("Invalid choice");
        }
    }
    while(ch!=4);
    return 0;
}
