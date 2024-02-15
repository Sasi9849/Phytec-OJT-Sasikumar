#include<stdio.h>
#include<string.h>
int main()
{
	char name[4][20];
	int x,i,j,count=0;
	char ch;
	printf("Enter ten names\n");
	for (x=0;x<4;x++)
	{
		scanf("%s",name[x]);
	}

	for(i=0;i<10;i++){
		for(j=0;j<strlen(name[i]);j++){
			//printf("%c\n",name[i][j]);

			if (name[i][j] =='a'|| name[i][j] == 'e' || name[i][j] == 'i' ||
			name[i][j]  == 'o'|| name[i][j] == 'u')
			{
				count=count+1;
			}

		}
	}
			printf("vowels in 10 names are %d",count);
	
}




