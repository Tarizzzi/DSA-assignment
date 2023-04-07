//value and address of variable with pointer
#include <stdio.h>
int main(){
    int x,*p=&x;
    printf("Enter a number:");
    scanf("%d",&x);
    printf("value=%d,address=%u",*p,p);
    return 0;
}
