//Linear search
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
void search_Element(int a[],int n){
    int i,m,flag=0;
    printf("\nEnter the element to be searched:");
    scanf("%d",&m);
    for(i=0;i<n;i++){
        if(a[i]==m){
            printf("The element %d is found at %d index.",m,i);{
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    printf("Element not found.");
}
int main(){
    int a[100],n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    create_Array(a,n);
    display_Array(a,n);
    search_Element(a,n);
    return 0;
}
