#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t size;
	size_t capacity;
} header_t;

int *array_init(size_t size)
{
	header_t *header = malloc(sizeof(header_t) + (sizeof(int)*size));
	header->size = 0;
	header->capacity = size;
	return (int*)(header + 1);
}

size_t array_size(int *arr)
{
	return ((header_t*)arr - 1)->size;
}

void arr_append(int *arr, int var)
{
	header_t *header = (header_t*)arr - 1;
	if (header->capacity >= header->size + 1) {
		arr[header->size++] = var;
	} else {
		if (header->capacity < 1) header->capacity = 1;
		header->capacity *= 2;
		header = realloc(header, 
				sizeof(header_t) + (sizeof(int) * header->capacity));
		arr[header->size++] = var;
	}
}

void arr_free(int *arr)
{
	header_t *header = (header_t*)arr - 1;
	free(header);
}

int main(void)
{
	int *arr = array_init(0);
	for (size_t i = 0; i < 38; ++i) {
		arr_append(arr, i);
	}

	for (size_t i = 0; i < array_size(arr); ++i) {
		printf("%d\t", arr[i]);
	}

	arr_free(arr);

	printf("\nDone!\n");
	return 0;
}
