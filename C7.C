#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i;
    for ( i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
int i;
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n,i;
    int arr[5];
    printf("Enter the number of elements: ");
    scanf("%d", &n);



    printf("Enter %d integers:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
