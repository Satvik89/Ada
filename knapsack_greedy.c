#include<stdio.h>

void knapsackGreedy(int n, int weight[], int value[], int capacity)
{
    float ratio[n];
    int i, j, temp;
    float totalValue = 0, totalWeight = 0;
  
    // Calculating the ratio of value to weight for each item
    for (i = 0; i < n; i++)
        ratio[i] = (float)value[i] / weight[i];
  
    // Sorting the items based on the ratio in descending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                // Swapping ratio
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
  
                // Swapping weight
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
  
                // Swapping value
                temp = value[j];
                value[j] = value[i];
                value[i] = temp;
            }
        }
    }
  
    // Adding items to the knapsack
    for (i = 0; i < n; i++)
    {
        if (totalWeight + weight[i] <= capacity)
        {
            totalValue += value[i];
            totalWeight += weight[i];
        }
        else
        {
            float remainingWeight = capacity - totalWeight;
            totalValue += ratio[i] * remainingWeight;
            break;
        }
    }
  
    printf("Maximum value in the knapsack: %f\n", totalValue);
}

int main()
{
    int n, capacity, i;
  
    printf("Enter the number of items: ");
    scanf("%d", &n);
  
    int weight[n], value[n];
  
    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++)
    {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &weight[i]);
        printf("Value: ");
        scanf("%d", &value[i]);
    }
  
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
  
    knapsackGreedy(n, weight, value, capacity);
  
    return 0;
}
