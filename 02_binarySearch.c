#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    // The array must be sorted for binary search to work
    int numbers[] = {2, 5, 7, 8, 10, 15, 20};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int target1 = 20;
    int target2 = 100;

    int result1 = binarySearch(numbers, n, target1);
    int result2 = binarySearch(numbers, n, target2);

    printf("Array elements (Sorted): ");
    for (int i = 0; i < n; i++) {
        printf("%d%s", numbers[i], (i == n - 1) ? "" : ", ");
    }
    printf("\n\n");

    printf("Searching for target: %d (Binary Search)\n", target1);
    if (result1 != -1) {
        printf("Element %d found at index %d.\n", target1, result1);
    } else {
        printf("Element %d not found in the array.\n", target1);
    }

    printf("----------------------------------------\n");

    printf("Searching for target: %d (Binary Search)\n", target2);
    if (result2 != -1) {
        printf("Element %d found at index %d.\n", target2, result2);
    } else {
        printf("Element %d not found in the array.\n", target2);
    }

    return 0;
}
