/*program to do a menu base program for different sorting*/

#include<stdio.h>

int arr[20],n;

void input();
void output(int arr[],int n);
void bubble_asc(int arr[],int n);
void selection_desc(int arr[],int n);
void insertion_asc(int arr[],int n);

int main(){
    char ch;
    do{
        int choice;
        printf("SORTING PROGRAM\n1.INPUT\n2.OUTPUT\n3.Bubble Sort\n4.Selection Sort\n5.Insertion Sort\n\nFor Exit Enter 0\n\nEnter your choice(1-5):");
        scanf("%d",&choice);
        switch(choice){
            case 1:input();
            break;
            case 2:output(arr,n);
            break;
            case 3:bubble_asc(arr,n);
            break;
            case 4:selection_desc(arr,n);
            break;
            case 5:insertion_asc(arr,n);
            break;
            case 0:exit(0);
            break;
            default:printf("\nInvalid Choice !\n");
        }
        printf("Do you want to continue(y/n):");
        scanf(" %c",&ch);
    }while(ch=='y');
    return 0;
}

void input(){
    printf("\nEnter the total number of elements:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}

void output(int arr[],int n){
    printf("The elements:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void bubble_asc(int arr[],int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selection_desc(int arr[],int n){
    int i,j,temp;
	j=0;
	while(j<n){
		i=j+1;
		while(i<n){
			if(arr[i]>arr[j]){
				
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
			i++;
		}
		j++;
	}
}

void insertion_asc(int arr[],int n){
    int i,j,temp;
    for(i=0;i<=n-1;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && temp<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}