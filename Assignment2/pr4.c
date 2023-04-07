//swapping using pointer
#include <stdio.h>
void swap(int *p,int*q){
    int c;
    printf("before swapping\nx=%d,y=%d",*p,*q);
    c=*p;
    *p=*q;
    *q=c;
    printf("\nafter swapping\nx=%d,y=%d",*p,*q);
}
int main(){
    int x,y,*p=&x,*q=&y;
    printf("Enter value of x and y:");
    scanf("%d%d",&x,&y);
    swap(p,q);
    return 0;
}
