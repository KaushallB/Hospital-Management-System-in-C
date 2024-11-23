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
void list();
void dis();
int main(){

    int ch;
start:
    
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
            list();
            break;

        case 3:
            patient();
            break;

       
        default:
            printf("Invalid Choice...\n\n");

        }
        printf("\n\nPress Any Key To Continue...");
    goto start;
    return 0;
	}

    


void patient(){
    fp = fopen("patients.txt", "a");

    printf("Enter Patient id: ");
    scanf("%d", &p.id);
    fflush(stdin);
    
	printf("Enter Patient name: ");
    scanf("%[^\n]",p.na);
    fflush(stdin);
	
	printf("Enter Patient Address: ");
    scanf("%[^\n]",p.ad);
    fflush(stdin);
    
	printf("Enter Patient Disease: ");
    scanf("%[^\n]",p.d);
    fflush(stdin);
    
   	printf("Enter cabin no : ");
		scanf("%d",&p.cab);
			fflush(stdin);
			printf("Enter Age : ");
		scanf("%d",&p.age);
			fflush(stdin);
			printf("Enter Contact number : ");
		scanf("%lld",&p.numb);
    
	printf("\nPatient Added Successfully");

    fprintf(fp,"%d\n%s\n%s\n%s\n%d\n%d\n%lld\n", p.id,p.na,p.ad,p.d,p.cab,p.age,p.numb);
}

void list(){

    
    printf("<== Patient List ==>\n\n");
    printf("%-10s %-30s %-30s %-20s  %-20s\n %-30s\n %-20s\n", "Id", "Patient Name", "Address", "Disease", "Cabin no:", "Age", "Contact No:");
    printf("----------------------------------------------------------------------------------------------------------\n");

    fp = fopen("patients.txt", "r");
    while( fscanf(fp,"%d\n%s\n%s\n%s\n%d\n%d\n%lld\n",&p.id,p.na,p.ad,p.d,&p.cab,&p.age,&p.numb) == 1){
        printf("%-10d %-30s %-30s %-20s %d\n %d\n %lld\n", p.id, p.na, p.ad, p.d,p.cab,p.age,p.numb);
    }

    fclose(fp);
}


void discharge(){
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


