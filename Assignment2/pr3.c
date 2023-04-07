//value and address of variable with pointer
#include <stdio.h>
int area(int *p,int*q){
    int a=(*p)*(*q);
    return a;
}
int perimeter(int *p,int*q){
    int r=2*((*p)+(*q));
    return r;
}
int main(){
    int l,b,*p=&l,*q=&b,a,r;
    printf("Enter the length and breadth:");
    scanf("%d%d",&l,&b);
    a=area(p,q);
    r=perimeter(p,q);
    printf("area=%d,perimeter=%d",a,r);
    return 0;
}
