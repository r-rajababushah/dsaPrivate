#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int numbers[] = {10, 5, 8, 20, 15, 2, 7};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int target1 = 20;
    int target2 = 100;

    int result1 = linearSearch(numbers, n, target1);
    int result2 = linearSearch(numbers, n, target2);

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d%s", numbers[i], (i == n - 1) ? "" : ", ");
    }
    printf("\n\n");

    printf("Searching for target: %d\n", target1);
    if (result1 != -1) {
        printf("Element %d found at index %d.\n", target1, result1);
    } else {
        printf("Element %d not found in the array.\n", target1);
    }

    printf("----------------------------------------\n");

    printf("Searching for target: %d\n", target2);
    if (result2 != -1) {
        printf("Element %d found at index %d.\n", target2, result2);
    } else {
        printf("Element %d not found in the array.\n", target2);
    }

    return 0;
}
