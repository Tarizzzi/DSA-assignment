//infix to postfix
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#define max 30
char stack[max];
int top=-1;
bool is_Empty(){
    if(stack[top]==-1)
    return 1;
    else return 0;
}
bool is_Full(){
    if(stack[top]==max-1)
    return 1;
    else
    return 0;
}
void push(char ele){
    if(is_Full())
    printf("Stack overflow");
    else
    stack[++top]=ele;
}
char pop(){
    char ele;
    if(is_Empty())
    printf("Stack underflow");
    else
    ele=stack[top--];
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
        case '/':
        case '%':
        return 2;
        break;
        case '+':
        case '-':
        return 1;
        default:
        return 0;
    }
}
void infix_Postfix(char infix[]){
    char postfix[max],ch;
    int i,j=0;
    for(i=0;infix[i]!='\0';i++){
        ch=infix[i];
        if(isalnum(ch))
        postfix[j++]=ch;
        else if(ch=='(')
        push(ch);
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
    }
    while(stack[top]!=-1)
    postfix[j++]=pop();
    postfix[j]='\0';
    printf("The postfix expression: %s ",postfix);
}
int main(){
    char infix[max];
    printf("Enter the infix expression:");
    scanf("%s",infix);
    infix_Postfix(infix);
    return 0;
}
