#include <stdio.h>
#include <stdlib.h>

//prototipo de funciones
int divres(int, int);

int main()
{
int dividendo = 0;
int divisor = 0;

printf("Ingrese dividendo: ");
scanf("%d", &dividendo);
printf("Ingrese divisor: ");
scanf("%d", &divisor);

int resultado = divres(dividendo, divisor);
printf("Resultado de la division: %d", resultado);
    return 0;
}

int divres(int dividendo, int divisor){
if(dividendo < divisor){
    return 0;
}
else{
    return 1 + divres(dividendo - divisor, divisor);
}

}
