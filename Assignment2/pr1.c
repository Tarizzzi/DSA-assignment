//value and address of variable without pointer
#include <stdio.h>
int main(){
    int x;
    printf("Enter a number:");
    scanf("%d",&x);
    printf("value=%d,address=%u",x,&x);
    return 0;
}
