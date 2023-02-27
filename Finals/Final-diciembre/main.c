#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaro prototipo de funciones a utilizar
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
void imprimirMenu();
void tomarValorMenu(int *);

void cargarDatos();
void ingresoManual();

void verificarMonto();
void verificarCuenta();

void opcionDebito();
void opcionCredito();
void crearCuenta(FILE *, struct binario *);

void guardarLog();

void iniciarBaseDeDatos();
void modificarTitular();
void consultarCuentas();
void guardarBaseDeDatos();

int main()
{
    FILE *movimientos, *cuentasBancarias, *log;
    int contador = 0, opcion = 0, opcionGuardar = 0, opcionGuardada = 0;
    struct registro dato;
    struct binario dato_grabar;
    //imprimirMenu();
    crearCuenta(cuentasBancarias, &dato_grabar);
    consultarCuentas();
    return 0;
}
/*void imprimirMenu()
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
*/
void crearCuenta(FILE *  cuentasBancarias, struct binario *dato_grabar)
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
void consultarCuentas()
{
  FILE *binaryFile;
struct binario dato_leer;

// Open binary file in read mode
binaryFile = fopen("cuentas_bancarias.bin", "rb");

// Check if file was opened successfully
if (binaryFile == NULL) {
    printf("Error opening binary file");
    return;
}

// Read data from binary file
while (fread(&dato_leer, sizeof(struct binario), 1, binaryFile) == 1) {
    printf("Numero de Cuenta: %d\n", dato_leer.numero);
    printf("Saldo: %f\n", dato_leer.saldo);
    printf("Nombre de Titular:%s\n", dato_leer.nombre);
}

// Close binary file
fclose(binaryFile);
}
