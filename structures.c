#include<stdio.h>
struct book{
	int bookid;
	char bookname[20];
	char authorname[20];
	char subject[20];

};
int main()
{
	struct book b[10];
	for(int i=0;i<10;i++)
	{
		printf("enter bookid:");
		scanf("%d",&b[i].bookid);
		printf("Enter bookname:");
		__fpurge(stdin);
		gets(&b[i].bookname);
		printf("enter authorname:");
		gets(&b[i].authorname);
		printf("enter subject:");
		gets(&b[i].subject);
	}
	printf("***************************\n");
	int c;
	printf("enter bookid to search\n");
	scanf("%d",&c);
	for (int i=0;i<10;i++)
	{
		if (c==b[i].bookid)
		{
			printf("%d\n",b[i].bookid);
			printf("%s\n",b[i].bookname);
			printf("%s\n",b[i].authorname);
			printf("%s\n",b[i].subject);
		}
	}
}


