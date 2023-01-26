#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Realizar una funci�n que reciba por referencia una frase y el tipo de operaci�n, donde la operaci�n
indicar� pasar a may�scula o min�scula toda la frase. Se deber� contemplar que algunos caracteres o
todos ya se encuentres en el formato de salida, y que los espacios, signos de puntuaci�n y caracteres
especiales no deben convertirse.
*/

/*
Prototipo de funcion, recibe un puntero a char y una operacion
*/
void modificar_frase(char*, int);

int main()
{
    char frase[] = "Hola, Mundo";
    modificar_frase(frase, 0);
    printf("Frase modificada: %s", frase);
    return 0;
}

void modificar_frase(char* frase, int operacion){
int tamanio = strlen(frase);
for(int i = 0; i < tamanio;i++){
    if((frase[i] >='A' && frase[i]<='Z')
       || (frase[i] >='a' && frase[i]<='z')){
       if(operacion == 0){
        frase[i] = tolower(frase[i]);
       }
       else if(operacion == 1){
        frase[i]= toupper(frase[i]);
       }
       }
}

}
