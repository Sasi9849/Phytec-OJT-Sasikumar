#include<stdio.h>
#include<string.h>
typedef struct employee{
	int employeenumber;
	char name[20];
	float salary;
	int mobilenumber;
	char emailid[20];
}emp;
int display(emp e1[5]);
int check(emp e1[5]);
int maxx(emp e1[5]);
int minn(emp e1[5]);
int main()
{
	emp e1[5];
	printf("enter employee details\n");
	for(int i=0;i<5;i++)
	{
		printf("Enter employe number:");
		scanf("%d",&e1[i].employeenumber);
		__fpurge(stdin);
		printf("Enter name:");
		gets(e1[i].name);
		printf("Enter salary:");
		scanf("%f",&e1[i].salary);
		printf("mobile number");
		scanf("%d",&e1[i].mobilenumber);
		__fpurge(stdin);
		printf("emailid:");
		gets(e1[i].emailid);
	}
	display(e1);
	check(e1);
	maxx(e1);
	minn(e1);
}
	int display(emp e1[5]){
		for (int i=0;i<5;i++)
		{
			printf("employee number:%d\n",e1[i].employeenumber);
			printf("name: %s\n",e1[i].name);
			printf("salary: %f\n",e1[i].salary);
			printf("Mobile number:  %d\n",e1[i].mobilenumber);
			printf("Email id: %s\n",e1[i].emailid);
		}
	}


	int check(emp e1[5]){
		int checkemploye,i;
		printf("enter employee to be search");
		scanf("%d",&checkemploye);
		for(i=0;i<5;i++)
		{
			if(checkemploye==e1[i].employeenumber)
			{
				printf("name: %s\n",e1[i].name);
				printf("salary: %f\n",e1[i].salary);
				printf("Mobile number:  %d\n",e1[i].mobilenumber);
				printf("Email id: %s\n",e1[i].emailid);
			}
		}
	}

	int maxx(emp e1[5]){
		int max=e1[0].salary;
		int min=e1[0].salary;
		for(int i=1;i<5;i++)
		{
			if(e1[i].salary>max)
			{
				max=e1[i].salary;
			}	
		}
		int j;
		for(int i=0;i<5;i++){
		
			if(max==e1[i].salary)
				j=i;
		}

		printf("MAX SALARY EMPLOYEE\n");	
		printf("employee number: %d\n",e1[j].employeenumber);	
		printf("name:%s\n",e1[j].name);
		printf("mobile number:%d\n",e1[j].mobilenumber);
		printf("Emailid: %s\n",e1[j].emailid);
	}
	int minn(emp e1[5]){
		int min=e1[0].salary;
		for (int i=1;i<5;i++)
		{
			if(e1[i].salary<min)
			{
				min=e1[i].salary;
			}
		}
		int j;
		for(int i=0;i<5;i++){
			if (min==e1[i].salary)
				j=i;
		}
		printf("MIN SALARY EMPLOYEE");
		printf("Employee number: %d\n",e1[j].employeenumber);
		printf("name:%s"\n,e1[j].name);
		printf("mobilenumber:%d"\n,e1[j].mobilenumber);
		printf("emailid:%s\n",e1[j].emailid);
	}






	
