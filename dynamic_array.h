#ifndef DYNAMIC_ARRAY_
#define DYNAMIC_ARRAY_

#include <stddef.h>

int *darr_init(size_t size);
size_t darr_size(int *arr);
void darr_remove(int *arr, int var);
void darr_append(int *arr, int var);
void darr_free(int *arr);

#ifdef DYNAMIC_ARRAY_IMPLEMENTATION

#define DEF_ARR_CAPACITY 16

typedef struct {
	size_t size;
	size_t capacity;
} header_t;

int *darr_init(size_t size)
{
	int capacity = size < DEF_ARR_CAPACITY ? DEF_ARR_CAPACITY : size;
	header_t *header = malloc(sizeof(header_t) + (sizeof(int)*capacity));
	header->size = 0;
	header->capacity = capacity;
	return (int*)(header + 1);
}

size_t darr_size(int *arr)
{
	return ((header_t*)arr - 1)->size;
}

void darr_remove(int *arr, int var)
{
	size_t size = darr_size(arr);
	for (size_t i = 0; i < size; ++i) {
		if (arr[i] == var) {
			arr[i] = arr[size - 1];
			((header_t*)arr - 1)->size = size - 1;
			break;
		}
	}
}

void darr_append(int *arr, int var)
{
	header_t *header = (header_t*)arr - 1;
	if (header->capacity > header->size) {
		arr[header->size++] = var;
	} else {
		header->capacity *= 2;
		header = realloc(header, 
				sizeof(header_t) + (sizeof(int) * header->capacity));
		arr[header->size++] = var;
	}
}

void darr_free(int *arr)
{
	header_t *header = (header_t*)arr - 1;
	free(header);
}

#endif /* DYNAMIC_ARRAY_IMPLEMENTATION */

#endif /* DYNAMIC_ARRAY_ */
