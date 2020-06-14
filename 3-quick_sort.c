#include "sort.h"

/**
 * quick_sort - function that sorts an array of
 * integers in ascending order using the Quick
 * sort algorithm.
 *
 * @array: array of integers to sort.
 * @size: size of array.
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_alg(array, size, 0, size - 1);
}

/**
 * quick_sort_alg - quick sort funciton.
 *
 * @array: array to sort.
 * @size: size of array.
 * @lo: lo limit to sort.
 * @hi: hi limit to sort.
 */

void quick_sort_alg(int *array, size_t size, size_t lo, size_t hi)
{
	size_t p = 0;

	if (lo < hi)
	{
		p = partition(array, size, lo, hi);
		quick_sort_alg(array, size, lo, p - 1);
		quick_sort_alg(array, size, p + 1, hi);
	}
}

/**
 * partition - partition funciton.
 *
 * @array: array to sort.
 * @size: size of array.
 * @lo: lo limit to sort.
 * @hi: hi limit to sort.
 *
 * Return: partition.
 */

size_t partition(int *array, size_t size, size_t lo, size_t hi)
{
	int aux = 0, pivot = 0;
	size_t i = 0, j = 0;
	(void) size;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			/*print_array(array, size);*/
		}
	}
	aux = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = aux;
	/*print_array(array, size);*/

	return (i + 1);
}
