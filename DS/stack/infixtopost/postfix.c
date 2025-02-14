#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[30], postfix[30];
int sp;
void push(char sym)
{
    stack[++sp] = sym;
}
char pop()
{
    return stack[sp--];
}
char stacktop()
{
    return stack[sp];
}
int presidence(char sym)
{
    switch(sym)
    {
    case '#':
        return 1;
        break;
    case '(':
        return 2;
        break;
    case '+':
    case '-':
        return 3;
        break;
    case '*':
    case '/':
    case '%':
        return 4;
        break;
    case '^':
        return 5;
        break;

    default:
    printf("invalid operend ");
    exit (0);
    }
}

 void infixtopost(char infix[]){
    int i=0,j=0;
    char sym,x;
    while ((sym=infix[i++])!='\0')
    {
        if(isalnum(sym)){
            postfix[j++]=sym;
        }
        else if (sym=='(')      
        {
            push(sym);
        }
        else if(sym==')'){
            while ((x=pop())!='(')
            {
                postfix[j++]=x;
            }
            
        }
        else{
            while (presidence(sym)<presidence(stacktop()))
            {
                x=pop();
                postfix[j++]=x;
            }
            push(sym);
        }
        
    }while ((x=pop())!='#')
    {
        postfix[j++]=x;
    }
    postfix[i]='\0';
 }
 int main(){
    char infix[30];
    printf("Ehter the infix expression");
    scanf("%s",infix);
    sp=-1;
    push('#');
    infixtopost(infix);
    printf("%s is an infix expression\n",postfix);
    return 0;
 }