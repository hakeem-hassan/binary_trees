#include <stdio.h>
#include <stdlib.h>

typedef struct heap_s {
    int *array;
    size_t size;
} heap_t;

void heapify(int *array, size_t size, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, size, largest);
    }
}

int *heap_to_sorted_array(heap_t *heap, size_t *size) {
    if (heap == NULL || size == NULL)
        return NULL;

    *size = heap->size;
    int *sorted_array = malloc(*size * sizeof(int));
    if (sorted_array == NULL)
        return NULL;

    for (size_t i = 0; i < *size; i++) {
        sorted_array[i] = heap->array[0];
        heap->array[0] = heap->array[heap->size - 1];
        heap->size--;
        heapify(heap->array, heap->size, 0);
    }

    return sorted_array;
}

int main() {
    heap_t heap;
    heap.size = 6;
    heap.array = (int[]) { 16, 14, 10, 8, 7, 9 };

    size_t size;
    int *sorted_array = heap_to_sorted_array(&heap, &size);

    if (sorted_array != NULL) {
        for (size_t i = 0; i < size; i++) {
            printf("%d ", sorted_array[i]);
        }
        printf("\n");
        free(sorted_array);
    }

    return 0;
}

