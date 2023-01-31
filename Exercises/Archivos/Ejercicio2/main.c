#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct registro{
    char legajo[3];
    char dni[8];
    char nombre_apellido[6];
    char edad[3];
};

int main(){
    FILE *archivo;
    struct registro Dato_grabar;
    archivo = fopen("archivo.txt", "r+");
    printf("Leyendo archivo...\n\n");

    if(archivo == NULL)
        {
            printf("No se pudo abrir el archivo\n");
            return 1;
        }

    while(fgets(Dato_grabar.legajo, 3, archivo) != NULL)
        {
            fgets(Dato_grabar.dni, 8, archivo);
            fgets(Dato_grabar.nombre_apellido, 6 , archivo);
            fgets(Dato_grabar.edad, 3, archivo);

            Dato_grabar.legajo[strcspn(Dato_grabar.legajo, "\n")] = 0;
            Dato_grabar.dni[strcspn(Dato_grabar.dni, "\n")] = 0;
            Dato_grabar.nombre_apellido[strcspn(Dato_grabar.nombre_apellido,"\n")] = 0;
            Dato_grabar.edad[strcspn(Dato_grabar.edad, "\n")] = 0;

            printf("Legajo: %s\n",Dato_grabar.legajo);
            printf("DNI: %s\n",Dato_grabar.dni);
            printf("Nombre y apellido: %s\n",Dato_grabar.nombre_apellido);
            printf("Edad: %s\n\n",Dato_grabar.edad);

        }
    fclose (archivo); // cierro archivo
    return 0;
}
