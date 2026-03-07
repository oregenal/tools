#include <stdio.h>

#define array_size(X) ((sizeof(X)) / (sizeof(X[0])))

int main(void)
{
	static int array1[] = { 1, 3, 4, 6, 0, 0, 0 };
	static int array2[] = { 2, 5, 7 };

	size_t size_of_array1 = array_size(array1);
	size_t size_of_array2 = array_size(array2);

	for (size_t k = 0; k < size_of_array2; ++k) {
		for (size_t i = 0; i < size_of_array1; ++i) {
			if (array1[i] == 0) {
				array1[i] = array2[k];
				break;
			} else if (array1[i] > array2[k]) {
				int tmp = array1[i];
				array1[i] = array2[k];
				array2[k] = tmp;
			}
		}
	}

	for (size_t i = 0; i < size_of_array1; ++i) {
		printf("%d ", array1[i]);
	}
	putchar('\n');

	return 0;
}

/* vim: set noet ts=8 sw=8: */
