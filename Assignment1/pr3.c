//copy and display from another array
#include <stdio.h>
void create_Array(int a[],int n){
    int i;
    printf("Enter the elements of the array a:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void copy_Array(int a[],int b[],int n){
    int i;
    for(i=0;i<n;i++){
        b[i]=a[i];
    }
}
void display_Array(int b[],int n){
    int i;
    printf("The elements of array b:\n");
    for(i=0;i<n;i++){
        printf("%d\t",b[i]);
    }
}
int main(){
    int a[100],b[100],n;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    create_Array(a,n);
    copy_Array(a,b,n);
    display_Array(b,n);
    return 0;
}
