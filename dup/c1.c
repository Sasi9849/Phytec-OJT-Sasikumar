#include<stdio.h>
#include"head.h"
int main()
{
	int arr[] = {1, 2, 2, 3, 4,
				4, 4, 5, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	n = removeDuplicates(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}


