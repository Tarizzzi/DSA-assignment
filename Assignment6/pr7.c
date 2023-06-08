//merging two linked lists
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
	if(n>=1){
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
NODE *merge(NODE *head1,NODE *head2){
	NODE *temp;
	temp=head1;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=head2;
	return head1;
}
void fwd_Traverse(NODE *head){
	NODE *temp;
	if(head==NULL)
		printf("no content to display");
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
	NODE *head=NULL,*head1=NULL,*head2=NULL;
	printf("For the first linked list:\n");
	head1=create_List(head1);
	printf("For the second linked list:\n");
	head2=create_List(head2);
	printf("The merged array:\n");
	head=merge(head1,head2);
	fwd_Traverse(head);
	printf("\n");
	return 0;
}
