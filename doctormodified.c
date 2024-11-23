#include<stdio.h>
#include<stdlib.h>


struct patient{
    int id;
    char na[50];
    char ad[50];
    char d[50];
    int cab,age;
    long long int numb;
}p;

struct doctor{
    int id;
    char n[50];
    char ad[50];
    char sp[50];
    
}d;

FILE *fp;
void patient();
void lists();
void dis();
int main(){

    int ch;
abc:
    
        system("cls");
        printf("<== Hospital Management System ==>\n");
        printf("1.Admit Patient\n");
        printf("2.Patient List\n");
        printf("3.Discharge Patient\n");
        printf("4.Add Doctor\n");
        printf("5.Doctors List\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            patient();
            break;

        case 2:
            lists();
            break;

        case 3:
            dis();
            break;

       
        default:
            printf("Invalid Choice...\n\n");

        }
        printf("\n\nPress Any Key To Continue...");
goto abc;
    return 0;
	}

    


void patient(){
    fp = fopen("patients.txt", "a");

    printf("Enter Patient id: ");
    scanf("%d", &p.id);
    fflush(stdin);
    
	printf("Enter Patient name: ");
    gets(p.na);
    fflush(stdin);
	
	printf("Enter Patient Address: ");
    gets(p.ad);
    fflush(stdin);
    
	printf("Enter Patient Disease: ");
    gets(p.d);
    fflush(stdin);
    
   	printf("Enter cabin no : ");
		scanf("%d",&p.cab);
			fflush(stdin);
			printf("Enter Age : ");
		scanf("%d",&p.age);
			fflush(stdin);
			printf("Enter Contact number : ");
		scanf("%lld",&p.numb);
    fflush(stdin);
	printf("\nPatient Added Successfully");

    fwrite(&p, sizeof(p), 1, fp);
}

void lists(){
system("cls");
    
    printf("<== Patient List ==>\n");
    printf("%-10s %-10s %-10s %-10s  %-10s %-10s %-10s", "Id", "Patient Name", "Address", "Disease", "Cabin no:", "Age", "Contact No:");
    printf("-------------------------------------------------------------------------------------\n");

    fp = fopen("patients.txt", "r");
    while(fread(&p, sizeof(p), 1, fp)!=EOF){
        printf("%-10d %-10s %-10s %-10s %-10d %-10d %-10lld", p.id, p.na, p.ad, p.d, p.cab, p.age, p.numb);
    }

    fclose(fp);
}


void dis(){
    int id, f=0;
    system("cls");
    printf("<== Discharge Patient ==>\n\n");
    printf("Enter Patient id to discharge: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("patients.txt", "r");
    ft = fopen("temp.txt", "w");

    while(fscanf(fp,"%d\n%s\n%s\n%s\n%d\n%d\n%lld\n",&p.id,p.na,p.ad,p.d,&p.cab,&p.age,&p.numb) == 1){

        if(id == p.id){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nPatient Discharged Successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

}


