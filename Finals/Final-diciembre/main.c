#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct binario
{
    int numero;
    float saldo;
    char nombre[50];
};

void crearCuenta(FILE *, struct binario *);
void consultarCuentas(FILE *);

int main()
{
    FILE *cuentasBancarias;
    struct binario dato_grabar;

    crearCuenta(cuentasBancarias, &dato_grabar);
    consultarCuentas(cuentasBancarias);

    return 0;
}

void crearCuenta(FILE *cuentasBancarias, struct binario *dato_grabar)
{
    cuentasBancarias = fopen("cuentas_bancarias.bin", "ab");

    if(!cuentasBancarias)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    printf("\nOpcion Crear Cuenta \n");

    printf("\n Ingrese Numero de cuenta:\n");
    scanf("%d", &dato_grabar->numero);
    printf("\n Ingrese Saldo:\n");
    scanf("%f", &dato_grabar->saldo);
    printf("\nIngrese numero de titular\n");
    scanf("%s",dato_grabar->nombre);

    fwrite(dato_grabar, sizeof(struct binario), 1, cuentasBancarias);
    fclose(cuentasBancarias);
}

void consultarCuentas(FILE *cuentasBancarias)
{
    cuentasBancarias = fopen("cuentas_bancarias.bin", "rb");

    if(!cuentasBancarias)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    struct binario dato;

    rewind(cuentasBancarias);

    while(fread(&dato, sizeof(struct binario),1,cuentasBancarias) == 1)
    {
        printf("Numero de cuenta: %d\n", dato.numero);
        printf("Saldo: %.2f\n", dato.saldo);
        printf("Titular: %s\n\n", dato.nombre);
    }

    fclose(cuentasBancarias);
}
