//stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *next;
}STACK;
STACK *PUSH(STACK *top,int data){
	STACK *nw;
	nw=(STACK*)malloc(sizeof(STACK));
	if(nw==NULL){
		printf("stack overflow");
		exit(0);
	}
	else{
		nw->info=data;
		nw->next=NULL;
		if(top==NULL)
			top=nw;
		else{
			nw->next=top;
			top=nw;
		}
	}
	return top;
}
STACK *POP(STACK *top){
	STACK *temp;
	if(top==NULL)
		printf("no element to pop");
	else{
		temp=top;
		top=top->next;
		printf("The popped element is %d",temp->info);
		temp->next=NULL;
		free(temp);
	}
	return top;
}
void display_Stack(STACK *top) {
    if (top==NULL) {
        printf("no element to display");
        return;
    }
    STACK *temp=top;
    while (temp!=NULL) {
        printf("%d\t", temp->info);
        temp=temp->next;
    }
}
int main(){
	STACK *top=NULL;
	int ch,data;
	do{
		printf("\nTHE MENU:\n1:push\n2:pop\n3:display\n4:exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the data to be pushed:");
				scanf("%d",&data);
				top=PUSH(top,data);
				break;
			case 2:
				top=POP(top);
				break;
			case 3:
				display_Stack(top);
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
