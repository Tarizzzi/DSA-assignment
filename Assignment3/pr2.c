//triplet to sparse
#include<stdio.h>
#define max 20
void read_Triplet(int a[][3]){
    int i,j;
    printf("Enter the elements of the triplet:\n");
    for(i=0;i<a[0][2]+1;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void display_Triplet(int a[][3]){
    int i,j;
    printf("The input triplet matrix:\n");
    for(i=0;i<a[0][2]+1;i++){
        for(j=0;j<3;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void convert_SM(int a[][3],int b[][max]){
    int i,j;
    for(i=0;i<a[0][0];i++){
        for(j=0;j<a[0][1];j++){
            b[i][j]=0;
        }
    }
    for(i=1;i<a[0][2]+1;i++){
        b[a[i][0]][a[i][1]]=a[i][2];
        }
}
void display_SM(int a[][3],int b[][max]){
    int i,j;
    printf("The sparse matrix:\n");
    for(i=0;i<a[0][0];i++){
        for(j=0;j<a[0][1];j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int a[max][3],b[max][max];
    read_Triplet(a);
    display_Triplet(a);
    convert_SM(a,b);
    display_SM(a,b);
    return 0;
}
