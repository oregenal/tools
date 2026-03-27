#include <stdio.h>
#include <stdlib.h>

#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "dynamic_array.h"

int main(void)
{
	int *arr = darr_init(0);
	for (size_t i = 0; i < 38; ++i) {
		darr_append(arr, i);
	}

	for (size_t i = 0; i < darr_size(arr); ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	
	darr_remove(arr, 33);

	for (size_t i = 0; i < darr_size(arr); ++i) {
		printf("%d\t", arr[i]);
	}

	darr_free(arr);

	printf("\nDone!\n");
	return 0;
}
