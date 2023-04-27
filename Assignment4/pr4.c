//decimal to (binary),(octal),(hexadecimal)
#include<stdio.h>
#include<stdbool.h>
#define max 20
char stack[max];
int top=-1;
bool is_Full(){
    if(top==max-1)
    return 1;
    else
    return 0;
}
bool is_Empty(){
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(char ele){
    if(is_Full())
    printf("stack overflow");
    else
    stack[++top]=ele;
}
char pop(){
    char ele;
    if(is_Empty())
    printf("stack undeflow");
    else
    ele=stack[top--];
    return ele;
}
void convert_Decimal(int n,int base){
    char r;
    while(n!=0){
        r=n%base;
        switch(r){
            case 10:
            push('A');
            break;
            case 11:
            push('B');
            break;
            case 12:
            push('C');
            break;
            case 13:
            push('D');
            break;
            case 14:
            push('E');
            break;
            case 15:
            push('F');
            break;
            default:
            push(r+48);
        }
        n=n/base;
    }
    while(top!=-1){
        printf("%s",pop());
    }
}
int main(){
    int n,base;
    printf("Enter the number and its base:");
    scanf("%d",&n,&base);
    convert_Decimal(n,base);
    return 0;
}
