#include <stdio.h>

#define MAX_ITEMS 20

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, capacity;
    int weight[MAX_ITEMS], value[MAX_ITEMS];
    int V[MAX_ITEMS + 1][MAX_ITEMS + 1];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter weights and values:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &weight[i], &value[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Initialize the DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                V[i][j] = 0;
            }
            else if (j >= weight[i])
            {
                V[i][j] = max(V[i - 1][j], V[i - 1][j - weight[i]] + value[i]);
            }
            else
            {
                V[i][j] = V[i - 1][j];
            }
        }
    }

    printf("The items in the knapsack are:\n");
    int w = capacity;
    for (int i = n; i > 0; i--)
    {
        if (V[i][w] != V[i - 1][w])
        {
            printf("Item %d (Weight: %d, Value: %d)\n", i, weight[i], value[i]);
            w -= weight[i];
        }
    }
    printf("DP matrix V:\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            printf("%4d ", V[i][j]);
        }
        printf("\n");
    }
    printf("Total profit = %d\n", V[n][capacity]);

    return 0;
}