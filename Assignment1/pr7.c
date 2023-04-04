//element insertion
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
void insert_Element(int a[],int n){
    int i,m,p;
    printf("\nEnter the element to be inserted:");
    scanf("%d",&m);
    printf("Enter the position in which it needs to be inserted:");
    scanf("%d",&p);
    for(i=n-1;i>p-2;i--){
        a[i+1]=a[i];
    }
    a[p-1]=m;
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
    insert_Element(a,n);
    display_Modifiedarray(a,n+1);
    return 0;
}
