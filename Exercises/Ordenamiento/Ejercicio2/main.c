#include <stdio.h>
#include <stdlib.h>

//Prototipo de funcion
//Busqueda binaria

int busqueda_binaria(int *, int, int);

int main()
{
    int tamanio,valor, inicio, i,pos;

    printf("Ingresa el tamanio del vector:");
    scanf("%d",&tamanio);

    int *vector = (int*)malloc(tamanio*sizeof(int));

    if(vector == NULL){
        printf("Error de memoria\n");
        return 1;
    }

    printf("Ingrese el inicio del numero: ");
    scanf("%d",&inicio);

    for(i = 0; i<tamanio; i++){
        vector[i] = inicio+ (2*i);
    }

    printf("Vector: ");
    for(i = 0; i < tamanio; i++){
        printf("%d ", vector[i]);
    }

    printf("\nIngrese el valor a buscar: ");
    scanf("%d", &valor);
    pos = busqueda_binaria(vector, tamanio, valor);

    if(pos == -1){
        printf("Valor no encontrado en el vector!\n");
    }
    else{
        printf("Valor encontrado en la posicion %d\n", pos);
    }

    free(vector);
    return 0;
}

int busqueda_binaria(int* vector, int tamanio, int valor){
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
