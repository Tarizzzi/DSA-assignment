//bubble sort
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
NODE *sort(NODE *head){
	NODE *p,*q;
	int c;
	for(p=head;p!=NULL;p=p->next){
		for(q=head;q->next!=NULL;q=q->next){
			if(p->info<q->info){
				c=p->info;
				p->info=q->info;
				q->info=c;
			}
		}
	}
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
int main(){
	NODE *head=NULL;
	head=create_List(head);
	fwd_Traverse(head);
	printf("\n");
	head=sort(head);
	fwd_Traverse(head);
	return 0;
}
