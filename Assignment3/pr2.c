//triplet to sparse
#include<stdio.h>
#define MAX 20
void read_Triplet(int a[][3],int m){
    int i,j;
    printf("Enter the elements of the triplet:\n");
    for(i=0;i<m;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
display_Triplet(int a[][3],int m){
    printf("The input triplet matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<3;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void convert_SM(int a[][3],int m,int b[][max){
    int i,j;
    for(i=0;i<a[0][0];i++){
        for(j=0;j<a[0][1];j++){
            b[i][j]=0;
        }
    }
    for(i=1;i<m;i++){
        b[a[i][0]][a[i][1]]=a[i][2];
        }
}
void display_SM(int a[][3],int b[max][max]){
    int i,j;
    printf("The sparse matrix:\n");
    for(i=0;i<a[0][0];i++){
        for(j=0;j<a[0][1];j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
}
int main(){
    int a[max][3],b[max][max],m;
    printf("Enter the rows of the triplet matrix:");
    scanf("%d",&m);
    read_Triplet(a,m);
    display_Triplet(a,m);
    convert_SM(a,m,b);
    display_SM(a,b);
    return 0;
}
