#include<stdio.h>
#include<stdlib.h>
int main()
{
char s1[50],*s2;
int i,a;
printf("enter the first string ");
scanf("%s",s1);
for (i = 0; s1[i]!='\0'; i++)
{
    a=i;
    /* code */
}
s2=(char*)calloc(a,sizeof(char));
if(s2==NULL)
{
   printf("Error in the memory allocation");
   return 0;
}
for ( i = 0; s1[i]!='\0'; i++)
{
        s2[i]=s1[i];
}
printf("original string : %s\n",s1);
printf("Second :%s\n",s2);
free(s2);
return 0;
}