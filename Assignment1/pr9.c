//merge 2 arrays
#include <stdio.h>
void create_Array(int a[],int n,int b[],int m){
    int i;
    printf("Enter the elements of the array a:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the elements of the array b:\n");
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
}
void display_Array(int a[],int n,int b[],int m){
    int i;
    printf("The elements of array a:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\nThe elements of array b:\n");
    for(i=0;i<m;i++){
        printf("%d\t",b[i]);
    }
}
void merge_Arrays(int a[],int n,int b[],int m,int c[]){
    int i,j;
    for(i=0;i<n;i++){
        c[i]=a[i];
    }
    for(i=n,j=0;i<m+n,j<m;i++,j++){
        c[i]=b[j];
    }
}
void display_Mergedarray(int c[],int n){
    int i;
    printf("\nThe elements of merged array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",c[i]);
    }
}
int main(){
    int a[100],b[100],c[100],n,m;
    printf("Enter the number of elements of array a:");
    scanf("%d",&n);
    printf("Enter the number of elements of array b:");
    scanf("%d",&m);
    create_Array(a,n,b,m);
    display_Array(a,n,b,m);
    merge_Arrays(a,n,b,m,c);
    display_Mergedarray(c,n+m);
    return 0;
}
