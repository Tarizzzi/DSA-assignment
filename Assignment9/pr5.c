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
int *insertion_Sort(int *a,int n){
	int i,j,c;
	printf("INSERTION SORTED ARRAY:\n");
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i]<a[j]){
				c=a[i];
				a[i]=a[j];
				a[j]=c;
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
	a=insertion_Sort(a,n);
	display(a,n);
	return 0;
}
