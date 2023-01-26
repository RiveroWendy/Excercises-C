#include <stdio.h>
#include <stdlib.h>
//prototipo de funciones
void torreshanoi(int, char, char, char);

int main()
{
int cantidad = 0;

printf("Ingrese cantidad de discos");
scanf("%d", &cantidad);

torreshanoi(cantidad, 'A','C','B');
    return 0;
}

void torreshanoi(int cantidad, char origen, char destino, char temp){

if(cantidad > 0){
    torreshanoi(cantidad - 1, origen, temp, destino);
    printf("Mover disco %d desde %c hasta %c\n", cantidad, origen, destino);
    torreshanoi(cantidad-1,temp, destino,origen);
}
}

