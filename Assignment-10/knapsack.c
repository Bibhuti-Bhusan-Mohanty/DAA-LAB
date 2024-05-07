// write a program to take input for some products,each having product id,product name,profit and weight,using greedy algorithm find the solution to accomodate  the objects in the knapsack of capacity W

#include <stdio.h>
struct Product
{
    int id;
    char name[100];
    int profit;
    int weight;
};
void sortByRatio(struct Product arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if ((float)arr[j].profit/arr[j].weight < (float)arr[j+1].profit/arr[j+1].weight)
            {
                struct Product temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted by ratio: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Product id: %d\n", arr[i].id);
        printf("Product name: %s\n", arr[i].name);
        printf("Profit: %d\n", arr[i].profit);
        printf("Weight: %d\n", arr[i].weight);
        printf("Ratio: %.2f\n", (float)arr[i].profit/arr[i].weight);
        printf("---------------------------------\n");
    }
}
int main()
{
    int n, capacity;
    printf("Enter number of products: ");
    scanf("%d", &n);
    struct Product products[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter product %d id, name, profit and weight:\n", i+1);
        scanf("%d", &products[i].id);
        scanf("%s", products[i].name); 
        scanf("%d", &products[i].profit);
        scanf("%d", &products[i].weight);
        }  
        printf("Enter knapsack capacity: ");
        scanf("%d", &capacity);
        sortByRatio(products, n);
        int currWeight = 0;
        int totalProfit = 0;
        for(int i=0; i<n; i++)
        {
            if(currWeight + products[i].weight <= capacity)
            {
                currWeight += products[i].weight;
                totalProfit += products[i].profit;
            } 
            else
            {
                break;
            }
        }
        printf("Total weight: %d\n", currWeight);
        printf("Total profit: %d\n", totalProfit);
        return 0;
}
