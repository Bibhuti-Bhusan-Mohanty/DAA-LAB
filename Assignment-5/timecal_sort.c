#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void input(int [], int);
void display(int [], int);
void bubble_asc(int [], int);
void selection_desc(int [], int);
void insertion_asc(int [], int);
void merge(int [], int, int, int);
void merge_sort(int [], int, int);

int main(){
	int a[1000], ch, n, i;
	clock_t start, end;
	double cpu_time;
	
	do{
		printf("\nThe menu\n1:INPUT\n2:OUTPUT\n3:Bubble Sort Asc\n4:Selection Sort Desc\n5:Insertion Sort Asc\n6:Merge Sort Asc\n7:Exit\nEnter your choice: ");
        scanf("%d", &ch);
		switch(ch){
			case 1:
			printf("Enter the number of elements in the array.\n");
			scanf("%d", &n);
			printf("The array is randomly inputted.\n");
			for(i = 0; i < n; i++)
				a[i] = rand()%(n+1);
				break;
            case 2:
			display(a, n);
			break;
            case 3:
			start = clock();
            bubble_asc(a, n);
			end = clock();
			cpu_time = end - start;
			printf("Time taken : %lf seconds\n", cpu_time/CLOCKS_PER_SEC);
            break;
            case 4:
			start = clock();
            selection_desc(a, n);
			end = clock();
			cpu_time = end - start;
			printf("Time taken : %lf seconds\n", cpu_time/CLOCKS_PER_SEC);
            break;
            case 5:
			start = clock();
            insertion_asc(a, n);
			end = clock();
			cpu_time = end - start;
			printf("Time taken : %lf seconds\n", cpu_time/CLOCKS_PER_SEC);
			break;
            case 6:
			start = clock();
			merge_sort(a, 0, n-1);
			end = clock();
			cpu_time = end - start;
			printf("Time taken : %lf seconds\n", cpu_time/CLOCKS_PER_SEC);
			break;
			case 7:
            printf("Program Terminated\n");
            exit(0);
            default:
			printf("Invalid input\nPlease enter a number between 1 and 6\n");
        }
    }while(ch != 7);
    return 0;
}

/*void input(int a[], int n){
	int i;
	printf("Enter the elements :\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
}*/

void display(int a[], int n){
	int i;
	printf("The array :\n");
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
}

void bubble_asc(int a[], int n){
	int i, j, c;
	for(i = 0; i < n; i++){
		for(j = 0; j < n-1; j++){
			if(a[i] < a[j]){
				c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
}

void selection_desc(int a[], int n){
	int i, j, c;
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(a[i] < a[j]){
				c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
}

void insertion_asc(int a[], int n){
    int i, j, c;
    for(i = 1; i < n; i++){
        for(j = 0; j < i; j++){
            if(a[i] < a[j]){
                c = a[i];
                a[i] = a[j];
                a[j] = c;
			}
		}
	}
}

void merge(int a[], int lb, int mid, int ub){
	int i=lb, j=mid+1, k=lb, b[50];
	while(i <= mid && j <= ub){
		if(a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while(i <= mid)
		b[k++] = a[i++];
	while(j <= ub)
		b[k++] = a[j++];
	for(i = lb; i <= ub; i++)	
		a[i] = b[i];
}

void merge_sort(int a[], int lb, int ub){
	int mid;
	if(lb < ub){
		mid = (lb + ub) / 2;
		merge_sort(a, lb, mid);
		merge_sort(a, mid+1, ub);
		merge(a,lb,mid,ub);
	}
}