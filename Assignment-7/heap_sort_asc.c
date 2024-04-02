/*program to sort a given array in ascending order using heap sort implement the functions max_heapify(),build_max_heap(),heap_sort()*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void max_heapify(int arr[],int n,int i);
void build_max_heap(int arr[],int n);
void heap_sort(int arr[],int n);

int main(){
    int arr[1000], n;
    printf("\nEnter the size of array(1-1000): ");
    scanf("%d", &n);
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand(); 
    heap_sort(arr, n);
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

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