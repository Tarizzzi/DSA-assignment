//infix to postfix
#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define max 50
char infix[max],stack[max];
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
    int ele;
    if(is_Empty()){
        printf("\nstack underflow");
    }
    else{
        ele=stack[top--];
    }
    return ele;
}
int operate(char op){
    switch(op){
        case '^':
        case '*':
        case '/':
        case '%':
        case '+':
        case '-':
        return 1;
        break;
        default:
        return 0;
    }
}
int op_Precedence(char op){
        switch(op){
        case '^':
        return 3;
        break;
        case '*':
        case '%':
        case '/':
        return 2;
        break;
        case '+':
        case '-':
        return 1;
        break;
        default:
        return 0;
    }
}
void infix_Postfix(char a[]){
    char postfix[50];
    int i,j=0;
    char ch;
    for(i=0;a[i]!='\0';i++){
        ch=a[i];
        if(ch=='(')
        push(ch);
        else if(isalnum(ch))
        postfix[j++]=ch;
        else if(ch==')'){
            while(stack[top]!='(')
            postfix[j++]=pop();
            ch=pop();
        }
        else if(operate(ch)){
            while(op_Precedence(ch)<=op_Precedence(stack[top]))
            postfix[j++]=pop();
            push(ch);
        }
        else 
        printf("Invalid");
    }
        while(top!=-1)
        postfix[j++]=pop();
        postfix[j]='\0';
        printf("The postfix expression is %s\n",postfix);
}
int main(){
    char a[max];
    printf("Enter an expression:");
    scanf("%s",a);
    infix_Postfix(a);
    return 0;
}
