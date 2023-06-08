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
NODE *insert_Beg(NODE *head){
	NODE *nw;
	nw=create_Node();
	if(head==NULL)
		head=nw;
	else{
		nw->next=head;
		head=nw;
	}
	return head;
}
NODE *insert_End(NODE *head){
	NODE *nw,*temp;
	nw=create_Node();
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=nw;
	nw->next=NULL;
	return head;
}
NODE *insert_Loc(NODE *head){
	NODE *p,*nw;
	p=head;
	int i,cnt=1,n;
	while(p!=NULL){
		p=p->next;
		cnt++;
	}
	if(head==NULL)
		head=create_Node();
	else{
		printf("Enter the location you want to insert the element:");
		scanf("%d",&n);
		if(n>cnt+1)
			printf("insertion not possible");
		else if(n==1)
			head=insert_Beg(head);
		else if(n==cnt+1)
			head=insert_End(head);
		else{
			p=head;
			for(i=1;i<n-1;i++)
				p=p->next;
			nw=create_Node();
			nw->next=p->next;
			p->next=nw;
		}
	}
	return head;
}
NODE *insert_AfterNode(NODE *head){
	NODE *p,*nw;
	int i=1,n;
	if(head==NULL)
		head=create_Node();
	else{
		printf("Enter the node's element after which you want to insert:");
		scanf("%d",&n);
		nw=create_Node();
		p=head;
		while(p->info!=n)
			p=p->next;
		nw->next=p->next;
		p->next=nw;
	}
	return head;
}
int main(){
	NODE *head=NULL;
	int ch;
	do{
		printf("\nTHE MENU:\n");
		printf("1:create list\n2:traverse list\n3:insert at beginning\n4:insert at end\n5:insert at any location\n6:insert after a node\n7:exit\n");
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
				head=insert_Beg(head);
				break;
			case 4:
				head=insert_End(head);
				break;
			case 5:
				head=insert_Loc(head);
				break;
			case 6:
				head=insert_AfterNode(head);
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
