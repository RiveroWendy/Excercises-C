#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaro prototipo de funciones a utilizar

void imprimirMenu();
void tomarValorMenu(int *);

void cargarDatos();
void ingresoManual();

void verificarMonto();
void verificarCuenta();

void opcionDebito();
void opcionCredito();
void crearCuenta();

void guardarLog();

void iniciarBaseDeDatos();
void modificarTitular();
void consultarCuentas();
void guardarBaseDeDatos();

struct registro
{
    int cuenta;
    float monto;
    int operacion;
};

struct binario
{
    int numero;
    float saldo;
    char nombre[50];
};
int main()
{
    FILE *movimientos = fopen("movimientos.txt", "r+");
    FILE *cuentaBancaria= fopen("cuentas_bancarias.bin","rb");
    FILE *log = fopen("log.txt","a");
    char buffer[500], *ptr, *var_ptr, temporal[250];
    int contador = 0, opcion = 0, opcionGuardar = 0, opcionGuardada = 0;
    struct registro dato;

    imprimirMenu();

//Menu de opciones



    return 0;
}
void imprimirMenu()
{

    printf("\nBIENVENIDO!\n\nSeleccione una opcion: \n");

    printf("1 - Operaciones desde archivo\n");

    printf("2 - Ingreso nueva cuenta\n");

    printf("2 - Procesar transacciones\n");

    printf("3 - Modificar nombre del titular\n");

    printf("4 - Consultar estados de cuenta\n");

    printf("5 - Guardar base de datos\n");

    printf("6 - Salir del programa\n");

}
