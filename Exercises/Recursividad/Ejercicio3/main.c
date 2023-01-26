#include <stdio.h>
#include <stdlib.h>

//prototipo de funcion
int maxdiv(int, int);

int main()
{
int num1 = 0;
int num2 = 0;

printf("\nIngrese primer numero: ");
scanf("%d", &num1);
printf("\nIngrese segundo numero: ");
scanf("%d",&num2);
int max = maxdiv(num1, num2);

printf("\nMaximo comun divisor de %d y %d es: %d",num1,num2, max);
    return 0;
}

int maxdiv(int num1, int num2){

if(num2 == 0){
    return num1;
}
else{
    return maxdiv(num2, num1%num2);
}

}
