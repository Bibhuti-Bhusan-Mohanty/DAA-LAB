/*program to find a element from an array*/

#include<stdio.h>

int element_search(int[],int,int);

int main(){
    int i,n,num,indx=0;
    int arr[20];
    printf("\nEnter the number of elements in the array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the element to search:");
    scanf("%d",&num);
    indx=element_search(arr,n,num);
    if(indx!=-1)
        printf("%d found at position %d\n",num,indx); 
    else
        printf("Element not found !\n");
    return 0;
}

int element_search(int arr[],int n,int ele){
    for(int i=0;i<n;i++){
        if(arr[i]==ele)
            return i+1;
    }
    return -1;
}