

#include <stdio.h>
int desc_order(int a[10], int n)
{
	int i, j, t = 0;
	
	for (i = 0; i < n; i++) {
		
		for (j = i + 1; j < n; j++) {
			
			if (a[i] < a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
