#include <stdio.h>
void knapsack();
int max(int, int);
int i, j, n, m, p[10], w[10], v[10][10];
void main()
{
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("\nEnter weight of each item:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("\nEnter profit of each item: \n");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("\nEnter the Knapsack's capacity: ");
    scanf("%d", &m);
    knapsack();
}
void knapsack()
{
    int X[10];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (j - w[i] < 0)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
        }
    }
    printf("\nOutput is: \n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n\n");
    }
    printf("\nThe Optimal Solution is :%d", v[n][m]);
    printf("\nThe solution vector is: \n");
    for (i = n; i >= 1; i--)
    {
        if (v[i][m] != v[i - 1][m])
        {
            X[i] = 1;
            m = m - w[i];
        }
        else
            X[i] = 0;
    }
    for (i = 1; i <= n; i++)
        printf("%d\t", X[i]);
}
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
