#include <stdio.h>
#include <stdlib.h>

struct fecha{
 int dia;
 int mes;
 int anio;
};
//prototipo de funciones
void imprimir_fecha(struct fecha*,char**);


int main()
{
char* nombre_meses[] ={"Enero", "Febrero","Marzo", "Abril", "Mayo",
"Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

struct fecha f = {10,12,2023};
imprimir_fecha(&f,nombre_meses);

    return 0;
}

void imprimir_fecha(struct fecha* f, char** nombres_meses)
{
    if(f->dia <1 || f->dia >30){
        printf("Dia invalido\n");
        return;
    }
    if(f->mes < 1 || f->mes > 12){
        printf("Mes invalido\n");
        return;
    }
    if(f->anio<1){
        printf("Anio invalido\n");
        return;
    }

    printf("%d de %s del %d\n",f->dia,nombres_meses[f->mes-1],f->anio);
}

