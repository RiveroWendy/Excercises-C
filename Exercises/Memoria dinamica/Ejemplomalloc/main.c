#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cantElementos;
    //puntero al vector
    int* vector;

    printf("Largo del vector");
    scanf("%d", &cantElementos);

    //reserva de memoria
    vector =(int*)malloc(cantElementos*sizeof(int));
    if(vector==NULL){
        //si no hay memoria suficiente, se sale del programa
        printf("Problemas reservando memoria");
        exit(1);
    }
    for(int i= 0;i< cantElementos;i++)
    printf("%d\n",vector+i);
    //Trabajamos con el vector en esta parte

    //funcion para liberar memoria
    free(vector);

    return 0;
}
