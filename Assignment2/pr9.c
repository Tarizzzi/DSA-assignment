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
void sort_Array(int *a,int n){
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
    int *a,n,choice;
    do{
        printf("create an array: 1\n");
        printf("display the array: 2\n");
        printf("sort the array(in ascending order): 3\n");
        printf("search an element in the array: 4\n");
        printf("Exit: 5\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the lenght of the array:");
            scanf("%d",&n);
            a=create_Array(a,n);
            break;
            case 2:
            display_Array(a,n);
            break;
            case 3:
            sort_Array(a,n);
            break;
            case 4:
            linear_Search(a,n);
            break;
            case 5:
            printf("program exited");
            break;
            defalut:
            printf("Invalid choice");
        }
    }
    while(choice!=5);
    return 0;
}
