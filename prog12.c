#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
char s[30][30], count;
void display(int m[30], int n)
{
    int i, j;
    printf("\n-------%d---------\n\n", ++count);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            s[i][j] = '*';
    for (i = 0; i < n; i++)
        s[i][m[i]] = 'Q';
    for (i = 0; i < n; i++)
    {
        {
            for (j = 0; j < n; j++)
                printf("%2c", s[i][j]);
            printf("\n\n");
        }
    }
    printf("\n\n\n");
    getch();
}
int place(int m[30], int k)
{
    int i;
    for (i = 0; i < k; i++)
    {
        if (m[k] == m[i] || (abs(m[i] - m[k]) == abs(i - k)))
            return 0;
    }
    return 1;
}
void main()
{
    int n, k = 0, i, m[30];
    printf("Enter the number of queens\n");
    scanf("%d", &n);
    if (n == 2 || n == 3)
    {
        printf("No solution\n");
        getch();
        exit(0);
    }
    n--;
    for (m[0] = 0; k >= 0; m[k]++)
    {
        while (m[k] <= n && !place(m, k))
            m[k]++;
        if (m[k] <= n)
        {
            if (k == n)
            {
                display(m, n + 1);
            }
            else
                k++, m[k] = -1;
        }
        else
            k--;
    }
}