#include <stdio.h>
#include <stdlib.h>

typedef struct heap_s {
    int value;
    struct heap_s *left;
    struct heap_s *right;
} heap_t;

// Function to create a new heap node
heap_t *create_node(int value) {
    heap_t *node = malloc(sizeof(heap_t));
    if (!node) {
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to swap values of two nodes
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i
void heapify(int *array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

// Function to convert array to a max heap
void build_max_heap(int *array, size_t size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
}

// Function to insert nodes in level order
heap_t *insert_level_order(int *array, heap_t *root, int i, int size) {
    if (i < size) {
        heap_t *temp = create_node(array[i]);
        root = temp;

        root->left = insert_level_order(array, root->left, 2 * i + 1, size);
        root->right = insert_level_order(array, root->right, 2 * i + 2, size);
    }
    return root;
}

// Function to convert array to a max heap tree
heap_t *array_to_heap(int *array, size_t size) {
    if (array == NULL || size == 0) {
        return NULL;
    }

    build_max_heap(array, size);

    return insert_level_order(array, NULL, 0, size);
}

// Helper function to print the heap (in-order traversal)
void print_heap(heap_t *root) {
    if (root != NULL) {
        print_heap(root->left);
        printf("%d ", root->value);
        print_heap(root->right);
    }
}

// Helper function to free the heap
void free_heap(heap_t *root) {
    if (root != NULL) {
        free_heap(root->left);
        free_heap(root->right);
        free(root);
    }
}

int main() {
    int array[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    size_t size = sizeof(array) / sizeof(array[0]);

    heap_t *heap = array_to_heap(array, size);

    printf("Heap (in-order traversal): ");
    print_heap(heap);
    printf("\n");

    free_heap(heap);
    return 0;
}

