#include<stdio.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int temp;
    int n = 4;

    for (int i = 0; i <= 2; i++) {
        temp = a[i];
        a[i] = a[i + n];
        a[i + n] = temp;
        n = n - 2;
    }

    for (int j = 0; j < 5; j++) {
        printf("%d ", a[j]);
    }

    return 0;
}

