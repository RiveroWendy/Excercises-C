#include <stdio.h>
#include <stdlib.h>

void mostrar_concurrencia(int vector[], int largo);

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

    mostrar_concurrencia(vector, largo);

    return 0;
}


void mostrar_concurrencia(int vector[], int largo)
{
    int i = 0, j = 1;

    while(i < largo && j < largo)
        {
            if( vector[i] == vector[j])
                {
                    int contador = 1;

                    while(vector[i] == vector[j])
                        {
                            contador++;
                            j++;

                        }

                        if(contador > 1)
                            {
                                printf("Valor %d aparece %d veces \n", vector[i], contador);

                            }
                }
                else
                {
                    i++;
                    j++;
                }
        }

}
