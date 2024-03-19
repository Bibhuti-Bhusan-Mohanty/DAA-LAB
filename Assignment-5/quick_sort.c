/*program to take n random inputs and sort using quick sort in ascending order*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input(int [], int);
void display(int [], int);
void quicksort(int arr[],int l,int h);
int partition(int arr[],int l,int h);

int main(){
	int a[100000],ch,n,i;
	clock_t start,end;
	double cpu_time;
	do{
		printf("\nThe menu\n1:INPUT\n2:OUTPUT\n3:Quick Sort Asc\n4:Exit\nEnter your choice:");
        scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter the number of elements in the array:\n");
			scanf("%d",&n);
			printf("The array is randomly inputted\n");
			for(i=0;i<n;i++)
				a[i]=rand()%(n+1);
			break;
            case 2:
			display(a,n);
			break;
            case 3:
			start=clock();
            quicksort(a,0,n-1);
			end=clock();
			cpu_time=end-start;
			printf("Time taken : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
			case 4:
            printf("Program Terminated\n");
            exit(0);
            default:
			printf("Invalid input\nPlease enter a number between 1 and 6\n");
		}
	}while(ch!=7);
    return 0;
}

/*void input(int a[],int n){
	int i;
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}*/

void display(int a[],int n){
	int i;
	printf("The array:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}

void quicksort(int arr[],int l,int h){
	int pivot;
	if (l<h){
		pivot=partition(arr,l,h);
		quicksort(arr,l,pivot-1);
		quicksort(arr,pivot+1,h);
	}
}

int partition(int arr[],int l,int h){
	int i=l-1,j;
	int x=arr[h],temp;
	for(j=l;j<=h-1;j++){
		if(arr[j]<=x){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[h];
	arr[h]=temp;
	return(i+1);
}