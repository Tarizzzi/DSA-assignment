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
        printf("no memory allocated");
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
    printf("No list possible");
    return head;
}
NODE *delete_Node(NODE *head,int n){
    NODE *p=head,*q;
    while(p->info==n){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    p->next=NULL;
    printf("%d\t",p->info);
    free(p);
    return head;
}
NODE *delete_Odd(NODE *head){
    NODE *p=head;
    int i=0,c=1;
    while(p!=NULL){
        p=p->next;
        c++;
    }
    for(i=0,p=head;i<c;i++,p=p->next){
        if(i%2!=0)
        delete_Node(head,p->info);
    }
    return head;
}
void fwd_Traverse(NODE *head){
    NODE *temp;
    if(head==NULL)
    printf("No content to display");
    else{
        printf("The content of the linked list:\n");
        for(temp=head;temp->next!=NULL;temp=temp->next)
        printf("%d\t",temp->info);
        printf("%d",temp->info);
    }
}
int main(){
    NODE *head=NULL;
    head=create_List(head);
    fwd_Traverse(head);
    delete_Odd(head);
    printf("\nThe deleted nodes are:\n");
    fwd_Traverse(head);
    return 0;
}
