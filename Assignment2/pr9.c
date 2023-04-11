//menu driven program
#include<stdio.h>
#include<stdlib.h>
int *create_Array(int *a,int n){
    int i;
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",(a+i));
    }
}
void display_Array(int *a,int n){
    int i;
    printf("The array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",*(a+i));
    }
}
int *sort_Array(int *a,int n){
    int i,j,c;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(*(a+i)>*(a+j)){
                c=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=c;
            }
        }
    }
    printf("The sorted array:\n");
        for(i=0;i<n;i++){
            printf("%d\t",*(a+i));
        }
}
void linear_Search(int *a,int n){
    int i,key,flag=0;
    printf("Enter the element to be searched:");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(*(a+i)==key){
            printf("The element %d is found at %d index",key,i);
            break;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("The element %d is not found",key);
    }
}
int main(){
    int *a,n,c,i;
    printf("Enter the lenght of the array:");
    scanf("%d",&n);
    printf("Enter your choice:");
    scanf("%d",&c);
    switch(c){
        case 1:
        a=create_Array(a,n);
        break;
        case 2:
        a=create_Array(a,n);
        display_Array(a,n);
        break;
        case 3:
        a=create_Array(a,n);
        display_Array(a,n);
        a=sort_Array(a,n);
        break;
        case 4:
        a=create_Array(a,n);
        display_Array(a,n);
        a=sort_Array(a,n);
        linear_Search(a,n);
    }
    return 0;
}
