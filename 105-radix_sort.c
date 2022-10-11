#include "sort.h"

/**
<<<<<<< HEAD
 * radix_sort - sort array with radix method
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
*/
void radix_sort(int *array, size_t size)
{
int i, j, x, y, cantRep, max, div = 1, t = 0;
int buckets[10][1000];
if (!array || size < 2)
return;
max = array[0];
for (i = 1; i < (int) size; i++)
if (array[i] > max)
max = array[i];
for (i = 0; i < 10; ++i)
for (j = 0; j < 1000; ++j)
buckets[i][j] = -1;
cantRep = getCantRep(max);
for (i = 0; i < cantRep; ++i)
{
for (j = 0; j < (int) size; ++j)
{
for (y = 0; buckets[(array[j] / div) % 10][y] != -1; y++)
;
buckets[(array[j] / div) % 10][y] = array[j];
}
div = div * 10;
t = 0;
for (x = 0; x < 10; ++x)
{
for (y = 0; buckets[x][y] != -1; y++)
{
array[t] = buckets[x][y];
buckets[x][y] = -1;
t++;
}
}
print_array(array, size);
}
}
=======
 * max_num - function reutrn max integer
 *
 * @array: pointers array
 * @size: size value the lengeth
 * Return: integer data
 */
int max_num(int *array, int size)
{
	int max_num, j;

	for (max_num = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max_num)
			max_num = array[j];
	}
	return (max_num);
}

/**
 * radix_counting - function radix counting data
 *
 * @array: pointers array
 * @size: size value the lengeth
 * @powten: integer data powten
 * @copy: malloc with copy the array
 */
void radix_counting(int *array, size_t size, int powten, int *copy)
{
	int count[10] = {0};
	int index;

>>>>>>> a189baac26753e73c5a15a87d0eafc82925bc0dd

	for (index = 0; index < (int)size; index++)
		count[(array[index] / powten) % 10] += 1;

	for (index = 0; index < 10; index++)
		count[index] += count[index - 1];

	for (index = (int)size - 1; index >= 0; index--)
	{
		copy[count[(array[index] / powten) % 10] - 1] = array[index];
		count[(array[index] / powten) % 10] -= 1;
	}
	for (index = 0; index < (int)size; index++)
		array[index] = copy[index];
}

/**
<<<<<<< HEAD
 * getCantRep - Returns the number of digits of the largest number in the array
 * @num: The largest number
 * Return: Number of digits of the num
=======
 * radix_sort - function sorting radix
 *
 * @array: pointers array
 * @size: size value the lengeth
>>>>>>> a189baac26753e73c5a15a87d0eafc82925bc0dd
 */
int getCantRep(int num)
{
<<<<<<< HEAD
bool flag = true;
int cont = 0;
while (flag)
{
flag = false;
if (num > 0)
{
num = num / 10;
cont++;
flag = true;
}
}
return (cont);
=======
	int max, powten, *copy;

	if (!array || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	max = max_num(array, size);

	for (powten = 1; max / powten > 0; powten *= 10)
	{
		radix_counting(array, size, powten, copy);
		print_array(array, size);
	}
	free(copy);
>>>>>>> a189baac26753e73c5a15a87d0eafc82925bc0dd
}
