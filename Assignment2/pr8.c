//reversing array using pointer
#include<stdio.h>
#include<stdlib.h>
int *create_Array(int *a,int n){
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
int *reverse(int *a,int n){
    int i,j,c;
    for(i=0,j=n-1;i<n/2;i++,j--){
        c=*(a+i);
        *(a+i)=*(a+j);
        *(a+j)=c;
    }
    return a;
}
void display_Reversed_Array(int *a,int n){
    int i;
    printf("\nThe reversed array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",*(a+i));
    }
}
int main(){
    int *a,n;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    a=create_Array(a,n);
    display_Array(a,n);
    a=reverse(a,n);
    display_Reversed_Array(a,n);
    return 0;
}
