#include <stdio.h>

#define MAX_SIZE 7

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void insert(MinHeap*, int);
void swap(int*, int*);
void heapifyUp(MinHeap*, int);
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
    printf("Child: %d - Parent: %d\n", index, parent);
    if (parent >= 0 && heap->data[index] < heap->data[parent]) {
        swap(&heap->data[index], &heap->data[parent]);
        heapifyUp(heap, parent);
    }
}

void printHeap(MinHeap* heap) {
    printf("Size: %d\n", heap->size);
    
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("[%d] ", heap->data[i]);
    }
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

    return 0;
}

/*
 @0  @1  @2  @3  @4  @5  @6
[15][25][30][40][50][60][10]

      [15]
      /  \
    [25][30]
   /  |  |  \
[40][50][60][10]

*/