//array input and display using pointers
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
    printf("\nThe address of the elements of the array:\n");
    for(i=0;i<n;i++){
        printf("%u\t",(a+i));
    }
}
int main(){
    int *a,n;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    a=create_Array(a,n);
    display_Array(a,n);
    return 0;
}
