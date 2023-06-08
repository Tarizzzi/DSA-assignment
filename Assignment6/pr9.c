//searching an element
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
void search(NODE *head){
	NODE *temp;
	int c,flag=0,posi=1;
	printf("Enter the data to be searched:");
	scanf("%d",&c);
	for(temp=head;temp!=NULL;temp=temp->next,posi++){
		if(temp->info==c){
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("ELEMENT FOUND at %d position",posi);
	else
		printf("ELEMENT NOT FOUND");
}
int main(){
	NODE *head=NULL;
	head=create_List(head);
	search(head);
	return 0;
}
