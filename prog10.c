#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    srand(time(NULL)); // Seed for random number generation
    FILE *fp;
    fp = fopen("time_complexity_data.csv", "w");
    fprintf(fp, "n,Time Taken\n");
    int n_values[] = {6000, 7000, 8000, 9000, 10000}; // Varying values of n
    int num_values = sizeof(n_values) / sizeof(n_values[0]);
    for (int i = 0; i < num_values; i++)
    {
        int n = n_values[i];
        int arr[n];
        // Generating random numbers for the array
        for (int j = 0; j < n; j++)
        {
            arr[j] = rand() % 1000; // Random numbers from 0 to 999
        }
        clock_t start_time = clock(); // Start the clock
        quickSort(arr, 0, n - 1);     // Sort the array using Quick Sort
        clock_t end_time = clock();   // End the clock
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Time taken to sort %d elements: %.6f seconds\n", n, time_taken);
        fprintf(fp, "%d,%.6f\n", n, time_taken);
    }
    fclose(fp);
    // Plotting the graph (not implemented in C, use other tools like Python or MATLAB)
    printf("\nGraph plotting not implemented in C. Please use other tools like Python or MATLAB to plot the graph.\n");
    return 0;
}