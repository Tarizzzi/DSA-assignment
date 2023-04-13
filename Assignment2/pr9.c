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
void display_Array(int *a,int n){
	int i;
	printf("\nThe elements of the array:\n");
	for(i=0;i<n;i++){
		printf("%d\t",*(a+i));
	}
}
int *sort_Array(int *a,int n){
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
	return a;
}
int linear_Search(int *a,int n,int k){
	int i,flag=0;
	for(i=0;i<n;i++){
		if(*(a+i)==k){
		    flag=1;
		    return i;
		}
	}
	if(flag==0){
	printf("\nThe element not found");   
	}
}
int main(){
	int *a,n,choice,i,k;
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
				a=sort_Array(a,n);
				printf("\nThe sorted array:\n");
	            for(i=0;i<n;i++){
		            printf("%d\t",*(a+i));
	            }
				break;
			case 4:
			    printf("\nEnter the element you want to search:");
	            scanf("%d",&k);
				i=linear_Search(a,n,k);
			    printf("\nThe element %d is found at %d index",k,i);
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
