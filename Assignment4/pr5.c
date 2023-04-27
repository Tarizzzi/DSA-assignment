#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10
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
    }
    else{
        stack[++top]=ele;
    }
}
char pop(){
    char ele;
    if(is_Empty()){
        printf("\nstack underflow");
    }
    else{
        ele=stack[top--];
    }
    return ele;
}
void check_Balanced(char s[]){
    int i;
    char r;
    for(i=0;s[i]!='\0';i++){
        r=s[i];
        if(r=='(')
        push(r);
        else if(r==')'){
            if(top==-1){
                printf("unbalanced");
                exit(0);
            }
            else
            r=pop();
        }
    }
    if(top==-1)
        printf("matched");
    else
        printf("unmatched");
}
int main(){
    char s[max];
    printf("Enter the equation:");
    scanf("%s",s);
    check_Balanced(s);
    return 0;
}
