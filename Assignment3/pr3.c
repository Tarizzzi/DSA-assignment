//transpose of a matrix
#include<stdio.h>
#define max 10
void read_Sparse(int a[][3]){
    int i,j;
    printf("Enter the elements of the triplet:\n");
    for(i=0;i<a[0][2]+1;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void display_Sparse(int a[][3]){
    int i,j;
    printf("The input triplet:\n");
    for(i=0;i<a[0][2]+1;i++){
        for(j=0;j<3;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void transpose_Sparse(int a[][3],int b[][3]){
    int i,j,k=1;
    b[0][0]=a[0][1];
    b[0][1]=a[0][0];
    b[0][2]=a[0][2];
    for(i=0;i<a[0][1];i++){
        for(j=1;j<=a[0][2];j++){
            if(a[j][1]==i){
                b[k][0]=a[j][1];
                b[k][1]=a[j][0];
                b[k][2]=a[j][2];
                k++;
            }
        }
    }
}
void display_Transposed_Sparse(int b[][3]){
    int i,j;
    printf("Tranpose of the triplet:\n");
    for(i=0;i<b[0][2]+1;i++){
        for(j=0;j<3;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int a[max][3],b[max][3];
    read_Sparse(a);
    display_Sparse(a);
    transpose_Sparse(a,b);
    display_Transposed_Sparse(b);
    return 0;
}
