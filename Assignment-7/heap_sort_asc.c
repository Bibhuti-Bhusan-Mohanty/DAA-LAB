/*program to sort a given array in ascending order using heap sort implement the functions max_heapify(),build_max_heap(),heap_sort()*/

#include <stdio.h>

void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;
    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, n, largest);
    }
}

void build_max_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}

void heap_sort(int arr[], int n) {
    build_max_heap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        max_heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {20, 18, 5, 15, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    heap_sort(arr, n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}