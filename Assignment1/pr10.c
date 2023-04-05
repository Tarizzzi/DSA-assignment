//bubble sort
#include <stdio.h>
void create_Array(int a[],int n){
    int i;
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void display_Array(int a[],int n){
    int i;
    printf("The array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void sort_Array(int a[],int n){
    int i,j,c;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]>a[i]){
                c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
    }
}
void display_Sorted_array(int a[],int n){
    int i;
    printf("\nThe sorted array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
    int a[100],n;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    create_Array(a,n);
    display_Array(a,n);
    sort_Array(a,n);
    display_Sorted_array(a,n);
    return 0;
}
