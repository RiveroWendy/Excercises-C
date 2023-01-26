#include <stdio.h>
#include <stdlib.h>
/*
Una empresa tiene ordenados los números de facturas ordenadas (pero empezando por un
numero sin aclarar), las cuales algunas tienen remitos consecutivos asociados. Por otro lado, los
remitos están ordenados y se marcan si la mercadería fue entregada o no.
El Director de Logística nos solicita que armemos un programa que permita ingresar el número
de factura o remito, validando la existencia de la misma. En caso de ingresar una factura,
mostrar el número de remito relacionado (si es que hay) y en ese caso especificar si la
mercadería fue entregada. Si se ingresa el número de remito, informar el número de factura
asociada y si la mercadería fue entregada.
Considerar que:

Cada factura puede tener solo un remito asociado, o no tener remito si fue
retirado.
Todo remito debe tener una factura asociada.
Utilizar struct para almacenar los datos de las facturas y remitos.
*/
struct FacturaRemito{
    int numero;
    int numeroAsociado;
    // 1 o 0
    int fueEntregado;
};


int main()
{
    //Inicializar Array de structs
    struct FacturaRemito facturas[] ={
    {100, 101, 1},
    {200, 201, 0},
    {300, 0, 1},
    {400, 401, 1},
    };

    int numFacturasRemitos = sizeof(facturas)/
    sizeof(facturas[0]);

    //ordenar el array de struct por numero de remito
    //Ordenamiento por burbuja
    for(int i = 0; i <numFacturasRemitos - 1; i++){
        for(int j = 0; j < numFacturasRemitos-i-1;j++){
            if(facturas[i].numero > facturas[j+1].numero){
                struct FacturaRemito temp = facturas[j];
                facturas[j] = facturas[j+1];
                facturas[j + 1] = temp;
            }
        }
    }

    //Obtener numero de remito desde el usuario
    int numeroIngresado;
    printf("Ingrese numero de factura/remito: ");
    scanf("%d", &numeroIngresado);

    //Buscar por coincidencia de numero de remito en la estructura
    struct FacturaRemito *structEncontrado = NULL;
    for(int i = 0; i < numFacturasRemitos; i++){
        if(facturas[i].numero==numeroIngresado){
            structEncontrado = &facturas[i];
            break;
        }
    }

    //Revisar si la estructura fue encontrada

    if(structEncontrado!=NULL){
        printf("numero de Factura/Remito: %d\n", structEncontrado->numero);
        if(structEncontrado->numeroAsociado != 0){
            printf("numero de Factura/Remito asociado %d\n", structEncontrado->numeroAsociado);
        }
        if(structEncontrado->fueEntregado == 1){
            printf("fue Entregado: Si\n");
        }
        else{
            printf("fue Entregado: No\n");
        }
    }
    else{
        printf("Numero de Factura/Remito invalido.\n");
    }

    return 0;
}

