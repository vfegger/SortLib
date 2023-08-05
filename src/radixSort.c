#include <stdlib.h>

void binaryRadixSort(int *array, int length)
{
    if (length == 0)
    {
        return;
    }
    int *aux = (int *)malloc(sizeof(int) * length);

    int i0, i1;
    for (int bit = 0; bit < 32; ++bit)
    {
        int mask = 1 << bit;
        i0 = 0;
        i1 = 0;
        for (int i = 0; i < length; ++i)
        {
            if (array[i] & mask)
            {
                aux[i1++] = array[i];
            }
            else
            {
                array[i0++] = array[i];
            }
        }

        for (int i = 0; i < i1; ++i)
        {
            array[i0 + i] = aux[i];
        }
    }

    // Swap negative numbers
    for (int i = 0; i < i1; i++)
    {
        aux[i] = array[i0 + i];
    }
    for (int i = 0; i < i0; i++)
    {
        array[length - 1 - i] = array[length - 1 - i1 - i];
    }
    for (int i = 0; i < i1; i++)
    {
        array[i] = aux[i];
    }

    free(aux);
}