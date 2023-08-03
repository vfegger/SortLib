#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/sort.h"

#define PRINT_ARRAYS 0
#define TEST_N2 0
#define TEST_NLOGN 1
#define TEST_PN 1
#define K 8

void printArray(int *array, int n)
{
    if (PRINT_ARRAYS)
    {
        printf("Array = [ ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("]\n");
    }
}

void test(void (*sort)(int *, int), int *array, int n)
{
    clock_t start, end;
    double cpu_time_used;
    int *aux = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        aux[i] = array[i];
    }
    start = clock();
    sort(aux, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", cpu_time_used);
    free(aux);
}

int main()
{
    printf("Start Sort Test\n");
    time_t t;
    srand((unsigned)time(&t));
    int k = K;
    int n = 1;
    while (k > 0)
    {
        n = 10 * n;
        k--;
        printf("Size N = %d\n", n);
        int *array = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            array[i] = rand();
        }

        // Bubble Sort
        if (TEST_N2)
        {
            printf("\tBubble Sort - ");
            test(bubbleSort, array, n);
        }

        // Insertion Sort
        if (TEST_N2)
        {
            printf("\tInsertion Sort - ");
            test(insertionSort, array, n);
        }

        // Merge Sort
        if (TEST_NLOGN)
        {
            printf("\tMerge Sort - ");
            test(mergeSort, array, n);
        }

        // Quick Sort
        if (TEST_NLOGN)
        {
            printf("\tQuick Sort - ");
            test(quickSort, array, n);
        }

        // Selection Sort
        if (TEST_N2)
        {
            printf("\tSelection Sort - ");
            test(selectionSort, array, n);
        }

        // Radix Sort
        if (TEST_PN)
        {
            printf("\tRadix Sort - ");
            test(radixSort, array, n);
        }
    }
}