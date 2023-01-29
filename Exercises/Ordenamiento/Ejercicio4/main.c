#include <stdio.h>
#include <stdlib.h>

void ordenar(int [], int);
int busqueda_binaria(int [], int, int);

int main()
{
    int largo, valor, pos;
    do{
    printf("Ingresar el largo del vector entre 0 y 10000: ");
    scanf("%d",&largo);
    }while(largo < 0 || largo > 10000);

    int vector[largo];

    for (int i = 0; i < largo; i++)
    {
        vector[i] = rand() % 2001;
    }

    printf("Vector: {");

    for (int i = 0; i < largo; i++)
    {
        printf(" %d ", vector[i]);
    }
    printf("}\n");

    ordenar(vector, largo);

    printf("\nIngrese el valor a buscar: ");
    scanf("%d", &valor);

    pos = busqueda_binaria(vector, largo, valor);

    if(pos == -1){
        printf("Valor no encontrado en el vector!\n");
    }
    else{
        printf("Valor encontrado en la posicion %d\n", pos);
    }

    return 0;
}

void ordenar(int vector[], int largo)
{
    int temp;
    for(int i = 0; i < largo - 1; i++)
        {
            for(int j = 0; j < largo - i - 1; j++)
                {
                    if(vector[j] > vector[j + 1])
                        {
                            temp = vector[j];
                            vector[j] = vector[j + 1];
                            vector[j + 1] = temp;
                        }
                }
        }

    printf("Vector ordenado\n");

    for(int i = 0 ; i < largo - 1; i++)
        {
           printf(" %d ", vector[i]);
        }
}


int busqueda_binaria(int vector[], int tamanio, int valor){
    int izq = 0, der = tamanio - 1, medio, contador = 0;

    while(izq <= der){
        contador++;
        medio=(izq+der/2);
        if(vector[medio] == valor){
            printf("Numero de divisiones: %d\n", contador);
            return medio;
        }
        else if(vector[medio]<valor){
            izq = medio + 1;
        }
        else{
            der = medio - 1;
        }
    }
    printf("Numero de divisiones: %d\n", contador);
    return -1;

}
