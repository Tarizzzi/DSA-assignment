//transpose of a matrix
#include<stdio.h>
#define max 10
void read_Matrix(int a[][max],int m,int n){
    int i,j;
    printf("Enter the elements of the sparse matrix:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void display_Matrix(int a[][max],int m,int n){
	int i,j;
	printf("The input sparse matrix:\n");
	for(i=0;i<m;i++){
       		for(j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void create_Triplet(int a[][max],int m,int n,int b[][3]){
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
	for(i=0;i<=b[0][2];i++){
		for(j=0;j<3;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
}
void transpose_Sparse(int b[][3],int c[][3]){
	int i,j,k=1;
	c[0][0]=b[0][1];
	c[0][1]=b[0][0];
	c[0][2]=b[0][2];
	for(i=0;i<b[0][1];i++){
		for(j=1;j<=b[0][2];j++){
			if(b[j][1]==i){
				c[k][0]=b[j][1];
				c[k][1]=b[j][0];
				c[k][2]=b[j][2];
				k++;
			}
		}
	}
}
void display_Sparse(int c[][3]){
	int i,j;
	printf("The transposed triplet matrix:\n");
    	for(i=0;i<=c[0][2];i++){
        	for(j=0;j<3;j++){
            		printf("%d\t",c[i][j]);
        		}
        	printf("\n");
    	}
}
int main(){
    int a[max][max],b[max+1][3],c[max+1][3],m,n;
    printf("Enter the rows and columns:");
    scanf("%d%d",&m,&n);
    read_Matrix(a,m,n);
    display_Matrix(a,m,n);
    create_Triplet(a,m,n,b);
    display_Triplet(b);
    transpose_Sparse(b,c);
    display_Sparse(c);
    return 0;
}
