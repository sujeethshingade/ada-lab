#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void main()
{
    int n, i, j, capacity;
    int weight[20], value[20];
    int v[20][20], w;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("________________");
    printf("\nWEIGHTS VALUES\n");
    printf("________________\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &weight[i]);
        scanf("%d", &value[i]);
    }
    printf("Enter capacity of Knapsack: ");
    scanf("%d", &capacity);
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
            else if (j - weight[i] >= 0)
            {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - weight[i]] + value[i]);
            }
            else
            {
                v[i][j] = v[i - 1][j];
            }
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    w = capacity;
    printf("The items in the Knapsack are\n");
    for (i = n; i > 0; i--)
    {
        if (v[i][w] == v[i - 1][w])
        {
            continue;
        }
        else
        {
            printf("%d\t", weight[i]);
            w = w - weight[i];
        }
    }
    printf("\nTotal profit = %d", v[n][capacity]);
}