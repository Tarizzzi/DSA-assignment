//copy and display from another array
#include <stdio.h>
void create_Array(int a[],int n){
    int i;
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void reverse_Array(int a[],int n){
    int i,j,c;
    for(i=0,j=n-1;i<=(n-1)/2;i++,j--){
        c=a[i];
        a[i]=a[j];
        a[j]=c;
    }
}
void display_Array(int a[],int n){
    int i;
    printf("The elements of array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
    int a[100],n;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    create_Array(a,n);
    reverse_Array(a,n);
    display_Array(a,n);
    return 0;
}
