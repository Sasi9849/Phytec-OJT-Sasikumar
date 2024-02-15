#include<stdio.h>
#include<string.h>
struct date{
	char day[10];
	int dd;
	int mm;
	int yyyy;
};
void struct_func1(struct date d1){
	printf("%s-%d-%d\n",d1.dd,d1.mm,d1.yyyy);
	}
void struct
