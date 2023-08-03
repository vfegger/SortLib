void selectionSort(int *array, int length)
{
    for (int j = 0; j < length - 1; ++j)
    {
        int index = j;
        int aux = array[j];
        for (int i = j + 1; i < length; ++i)
        {
            if(array[i] < aux){
                aux = array[i];
                index = i;
            }
        }
        array[index] = array[j];
        array[j] = aux;
    }
    return;
}