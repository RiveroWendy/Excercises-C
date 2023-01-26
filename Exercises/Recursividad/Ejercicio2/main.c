#include <stdio.h>
#include <stdlib.h>

//prototipo de funcion
int fibonacci(int);
int main()
{
int num = 0;
printf("Ingrese num: ");
scanf("%d",&num);

int total = fibonacci(num);
printf("\nResultado fibonacci: %d", total);
    return 0;
}

int fibonacci(int num)
{
    if(num == 0){
        return 0;
    }
    else if(num == 1){
        return 1;
    }
    else{
        return fibonacci(num-1) + fibonacci(num - 2);
    }

}
