#include <stdio.h>
#include <stdlib.h>

/*
Programar una función recursiva que invierta el ingreso de un string, por ejemplo si
ingreso 1234, que devuelva 4321.
*/

//Prototipo de funciones
void cambiarOrden(char*);

int main()
{
    char string[10];
    printf("Ingrese string a revertir: ");
    scanf("%s",string);
    cambiarOrden(string);
    return 0;
}

void cambiarOrden(char* string){
if(string && *string){
    cambiarOrden(string + 1);
    printf("%c", *string);
}
}
