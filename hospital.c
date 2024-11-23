
#include<stdio.h>
#include<string.h>
struct ad
{
    char na[30];
    char d[30];
    int cab,age;
    long long int numb;
} x[100];
int n,i,j=0,a=0,sum=0,g,flag,num;
void read();
void add();
void view();
void search();
void edit();
void del();
void show();
int main()
{
    read();
    int c,i,q;
    printf("Simple Hospital Management System\n");
    int m,n;
//making out the pattern
    
    for(m=1; m<=4; m++)
    {
        for(n=1; n<=5; n++)
            printf(" ");
        for(n=1; n<=m-1; n++)
        {
            printf(" ");
        }
        for(n=1; n<=4-m+1; n++)
        {
            if(n==4-m+1 || m==1 || m==4)
                printf("*");
            else
                printf(" ");
        }
        for(n=1; n<=4-m+1; n++)
        {
            if(n==1 ||m==1 || m==4)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    while(c!=6)
    {

        printf("**Enter your choice**\n\n1. Add Information\n2. View Information\n3. Search\n4. Edit Information\n5. Delete Information\n6. Exit\n\nOption=");
        scanf("%d",&c);//choice for option
        fflush(stdin);//making it clear
        if(c==1)//add
        {
            system("cls");
            add();
        }
        else if(c==2)//view
        {
            system("cls");
            view();
        }
        else if(c==3)//search
        {
            system("cls");
            search();
        }
        else if(c==4)//edit
        {
            system("cls");
            edit();
        }
        else if(c==5)//delete
        {
            system("cls");
            del();
        }
        else if(c==6)
        {
            write();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}
void add()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n",num);//how many inputs
    printf("How many entry do you want to add=\n");
    scanf("%d",&n);
    sum=n+num;

   FILE *j;
	j=fopen("patient.txt","w");
	int n,i;
	printf("How many records?: ");
	scanf("%d",&n);
	struct ad s[n]; 
	
	for(i=0;i<n;i++){
		printf("\nEnter information for Patient no.%d :",i+1);
			fflush(stdin);
		printf("\nEnter name : ");
		scanf("%[^\n]",s[i].na);
			fflush(stdin);
		printf("\nEnter Disease : ");
		scanf("%[^\n]",s[i].d);
			fflush(stdin);
		printf("\nEnter cabin no : ");
		scanf("%d",&s[i].cab);
			fflush(stdin);
			printf("\nEnter Age : ");
		scanf("%d",&s[i].age);
			fflush(stdin);
			printf("\nEnter Contact number : ");
		scanf("%d",&s[i].numb);
			fflush(stdin);
			
		fprintf(j,"%s\n%s\n%d\n%d\n%lld\n",s[i].na,s[i].d,s[i].cab,s[i].age,s[i].numb);
	}
		fclose(j);
	}
    }
}


