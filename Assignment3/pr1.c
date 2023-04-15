//sparse to triplet
#include<stdio.h>
#define max 20
void read_Sparse(int a[][max],int m,int n){
    int i,j;
    printf("Enter the elements of the sparse matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void display_Sparse(int a[][max],int m,int n){
    int i,j;
    printf("The input sparse matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void convert_Triplet(int a[][max],int m,int n,int b[][3]){
    int i,j,k=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=0){
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    b[0][0]=m;
    b[0][1]=n;
    b[0][2]=k-1;
}
void display_Triplet(int b[][3]){
    int i,j;
    printf("The triplet matrix:\n");
    for(i=0;i<b[0][2]+1;i++){
        for(j=0;j<3;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int a[max][max],b[max][3],m,n;
    printf("Enter the rows and columns of the sparse matrix:");
    scanf("%d%d",&m,&n);
    read_Sparse(a,m,n);
    display_Sparse(a,m,n);
    convert_Triplet(a,m,n,b);
    display_Triplet(b);
    return 0;
}
