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


int main(){
     char f[10];
     scanf("%s",f);
     read(f);

     read_students(f);

     return 0;


}