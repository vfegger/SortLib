#include <stdio.h>

void insertionSort(int *array, int length)
{
    for (int j = 1; j < length; ++j)
    {
        int i;
        int aux = array[j];
        for(i = 0; i < j; ++i){
            if(array[i] > aux){
                break;
            }
        }
        for(int k = j; k > i; --k){
            array[k] = array[k-1];
        }
        array[i] = aux;
    }
    return;
}