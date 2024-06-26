#include <stdio.h>

#define MAX_SIZE 7

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void insert(MinHeap*, int);
void swap(int*, int*);
void heapifyUp(MinHeap*, int);
void heapifyDown(MinHeap*, int);
void printHeap(MinHeap*);

void insert(MinHeap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    heap->size++;
    heap->data[heap->size - 1] = value;
    heapifyUp(heap, heap->size - 1);
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    int parent = (index - 1) / 2;
    if (parent >= 0 && heap->data[index] < heap->data[parent]) {
        swap(&heap->data[index], &heap->data[parent]);
        heapifyUp(heap, parent);
    }
}

void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;

    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;
    
    if (smallest != index) {
        swap(&heap->data[smallest], &heap->data[index]);
        heapifyDown(heap, smallest);
    }
}

void printHeap(MinHeap* heap) {
    printf("Size: %d\n", heap->size);
    
    for (int i = 0; i < heap->size; i++) {
        printf("[%d] ", heap->data[i]);
    }
    printf("\n\n");
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int value = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->data[heap->size - 1] = 0;
    heap->size--;
    heapifyDown(heap, 0);
    return value;
}

int main(int argc, char * argv[]) {
    MinHeap heap;
    heap.size = 0;
    for (int i = 0; i < MAX_SIZE; i++) heap.data[i] = 0;

    insert(&heap, 15);
    insert(&heap, 25);
    insert(&heap, 30);
    insert(&heap, 40);
    insert(&heap, 50);
    insert(&heap, 60);
    insert(&heap, 10);

    printHeap(&heap);

    extractMin(&heap);

    printHeap(&heap);

    return 0;
}
