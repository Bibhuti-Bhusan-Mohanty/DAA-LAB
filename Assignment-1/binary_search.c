/*program to find a elemnat of an array using binary search*/

#include <stdio.h>
int binary_search(int [], int, int);

int main() {
    int arr[20],i,n,num,indx=0;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("Enter %d elements in ascending order:\n", n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the element to search:");
    scanf("%d",&num);
    indx=binary_search(arr,n,num);
    if(indx!=-1)
        printf("%d found at position %d\n", num, indx);
    else
        printf("Element not found!\n");
    return 0;
}

int binary_search(int arr[],int n,int ele){
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==ele)
            return mid+1;
        else if(arr[mid]<ele)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}