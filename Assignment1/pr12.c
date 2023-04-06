//sort 2 arrays,merge and sort
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
void sort_Array(int a[],int n,int b[],int m){
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
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(b[j]>b[i]){
                c=b[i];
                b[i]=b[j];
                b[j]=c;
            }
        }
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
void sort_Merged_Array(int c[],int n){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(c[j]>c[i]){
                k=c[i];
                c[i]=c[j];
                c[j]=k;
            }
        }
    }
}
void display_Sorted_Merged_Array(int c[],int n){
    int i;
    printf("\nThe sorted merged array:\n");
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
    sort_Array(a,n,b,m);
    merge_Arrays(a,n,b,m,c);
    sort_Merged_Array(c,m+n);
    display_Sorted_Merged_Array(c,n+m);
    return 0;
}
