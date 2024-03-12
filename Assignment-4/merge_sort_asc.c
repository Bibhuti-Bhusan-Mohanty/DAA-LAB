/*program to sort the elements of an array using mergr sort in ascending order*/

#include<stdio.h>

void merge_sort(int arr[],int l,int r);
void merge(int arr[],int l,int m,int r);
void printarray(int arr[],int size);

int main(){
    int arr[20],size;
    printf("Enter the size of array:");
    scanf("%d",&size);
    printf("Enter %d elements:\n",size);
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("\nGiven array is:\n");
    printarray(arr,size);
    merge_sort(arr,0,size- 1);
    printf("\nSorted array is:\n");
    printarray(arr,size);
    return 0;
}

void printarray(int arr[],int size){
    int i;
    for (i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void merge_sort(int arr[],int l,int r){
    if(l<r)
    {
        int m=(l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void merge(int arr[],int l,int m,int r){
    int sarr[20];
    int i,j,k;
    i=l;j=m+1;k=l;
    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
            sarr[k]=arr[i];
            k++;
            i++;
        }
        else{
            sarr[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=m){
        sarr[k]=arr[i];
        k++;
        i++;
    }
    while(j<=r){
        sarr[k]=arr[j];
        k++;
        j++;
    }
    for(i=l;i<r;i++)
        arr[i]=sarr[i];
}