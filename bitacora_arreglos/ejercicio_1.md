```
#include <stdio.h>

int main() {
    int arreglo[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    printf("Índice\tValor\tDirección de memoria\n");
    for (int i = 0; i < 10; i++) 
    {
        printf("%d\t%d\t%p\n", i, arreglo[i], (void*)&arreglo[i]);
    }

    return 0;
}

```
