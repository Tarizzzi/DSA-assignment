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
NODE *insert_Beg(NODE *head){
    NODE *temp,*nw;
    temp=head;
    nw=create_Node();
    if(head==NULL)
    head=nw;
    else{
        nw->next=head;
        head->prev=nw;
        head=nw;
    }
    return head;
}
NODE *insert_End(NODE *head){
    NODE *nw,*temp;
    nw=create_Node();
    if(head==NULL)
    head=nw;
    else{
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=nw;
        nw->prev=temp;
    }
    return head;
}
NODE *insert_Loc(NODE *head){
    NODE *temp,*nw;
    int n,i;
    temp=head;
    if(head==NULL)
    head=create_Node();
    else{
        printf("Enter the location you want to insert:");
        scanf("%d",&n);
        nw=create_Node();
        for(i=1;i<n-1;i++)
        temp=temp->next;
        nw->next=temp->next;
        (temp->next)->prev=nw;
        temp->next=nw;
        nw->prev=temp;
    }
    return head;
}
NODE *after_Node(NODE *head){
    NODE *temp,*nw;
    int data,i;
    temp=head;
    if(head==NULL)
    head=create_Node();
    else{
        printf("Enter the info of the node after which you want to insert:");
        scanf("%d",&data);
        while(temp->info!=data)
        temp=temp->next;
        nw=create_Node();
        nw->next=temp->next;
        (temp->next)->prev=nw;
        nw->prev=temp;
        temp->next=nw;
    }
    return head;
}
int main(){
    NODE* head;
    int ch;
    head=NULL;
    do{
        printf("\nTHE MENU:\n1:create list\n2:forward traverse\n3:backward traverse\n4:insert at he beggining\n5:insert at the end\n6:insert at a given location\n7:insert after a node\n8:exit\nEnter your choice:");
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
            head=insert_Beg(head);
            break;
            case 5:
            head=insert_End(head);
            break;
            case 6:
            head=insert_Loc(head);
            break;
            case 7:
            head=after_Node(head);
            break;
            case 8:
            printf("PROGRAM TERMINATED");
            exit(0);
            deafult:
            printf("Invalid choice");
        }
    }
    while(ch!=8);
    return 0;
}
