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
int *selection_Sort(int *a,int n){
	int i,j,c;
	printf("SELECTION SORTED ARRAY:\n");
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
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
	a=selection_Sort(a,n);
	display(a,n);
	return 0;
}
