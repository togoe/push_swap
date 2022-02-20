#include <stdio.h>

void my_swap(int *a, int *b)
{
    int aa, bb;

    aa = *a;
    bb = *b;
    *a = bb;
    *b = aa;
}

void    array_print(int *array, size_t size)
{
    for (size_t index = 0; index < size; index++)
        printf("array[%lu] = %d\n", index, array[index]);
}

void    array_sort(int *array, size_t size)
{
    if (size > 1)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (array[0] > array[i])
                my_swap(array + 0, array + i);
        }
    }
}

int main(void)
{
    int numbers[] = {23, 234, 45, 46, 12, 3456, 32};
    size_t  size = sizeof(numbers) / sizeof(*numbers); 
    printf("Before sort\n");
    array_print(numbers, size);
    printf("\n");
    array_sort(numbers, size);
    printf("After sort\n");
    array_print(numbers, size);
    printf("\n");
    return (0);
}