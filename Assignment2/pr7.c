//array input and display using pointers
#include<stdlib.h>
#include<stdio.h>
int* create_Array(int *a,int n){
    int i;
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",(a+i));
    }
    return a;
}
void display_Array(int *a,int n){
    int i;
    printf("The array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",*(a+i));
    }
}
int sum(int *p,int n){
    int i,sum=0;
    for(i=0;i<n;i++){
        sum+=*(p+i);
    }
    return sum;
}
int main(){
    int *a,n,s;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    a=create_Array(a,n);
    display_Array(a,n);
    s=sum(a,n);
    printf("\nThe sum of the elements of the array:%d",s);
    return 0;
}
