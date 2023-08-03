#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node *right,*left;
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
		nw->left=NULL;
		nw->right=NULL;
	}
	return nw;
}
NODE *create_BST(NODE *root){
	NODE *nw,*p;
	int n,i;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	if(n>0){
		for(i=0;i<n;i++){
			nw=create_Node();
			if(root==NULL)
				root=nw;
			else{
				p=root;
				while(p!=NULL){
					if((p->info<nw->info)&&(p->right!=NULL))
						p=p->right;
					else if((p->info>nw->info)&&(p->left!=NULL))
						p=p->left;
					else
						break;
				}
				if(nw->info>p->info)
					p->right=nw;
				else
					p->left=nw;
			}
		}
	}
	else
		printf("NO BINARY SEARCH TREE POSSIBLE");
	return root;
}
void inorder(NODE *root){
	NODE *p=root;
	if(p==NULL)
		return;
	else{
		inorder(p->left);
		printf("%d\t",p->info);
		inorder(p->right);
	}
}
void search_BST(NODE *root,int ele){
	NODE *p;
	if(root==NULL)
		printf("no element to search");
	else{
		p=root;
		while(p!=NULL){
			if(p->info==ele){
				printf("Element found");
				break;
			}
			else if(p->info>ele)
				p=p->left;
			else
				p=p->right;
		}
		if(p==NULL)
			printf("Element not found");
	}
}
NODE *insert_BST(NODE *root){
	NODE *nw,*p;
	nw=create_Node();
	if(root==NULL)
		root=nw;
	else{
		p=root;
		while(p!=NULL){
			if((p->info<nw->info)&&(p->right!=NULL))
				p=p->right;
			else if((p->info>nw->info)&&(p->left!=NULL))
				p=p->left;
			else
				break;
		}
		if(nw->info>p->info)
			p->right=nw;
		else
			p->left=nw;
	}
	printf("Node inserted");
	return root;
}
void preorder(NODE *root){
	NODE *p=root;
	if(p==NULL)
		return;
	else{
		printf("%d\t",p->info);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(NODE *root){
	NODE *p=root;
	if(p==NULL)
		return;
	else{
		postorder(p->left);
		postorder(p->right);
		printf("%d\t",p->info);
	}
}
void swap(NODE *p,NODE *temp){
	int i;
	i=p->info;
	p->info=temp->info;
	temp->info=i;
}
NODE *delete_BST(NODE *root,int ele){
	NODE *p,*q,*temp;
	p=root;
	q=NULL;
	while(p!=NULL){
		if(ele>p->info){
			q=p;
			p=p->right;
		}
		else if(ele<p->info){
			q=p;
			p=p->left;
		}
		else if(ele==p->info)
			break;
	}
	if(p==NULL)
		printf("No element found");
	else if(root==NULL)
		printf("no deletion possible");
	else
	{
	if((p->left==NULL)&&(p->right==NULL)){
		if(q->right==p){
			q->right=NULL;
			printf("The deleted element is %d",p->info);
			free(p);
		}
		else if(q->left==p){
			q->left=NULL;
			printf("The deleted element is %d",p->info);
			free(p);
		}
		else if(q==NULL){
			root=NULL;
			printf("The deleted element is %d",p->info);
			free(p);
		}
	}
	else if((p->left==NULL)&&(p->right!=NULL)){
		if(q==NULL){
			root=p->right;
			p->right=NULL;
			printf("The deleted element is %d",p->info);
			free(p);
		}
		else if(q->left==p){
			q->left=p->right;
			p->right=NULL;
			printf("The deleted element is %d",p->info);
			free(p);
		}
		else if(q->right==p){
			q->right=p->right;
			p->right=NULL;
			printf("The deleted element is %d",p->info);
			free(p);
		}
	}
	else if((p->right==NULL)&&(p->left!=NULL)){
		if(q==NULL){
			root=p->left;
			p->left=NULL;
			printf("The deleted element is %d",p->info);
			free(p);
		}
		else{
			if(q->left==p){
				q->left=p->left;
				p->left=NULL;
				printf("The deleted element is %d",p->info);
				free(p);
			}
			else if(q->right==p){
				q->right=p->left;
				p->left=NULL;
				printf("The deleted element is %d",p->info);
				free(p);
			}
		}
	}
	else if((p->right!=NULL)&&(p->left!=NULL)){
		q=p;
		temp=p->right;
		while(temp->left!=NULL){
			q=temp;
			temp=temp->left;
		}
	swap(p,temp);
	q->left=NULL;
	printf("The deleted element is %d",p->info);
	free(temp);
	}
	}
	return root;
}
int main(){
	NODE *root=NULL;
	int ch,ele;
	do{
		printf("\nTHE MENU:\n1:create BST\n2:inorder traversal\n3:search a node\n4:insert a node\n5:preorder traversal\n6:postorder traversal\n7:delete a node\n8:exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				root=create_BST(root);
				break;
			case 2:
				printf("The binary tree in inorder:\n");
				inorder(root);
				break;
			case 3:
				printf("Enter the element to be searched:");
				scanf("%d",&ele);
				search_BST(root,ele);
				break;
			case 4:
				root=insert_BST(root);
				break;
			case 5:
				printf("The binary tree in preorder:\n");
				preorder(root);
				break;
			case 6:
				printf("The binary tree in postorder:\n");
				postorder(root);
				break;
			case 7:
				printf("Enter the element of the node to be deleted:");
				scanf("%d",&ele);
				root=delete_BST(root,ele);
				break;
			case 8:
				printf("PROGRAM TERMINATED");
				exit(0);
			default:
				printf("Invalid choice");
		}
	}
	while(ch!=8);
	return 0;
}
