#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct binario
{
    int numero;
    float saldo;
    char nombre[50];
};

struct registro
{
    int cuenta;
    float monto;
    int operacion;
};

void crearCuenta(FILE *, struct binario *);
void consultarCuentas(FILE *);
void operacionDebito(FILE *, int, float);
void guardarMovimiento(FILE *);

int verificarNumero(int);
int verificarDebito(int);
int buscarCuenta(FILE *, int);

int main()
{
    FILE *cuentasBancarias = NULL;
    struct binario dato_grabar;
    int opcion, numeroCuenta;
    float monto;

    do {
        printf("\nOpciones:\n");
        printf("1. Crear cuenta\n");
        printf("2. Consultar cuentas\n");
        printf("3. Buscar cuenta\n");
        printf("4. Realizar un debito\n");
        printf("0. Salir\n");
        printf("\nIngrese su opcion:\n");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                crearCuenta(cuentasBancarias, &dato_grabar);
                break;
            case 2:
                consultarCuentas(cuentasBancarias);
                break;
            case 3:
                printf("Ingrese numero de cuenta:\n");
                scanf("%d", &numeroCuenta);
                buscarCuenta(cuentasBancarias, numeroCuenta);
                break;
            case 4:
                printf("Ingrese numero de cuenta:\n");
                scanf("%d", &numeroCuenta);
                printf("Ingrese monto a debitar:\n");
                scanf("%f", &monto);
                operacionDebito(cuentasBancarias, numeroCuenta, monto);
                break;
            case 0:
                printf("Adios!\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while(opcion != 0);

    return 0;
}


void crearCuenta(FILE *cuentasBancarias, struct binario *dato_grabar)
{
    cuentasBancarias = fopen("cuentas_bancarias.bin", "ab");
    int num_digitos = 0;
    if(!cuentasBancarias)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    printf("\nOpcion Crear Cuenta \n");

   do {
    printf("\n Ingrese Numero de cuenta:\n");
    scanf("%d", &dato_grabar->numero);
    num_digitos = verificarNumero(dato_grabar->numero);
    if(buscarCuenta(cuentasBancarias, dato_grabar->numero))
        {
            printf("El numero de cuenta ya existe. Intente nuevamente.\n");
            num_digitos = 0;
        }
    } while(num_digitos != 8);

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

void operacionDebito(FILE *cuentasBancarias, int cuenta, float monto)
{
    cuentasBancarias = fopen("cuentas_bancarias.bin", "r+b");
    if (!cuentasBancarias) {
        printf("Error al abrir el archivo\n");
        return;
    }
    struct binario dato;
    int encontrado = 0;

    while (fread(&dato, sizeof(struct binario), 1, cuentasBancarias) == 1) {
        if (dato.numero == cuenta) {
            encontrado = 1;
            if (dato.saldo >= monto) {
                dato.saldo -= monto;
                fseek(cuentasBancarias, sizeof(struct binario), SEEK_CUR);
                fwrite(&dato, sizeof(struct binario), 1, cuentasBancarias);
                printf("Debito exitoso\n");
            } else {
                printf("Saldo insuficiente\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Cuenta no encontrada\n");
    }

    fclose(cuentasBancarias);
}


int verificarNumero(int numero)
{
    int tamanio = 0;
    int temp = numero;

    while (temp != 0)
    {
        temp /= 10;
        tamanio++;
    }

    return tamanio;
}

int verificarDebito(int numDebito)
{
    struct binario dato;

    if(dato.saldo>=numDebito)
        {
            return 1;
        }
    return 0;

}

int buscarCuenta(FILE * cuentasBancarias, int numeroCuenta)
{
cuentasBancarias = fopen("cuentas_bancarias.bin", "rb");
struct binario dato;
if (!cuentasBancarias)
    {
        printf("Error al abrir el archivo\n");
        return -1;
    }

    rewind(cuentasBancarias);
    while(fread(&dato, sizeof(struct binario), 1 , cuentasBancarias) == 1)
        {
            if(dato.numero == numeroCuenta)
                {
                    printf("Cuenta Encontrada\n");
                    printf("Numero de cuenta: %d\n", dato.numero);
                    printf("Saldo: %.2f\n", dato.saldo);
                    printf("Titular: %s\n\n", dato.nombre);
                    fclose(cuentasBancarias);
                    return 1;
                }
        }
        printf("Cuenta no encontrada\n");
        fclose(cuentasBancarias);
        return 0;
}
