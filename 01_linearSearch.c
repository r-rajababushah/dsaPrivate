#include <stdio.h>

int linearSearch(int arr[], int size, int target){
    for(int i = 0; i<size; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {5, 6, 7, 1, 9, 2, 4, 0, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 9;

    int result = linearSearch(arr, size, target);
    if(result != -1){
        printf("Value is found at index %d", result);
    }
    return 0;
}