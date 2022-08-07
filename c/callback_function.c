#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * mapInteger(int[], unsigned int, int (*)(int));
char ** mapString(char * [], unsigned int, void (*)(char**));

int * mapInteger(int arr[], unsigned int n, int (*ptrFunction)(int value)) {
    n = n/sizeof(int);
    printf("[");
    for (int i = 0; i < n; i++) {
        arr[i] = (*ptrFunction) ? (*ptrFunction)(arr[i]) : arr[i];
        printf("%d, ", arr[i]);
    }
    printf("\b\b]\n");
}

char ** mapString(char ** arr, unsigned int n, void (*ptrFunction)(char ** value)) {
    n = n/sizeof(char *);
    printf("[");
    for (int i = 0; i < n; i++) {
        (*ptrFunction) ? (*ptrFunction)(&arr[i]) : 0;
        printf("%s, ", arr[i]);
    }
    printf("\b\b]\n");
    return arr;
}

int mult(int value) {
    return value * 2;
}

void novoValor(char ** value) {
    *value = " --Novo Valor-- ";
}

int main() {

    int arr1[] = {20, 30, 40, 100, 1000, 2000, 3000};
    char * arr2[] = {"alex", "sarah", "isabela", "pedro", "kraby"};
    mapInteger(arr1, sizeof(arr1), &mult);
    mapString(arr2, sizeof(arr2), &novoValor);

    return 0;
}