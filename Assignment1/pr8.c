//element deletion
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
    printf("The elements of array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void delete_Element(int a[],int n){
    int i,m;
    printf("\nEnter the element to be deleted:");
    scanf("%d",&m);
    for(i=0;i<n;i++){
        if(a[i]==m){
            for(;i<n;i++){
                a[i]=a[i+1];
            }
        }
    }
}
void display_Modifiedarray(int a[],int n){
    int i;
    printf("The elements of array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
int main(){
    int a[100],n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    create_Array(a,n);
    display_Array(a,n);
    delete_Element(a,n);
    display_Modifiedarray(a,n-1);
    return 0;
}
