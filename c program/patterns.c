#include<stdio.h>
void pattern1(int n) {
    int i, j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < i+1; j++)
        {
           printf("*");
        }

        printf("\n");
    }        /* code */

    

}

void pattern2(int n) {
    int i, j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
           printf("*");
        }

        printf("\n");
    }        /* code */

}
void pattern3(int n) {
    int i, j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 1; j <= i; j++)
        {
           printf("%d",j);
        }

     printf("\n");
    }        /* code */
}

void pattern4(int n) {

    int i, j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j <= i; j++)
        {
           printf("%d",i+1);
        }

     printf("\n");
    }        /* code */

}
void pattern5(int n) {
    
    int i, j;
    for ( i =0; i <n; i++)
    {
        n=j-i;
        for ( j = n; j >= 0; j--)
        {
           printf("*");
        }

     printf("\n");
    }        /* code */

}
int main(){
    int n ;
    // printf("Enetr the number of rows and colloms ");
    // scanf("%d",&n);
    n=5;
    pattern1(n);
    printf("\n\n\n");
        pattern2(n);
        printf("\n\n\n");
        pattern3(n);
         printf("\n\n\n");
        pattern4(n);
         printf("\n\n\n");
        pattern5(n);
}