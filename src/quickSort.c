void quickSort(int *array, int length)
{
    if (length < 2)
    {
        return;
    }
    int aux = array[0];
    int i = 0;
    int j = length;
    while (j - i != 1)
    {
        int temp = array[i + 1];
        if (temp > aux)
        {
            array[i + 1] = array[j - 1];
            array[j - 1] = temp;
            --j;
        }
        else
        {
            ++i;
        }
    }
    array[0] = array[i];
    array[i] = aux;
    quickSort(array, i);
    quickSort(array + j, length - j);
}