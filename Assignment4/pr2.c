//sum of digits of a number
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 20
int stack[max],top=-1;
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
int push(int ele){
    if(is_Full()){
        printf("\nstack overflow");
        exit(0);
    }
    else{
        stack[++top]=ele;
    }
}
int pop(){
    int ele;
    if(is_Empty()){
        printf("\nstack underflow");
        exit(0);
    }
    else{
        ele=stack[top--];
    }
    return ele;
}
int sum(int n){
    int s;
    while(n!=0){
        push(n%10);
        n=n/10;
    }
    while(top!=-1)
    s+=pop();
    return s;
}
int main(){
    int n,s;
    printf("Enter the number:");
    scanf("%d",&n);
    s=sum(n);
    printf("The sum of the digits of the number:%d",s);
    return 0;
}
