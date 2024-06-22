#include <stdio.h>
#include <stdlib.h>
#include "data.h"

/**
 * read a entire file and returns a buffer with the content
 */
char *readDataFromFile(char *filename) {
    FILE *file;
    long file_size;
    char *buffer;

    file = fopen(filename, "rb");

    if (file == NULL) {
        perror("failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("failed to alloc memory");
        fclose(file);
        return NULL;
    }

    if (fread(buffer, 1, file_size, file) != file_size) {
        perror("failed to read file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    buffer[file_size] = '\0';

    fclose(file);
    return buffer;
}
