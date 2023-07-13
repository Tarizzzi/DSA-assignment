//deletion
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
void fwd_Traverse(NODE *head){
	NODE *temp;
	if(head==NULL)
		printf("no content to display");
	else{
		temp=head;
		printf("The content of the linked list:\n");
		while(temp->next!=NULL){
			printf("%d\t",temp->info);
			temp=temp->next;
		}
		printf("%d",temp->info);
	}
}
NODE *delete_Beg(NODE *head){
	NODE *temp;
	if(head==NULL){
		printf("Deletion not possible");
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
NODE *delete_End(NODE *head){
	NODE *temp,*temp1;
	if(head==NULL){
		printf("deletion not possible");
		exit(0);
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp1=temp;
			temp=temp->next;
		}
		printf("The deleted element is %d",temp->info);
		temp->next=NULL;
		free(temp);
		temp1->next=NULL;
	}
	return head;
}
NODE *delete_Loc(NODE *head){
	NODE *temp,*temp2;
	int i,n;
	temp=head;
	temp2=head;
	if(head==NULL)
		printf("deletion not possible");
	else{
		printf("Enter the node you want to delete:");
		scanf("%d",&n);
		for(i=1;i<n;i++)
			temp=temp->next;
		while(temp2->next!=temp)
			temp2=temp2->next;
		temp2->next=temp->next;
		printf("The deleted node:%d",temp->info);
		temp->next=NULL;
		free(temp);
	}
	return head;
}
NODE *delete_Info(NODE *head){
	NODE *temp,*temp2;
	int n;
	if(head==NULL)
		printf("Deletion not possible");
	else{
		printf("Enter the element of the node you want to delete:");
		scanf("%d",&n);
		temp=head;
		temp2=head;
		while(temp->info!=n)
			temp=temp->next;
		while(temp2->next!=temp)
			temp2=temp2->next;
		temp2->next=temp->next;
		printf("The deleted node:%d",temp->info);
		temp->next=NULL;
		free(temp);
	}
	return head;
}
int main(){
	NODE *head=NULL;
	int ch;
	do{
		printf("\nTHE MENU:\n");
		printf("1:create list\n2:traverse list\n3:delete from the beginning\n4:delete from the end\n5:delete from the given location\n6:delete from the info in node\n7:exit\n");
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
				head=delete_Beg(head);
				break;
			case 4:
				head=delete_End(head);
				break;
			case 5:
				head=delete_Loc(head);
				break;
			case 6:
			    head=delete_Info(head);
				break;
			case 7:
				printf("PROGRAM TERMINATED\n");
				exit(0);
			default:
				printf("Invalid choice");
		}
	}
	while(ch!=7);
	return 0;
}
