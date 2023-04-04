//enter and multiply 1o to each element
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
    printf("The array after multiplying 10 to each element:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]*10);
    }
}
int main(){
    int a[100],n;
    printf("Enter the length of the array:");
    scanf("%d",&n);
    create_Array(a,n);
    display_Array(a,n);
    return 0;
}
