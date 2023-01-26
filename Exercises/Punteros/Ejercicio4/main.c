#include <stdio.h>
#include <stdlib.h>

struct inventario{
    int id;
    char nombre[20];
    float costo;
    int cantidad;
};
//Prototipo de funciones
float calcularInventario(struct inventario*, int);
void buscarInventario(struct inventario*, int, int);

int main()
{
    struct inventario catalogo[] ={
     {1, "item1", 10.4, 5},
     {2, "item2", 17.4, 4},
     {3, "item3", 15.4, 2},
     {4, "item4", 9.4, 3},
    };
    int tamanio = sizeof(catalogo)/sizeof(catalogo[0]);
    float total = calcularInventario(catalogo, tamanio);
    printf("Inventario valor: $%.2f\n", total);
    int codigo_objeto = 3;
    buscarInventario(catalogo, tamanio, codigo_objeto);
    return 0;
}

float calcularInventario(struct inventario* catalogo, int tamanio){

float valor = 0;
struct inventario* objeto;
for(int i=0; i<tamanio;i++){
    objeto = catalogo+i;
    valor += objeto->costo * objeto->cantidad;
}
return valor;
}

void buscarInventario(struct inventario* catalogo, int tamanio, int codigo_objeto){
struct inventario* objeto;
for(int i = 0; i < tamanio;i++){
    objeto = catalogo + i;
    if(objeto->id == codigo_objeto){
        printf("Objeto encontrado;\n");
        printf("ID: %d\n", objeto->id);
        printf("Nombre: %s\n",objeto->nombre);
        printf("Costo: %f\n",objeto->costo);
        printf("Cantidad: %d\n",objeto->cantidad);
        return;
    }
    printf("Objeto no encontrado.\n");
    }
}
