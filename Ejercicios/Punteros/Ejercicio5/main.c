#include <stdio.h>
#include <stdlib.h>
/*
Escribir un programa que tenga una funci�n que calcule el m�ximo y el m�nimo de los n�meros de un
vector. El tama�o del vector ser� como m�ximo 30. En el programa principal (main) le preguntar� al
usuario la cantidad de elementos que desea introducir (estos datos deben ser validados) y a continuaci�n
se leer� de teclado elemento por elemento. La funci�n recibir� la referencia y la cantidad de elementos
cargados. La funci�n calcular� el m�ximo y el m�nimo. El valor del m�ximo y el m�nimo se devolver� en
forma de una estructura que tambi�n es pasada como referencia a la funci�n, para luego ser mostrada
por la funci�n main().
El prototipo de la funci�n es: void Buscar(float *, int , struct MaxMin *);
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
