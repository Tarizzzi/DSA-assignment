//attempt#2
#include<stdio.h>
#define MAX 20
create_display_matrix(int sm[MAX][MAX],int r,int c){
    int i,j;
    printf("Enter the elements of the array:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&sm[i][j]);
        }
    }
    printf("The input array:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",sm[i][j]);
        }
        printf("\n");
    }
}
void triplet_matrix(int sm[MAX][MAX],int r,int c){
    int triplet[MAX+1][3],i,j,k=1;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(sm[i][j]!=0){
                triplet[k][0]=i;
                triplet[k][1]=j;
                triplet[k][2]=sm[i][j];
                k++;
            }
        }
    }
    triplet[0][0]=r;
    triplet[0][1]=c;
    triplet[0][2]=k-1;
    printf("The triplet matrix:\n");
    for(i=0;i<=sm[0][2];i++){
        for(j=0;j<3;j++){
            printf("%d\t",triplet[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int sm,r,c;
    printf("Enter the rows and columns:");
    scanf("%d%d",&r,&c);
    create_display_matrix(sm,r,c);
    triplet_matrix(sm,r,c);
    return 0;
}
