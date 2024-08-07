#include <stdlib.h>
#include "queue.h"

int main(int argc, const char * argv[]) {
    Queue queue = { .head = NULL, .tail = NULL, .size = 0 };

    enqueue(&queue, "c");
    enqueue(&queue, "c++");
    enqueue(&queue, "rust");
    enqueue(&queue, "python3");
    enqueue(&queue, "java");
    enqueue(&queue, "javascript");

    print_queue(queue);

    dequeue(&queue);
    dequeue(&queue);

    print_queue(queue);

    destroy_queue(&queue);

    print_queue(queue);

    return 0;
}
