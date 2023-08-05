#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/sort.h"

#define PRINT_ARRAYS 0
#define TEST_N2 1
#define TEST_NLOGN 1
#define TEST_PN 1
#define K 5

int checkArrays(int *array, int n)
{
    int acc = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (array[i] > array[i + 1])
        {
            ++acc;
        }
    }
    return acc;
}

void test(void (*sort)(int *, int), int *array, int *aux, int n)
{
    clock_t start, end;
    double cpu_time_used;
    for (int i = 0; i < n; ++i)
    {
        aux[i] = array[i];
    }
    start = clock();
    sort(aux, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%lf ", cpu_time_used);
    printf("\tResult 0-1 : %d\n", checkArrays(aux, n));
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
            array[i] = (2 * (rand() % 2) - 1) * rand();
        }
        int *aux = (int *)malloc(sizeof(int) * n * 6);
        int *aux0 = aux;
        int *aux1 = aux0 + n;
        int *aux2 = aux1 + n;
        int *aux3 = aux2 + n;
        int *aux4 = aux3 + n;
        int *aux5 = aux4 + n;

        // Bubble Sort
        if (TEST_N2)
        {
            printf("\tBubble Sort - ");
            test(bubbleSort, array, aux0, n);
        }

        // Insertion Sort
        if (TEST_N2)
        {
            printf("\tInsertion Sort - ");
            test(insertionSort, array, aux1, n);
        }

        // Merge Sort
        if (TEST_NLOGN)
        {
            printf("\tMerge Sort - ");
            test(mergeSort, array, aux2, n);
        }

        // Quick Sort
        if (TEST_NLOGN)
        {
            printf("\tQuick Sort - ");
            test(quickSort, array, aux3, n);
        }

        // Selection Sort
        if (TEST_N2)
        {
            printf("\tSelection Sort - ");
            test(selectionSort, array, aux4, n);
        }

        // Radix Sort
        if (TEST_PN)
        {
            printf("\tBinary Radix Sort - ");
            test(binaryRadixSort, array, aux5, n);
        }

        free(aux);
    }
}