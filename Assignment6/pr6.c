//backward traversal of linked list
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
		printf("Enter the data:");
		scanf("%d",&data);
		nw->info=data;
		nw->next=NULL;
	}
	return nw;
}
NODE *create_List(NODE *head){
	int n,i;
	NODE *temp,*nw;
	printf("Enter the number of nodes:");
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
		printf("linked list no possible");
	return head;
}
void rev_Traverser(NODE *head){
	if(head==NULL)
		return;
	else{
		rev_Traverser(head->next);
		printf("%d\t",head->info);
	}
}
int main(){
    NODE *head=NULL;
    head=create_List(head);
    printf("Reverse traversing the linked list:\n");
    rev_Traverser(head);
    return 0;
}
