#include <stdlib.h>

void f(void) {
    int* x = malloc(10 * sizeof(int));
    //loop para inserção
    for (int i = 0; i < 10; i++) {
        x[i] = i;
    }
    free(x); //desalocando memoria
}

int main(void) {
    f();
    return 0;
}