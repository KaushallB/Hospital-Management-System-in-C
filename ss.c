#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct std{
	char n[50];
	int r;
	struct {
		int m;
		int sc;
		int e;
		int ne;
		int so;
	}mark;
};
void pat();
void add();
void bulk();
void list();
void serch();
	void pat(){
	int i;
	
	printf("\n\n");
	for(i=0;i<45;i++)
	{
		printf("**");
	}
}
void add(){
struct std s;
FILE *j;
	pat();
	int i=1;
	j=fopen("stddata.txt","w");
		{
		printf("\n\n");
		printf("\nEnter information for student no.%d :",i);
			fflush(stdin);
		printf("\nEnter name : ");
		scanf("%[^\n]",s.n);
			fflush(stdin);
		printf("\nEnter Roll : ");
		scanf("%d",&s.r);
			fflush(stdin);
		printf("\nEnter Marks in Mathematics : ");
		scanf("%d",&s.mark.m);
			fflush(stdin);
			printf("\nEnter Marks in Science : ");
		scanf("%d",&s.mark.sc);
			fflush(stdin);
			printf("\nEnter Marks in English : ");
		scanf("%d",&s.mark.e);
			fflush(stdin);
			printf("\nEnter Marks in Nepali : ");
		scanf("%d",&s.mark.ne);
			fflush(stdin);
			printf("\nEnter Marks in Social : ");
		scanf("%d",&s.mark.so);
			fflush(stdin);
		fprintf(j,"%s\n%d\n%d\n%d\n%d\n%d\n%d\n",s.n,s.r,s.mark.m,s.mark.sc,s.mark.e,s.mark.ne,s.mark.so);
	}
		fclose(j);
}
void bulk(){
	FILE *j;
	j=fopen("stddata.txt","a");
	int n,i;
	printf("How many students?: ");
	scanf("%d",&n);
	struct std s[n]; 
	
	for(i=0;i<n;i++){
		printf("\nEnter information for student no.%d :",i+1);
			fflush(stdin);
		printf("\nEnter name : ");
		scanf("%[^\n]",s[i].n);
			fflush(stdin);
		printf("\nEnter Roll : ");
		scanf("%d",&s[i].r);
			fflush(stdin);
		printf("\nEnter Marks in Mathematics : ");
		scanf("%d",&s[i].mark.m);
			fflush(stdin);
			printf("\nEnter Marks in Science : ");
		scanf("%d",&s[i].mark.sc);
			fflush(stdin);
			printf("\nEnter Marks in English : ");
		scanf("%d",&s[i].mark.e);
			fflush(stdin);
			printf("\nEnter Marks in Nepali : ");
		scanf("%d",&s[i].mark.ne);
			fflush(stdin);
			printf("\nEnter Marks in Social : ");
		scanf("%d",&s[i].mark.so);
			fflush(stdin);
		fprintf(j,"%s\n%d\n%d\n%d\n%d\n%d\n%d\n",s[i].n,s[i].r,s[i].mark.m,s[i].mark.sc,s[i].mark.e,s[i].mark.ne,s[i].mark.so);
	}
		fclose(j);
	}

void list(){
int i;
FILE *j;
	j=fopen("stddata.txt","r");
	struct std s[i];
printf("\nRoll\t Name");
while(i!=EOF){

while(fscanf(j,"%s\n%d\n%d\n%d\n%d\n%d\n%d\n",s[i].n,&s[i].r,&s[i].mark.m,&s[i].mark.sc,&s[i].mark.e,&s[i].mark.ne,&s[i].mark.so)!=EOF)

	{
	printf("\n%d\t %s",s[i].r,s[i].n);
	i++;
	fclose(j);
	}
}
}
int main(){
	int ch;
		printf("\n\n");
		printf("\n1.Add a record");
		printf("\n2.Add bulk record");
		printf("\n3.List students");
		printf("\n4.Search students");
		printf("\n5.Quit");
		printf("\nWhat is your choice? : ");
		scanf("%d",&ch);
		
        switch(ch)
        {
        	case 1:
        		add();
        		break;
		case 2:
			bulk();
			break;
		
		case 3:
			list();
	}
		return 0;
	}
