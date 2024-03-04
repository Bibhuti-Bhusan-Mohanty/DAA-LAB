/*program to implement binary search using recurssion*/

#include<stdio.h>

int binary_search_recursive(int arr[],int low,int high,int key);

int main(){
    int arr[20],i,n,num,indx=0;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("Enter %d elements in ascending order:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the element to search:");
    scanf("%d",&num);
    indx=binary_search_recursive(arr,0,n-1,num);
    if(indx!=-1)
        printf("%d found at position %d\n",num,indx);
    else
        printf("Element not found !\n");
    return 0;
}

int binary_search_recursive(int arr[],int low,int high,int key){
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]<key)
        return binary_search_recursive(arr,mid+1,high,key);
    else
        return binary_search_recursive(arr,low,mid-1,key);
}