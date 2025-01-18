#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// struct name
// {
// char name[3]};

int main(){
    char  *p;
    p=(char*)malloc(sizeof(char));
    strcpy(p,"SIT");
    printf("%s\n",p);
    p=(char*)realloc(p,40);
    strcpy(p,"Siddaganga institue of tecknology");
    printf("%s\n",p);
    free(p);
    printf("%s:\n",p);

}