#include <stdio.h>
#include <stdlib.h>
/*
Escribir un programa que tenga una función que calcule el máximo y el mínimo de los números de un
vector. El tamaño del vector será como máximo 30. En el programa principal (main) le preguntará al
usuario la cantidad de elementos que desea introducir (estos datos deben ser validados) y a continuación
se leerá de teclado elemento por elemento. La función recibirá la referencia y la cantidad de elementos
cargados. La función calculará el máximo y el mínimo. El valor del máximo y el mínimo se devolverá en
forma de una estructura que también es pasada como referencia a la función, para luego ser mostrada
por la función main().
El prototipo de la función es: void Buscar(float *, int , struct MaxMin *);
*/
struct maxMin{
float max;
float min;
};
//Prototipo de funcion
void buscar(float *,int, struct maxMin *);

int main()
{
    int tamanio;
    printf("Ingresa el numero de elementos: ");
    scanf("%d", &tamanio);

    while(tamanio <=0 || tamanio > 30){
        printf("Por favor ingresa un numero entre 1 y 30:");
        scanf("%d", &tamanio);
    }

    float vector[tamanio];
    for(int i = 0; i < tamanio; i++){
        printf("Ingresa elemento %d: ", i + 1);
        scanf("%f", &vector[i]);
    }

    struct maxMin resultado;

    buscar(vector, tamanio, &resultado);

    printf("Maximo: %.2f\n", resultado.max);
    printf("Minimo: %.2f\n", resultado.min);

    return 0;
}

void buscar(float *vector, int tamanio, struct maxMin *resultado){
resultado->max = vector[0];
resultado->min = vector[0];

for(int i = 1; i< tamanio;i++){
        if(vector[i] > resultado->max){
            resultado->max = vector[i];
        }
        if(vector[i] < resultado->min){
            resultado->min = vector[i];
        }

}

}
