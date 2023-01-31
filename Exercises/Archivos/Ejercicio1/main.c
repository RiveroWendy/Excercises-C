#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct registro{
    int legajo;
    int dni;
    char nombre_apellido[250];
    int edad;
};

int main(){
    FILE *archivo;
    char buffer[500], *ptr, *var_ptr,temporal[250];
    struct registro Dato_grabar;
    int cont_variable;
    archivo = fopen("archivo.txt", "r+");
    printf("Leyendo archivo...\n\n");

    while(!feof(archivo)){
        cont_variable=1; //pongo en 1 para analizar primer campo
        ptr=buffer; // apunto al principio de lo que me traigo del archivo
        fgets(buffer,500,archivo); // leo una linea del archivo
        var_ptr=temporal; //inicializo puntero a la variable temporal
        while(*ptr!='\0'){
            //hasta no llegar al final del registro, leo los caracteres
            if(*ptr!='|'){
                //cargo en la variable correspondiente
                *var_ptr=*ptr; //voy copiando los caracteres
                var_ptr++; //incremento punteros
                ptr++; //incremento punteros
            }else{
                //implica que termina la linea a copiar
                *var_ptr='\0'; //finalizo string que apunta a temporal
                ptr++; // incremento puntero a buffer
                switch(cont_variable){
                    case 1:
                    Dato_grabar.legajo = atoi(temporal);
                    break;
                    case 2:
                    Dato_grabar.dni = atoi(temporal);
                    break;
                    case 3:
                    strcpy(Dato_grabar.nombre_apellido,temporal);
                    break;
                    }
                cont_variable++; //cuento varible utilizada
                var_ptr=temporal; // inicializo puntero a la variable temporal
                }
            }
            //copio la ultima variable leida por que llegue al '\0'
            *var_ptr='\0';
            Dato_grabar.edad=atoi(temporal);

            printf("Legajo: %d\n",Dato_grabar.legajo);
            printf("DNI: %d\n",Dato_grabar.dni);
            printf("Nombre y apellido: %s\n",Dato_grabar.nombre_apellido);
            printf("Edad: %d\n\n",Dato_grabar.edad);

        }
    fclose (archivo); // cierro archivo
    return 0;
}
