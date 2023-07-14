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
int *bubble_Sort(int *a,int n){
	int i,j,c;
	printf("BUBBLE SORTED ARRAY:\n");
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
	}
	return a;
}
void display(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
int main(){
	int *a,n;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	a=create_Array(a,n);
	a=bubble_Sort(a,n);
	display(a,n);
	return 0;
}
