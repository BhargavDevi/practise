#include<stdio.h>
struct  student{
    char name[30];
    int id;
    char usn[10];
};
typedef struct  student stu;



void read(char filename[]){
    FILE *fp;
    stu s;
    
      printf("Enter the name: ");
    scanf("%s", s.name);  // Input name (note: no '&' for strings)
    
    printf("Enter the ID: ");
    scanf("%d", &s.id);  // Input ID
    
    printf("Enter the USN: ");
    scanf("%s", s.usn); 
    fp=fopen(filename,"a+");
    if(fp==NULL){
        printf("File not found");
       return ;
    }
if(fwrite(&s,sizeof(s),1,fp)){
    printf("written in the file");
}
else{
    printf("not written");
}
 fclose(fp);
}
void read_students(char filename[]) {
    FILE *fp;
    stu s;
    fp = fopen(filename, "r");  // Open file in read mode

    if (fp == NULL) {
        printf("File not found\n");
        return;
    }

    // Read and display all student records from the binary file
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Name: %s, ID: %d, USN: %s\n", s.name, s.id, s.usn);
    }

    fclose(fp);  // Close the file
}


void search(char filename[],int sid){
    int count=0;
    FILE *fp;
    fp=fopen(filename,"r");
    stu s;
    if(fp==NULL){
        printf("File not found");
        return ;
    }
    while (fread(&s,sizeof(s),1,fp))
    {
    if(s.id==sid){
        printf("\n Name : %s \t\t id: %d \t USN: %s",s.name,s.id,s.usn);
        count=1;
    }
    if(count==0){
        printf("ID not found");
    }
    }

}

int main(){
    char f[20];
     int sid;
     int choise;
     printf("Give the student details");
     scanf("%s",f);
     printf("Enter the choise");
     while (1)
     {
       
     
     printf("\n1.Give input \n 2.Search \n 3.display \n 4.Exit");
     scanf("%d",&choise);
     switch (choise)
     {
     case 1:
         read(f);
        break;
     case 2:
         printf("Enter the id u have to search");
     scanf("%d",&sid);
     search(f,sid);
        break;
    case 3:
         read_students(f);
         break;
     case 4:
        break;
     default:
     printf("invalid input");
        break;
     }
     }
    return 0;


}