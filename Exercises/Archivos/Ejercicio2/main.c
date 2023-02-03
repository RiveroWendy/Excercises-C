#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct codon
{
    char *secuencia;
    int tamanio;
};

void imprimir_codon(struct codon *);

int main(){
    struct codon adn;
    adn.secuencia = "AAATTTGGG";
    adn.tamanio = strlen(adn.secuencia);
    imprimir_codon(&adn);
    return 0;
}
void imprimir_codon(struct codon *adn) {

    for (int i = 0; i < adn->tamanio; i += 3) {
        printf("%.3s\n", adn->secuencia + i);
    }
}
