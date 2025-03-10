#include<stdio.h>
struct player{
    char name[30];
    char team[30];
    int avgscor;
};
typedef struct player play;
play p[30];

void dispavg(play p[], int n){
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Team: %s, Average Score: %d\n", p[i].name, p[i].team, p[i].avgscor);
    }

}
int main(){
    int n;
    printf("Enter the number of players");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s  %s  %d",p[i].name,p[i].team,&p[i].avgscor);
    }
    
    for (int i=0;i<n;i++){
        if((p[i].avgscor>p[i+1].avgscor)){
            int temp;
            temp=p[i].avgscor;
            p[i].avgscor=p[i+1].avgscor;
            p[i+1].avgscor=temp;
            // dispavg(p[i].avgscor);

        }
    }
        dispavg(p, n);
        return 0;    dispavg(p, n);


}
    