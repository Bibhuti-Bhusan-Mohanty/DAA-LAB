/*program to implement randomized quick sort by choosing the pivot from random position*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
  int t=*a;
  *a=*b; 
  *b=t;
}
int partition(int arr[], int low, int high){
    int random =low + rand() % (high - low);
    swap(&arr[random], &arr[high]);
    int pivot = arr[high]; 
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void randomizedQuickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
        }
}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Generated random array: ");
    for(int i=0; i<n; i++){
        arr[i] = rand() % 100;
        printf("%d ", arr[i]); 
    }
    /*printf("Enter elements: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }*/
    randomizedQuickSort(arr, 0, n-1);
    printf("\nSorted array: \n");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}