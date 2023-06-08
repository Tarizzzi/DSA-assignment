//queue using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *next;
}QUEUE;
QUEUE *enque(QUEUE *front,int data){
	QUEUE *nw,*temp;
	nw=(QUEUE*)malloc(sizeof(QUEUE));
	if(nw==NULL){
		printf("queue overflow");
		exit(0);
	}
	else{
		nw->info=data;
		nw->next=NULL;
		temp=front;
		if(temp==NULL)
			front=nw;
		else{
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=nw;
	}
	return front;
	}
}
QUEUE *deque(QUEUE *front){
	QUEUE *temp,*rear;
	temp=front;
	if(front==NULL)
		printf("no element to delete");
	else{
		front=front->next;
		printf("The deleted element is %d",temp->info);
		temp->next=NULL;
		free(temp);
	}
	return front;
}
void display(QUEUE *front) {
    QUEUE *temp=front;
    if(temp==NULL)
        printf("No elements to display.\n");
    else{
        printf("The content of the queue:\n");
        while(temp!=NULL){
            printf("%d\t",temp->info);
            temp=temp->next;
        }
    }
}
int main(){
	QUEUE *rear=NULL,*front=NULL;
	int ch,data;
	do{
		printf("\nTHE MENU:\n1:insert\n2:delete\n3:display\n4:exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the value to be inserted in the queue:");
				scanf("%d",&data);
				front=enque(front,data);
				break;
			case 2:
				front=deque(front);
				break;
			case 3:
				display(front);
				break;
			case 4:
				printf("PROGRAM TERMINATED");
				exit(0);
			default:
				printf("INVALID CHOICE");
		}
	}
	while(ch!=4);
	return 0;
}
