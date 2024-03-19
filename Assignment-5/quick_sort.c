/*program to take n random inputs and sort using quick sort in ascending order*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input(int [], int);
void display(int [], int);
void quicksort(int arr[],int l,int h);
int partition(int arr[],int l,int h);

int main(){
}

void quicksort(int arr[],int l,int h)
{
	int pivot;
	if (l<h)
	{
		pivot=partition(arr,l,h);
		quicksort(arr,l,pivot-1);
		quicksort(arr,pivot+1,h);
	}
}

int partition(int arr[],int l,int h)
{
	int i=l-1,j;
	int x=arr[h],temp;
	for(j=l;j<=h-1;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[h];
	arr[h]=temp;
	return (i+1);
}