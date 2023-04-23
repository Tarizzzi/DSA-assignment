//palindrome
#include<stdio.h>
#include<stdlib.h>
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
    if(is_Full()){
        printf("\nstack overflow");
        exit(0);
    }
    else{
        stack[++top]=ele;
    }
}
char pop(){
    char ele;
    if(is_Empty()){
        printf("\nstack underflow");
        exit(0);
    }
    else{
        ele=stack[top--];
    }
    return ele;
}
int main(){
    char a[max],b[max],flag=1;
    int i;
    printf("Enter the string:");
    scanf("%[^\n]",a);
    for(i=0;a[i]!='\0';i++){
        push(a[i]);
    }
    for(i=0;a[i]!='\0';i++){
        b[i]=pop();
    }
    for(i=0;a[i]!='\0';i++){
        if(a[i]!=b[i])
        flag=0;
    }
    if(flag==0)
    printf("The string is not a palindrome");
    else
    printf("The string is a palindrome");
    return 0;
}
