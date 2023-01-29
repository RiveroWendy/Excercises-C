#include <stdio.h>
#include <stdlib.h>

//Prototipo de funcion
int buscar(int [], int , int );

int main()
{
    int largo;
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

    int valor;
    printf("Ingrese el valor a buscar: ");
    scanf("%d", &valor);

    int posicion = buscar(vector, largo, valor);

    if(posicion != -1)
        {
            printf("Valor %d encontrado en la posicion %d\n", valor, posicion);
        }
        else
            {
                printf("Valor %d no encontrado\n", valor);

            }

    return 0;
}

int buscar(int vector[], int largo, int valor)
{
     int tamanio = largo * sizeof(vector[0]) / 1024;
     printf("Tamanio del vector en memoria: %d Kbytes\n", tamanio);
     for (int i = 0; i < largo; i++)
        {
            if(vector[i] == valor)
                {
                    return i;
                }
        }
    return -1;
}
