#include<stdio.h>
#include<string.h>
struct ad
{
    char na[30];
    char d[30];
    int cab,age;
    long long int numb;
} s[100];
int n,i,j=0,a=0,sum=0,g,flag,num;

FILE *fp;
void add();
void view();
void search();
void edit();
int main()
{
    int c,i,q;
    printf("Simple Hospital Management System\n");
    int m,n;
//making out the pattern
    abc:
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
        switch(c){
		
        case 1:
            system("cls");
            add();
        break;
		case 2:
			system("cls");
			view();
		break;
		case 3:
			system("cls");
			search();
			break;
		case 4:
			system("cls");
			edit();
			break;
		
		}
        goto abc;
		return 0;
}
}
void add()
{
    printf("\n\n");
    
    printf("Enter a number of records");
    scanf("%d",&num);
    FILE *p;
    p=fopen("num.txt","w");
    fprintf(p,"%d",num);
    fclose(p);
	fp=fopen("patient.txt","w");
	struct ad s[num]; 
	
	for(i=0;i<num;i++){
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
		scanf("%lld",&s[i].numb);
			fflush(stdin);
			
		fprintf(fp,"%s\n%s\n%d\n%d\n%lld\n",s[i].na,s[i].d,s[i].cab,s[i].age,s[i].numb);
	}
		fclose(fp);
	}
    void view(){
    int l;
	FILE *p;
	p=fopen("num.txt","r");
	fscanf(p,"%d",&l);
fclose(p);
fp=fopen("patient.txt","r");
for(i=0;i<l;i++){
fscanf(fp,"%s%s%d%d%lld",s[i].na,s[i].d,&s[i].cab,&s[i].age,&s[i].numb);
	    printf("Serial Number=%d\n",i);
        printf("Name = ");
       printf("%s",s[i].na);
        printf("Disease = ");
        printf("%s",s[i].d);
        printf("Cabin no = %d\n Phone number = %lld\n Age=%d",s[i].cab,s[i].numb,s[i].age);
        printf("\n\n");

	fclose(fp);
	}
}


void edit()
{
    int q,p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Cabin\n5.Phone no.\n");
    printf("Option=");
    scanf("%d",&q);//option
    if(q<=5)
    {
        printf("Enter the serial no of that patient= (0 - %d)=",num-1);
        scanf("%d",&p);//serial number
        if(p<num)
        {
            if(q==1)
            {
                fflush(stdin);
                printf("Enter the new name=");
                gets(s[p].na);

            }
            else if(q==2)
            {
                fflush(stdin);
                printf("Enter the new Disease=");
                gets(s[p].d);
            }
            else if(q==3)
            {
                fflush(stdin);
                printf("Enter the new Age=");
                scanf("%d",&s[p].age);
            }

            else if(q==4)
            {
                fflush(stdin);
                printf("Enter the new Cabin no=");
                scanf("%d",&s[p].cab);
            }

            else if(q==5)
            {
                fflush(stdin);
                printf("Enter the new Phone no =");
                scanf("%lld",&s[p].numb);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
	void search()
{
    int sn,h,f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Cabin no.\n5.Phone no.\n6.Age\n\nOption = ");
    scanf("%d",&h);
    if(h==1)
    {
        printf("Enter Serial number of the patient=");
        scanf("%d",&sn);
        if(sn<num)
        {
          
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[sn].na);
                printf("Disease = ");
                puts(s[sn].d);
                printf("Cabin no = %d\nPhone number = 0%lldd\nAge = %d",s[g].cab,s[g].numb,s[g].age);
                printf("\n\n");
                
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if(h==2)//problem is here.........
    {
        int f=1;
        fflush(stdin);
        printf("Enter your name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,s[g].na)==0)
            {
                
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = 0%lldd\nAge = %d",s[g].cab,s[g].numb,s[g].age);
                printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("\nNot Found\n");



    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("Enter Disease = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,s[g].d)==0)
            {
                
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = 0%lldd\nAge = %d",s[g].cab,s[g].numb,s[g].age);
                printf("\n\n");
                f=0;


        }
        if(f==1){
		
            printf("\nNot Found\n");


    }
}
}

	else if(h==4)
    {
        int f=1;
        printf("Enter Cabin number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==s[g].cab)
            {
                
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = 0%lld\nAge = %d",s[g].cab,s[g].numb,s[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else if(h==5)
    {
        int f=1;
        printf("Enter Phone number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==s[g].numb)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",s[g].cab,s[g].numb,s[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found");
    }
    else if(h==6)
    {
        int f=1;
        printf("Enter Age = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==s[g].age)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = 0%lldd\nAge = %d",s[g].cab,s[g].numb,s[g].age);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("Not Found\n\n");

    }
    else
        printf("\n\nInvalid input\n\n");

}


