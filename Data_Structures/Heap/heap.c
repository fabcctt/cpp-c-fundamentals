#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} Heap;

Heap createHeap(int capacity) {
    Heap heap;
    heap.size = 0;
    heap.capacity = capacity;
    heap.data = malloc(sizeof(int) * capacity);

    return heap;
}
void destroyHeap(Heap* heap) {
    free(heap->data);

    heap->data = NULL;
    heap->size = 0;
    heap->capacity = 0;
}

int parentIndex(int index) {
    return (index - 1) / 2;
}

int leftChildIndex(int index) {
    return 2 * index + 1;
}

int rightChildIndex(int index) {
    return 2 * index + 2;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(Heap* heap, int value) {
    if(heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }
    int index = heap->size;

    heap->data[index] = value;
    heap->size++;

    while(index > 0) {
        int parent = parentIndex(index);

        if(heap->data[parent] >= heap->data[index]) {
            break;
        }
        swap(&heap->data[parent], &heap->data[index]);
        index = parent;
    }
}

void printHeap(Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int peekMax(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    }

    return heap->data[0];
}

void heapifyDown(Heap* heap, int index) {
    while (1) {
        int left = leftChildIndex(index);
        int right = rightChildIndex(index);
        int largest = index;

        if (left < heap->size &&
            heap->data[left] > heap->data[largest]) {
            largest = left;
        }

        if (right < heap->size &&
            heap->data[right] > heap->data[largest]) {
            largest = right;
        }

        if (largest == index) {
            break;
        }

        swap(&heap->data[index], &heap->data[largest]);

        index = largest;
    }
}
int extractMax(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int max = heap->data[0];

    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    if (heap->size > 0) {
        heapifyDown(heap, 0);
    }

    return max;
}
int main() {
    Heap heap = createHeap(5);

    if (heap.data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    insert(&heap, 90);
    insert(&heap, 50);
    insert(&heap, 70);
    insert(&heap, 100);
    insert(&heap, 80);

    printf("Heap created successfully\n");

    printf("Max value: %d\n", peekMax(&heap));
    printf("Size: %d\n", heap.size);
    printf("Capacity: %d\n", heap.capacity);
    printHeap(&heap);
    printf("Extracted max: %d\n", extractMax(&heap));
    printHeap(&heap);

    destroyHeap(&heap);
    return 0;
}