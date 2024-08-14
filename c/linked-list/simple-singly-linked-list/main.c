#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char* argv[]) {
    LinkedList list = { .HEAD = NULL, .length = 0 };

    insert_one(&list, "alex");
    insert_one(&list, "sarah");
    insert_one(&list, "smith");

    remove_one(&list, "alex");
    remove_one(&list, "sarah");

    destroy_list(&list);
    insert_one(&list, "javascript");
    insert_one(&list, "rust");
    insert_one(&list, "java");

    print_list(&list);

    return 0;
}