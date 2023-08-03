void radixSort(int *array, int length)
{
    if (length == 0)
    {
        return;
    }
    int nBit = 31;
    int mask = 1 << nBit;
    int i0, i1;
    // Inversion of the sign-bit
    i0 = length;
    i1 = 0;
    while (i0 - i1 > 1)
    {
        int aux = array[i1];
        if (aux & mask)
        {
            ++i1;
        }
        else
        {
            array[i1] = array[--i0];
            array[i0] = aux;
        }
    }
    // Sort all bits after the sign-bit
    while (--nBit > 0)
    {
        int basis = 1 << nBit;
        i0 = 0;
        while (i0 != length)
        {
            i1 = i0;
            int section = mask & array[i0];
            while (i1 < length && section == (mask & array[i1]))
            {
                ++i1;
            }
            int index = i1;
            while (i1 - i0 > 1)
            {
                int aux = array[i0];
                if (aux & basis)
                {
                    array[i0] = array[--i1];
                    array[i1] = aux;
                }
                else
                {
                    ++i0;
                }
            }
            i0 = index;
        }
        mask = mask | basis;
    }
    return;
}