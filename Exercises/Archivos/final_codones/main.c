#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir_codon(char *);
int verificar_codon(char *);

struct adn{

char codon[9];

};



int main(){

struct adn p;

//p = (struct  adn *) malloc(sizeof(struct adn)); //almacenamiento ram

/*if(p == NULL){
    printf("No se pudo asignar memoria");
}else{
    printf("Se asigno memoria");
}
*/

printf("\nIngrese codon: \n");
scanf("%3s", p.codon);



/*if(verificar_codon(p.codon)== 0 ){
    printf("%s", p.codon);

}else{
        printf("No se pudo");

}*/


imprimir_codon(&p);


//free(p);

return 0;}


int verificar_codon(char * p){

int cant = 0;

int flag = 0;

cant = strlen(p);

    for(int i=0; i<=cant; i++){
            if(cant%3 == 0){
            if(p[i] == 'A' || p[i] == 'T' || p[i] == 'G' || p[i] == 'C'){

                flag++;
            }
            }
    }
    if(flag==cant){
        return 0;
    }else{
    return -1;}
}


void imprimir_codon(char *p) {

int cant = 0;
cant = strlen(p);

     for(int i=0; i<=cant; i++){
            if(i%3 == 0 && i !=0){
            printf("\n");
            }
            printf("%c", p[i]);

     }
}

