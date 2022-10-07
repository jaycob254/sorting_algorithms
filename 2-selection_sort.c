#include "sort.h"
/**
 * selection_sort - function that sort selction
 * @array: array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, indexMin;

	for (i = 0; i < size - 1; i++)
	{
		indexMin = i;
		/** */
		for (j = i + 1; j < size; j++)
			if (array[j] < array[indexMin])
				indexMin = j;
		if (indexMin != i)
		{
			swap(&array[indexMin], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - Function that swaps two values
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
