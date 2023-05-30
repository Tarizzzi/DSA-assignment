//linked list menu driven
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
}NODE;
NODE *create_Node(){
    NODE *nw;
    int data;
    nw=(NODE*)malloc(sizeof(NODE));
    if(nw==NULL){
        printf("no memory allocated:");
        exit(0);
    }
    else{
        printf("Enter the number:");
        scanf("%d",&data);
        nw->info=data;
        nw->next=NULL;
    }
    return nw;
}
NODE *create_List(NODE *head){
    NODE *nw,*temp;
    int n,i;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    if(n>=0){
        head=create_Node();
        temp=head;
        for(i=1;i<n;i++){
            nw=create_Node();
            temp->next=nw;
            temp=nw;
        }
    }
    else
    printf("list not possible");
    return head;
}
void fwd_Traverse(NODE *head){
    NODE *temp;
    if(head==NULL)
    printf("no content to display");
    else{
        for(temp=head;temp->next!=NULL;temp=temp->next)
        printf("%d\t",temp->info);
        printf("%d",temp->info);
    }
}
NODE *insert_Beg(NODE *head){
    NODE *nw;
    if(head==NULL)
    head=create_Node();
    else{
        nw=create_Node();
        nw->next=head;
        head=nw;
    }
    return head;
}
NODE *insert_End(NODE *head){
    NODE *nw,*temp;
    if(head==NULL)
    head=create_Node();
    else{
        nw=create_Node();
        temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=nw;
    }
    return head;
}
NODE *insert_Location(NODE *head){
    NODE *temp,*nw;
    int n,i;
    printf("Enter the node in which you want to insert the element:");
    scanf("%d",&n);
    if(head==NULL)
    head=create_Node(head);
    else if(n>0){
        if(n==1)
        insert_Beg(head);
        else{
            temp=head;
            for(i=1;i<n-1;i++)
            temp=temp->next;
            nw=create_Node(head);
            nw->next=temp->next;
            temp->next=nw;
        }
    }
    return head;
}
NODE *del_Beg(NODE *head){
    NODE *temp;
    if(head==NULL){
        printf("deletion not possible");
        exit(0);
    }
    else{
        temp=head;
        head=head->next;
        printf("The deleted element is %d",temp->info);
        temp->next=NULL;
        free(temp);
    }
    return head;
}
NODE *del_Location(NODE *head){
    NODE *temp,*temp2;
    int i,n;
    printf("Enter the node you want to delete:");
    scanf("%d",&n);
    if(head==NULL){
        printf("deletion not possible");
        exit(0);
    }
    else if(n>0){
        if(n==1){
            del_Beg(head);
            exit(0);
        }
        else{
            temp2=temp=head;
            for(i=1;i<n-1;i++)
            temp=temp->next;
            while(temp2->next!=temp)
            temp2=temp2->next;
            temp2->next=temp->next;
            printf("The deleted element is %d",temp->info);
            temp->next=NULL;
            free(temp);
        }
    }
    return head;
}
int main(){
    int ch;
    NODE *head;
    do{
        printf("\nThe menu:\n1:create list\n2:traverse list\n3:insert at the beggining\n4:insert at the end\n5:Insert at the given location\n6:delete at beginning\n7:delete at given location\n8:exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            head=create_List(head);
            break;
            case 2:
            fwd_Traverse(head);
            break;
            case 3:
            head=insert_Beg(head);
            break;
            case 4:
            head=insert_End(head);
            case 5:
            head=insert_Location(head);
            break;
            case 6:
            head=del_Beg(head);
            break;
            case 7:
            head=del_Location(head);
            break;
            case 8:
            printf("PROGRAM TERMINATED");
            exit(0);
            default:
            printf("Invalid choice");
        }
    }
    while(ch!=8);
    return 0;
}
