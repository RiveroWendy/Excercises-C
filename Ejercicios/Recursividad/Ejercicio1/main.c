#include <stdio.h>
#include <stdlib.h>

//Prototipos de funciones
int suma(int);

int main()
{
int digito = 0;

printf("Ingrese un numero: ");
scanf("%d",&digito);

int total = suma(digito);
printf("\nTotal:%d",total);
    return 0;
}

//Funcion recursiva
int suma(int digito){
    if(digito == 0)
    {
        return 0;
    }
    else
    {
      return digito % 10 + suma(digito/10);
    }
}

