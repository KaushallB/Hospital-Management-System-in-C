#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct ad
{
    char na[30];
    char d[30];
    int cab,age;
    long long int numb;
    int id;
} s[100];
int n,i,g,num;

FILE *fp;
void add();
void view();
void edit();
void search();
void login();
void discharge();
int main()

{
    int c,i,q;
    char a[100];
    printf("Enter full name of the hospital:");
    scanf("%[^\n]",a);
	system("cls");
	printf("\t```````````Hospital Management System for %s`````````",strupr(a));
   
    int m,n;
//for pattern
    abc:
    
	login();//login screen display
	printf("\t```````````Hospital Management System for %s`````````",strupr(a));
	while(c!=6)
    {

        printf("\n\n\n\t\t\t**Enter your choice**\n\n1. Add Information\n2. View Information\n3. Edit Information\n4. Search\n5. Patient Discharge\n\nOption=");
        scanf("%d",&c);
        fflush(stdin);
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
			edit();
		break;
		case 4:
			system("cls");
			search();
		break;
        case 5:
        	system("cls");
			discharge();
        	break;
		goto abc;
		return 0;
		default:
	printf("Enter 1-5");
}
}
}
void login(){//`````````````````````````````````````````````````loginfunction
	int e=0;
	char username[20];
	char password[20];
char orginal_username[20]="anil";
char original_password[20]="5454";
do{
	printf("\n\t``````````````````````LOGIN SCREEN`````````````````````");
	printf("\n\tEnter Username and password:");
	printf("\n\tEnter Username:");
	scanf("%s",username);
	fflush(stdin);
	printf("\tEnter pasword:");
	scanf("%s",password);
	fflush(stdin);
	if(strcmp(username,orginal_username)==0 && strcmp(password,original_password)==0){
		printf("\n\t\t ``````Login successful`````\t");
		printf("\n\t\t```Press Enter to continue```");
		getch();
		break;
	}
	else{
		printf("\n Password is incorrect:(Try Again)");
		e++;
	}
	}while(e<=2);
	if(e>2){
	
	printf("You have crossed the limit.");
	
	exit(1);

}
system("cls");
	}

void add()//``````````````````````````````````````````````Add function
{
    printf("\n\n");
    
    printf("Enter a number of records:");
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
		printf("Enter Disease : ");
		scanf("%[^\n]",s[i].d);
			fflush(stdin);
		printf("Enter cabin no : ");
		scanf("%d",&s[i].cab);
			fflush(stdin);
			printf("Enter Age : ");
		scanf("%d",&s[i].age);
			fflush(stdin);
			printf("Enter Contact number : ");
		scanf("%lld",&s[i].numb);
			fflush(stdin);
				printf("Enter id:");
		scanf("%d",&s[i].id);
		fflush(stdin);
			
		fprintf(fp,"%s\n%s\n%d\n%d\n%lld\n%d\n",s[i].na,s[i].d,s[i].cab,s[i].age,s[i].numb,s[i].id);
		
	}
	printf("\t````````Record has been added successfully``````");
		fclose(fp);
	}
    void view(){//````````````````````````````````````````````````````view function
    int l;
	FILE *p;
	p=fopen("num.txt","r");
	fscanf(p,"%d",&l);
fclose(p);
fp=fopen("patient.txt","r");
for(i=0;i<l;i++){
fscanf(fp,"%s\n%s\n%d\n%d\n%lld\n%d\n",s[i].na,s[i].d,&s[i].cab,&s[i].age,&s[i].numb,&s[i].id);
	    printf("Serial Number=%d\n",i);
        printf("Name = ");
        printf("%s\n",s[i].na);
        printf("Disease = ");
        printf("%s\n",s[i].d);
        printf("Cabin no = %d\nPhone number = %lld\nAge=%d\nID = %d\n",s[i].cab,s[i].numb,s[i].age,s[i].id);
     
}
fclose(fp);
}

void search()//search function
{
    
	int sn,h,f,l,cd;
    char u[100];
    FILE *pq;
	pq=fopen("num.txt","r");
	fscanf(pq,"%d",&l);
	printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Cabin no.\n5.Phone no.\n6.Age\n7.Id\nOption = ");
    scanf("%d",&h);
    fp=fopen("patient.txt","r");
	for(i=0;i<l;i++){
while(fscanf(fp,"%s\n%s\n%d\n%d\n%lld\n%d\n",s[i].na,s[i].d,&s[i].cab,&s[i].age,&s[i].numb,&s[i].id)!=EOF){

	if(h==1)
    {
        printf("Enter Serial number of the patient=");
        scanf("%d",&sn);
        if(sn<l)
        {
          
                printf("\n");
                printf("Serial Number=%d\n",sn);
                printf("Name = ");
                puts(s[sn].na);
                printf("Disease = ");
                puts(s[sn].d);
                printf("\nCabin no = %d\nPhone number = %lld\nAge = %d\nID of patient = %d",s[g].cab,s[g].numb,s[g].age,s[g].id);
                printf("\n\n");
                break;
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if(h==2)
    {
        int f=1;
        fflush(stdin);
        printf("Enter your name=");
        gets(u);
        fflush(stdin);
        for(g=0; g<l; g++)
        {
            if(strcmpi(u,s[g].na)==0)
            {
                
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = %lld\nAge = %d\nID of patient = %d",s[g].cab,s[g].numb,s[g].age,s[g].id);
                printf("\n\n");
                f=0;
            break;
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
        for(g=0; g<l; g++)
        {
            if(strcmpi(u,s[g].d)==0)
            {
                
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = %lld\nAge = %d\nID of patient = %d",s[g].cab,s[g].numb,s[g].age,s[g].id);
                printf("\n\n");
                f=0;
break;

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
        for(g=0; g<l; g++)
        {
            if(f==s[g].cab)
            {
                
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = %lld\nAge = %d\nID of patient = %d",s[g].cab,s[g].numb,s[g].age,s[g].id);
                printf("\n\n");
                f=0;
      break;
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
        for(g=0; g<l; g++)
        {
            if(f==s[g].numb)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = %lld\nAge = %d\nID of patient = %d",s[g].cab,s[g].numb,s[g].age,s[g].id);
                printf("\n\n");
                f=0;
            break;
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
        for(g=0; g<l; g++)
        {
            if(f==s[g].age)
            {
                printf("\n");
                printf("Serial Number=%d\n",g);
                printf("Name = ");
                puts(s[g].na);
                printf("Disease = ");
                puts(s[g].d);
                printf("Cabin no = %d\nPhone number = %lld\nAge = %d\nID of patient = %d",s[g].cab,s[g].numb,s[g].age,s[g].id);
                printf("\n\n");
                f=0;
        break;
		    }

        }
        if(f==1)
            printf("Not Found\n\n");
}
   	else if(h==7)
    {
        printf("Enter Id of the patient=");
        scanf("%d",&cd);
        if(cd<l)
        {
          printf("\n");
                printf("Name = ");
                puts(s[cd].na);
                printf("Disease = ");
                puts(s[cd].d);
                printf("Cabin no = %d\nPhone number = %lld\nAge = %d\nID of patient = %d",s[cd].cab,s[cd].numb,s[cd].age,s[cd].id);
                printf("\n\n");
                break;
        }
        else
            printf("\n\nNot Found\n\n");
    }
    
    else
        printf("\n\nInvalid input\n\n");
}
}
}
void edit()//``````````````````````````````````````````````````````````````````````````````edit function
{
    int q,p,l;
    FILE *pq;
	pq=fopen("num.txt","r");
	fscanf(pq,"%d",&l);
	fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Cabin\n5.Phone no.\n");
    printf("Option=");
    scanf("%d",&q);//option
 	fp=fopen("patient.txt","r+");
	 for(i=0;i<l;i++){

while(fscanf(fp,"%s\n%s\n%d\n%d\n%lld\n%d\n",s[i].na,s[i].d,&s[i].cab,&s[i].age,&s[i].numb,&s[i].id)!=EOF){

	 if(q<=5)
    
	{
        printf("Enter the serial no.  of that patient= (0 - %d)=",l-1);
        scanf("%d",&p);//serial number
        if(p==l)
        {
            if(q==1)
            {
          fflush(stdin);
		  printf("\nEnter new name : ");
		  scanf("%[^\n]",s[p].na);
		
                
            }
            else if(q==2)
            {
        	fflush(stdin);        
                printf("Enter the new Disease=");
                scanf("%[^\n]",s[p].d);
		
                
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
    break;
	}
		
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
rewind(fp);
fprintf(fp,"%s\n%s\n%d\n%d\n%lld\n",s[i].na,s[i].d,s[i].cab,s[i].age,s[i].numb);
		}
fclose(fp);
}
}


	

void discharge(){//```````````````````````````````````````````````Discharge function
    int idd, f=0,l;
    system("cls");
    printf("<== Discharge Patient ==>\n\n");
    printf("Enter Patient id to discharge: ");
    scanf("%d", &idd);

    FILE *ft;

    fp = fopen("patient.txt", "r");
    ft = fopen("temp.txt", "w");
 FILE *pq;
	pq=fopen("num.txt","r");
	fscanf(pq,"%d",&l);
    
	       for(i=0;i<l;i++){
while(fscanf(fp,"%s\n%s\n%d\n%d\n%lld\n%d\n",s[i].na,s[i].d,&s[i].cab,&s[i].age,&s[i].numb,&s[i].id)!=EOF){

        if(idd == s[i].id){
            f=1;
          
        }else{
            fprintf(ft,"%s\n%s\n%d\n%d\n%lld\n%d\n",s[i].na,s[i].d,s[i].cab,s[i].age,s[i].numb,s[i].id);
    }
}

}
    if(f==1){
        printf("\n\nPatient Discharged Successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }

   
    fclose(fp);
    fclose(ft);

    remove("patient.txt");
    rename("temp.txt", "patient.txt");
FILE *q;
q=fopen("patient.txt","r");
 for(i=0;i<l;i++){
fscanf(fp,"%s\n%s\n%d\n%d\n%lld\n%d\n",s[i].na,s[i].d,&s[i].cab,&s[i].age,&s[i].numb,&s[i].id);
printf("\n Data after patient discharged:");

                printf("\n");
                printf("Name = ");
                puts(s[i].na);
                printf("Disease = ");
                puts(s[i].d);
                printf("Cabin no = %d\nPhone number = %lld\nAge = %d\nID of patient = %d",s[i].cab,s[i].numb,s[i].age,s[i].id);
                printf("\n\n");
                break;

}
}
