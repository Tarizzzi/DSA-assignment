//polynomial
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int exp;
	float coeff;
	struct node *next;
}POLY;
POLY *create_Term(){
	POLY *nw;
	int expo;
	float ceff;
	nw=(POLY*)malloc(sizeof(POLY));
	if(nw==NULL){
		printf("no memory allocated");
		exit(0);
	}
	else{
		printf("Enter the coefficient and exponent:");
		scanf("%f%d",&ceff,&expo);
		nw->exp=expo;
		nw->coeff=ceff;
		nw->next=NULL;
	}
	return nw;
}
POLY *create_Polynomial(POLY *head){
	int n,i;
	POLY *temp,*nw;
	printf("Enter the number of terms:");
	scanf("%d",&n);
	if(n>=1){
		nw=create_Term();
		head=nw;
		temp=head;
		for(i=1;i<n;i++){
			nw=create_Term();
			temp->next=nw;
			temp=nw;
		}
	}
	else
		printf("linked list no possible");
	return head;
}
void fwd_Traverse(POLY *head){
	POLY *temp;
	if(head==NULL)
		printf("no content to display");
	else{
		temp=head;
		while(temp->next!=NULL){
			printf("%.1fX^%d+",temp->coeff,temp->exp);
			temp=temp->next;
		}
		printf("%.1fX^%d",temp->coeff,temp->exp);
	}
}
POLY *add(POLY *head1,POLY *head2){
	POLY *nw,*res,*p=head1,*q=head2,*head3=NULL;
	while(p&&q){
		nw=(POLY*)malloc(sizeof(POLY));
		nw->next=NULL;
		if(p->exp>q->exp){
			nw->coeff=p->coeff;
			nw->exp=p->exp;
			p=p->next;
		}
		else if(p->exp<q->exp){
			nw->coeff=q->coeff;
			nw->exp=q->exp;
			q=q->next;
		}
		else{
			nw->coeff=p->coeff+q->coeff;
			nw->exp=p->exp;
			p=p->next;
			q=q->next;
		}
		if(head3==NULL)
			head3=nw;
		else
			res->next=nw;
		res=nw;
	}
	if(p==NULL)
		res->next=q;
	else
		res->next=p;
	return head3;
}
int main(){
	POLY *head1=NULL,*head2=NULL,*head=NULL;
	head1=create_Polynomial(head1);
	head2=create_Polynomial(head2);
	head=add(head1,head2);
	fwd_Traverse(head1);
	printf("\n");
	fwd_Traverse(head2);
	printf("\n");
	fwd_Traverse(head);
	return 0;
}
