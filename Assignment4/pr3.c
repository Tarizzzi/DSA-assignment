#include<stdio.h>
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
void push(int ele){
    if(is_Full())
    printf("stack overflow");
    else
    stack[++top]=ele;
}
int pop(){
    int ele;
    if(is_Empty())
    printf("stack undeflow");
    else
    ele=stack[top--];
    return ele;
}
void convert_Binary(int ele){
  int a[max],i,c=0;
    while(ele!=0){
        push(ele%2);
        ele=ele/2;
        c++;
    }
    printf("\nThe number in binary form:");
    for(i=0;i<c;i++){
        a[i]=pop();
        printf("%d",a[i]);
    }
}
void convert_Octal(int ele){
    int a[max],i,c=0;
    while(ele!=0){
        push(ele%8);
        ele=ele/8;
        c++;
    }
    printf("\nThe number in octal form:");
    for(i=0;i<c;i++){
        a[i]=pop();
        printf("%d",a[i]);
    }
}
void convert_Hexadecimal(int ele){
    int a[max],i,c=0;
    while(ele!=0){
        push(ele%16);
        ele=ele/16;
        c++;
    }
    printf("\nThe number in hexadecimal form:");
    for(i=0;i<c;i++){
        a[i]=pop();
        printf("%d",a[i]);
    }
}
int main(){
    int ele;
    printf("Enter the number:");
    scanf("%d",&ele);
    convert_Binary(ele);
    convert_Octal(ele);
    convert_Hexadecimal(ele);
    return 0;
}
