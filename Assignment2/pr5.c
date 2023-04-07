//factorial using pointer and function
#include<stdio.h>
int fact(int *p){
    int i,f=1;
    for(i=*p;i>0;i--){
        f*=i;
    }
    return f;
}
int main(){
    int x,*p=&x,f;
    printf("Enter value of x:");
    scanf("%d",&x);
    f=fact(p);
    printf("The factorial of %d is %u",x,f);
    return 0;
}
