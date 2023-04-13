//sparse matrix
#include<stdio.h>
void create_display_Matrix(int sm[100][100],int r,int c){
    int i,j;
    printf("Enter the elements of the matrix:");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&sm[i][j]);
        }
    }
    printf("The input matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",sm[i][j]);
        }
        printf("\n");
    }
}
void sm_triplet(int sm[100][100],int r,int c){
    int triplet[100][3],i,j,k=1;
    for(i=0;i<r;i++){
        for(i=0;i<c;i++){
            if(sm[i][j]!=0){
                triplet[k][0]=i;
                triplet[k][1]=j;
                triplet[k][2]=sm[i][j];
            }k++;
        }
        triplet[0][0]=r;
        triplet[0][1]=c;
        triplet[0][2]=k-1;
        printf("The triplet matrix:\n");
        for(i=0;i<=triplet[0][2];i++){
            for(j=0;j<3;j++){
                printf("%d\t",triplet[i][j]);
            }
            printf("\n");
        }
    }
}
int main(){
    int sm[100][100],r,c;
    printf("Enter rows and columns:");
    scanf("%d%d",&r,&c);
    create_display_Matrix(sm,r,c);
    sm_triplet(sm,r,c);
    return 0;
}
