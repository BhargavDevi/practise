
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
char stack[100], prefix[50];
int sp;

void push(char sym) {
stack[++sp] = sym;
}

char pop() {
if (sp == -1) {
printf("Error: Stack underflow\n");
exit(1);
}
return stack[sp--];
}

char stackTop() {
if (sp == -1) return '#';
return stack[sp];
}

int precOperator(char sym) {
switch (sym) {
case '#':
case ')': return 1;
case '+':
case '-': return 2;
case '*':
case '%':
case '/': return 3;
case '^': return 4;
default: return 0;
}
}

void strrev(char *str) {
int len = strlen(str);
for (int i = 0; i < len / 2; i++) {
char temp = str[i];
str[i] = str[len - i - 1];
str[len - i - 1] = temp;
}
}
void infixToPrefix(char infix[])
{
int i = 0, j = 0;
char sym, x;
strrev(infix);
while ((sym = infix[i++]) != '\0')
{
if (isalnum(sym))
{
prefix[j++] = sym;
}
else if (sym == ')')
{
push(sym);
}
else if (sym == '(')
{
while ((x = pop()) != ')')
{
prefix[j++] = x;
}
}
else
{
while (precOperator(sym) <= precOperator(stackTop()))
{
prefix[j++] = pop();
}
push(sym);
}
}
while ((x = pop()) != '#')
{
prefix[j++] = x;
}
prefix[j] = '\0';
strrev(prefix);
}

int main() {
char infix[50];
printf("Enter the infix expression to convert into prefix: ");
scanf("%s", infix);
sp = -1;
push('#');
infixToPrefix(infix);
printf("Prefix expression is: %s\n", prefix);
return 0;
}
