#include <stdio.h>
#include <stdlib.h>

/*
la matriz externa se asigna primero y luego se
asignan las matrices internas para cada fila.
*/
int main()
{
    int rows, cols;
    printf("Ingrese numero de filas: ");
    scanf("%d", &rows);
    printf("Ingrese numero de columnas: ");
    scanf("%d", &cols);

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
    arr[i] = (int *)malloc(cols * sizeof(int));
    }

    free(arr);
    return 0;
}
