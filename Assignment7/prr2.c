//circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *next;
}NODE;
NODE *create(){
	NODE *nw;
	int data;
	nw=(NODE*)malloc(sizeof(NODE));
	if(nw==NULL){
		printf("memory not allocated");
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
	NODE *nw,*temp;
	int n,i;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	if(n>0){
		head=create();
		temp=head;
		for(i=1;i<n;i++){
			nw=create();
			nw->next=head;
			temp->next=nw;
			temp=nw;
		}
	}
	else
		printf("linked list not possible");
	return head;
}
void traverse(NODE *head){
	NODE *temp=head;
	printf("%d\t",temp->info);
	temp=temp->next;
	while(temp!=head){
		printf("%d\t",temp->info);
		temp=temp->next;
	}
}
NODE *insert(NODE *head){
	NODE *temp=head,*nw;
	int data;
	printf("Enter the value of the node after which you want to insert:");
	scanf("%d",&data);
	nw=create();
	while(temp->info!=data)
		temp=temp->next;
	nw->next=temp->next;
	temp->next=nw;
	return head;
}
NODE *del(NODE *head){
	NODE *temp=head,*temp2=head;
	int n;
	printf("Enter the value of the node you want to delete:");
	scanf("%d",&n);
	while(temp->info!=n){
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=temp->next;
	temp->next=NULL;
	printf("The deleted node's data:%d",temp->info);
	free(temp);
	return head;
}
int main(){
	NODE *head=NULL;
	int ch;
	do{
		printf("\nTHE MENU:\n1:create list\n2:traverse\n3:insert\n4:delete\n5:exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				head=create_List(head);
				break;
			case 2:
				traverse(head);
				break;
			case 3:
				head=insert(head);
				break;
			case 4:
				head=del(head);
				break;
			case 5:
				printf("PROGRAM TERMINATED");
				exit(0);
			default:
				printf("INVALID OPTION");
		}
	}
	while(ch!=5);
	return 0;
}
