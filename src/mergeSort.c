#include <stdlib.h>

void mergeStep(int *array, int *workspace, int i, int j)
{
    if (j - i < 2)
    {
        return;
    }
    int h = (i + j) / 2;
    mergeStep(array, workspace, i, h);
    mergeStep(array, workspace, h, j);
    for (int k = i; k < j; ++k)
    {
        workspace[k] = array[k];
    }
    int ii = h;
    for (int k = i; k < j; ++k)
    {
        if ((i < h) && (ii >= j || workspace[i] < workspace[ii]))
        {
            array[k] = workspace[i];
            i++;
        }
        else
        {
            array[k] = workspace[ii];
            ii++;
        }
    }
}

void mergeSort(int *array, int length)
{
    int *aux = (int *)malloc(sizeof(int) * length);
    mergeStep(array, aux, 0, length);
    free(aux);
}