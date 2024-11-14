#include <stdio.h>
#include <stdlib.h>

void radix_sort(int num[], int l, int n){
    int output[n];
    int count[10] = {0};
    int exp = 1;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < 10; j++) {
            count[j] = 0;
        }

        for (int j = 0; j < n; j++) {
            count[(num[j] / exp) % 10]++;
        }
        
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }

        for (int j = n - 1; j >= 0; j--) {
            output[count[(num[j] / exp) % 10] - 1] = num[j];
            count[(num[j] / exp) % 10]--;
        }
        
        for (int j = 0; j < n; j++) {
            num[j] = output[j];
        }

        exp *= 10;
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int num[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Number: ");
        scanf("%d", &num[i]);
    }

    int l = 0, max = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }

    while (max != 0) {
        l++;
        max /= 10;
    }

    radix_sort(num, l, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}
