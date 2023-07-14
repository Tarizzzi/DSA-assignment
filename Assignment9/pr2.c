#include<stdio.h>
#include<stdlib.h>
int *create_Array(int *a,int n){
	int i;
	a=(int*)malloc(sizeof(int));
	printf("Enter the elements of the array:");
	for(i=0;i<n;i++){
		scanf("%d",(a+i));
	}
	return a;
}
void binary_Search(int *a,int n){
	int i,x,flag=0;
	printf("Enter the element to be searched:");
	scanf("%d",&x);
	if(*(a+n/2)==x){
		printf("Element found at %dth index",n/2);
		exit(0);
	}
	else if(*(a+n/2)<x){
		for(i=(n+2)/2;i<n;i++){
			if(*(a+i)==x){
				flag=1;
				break;
			}
		}
	}
	else if(*(a+n/2)>x){
		for(i=0;i<(n+2)/2;i++){
			if(*(a+i)==x){
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
		printf("Element not found");
	else
		printf("element found at %dth index",i);
}
int main(){
	int *a,n;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	a=create_Array(a,n);
	binary_Search(a,n);
	return 0;
}
