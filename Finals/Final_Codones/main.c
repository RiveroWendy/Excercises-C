#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct codon
{
    char *secuencia;
    int tamanio;
    int id;
};

void imprimir_codon(struct codon *);
void estadistica_codon(struct codon *);
int verificar_codon(char *);
void guardar_codon(struct codon *);
void leer_archivo();

int main(){
    struct codon adn;
    printf("Ingresa Codon secuencia: ");
    adn.tamanio = 100;
    adn.secuencia = (char*)malloc(adn.tamanio * sizeof(char));
    scanf("%s", adn.secuencia);
    adn.tamanio = strlen(adn.secuencia);

    if(verificar_codon(adn.secuencia) == 0)
        {
            imprimir_codon(&adn);
            estadistica_codon(&adn);
            guardar_codon(&adn);
            leer_archivo();
        }
    else{
        printf("\nNo se pudo, no es multiplo de 3 o ingresaste mal la secuencia");
    }

    free(adn.secuencia);
    return 0;
}
int verificar_codon(char * adn){

int cant = 0;

int flag = 0;

cant = strlen(adn);

    for(int i=0; i<=cant; i++){
            if(cant%3 == 0){
            if(adn[i] == 'A' || adn[i] == 'T' || adn[i] == 'G' || adn[i] == 'C'){
                flag=1;
            }
            }
    }
    if(flag==1){
        return 0;
    }else{
    return -1;}
}

void imprimir_codon(struct codon *adn) {

    for (int i = 0; i < adn->tamanio; i += 3) {
        printf("%.3s\n", adn->secuencia + i);
    }
}

void estadistica_codon(struct codon *adn)
{
    char parte_codon[4];
    char codons[64][4];
    int contador[64] = {0};
    int index = 0;
    int encontrado = 0;

    parte_codon[3] = '\0';

    for (int i = 0; i < adn->tamanio; i += 3)
    {
        strncpy(parte_codon, adn->secuencia + i, 3);

        for (int j = 0; j < index; j++)
        {
            if (strcmp(parte_codon, codons[j]) == 0)
            {
                contador[j]++;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            strcpy(codons[index], parte_codon);
            contador[index]++;
            index++;
        }

        encontrado = 0;
    }

    printf("Codon Estadistica\n");
    for (int i = 0; i < index; i++)
    {
        printf("%s\t%d\n", codons[i], contador[i]);
    }
}


void guardar_codon(struct codon *adn)
{

    FILE *binario = fopen("codon.bin", "wb");

    if(binario == NULL){
        printf("Error al abrir el archivo\n");
        return;
    }
    else{
    printf("Escribiendo en el archivo...\n");
    fwrite(adn, sizeof(struct codon), 1, binario);
    }
    fclose(binario);
}

void leer_archivo()
{
     FILE *binario = fopen("codon.bin", "rb");

     if(!binario)
        {
            printf("Error al abrir");
            return;

        }
    struct codon codon_leido;
    while(fread(&codon_leido, sizeof(struct codon),1,binario) == 1)
        {
            printf("ID: %d\n", codon_leido.id);
            printf("Secuencia: %s\n", codon_leido.secuencia);
            printf("Tamanio: %d\n", codon_leido.tamanio);
        }
    fclose(binario);
}

