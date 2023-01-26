#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Realizar una función que reciba por referencia una palabra y un vector de string que representa un
diccionario. Esta función deberá devolver verdadero o falso según encontré o no la palabra en el
diccionario.
*/

/*
Prototipo de funcion, que va a recibir una palabra
y un vector de string por referencia
*/

void encontrar_palabra(char*,char*[]);

int main()
{
    char palabra[]="hol";
    char* diccionario[5]={"hola", "como","estas"};
    encontrar_palabra(palabra,diccionario);
    return 0;
}

void encontrar_palabra(char* palabra, char* diccionario[]){

    for(int i = 0; i<3; i++){
        if(strcmp(palabra,diccionario[i]) == 0){
            printf("Palabra encontrada en la posicion %d\n",i);
            return;
        }
    }
    printf("Palabra no encontrada\n");
}
