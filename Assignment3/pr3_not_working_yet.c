//transpose of a matrix
#include<stdio.h>
#define max 10
void read_Sparse(int t[][3]){
    int i,j;
    printf("Enter the elements of the triplet:\n");
    for(i=0;i<t[0][2]+1;i++){
        for(j=0;j<3;j++){
            scanf("%d",&t[i][j]);
        }
    }
}
void transpose_Sparse(int t[][3],int tt[][3]){
    int i,j,k=1;
    tt[0][0]=t[0][1];
    tt[0][1]=t[0][0];
    tt[0][2]=t[0][2];
    for(i=0;i<t[0][1];i++){
        for(j=1;j<=t[0][2];j++){
            if(t[j][1]==i){
                tt[k][0]=t[i][1];
                tt[k][1]=t[i][0];
                tt[k][2]=t[i][2];
                k++;
            }
        }
    }
}
void display_Sparse(int tt[][3]){
    int i,j;
    printf("Tranpose of the triplet:\n");
    for(i=0;i<tt[0][2]+1;i++){
        for(j=0;j<3;j++){
            printf("%d\t",tt[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int t[max][3],tt[max][3];
    read_Sparse(t);
    transpose_Sparse(t,tt);
    display_Sparse(tt);
    return 0;
}
