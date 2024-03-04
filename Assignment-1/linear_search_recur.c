/*program to implement linear search using recurssion*/

#include<stdio.h>

int linear_search_recurssive(int arr[],int start,int end,int ele);

int main(){
    int arr[20],n,num,indx=0;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("Enter the %d elements:\n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the elements to search:");
    scanf("%d",&num);
    indx=linear_search(arr,0,n-1,num);
    if(indx!=-1)
        printf("%d found at position %d\n",num,indx);
    else
        printf("Element not found!\n");
    return 0;
    
}

int linear_search(int arr[],int start,int end,int ele){
    if(start>end)
        return -1;
    if(arr[start]==ele)
        return start+1;
    return linear_search(arr,start+1,end,ele);
}