//menu driven program
#include<stdio.h>
#include<stdlib.h>
int *create_Array(int *a,int n){
	int i;
	a=(int*)malloc(n*sizeof(int));
	printf("\nEnter the elements of the array:\n");
	for(i=0;i<n;i++){
		scanf("%d",(a+i));
	}
	return a;
}
void display_Array(int *b,int n){
	int i;
	printf("\nThe elements of the array:\n");
	for(i=0;i<n;i++){
		printf("%d\t",*(b+i));
	}
}
void sort_Array(int *a,int n){
	int i,j,c;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(*(a+i)<*(a+j)){
				c=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=c;
			}
		}
	}
	printf("\nThe sorted array:\n");
	for(i=0;i<n;i++){
		printf("%d\t",*(a+i));
	}
}
void linear_Search(int *a,int n){
	int i,k,flag=0;
	printf("\nEnter the element you want to search:");
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(*(a+i)==k){
			printf("\nThe element %d is found at %d index",k,i);
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("\nThe element not found");
	}
}
int main(){
	int *a,n,choice;
	do{	
		printf("\nMENU:");
		printf("\n1: create an array");
		printf("\n2: display the array");
		printf("\n3: sort the array");
		printf("\n4: Linear search");
		printf("\n5: Exit the program");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the length of the array:");
				scanf("%d",&n);
				a=create_Array(a,n);
				break;
			case 2:
				display_Array(a,n);
				break;
			case 3:
				sort_Array(a,n);
				break;
			case 4:
				linear_Search(a,n);
				break;
			case 5:
				printf("\nProgram terminated\n\n");
				break;
			default:
				printf("Invalid option\n");
		}
	}while(choice!=5);
	return 0;
}
